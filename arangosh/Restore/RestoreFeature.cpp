////////////////////////////////////////////////////////////////////////////////
/// DISCLAIMER
///
/// Copyright 2016 ArangoDB GmbH, Cologne, Germany
///
/// Licensed under the Apache License, Version 2.0 (the "License");
/// you may not use this file except in compliance with the License.
/// You may obtain a copy of the License at
///
///     http://www.apache.org/licenses/LICENSE-2.0
///
/// Unless required by applicable law or agreed to in writing, software
/// distributed under the License is distributed on an "AS IS" BASIS,
/// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
/// See the License for the specific language governing permissions and
/// limitations under the License.
///
/// Copyright holder is ArangoDB GmbH, Cologne, Germany
///
/// @author Jan Steemann
////////////////////////////////////////////////////////////////////////////////

#include "RestoreFeature.h"

#include <velocypack/Builder.h>
#include <velocypack/Options.h>
#include <velocypack/velocypack-aliases.h>

#include "ApplicationFeatures/ApplicationServer.h"
#include "Basics/FileUtils.h"
#include "Basics/OpenFilesTracker.h"
#include "Basics/Result.h"
#include "Basics/StringUtils.h"
#include "Basics/VelocyPackHelper.h"
#include "Basics/files.h"
#include "Basics/terminal-utils.h"
#include "Basics/tri-strings.h"
#include "Endpoint/Endpoint.h"
#include "Logger/Logger.h"
#include "ProgramOptions/ProgramOptions.h"
#include "Rest/HttpResponse.h"
#include "Rest/InitializeRest.h"
#include "Rest/Version.h"
#include "Shell/ClientFeature.h"
#include "SimpleHttpClient/GeneralClientConnection.h"
#include "SimpleHttpClient/SimpleHttpClient.h"
#include "SimpleHttpClient/SimpleHttpResult.h"
#include "Ssl/SslInterface.h"

#ifdef USE_ENTERPRISE
#include "Enterprise/Encryption/EncryptionFeature.h"
#endif

namespace {
/// @brief name of the feature to report to application server
constexpr auto FeatureName = "Restore";
}  // namespace

namespace {
/// @brief check whether HTTP response is valid, complete, and not an error
arangodb::Result checkHttpResponse(
    arangodb::httpclient::SimpleHttpClient& client,
    std::unique_ptr<arangodb::httpclient::SimpleHttpResult>& response) {
  using arangodb::basics::StringUtils::itoa;
  if (response == nullptr || !response->isComplete()) {
    return {TRI_ERROR_INTERNAL,
            "got invalid response from server: " + client.getErrorMessage()};
  }
  if (response->wasHttpError()) {
    return {TRI_ERROR_INTERNAL, "got invalid response from server: HTTP " +
                                    itoa(response->getHttpReturnCode()) + ": " +
                                    response->getHttpReturnMessage()};
  }
  return {TRI_ERROR_NO_ERROR};
}
}  // namespace

namespace {
bool sortCollections(VPackBuilder const& l, VPackBuilder const& r) {
  VPackSlice const left = l.slice().get("parameters");
  VPackSlice const right = r.slice().get("parameters");

  // First we sort by distribution.
  // We first have to create collections defining the distribution.
  VPackSlice leftDist = left.get("distributeShardsLike");
  VPackSlice rightDist = right.get("distributeShardsLike");

  if (leftDist.isNone() && !rightDist.isNone()) {
    return true;
  }

  if (rightDist.isNone() && !leftDist.isNone()) {
    return false;
  }

  int leftType =
      arangodb::basics::VelocyPackHelper::getNumericValue<int>(left, "type", 0);
  int rightType = arangodb::basics::VelocyPackHelper::getNumericValue<int>(
      right, "type", 0);

  if (leftType != rightType) {
    return leftType < rightType;
  }

  std::string leftName =
      arangodb::basics::VelocyPackHelper::getStringValue(left, "name", "");
  std::string rightName =
      arangodb::basics::VelocyPackHelper::getStringValue(right, "name", "");

  return strcasecmp(leftName.c_str(), rightName.c_str()) < 0;
}
}  // namespace

