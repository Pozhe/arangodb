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
/// @author Dan Larkin-York
////////////////////////////////////////////////////////////////////////////////

#ifndef ARANGODB_RESTORE_RESTORE_FEATURE_H
#define ARANGODB_RESTORE_RESTORE_FEATURE_H 1

#include "ApplicationFeatures/ApplicationFeature.h"

#include "Basics/VelocyPackHelper.h"
#include "Utils/ClientManager.h"
#include "Utils/ClientTaskQueue.h"
#include "Utils/ManagedDirectory.h"

namespace arangodb {
namespace httpclient {
class SimpleHttpResult;
}
class EncryptionFeature;
class ManagedDirectory;

class RestoreFeature final : public application_features::ApplicationFeature {
 public:
  RestoreFeature(application_features::ApplicationServer* server,
                 int& exitCode);

 public:
  void collectOptions(std::shared_ptr<options::ProgramOptions>) override;
  void validateOptions(
      std::shared_ptr<options::ProgramOptions> options) override;
  void prepare() override;
  void start() override;

 public:
  /**
   * @brief Returns the feature name (for registration with `ApplicationServer`)
   * @return The name of the feature
   */
  static std::string featureName();

  /**
   * @brief Saves a worker error for later handling and clears queued jobs
   * @param error Error from a client worker
   */
  void reportError(Result const& error);

 public:
  struct Options {
    std::vector<std::string> collections{};
    std::string inputPath{};
    uint64_t chunkSize{1024 * 1024 * 8};
    uint64_t defaultNumberOfShards{1};
    uint64_t defaultReplicationFactor{1};
    bool clusterMode{false};
    bool createDatabase{false};
    bool force{false};
    bool forceSameDatabase{false};
    bool ignoreDistributeShardsLikeErrors{false};
    bool importData{true};
    bool importStructure{true};
    bool includeSystemCollections{false};
    bool overwrite{true};
    bool progress{true};
  };

  struct Stats {
    uint64_t totalBatches{0};
    uint64_t totalCollections{0};
    uint64_t totalRead{0};
  };

  struct JobData {
    ManagedDirectory& directory;
    RestoreFeature& feature;
    Options const& options;
    Stats& stats;

    JobData(ManagedDirectory&, RestoreFeature&, Options const&, Stats&);
  };

 private:
  ClientManager _clientManager;
  ClientTaskQueue<JobData> _clientTaskQueue;
  std::unique_ptr<ManagedDirectory> _directory;
  int& _exitCode;
  Options _options;
  Stats _stats;
  Mutex _workerErrorLock;
  std::queue<Result> _workerErrors;
};
}  // namespace arangodb

#endif