namespace {
arangodb::Result tryCreateDatabase(std::string const& name) {
  using arangodb::httpclient::SimpleHttpClient;
  using arangodb::httpclient::SimpleHttpResult;
  using arangodb::rest::RequestType;
  using arangodb::rest::ResponseCode;
  using arangodb::velocypack::ArrayBuilder;
  using arangodb::velocypack::ObjectBuilder;

  // get client feature for configuration info
  auto client = arangodb::application_features::ApplicationServer::getFeature<
      arangodb::ClientFeature>("Client");
  TRI_ASSERT(nullptr != client);

  std::unique_ptr<SimpleHttpClient> httpClient;
  try {
    httpClient = client->createHttpClient();
    httpClient->params().setLocationRewriter(
        static_cast<void*>(client), arangodb::ClientManager::rewriteLocation);
    httpClient->params().setUserNamePassword("/", client->username(),
                                             client->password());
  } catch (...) {
    LOG_TOPIC(FATAL, arangodb::Logger::RESTORE)
        << "cannot create server connection, giving up!";
    return {TRI_SIMPLE_CLIENT_COULD_NOT_CONNECT};
  }

  VPackBuilder builder;
  {
    ObjectBuilder object(&builder);
    object->add("name", VPackValue(name));
    {
      ArrayBuilder users(&builder, "users");
      {
        ObjectBuilder user(&builder);
        user->add("username", VPackValue(client->username()));
        user->add("passwd", VPackValue(client->password()));
      }
    }
  }

  std::string const body = builder.slice().toJson();

  std::unique_ptr<SimpleHttpResult> response(httpClient->request(
      RequestType::POST, "/_api/database", body.c_str(), body.size()));

  if (response == nullptr || !response->isComplete()) {
    return {TRI_ERROR_INTERNAL};
  }

  auto returnCode = response->getHttpReturnCode();

  if (returnCode == static_cast<int>(ResponseCode::OK) ||
      returnCode == static_cast<int>(ResponseCode::CREATED)) {
    // all ok
    return {TRI_ERROR_NO_ERROR};
  }
  if (returnCode == static_cast<int>(ResponseCode::UNAUTHORIZED) ||
      returnCode == static_cast<int>(ResponseCode::FORBIDDEN)) {
    // invalid authorization
    auto res = ::checkHttpResponse(*httpClient, response);
    return {TRI_ERROR_FORBIDDEN, res.errorMessage()};
  }

  // any other error
  auto res = ::checkHttpResponse(*httpClient, response);
  return {TRI_ERROR_INTERNAL, res.errorMessage()};
}
}  // namespace

namespace {
void checkEncryption(arangodb::ManagedDirectory& directory) {
  using arangodb::Logger;
  if (directory.isEncrypted()) {
#ifdef USE_ENTERPRISE
    if (!directory.encryptionFeature()->keyOptionSpecified()) {
      LOG_TOPIC(WARN, Logger::RESTORE)
          << "the dump data seems to be encrypted with "
          << directory.encryptionType()
          << ", but no key information was specified to decrypt the dump";
      LOG_TOPIC(WARN, Logger::RESTORE)
          << "it is recommended to specify either "
             "`--encryption.key-file` or `--encryption.key-generator` "
             "when invoking arangorestore with an encrypted dump";
    } else {
      LOG_TOPIC(INFO, Logger::RESTORE)
          << "# using encryption type " << directory.encryptionType()
          << " for reading dump";
    }
#endif
  }
}
}  // namespace

namespace {
arangodb::Result readDumpInfo(arangodb::ManagedDirectory& directory,
                              bool forceSameDatabase) {
  using arangodb::ClientFeature;
  using arangodb::Logger;
  using arangodb::application_features::ApplicationServer;

  std::string databaseName;
  try {
    VPackBuilder fileContentBuilder = directory.vpackFromJsonFile("dump.json");
    VPackSlice const fileContent = fileContentBuilder.slice();
    databaseName = fileContent.get("database").copyString();
  } catch (...) {
    // the above may go wrong for several reasons
  }

  if (!databaseName.empty()) {
    LOG_TOPIC(INFO, Logger::RESTORE)
        << "Database name in source dump is '" << databaseName << "'";
  }

  ClientFeature* client =
      ApplicationServer::getFeature<ClientFeature>("Client");
  if (forceSameDatabase && databaseName != client->databaseName()) {
    return {TRI_ERROR_BAD_PARAMETER,
            std::string("database name in dump.json ('") + databaseName +
                "') does not match specified database name ('" +
                client->databaseName() + "')"};
  }

  return {};
}
}  // namespace

namespace {
arangodb::Result sendRestoreCollection(
    arangodb::httpclient::SimpleHttpClient& httpClient,
    arangodb::RestoreFeature::Options const& options, VPackSlice const& slice,
    std::string const& name) {
  using arangodb::Logger;
  using arangodb::httpclient::SimpleHttpResult;

  std::string url =
      "/_api/replication/restore-collection"
      "?overwrite=" +
      std::string(options.overwrite ? "true" : "false") +
      "&force=" + std::string(options.force ? "true" : "false") +
      "&ignoreDistributeShardsLikeErrors=" +
      std::string(options.ignoreDistributeShardsLikeErrors ? "true" : "false");

  if (options.clusterMode) {
    if (!slice.hasKey(std::vector<std::string>({"parameters", "shards"})) &&
        !slice.hasKey(
            std::vector<std::string>({"parameters", "numberOfShards"}))) {
      // no "shards" and no "numberOfShards" attribute present. now assume
      // default value from --default-number-of-shards
      LOG_TOPIC(WARN, Logger::RESTORE)
          << "# no sharding information specified for collection '" << name
          << "', using default number of shards "
          << options.defaultNumberOfShards;
      url += "&numberOfShards=" + std::to_string(options.defaultNumberOfShards);
    }
    if (!slice.hasKey(
            std::vector<std::string>({"parameters", "replicationFactor"}))) {
      // No replication factor given, so take the default:
      LOG_TOPIC(INFO, Logger::RESTORE)
          << "# no replication information specified for collection '" << name
          << "', using default replication factor "
          << options.defaultReplicationFactor;
      url += "&replicationFactor=" +
             std::to_string(options.defaultReplicationFactor);
    }
  }

  std::string const body = slice.toJson();

  std::unique_ptr<SimpleHttpResult> response(httpClient.request(
      arangodb::rest::RequestType::PUT, url, body.c_str(), body.size()));

  if (response == nullptr || !response->isComplete()) {
    return {TRI_ERROR_INTERNAL, "got invalid response from server: " +
                                    httpClient.getErrorMessage()};
  }

  if (response->wasHttpError()) {
    return ::checkHttpResponse(httpClient, response);
  }

  return {TRI_ERROR_NO_ERROR};
}
}  // namespace

namespace {
arangodb::Result sendRestoreIndexes(
    arangodb::httpclient::SimpleHttpClient& httpClient,
    arangodb::RestoreFeature::Options const& options, VPackSlice const& slice) {
  using arangodb::httpclient::SimpleHttpResult;

  std::string const url = "/_api/replication/restore-indexes?force=" +
                          std::string(options.force ? "true" : "false");
  std::string const body = slice.toJson();

  std::unique_ptr<SimpleHttpResult> response(httpClient.request(
      arangodb::rest::RequestType::PUT, url, body.c_str(), body.size()));

  if (response == nullptr || !response->isComplete()) {
    return {TRI_ERROR_INTERNAL, "got invalid response from server: " +
                                    httpClient.getErrorMessage()};
  }

  if (response->wasHttpError()) {
    return ::checkHttpResponse(httpClient, response);
  }

  return {TRI_ERROR_NO_ERROR};
}
}  // namespace

namespace {
arangodb::Result sendRestoreData(
    arangodb::httpclient::SimpleHttpClient& httpClient,
    arangodb::RestoreFeature::Options const& options, std::string const& cname,
    char const* buffer, size_t bufferSize) {
  using arangodb::basics::StringUtils::urlEncode;
  using arangodb::httpclient::SimpleHttpResult;

  std::string const url =
      "/_api/replication/restore-data?collection=" + urlEncode(cname) +
      "&force=" + (options.force ? "true" : "false");

  std::unique_ptr<SimpleHttpResult> response(httpClient.request(
      arangodb::rest::RequestType::PUT, url, buffer, bufferSize));

  if (response == nullptr || !response->isComplete()) {
    return {TRI_ERROR_INTERNAL, "got invalid response from server: " +
                                    httpClient.getErrorMessage()};
  }

  if (response->wasHttpError()) {
    return ::checkHttpResponse(httpClient, response);
  }

  return {TRI_ERROR_NO_ERROR};
}
}  // namespace

namespace {
/// @brief process a single job from the queue
arangodb::Result processJob(arangodb::httpclient::SimpleHttpClient& client,
                            arangodb::RestoreFeature::JobData& jobData) {
  arangodb::Result result{TRI_ERROR_NO_ERROR};

  return result;
}
}  // namespace

namespace {
/// @brief handle the result of a single job
void handleJobResult(
    std::unique_ptr<arangodb::RestoreFeature::JobData>&& jobData,
    arangodb::Result const& result) {
  if (result.fail()) {
    jobData->feature.reportError(result);
  }
}
}  // namespace

namespace {
arangodb::Result processInputDirectory(
    arangodb::httpclient::SimpleHttpClient& httpClient,
    arangodb::RestoreFeature::Options const& options,
    arangodb::ManagedDirectory& directory,
    arangodb::RestoreFeature::Stats& stats) {
  using arangodb::Logger;
  using arangodb::Result;
  using arangodb::basics::StringBuffer;
  using arangodb::basics::FileUtils::listFiles;

  // create a lookup table for collections
  std::map<std::string, bool> restrictList;
  for (size_t i = 0; i < options.collections.size(); ++i) {
    restrictList.insert(
        std::pair<std::string, bool>(options.collections[i], true));
  }
  try {
    std::vector<std::string> const files = listFiles(options.inputPath);
    std::string const suffix = std::string(".structure.json");
    std::vector<VPackBuilder> collections;

    // Step 1 determine all collections to process
    {
      // loop over all files in InputDirectory, and look for all structure.json
      // files
      for (std::string const& file : files) {
        size_t const nameLength = file.size();

        if (nameLength <= suffix.size() ||
            file.substr(file.size() - suffix.size()) != suffix) {
          // some other file
          continue;
        }

        // found a structure.json file
        std::string name = file.substr(0, file.size() - suffix.size());

        if (!options.includeSystemCollections && name[0] == '_') {
          continue;
        }

        VPackBuilder fileContentBuilder = directory.vpackFromJsonFile(file);
        VPackSlice const fileContent = fileContentBuilder.slice();
        if (!fileContent.isObject()) {
          return {TRI_ERROR_INTERNAL,
                  "could not read collection structure file '" +
                      directory.pathToFile(file) + "'"};
        }

        VPackSlice const parameters = fileContent.get("parameters");
        VPackSlice const indexes = fileContent.get("indexes");

        if (!parameters.isObject() || !indexes.isArray()) {
          return {TRI_ERROR_INTERNAL,
                  "could not read collection structure file '" +
                      directory.pathToFile(file) + "'"};
        }

        std::string const cname =
            arangodb::basics::VelocyPackHelper::getStringValue(parameters,
                                                               "name", "");

        bool overwriteName = false;

        if (cname != name &&
            name !=
                (cname + "_" + arangodb::rest::SslInterface::sslMD5(cname))) {
          // file has a different name than found in structure file
          if (options.importStructure) {
            // we cannot go on if there is a mismatch
            return {TRI_ERROR_INTERNAL,
                    "collection name mismatch in collection structure file '" +
                        directory.pathToFile(file) + "' (offending value: '" +
                        cname + "')"};
          } else {
            // we can patch the name in our array and go on
            LOG_TOPIC(INFO, Logger::RESTORE)
                << "ignoring collection name mismatch in collection "
                   "structure file '" +
                       directory.pathToFile(file) + "' (offending value: '" +
                       cname + "')";

            overwriteName = true;
          }
        }

        if (!restrictList.empty() &&
            restrictList.find(cname) == restrictList.end()) {
          // collection name not in list
          continue;
        }

        if (overwriteName) {
          // TODO: we have a JSON object with sub-object "parameters" with
          // attribute "name". we only want to replace this. how?
        } else {
          collections.emplace_back(std::move(fileContentBuilder));
        }
      }
    }
    std::sort(collections.begin(), collections.end(), ::sortCollections);

    StringBuffer buffer(true);
    // step2: run the actual import
    for (VPackBuilder const& b : collections) {
      VPackSlice const collection = b.slice();
      VPackSlice const parameters = collection.get("parameters");
      VPackSlice const indexes = collection.get("indexes");
      std::string const cname =
          arangodb::basics::VelocyPackHelper::getStringValue(parameters, "name",
                                                             "");
      int type = arangodb::basics::VelocyPackHelper::getNumericValue<int>(
          parameters, "type", 2);

      std::string const collectionType(type == 2 ? "document" : "edge");

      if (options.importStructure) {
        // re-create collection
        if (options.progress) {
          if (options.overwrite) {
            LOG_TOPIC(INFO, Logger::RESTORE)
                << "# Re-creating " << collectionType << " collection '"
                << cname << "'...";
          } else {
            LOG_TOPIC(INFO, Logger::RESTORE)
                << "# Creating " << collectionType << " collection '" << cname
                << "'...";
          }
        }

        Result res =
            ::sendRestoreCollection(httpClient, options, collection, cname);

        if (res.fail()) {
          if (options.force) {
            LOG_TOPIC(ERR, Logger::RESTORE) << res.errorMessage();
            continue;
          }
          return {TRI_ERROR_INTERNAL};
        }
      }
      stats.totalCollections++;

      if (options.importData) {
        // import data. check if we have a datafile
        auto datafile = directory.readableFile(
            cname + "_" + arangodb::rest::SslInterface::sslMD5(cname) +
            ".data.json");
        if (!datafile || datafile->status().fail()) {
          datafile = directory.readableFile(cname + ".data.json");
          if (!datafile || datafile->status().fail()) {
            return {TRI_ERROR_CANNOT_READ_FILE, "could not open file"};
          }
        }

        if (TRI_ExistsFile(datafile->path().c_str())) {
          // found a datafile

          if (options.progress) {
            LOG_TOPIC(INFO, Logger::RESTORE)
                << "# Loading data into " << collectionType << " collection '"
                << cname << "'...";
          }

          buffer.clear();

          while (true) {
            if (buffer.reserve(16384) != TRI_ERROR_NO_ERROR) {
              return {TRI_ERROR_OUT_OF_MEMORY, "out of memory"};
            }

            ssize_t numRead = datafile->read(buffer.end(), 16384);
            if (datafile->status().fail()) {  // error while reading
              return datafile->status();
            }

            // read something
            buffer.increaseLength(numRead);

            stats.totalRead += (uint64_t)numRead;

            if (buffer.length() < options.chunkSize && numRead > 0) {
              // still continue reading
              continue;
            }

            // do we have a buffer?
            if (buffer.length() > 0) {
              // look for the last \n in the buffer
              char* found = (char*)memrchr((const void*)buffer.begin(), '\n',
                                           buffer.length());
              size_t length;

              if (found == nullptr) {
                // no \n found...
                if (numRead == 0) {
                  // we're at the end. send the complete buffer anyway
                  length = buffer.length();
                } else {
                  // read more
                  continue;
                }
              } else {
                // found a \n somewhere
                length = found - buffer.begin();
              }

              stats.totalBatches++;

              Result res = ::sendRestoreData(httpClient, options, cname,
                                             buffer.begin(), length);

              if (res.fail()) {
                if (options.force) {
                  LOG_TOPIC(ERR, Logger::RESTORE) << res.errorMessage();
                  continue;
                }
                return res;
              }

              buffer.erase_front(length);
            }

            if (numRead == 0) {
              // EOF
              break;
            }
          }
        }
      }

      if (options.importStructure) {
        // re-create indexes
        if (indexes.length() > 0) {
          // we actually have indexes
          if (options.progress) {
            LOG_TOPIC(INFO, Logger::RESTORE)
                << "# Creating indexes for collection '" << cname << "'...";
          }

          Result res = ::sendRestoreIndexes(httpClient, options, collection);

          if (res.fail()) {
            if (options.force) {
              LOG_TOPIC(ERR, Logger::RESTORE) << res.errorMessage();
              continue;
            }
            return {TRI_ERROR_INTERNAL};
          }
        }
      }
    }
  } catch (std::exception const& ex) {
    return {TRI_ERROR_INTERNAL,
            std::string(
                "arangorestore terminated because of an unhandled exception: ")
                .append(ex.what())};
  } catch (...) {
    return {TRI_ERROR_OUT_OF_MEMORY, "arangorestore out of memory"};
  }
  return {TRI_ERROR_NO_ERROR};
}
}  // namespace

namespace arangodb {

RestoreFeature::JobData::JobData(ManagedDirectory& d, RestoreFeature& f,
                                 RestoreFeature::Options const& o,
                                 RestoreFeature::Stats& s)
    : directory{d}, feature{f}, options{o}, stats{s} {}

RestoreFeature::RestoreFeature(application_features::ApplicationServer* server,
                               int& exitCode)
    : ApplicationFeature(server, RestoreFeature::featureName()),
      _clientManager{Logger::RESTORE},
      _clientTaskQueue{::processJob, ::handleJobResult},
      _exitCode{exitCode} {
  requiresElevatedPrivileges(false);
  setOptional(false);
  startsAfter("Client");
  startsAfter("Logger");

#ifdef USE_ENTERPRISE
  startsAfter("Encryption");
#endif

  using arangodb::basics::FileUtils::buildFilename;
  using arangodb::basics::FileUtils::currentDirectory;
  _options.inputPath = buildFilename(currentDirectory().result(), "dump");
}

void RestoreFeature::collectOptions(
    std::shared_ptr<options::ProgramOptions> options) {
  using arangodb::options::BooleanParameter;
  using arangodb::options::StringParameter;
  using arangodb::options::UInt32Parameter;
  using arangodb::options::UInt64Parameter;
  using arangodb::options::VectorParameter;

  options->addOption(
      "--collection",
      "restrict to collection name (can be specified multiple times)",
      new VectorParameter<StringParameter>(&_options.collections));

  options->addObsoleteOption(
      "--recycle-ids", "collection ids are now handled automatically", false);

  options->addOption("--batch-size",
                     "maximum size for individual data batches (in bytes)",
                     new UInt64Parameter(&_options.chunkSize));

  options->addOption("--include-system-collections",
                     "include system collections",
                     new BooleanParameter(&_options.includeSystemCollections));

  options->addOption("--create-database",
                     "create the target database if it does not exist",
                     new BooleanParameter(&_options.createDatabase));

  options->addOption(
      "--force-same-database",
      "force usage of the same database name as in the source dump.json file",
      new BooleanParameter(&_options.forceSameDatabase));

  options->addOption("--input-directory", "input directory",
                     new StringParameter(&_options.inputPath));

  options->addOption("--import-data", "import data into collection",
                     new BooleanParameter(&_options.importData));

  options->addOption("--create-collection", "create collection structure",
                     new BooleanParameter(&_options.importStructure));

  options->addOption("--progress", "show progress",
                     new BooleanParameter(&_options.progress));

  options->addOption("--overwrite", "overwrite collections if they exist",
                     new BooleanParameter(&_options.overwrite));

  options->addOption("--default-number-of-shards",
                     "default value for numberOfShards if not specified",
                     new UInt64Parameter(&_options.defaultNumberOfShards));

  options->addOption("--default-replication-factor",
                     "default value for replicationFactor if not specified",
                     new UInt64Parameter(&_options.defaultReplicationFactor));

  options->addOption(
      "--ignore-distribute-shards-like-errors",
      "continue restore even if sharding prototype collection is missing",
      new BooleanParameter(&_options.ignoreDistributeShardsLikeErrors));

  options->addOption(
      "--force", "continue restore even in the face of some server-side errors",
      new BooleanParameter(&_options.force));
}

void RestoreFeature::validateOptions(
    std::shared_ptr<options::ProgramOptions> options) {
  using arangodb::basics::StringUtils::join;

  auto const& positionals = options->processingResult()._positionals;
  size_t n = positionals.size();

  if (1 == n) {
    _options.inputPath = positionals[0];
  } else if (1 < n) {
    LOG_TOPIC(FATAL, arangodb::Logger::FIXME)
        << "expecting at most one directory, got " + join(positionals, ", ");
    FATAL_ERROR_EXIT();
  }

  // use a minimum value for batches
  if (_options.chunkSize < 1024 * 128) {
    _options.chunkSize = 1024 * 128;
  }
}

void RestoreFeature::prepare() {
  if (!_options.inputPath.empty() &&
      _options.inputPath.back() == TRI_DIR_SEPARATOR_CHAR) {
    // trim trailing slash from path because it may cause problems on ...
    // Windows
    TRI_ASSERT(_options.inputPath.size() > 0);
    _options.inputPath.pop_back();
  }

  if (!_options.importStructure && !_options.importData) {
    LOG_TOPIC(FATAL, arangodb::Logger::FIXME)
        << "Error: must specify either --create-collection or --import-data";
    FATAL_ERROR_EXIT();
  }
}

void RestoreFeature::start() {
  using arangodb::httpclient::SimpleHttpClient;

  // set up the output directory, not much else
  _directory =
      std::make_unique<ManagedDirectory>(_options.inputPath, false, false);
  if (_directory->status().fail()) {
    switch (_directory->status().errorNumber()) {
      case TRI_ERROR_FILE_NOT_FOUND:
        LOG_TOPIC(FATAL, arangodb::Logger::FIXME)
            << "input directory '" << _options.inputPath << "' does not exist";
        break;
      default:
        LOG_TOPIC(ERR, arangodb::Logger::FIXME)
            << _directory->status().errorMessage();
        break;
    }
    FATAL_ERROR_EXIT();
  }

  ClientFeature* client =
      application_features::ApplicationServer::getFeature<ClientFeature>(
          "Client");

  _exitCode = EXIT_SUCCESS;

  std::unique_ptr<SimpleHttpClient> httpClient;
  Result result =
      _clientManager.getConnectedClient(httpClient, _options.force, true);
  if (result.is(TRI_SIMPLE_CLIENT_COULD_NOT_CONNECT)) {
    LOG_TOPIC(FATAL, Logger::RESTORE)
        << "cannot create server connection, giving up!";
    FATAL_ERROR_EXIT();
  } else if (result.is(TRI_ERROR_ARANGO_DATABASE_NOT_FOUND) &&
             _options.createDatabase) {
    // database not found, but database creation requested
    std::string dbName = client->databaseName();
    LOG_TOPIC(INFO, Logger::RESTORE) << "Creating database '" << dbName << "'";

    client->setDatabaseName("_system");

    Result res = ::tryCreateDatabase(dbName);
    if (res.fail()) {
      LOG_TOPIC(ERR, Logger::RESTORE)
          << "Could not create database '" << dbName << "'";
      LOG_TOPIC(FATAL, Logger::RESTORE) << httpClient->getErrorMessage();
      FATAL_ERROR_EXIT();
    }

    // restore old database name
    client->setDatabaseName(dbName);

    // re-check connection and version
    result =
        _clientManager.getConnectedClient(httpClient, _options.force, true);
    if (result.fail() &&
        !(_options.force && result.is(TRI_ERROR_INCOMPATIBLE_VERSION))) {
      LOG_TOPIC(FATAL, arangodb::Logger::FIXME)
          << "cannot create server connection, giving up!";
      FATAL_ERROR_EXIT();
    }
  }

  // read encryption info
  ::checkEncryption(*_directory);

  // read dump info
  result = ::readDumpInfo(*_directory, _options.forceSameDatabase);
  if (result.fail()) {
    LOG_TOPIC(FATAL, arangodb::Logger::FIXME) << result.errorMessage();
    FATAL_ERROR_EXIT();
  }

  // Version 1.4 did not yet have a cluster mode
  std::tie(result, _options.clusterMode) =
      _clientManager.getArangoIsCluster(*httpClient);
  if (result.fail()) {
    LOG_TOPIC(ERR, arangodb::Logger::FIXME) << result.errorMessage();
    _exitCode = EXIT_FAILURE;
    return;
  }

  if (_options.progress) {
    LOG_TOPIC(INFO, Logger::RESTORE)
        << "# Connected to ArangoDB '" << httpClient->getEndpointSpecification()
        << "'";
  }

  try {
    result =
        ::processInputDirectory(*httpClient, _options, *_directory, _stats);
  } catch (std::exception const& ex) {
    LOG_TOPIC(ERR, arangodb::Logger::FIXME) << "caught exception " << ex.what();
    result = {TRI_ERROR_INTERNAL};
  } catch (...) {
    LOG_TOPIC(ERR, arangodb::Logger::FIXME)
        << "Error: caught unknown exception";
    result = {TRI_ERROR_INTERNAL};
  }

  if (result.fail()) {
    LOG_TOPIC(ERR, arangodb::Logger::FIXME) << result.errorMessage();
    _exitCode = EXIT_FAILURE;
  }

  if (_options.progress) {
    if (_options.importData) {
      LOG_TOPIC(INFO, Logger::RESTORE)
          << "Processed " << _stats.totalCollections << " collection(s), "
          << "read " << _stats.totalRead << " byte(s) from datafiles, "
          << "sent " << _stats.totalBatches << " batch(es)";
    } else if (_options.importStructure) {
      LOG_TOPIC(INFO, Logger::RESTORE)
          << "Processed " << _stats.totalCollections << " collection(s)";
    }
  }
}

void RestoreFeature::reportError(Result const& error) {
  try {
    MUTEX_LOCKER(lock, _workerErrorLock);
    _workerErrors.emplace(error);
    _clientTaskQueue.clearQueue();
  } catch (...) {
  }
}

std::string RestoreFeature::featureName() { return ::FeatureName; }

}  // namespace arangodb
