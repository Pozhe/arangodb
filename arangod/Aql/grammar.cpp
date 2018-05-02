/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         Aqlparse
#define yylex           Aqllex
#define yyerror         Aqlerror
#define yydebug         Aqldebug
#define yynerrs         Aqlnerrs


/* Copy the first part of user declarations.  */
#line 9 "Aql/grammar.y" /* yacc.c:339  */

#include "Aql/Aggregator.h"
#include "Aql/AstNode.h"
#include "Aql/Function.h"
#include "Aql/Parser.h"
#include "Aql/Quantifier.h"
#include "Basics/tri-strings.h"
#include "VocBase/AccessMode.h"

#line 82 "Aql/grammar.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "grammar.hpp".  */
#ifndef YY_AQL_AQL_GRAMMAR_HPP_INCLUDED
# define YY_AQL_AQL_GRAMMAR_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int Aqldebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    T_END = 0,
    T_FOR = 258,
    T_LET = 259,
    T_FILTER = 260,
    T_RETURN = 261,
    T_COLLECT = 262,
    T_SORT = 263,
    T_LIMIT = 264,
    T_ASC = 265,
    T_DESC = 266,
    T_IN = 267,
    T_WITH = 268,
    T_INTO = 269,
    T_AGGREGATE = 270,
    T_VIEW = 271,
    T_GRAPH = 272,
    T_SHORTEST_PATH = 273,
    T_DISTINCT = 274,
    T_REMOVE = 275,
    T_INSERT = 276,
    T_UPDATE = 277,
    T_REPLACE = 278,
    T_UPSERT = 279,
    T_NULL = 280,
    T_TRUE = 281,
    T_FALSE = 282,
    T_STRING = 283,
    T_QUOTED_STRING = 284,
    T_INTEGER = 285,
    T_DOUBLE = 286,
    T_PARAMETER = 287,
    T_DATA_SOURCE_PARAMETER = 288,
    T_ASSIGN = 289,
    T_NOT = 290,
    T_AND = 291,
    T_OR = 292,
    T_NIN = 293,
    T_REGEX_MATCH = 294,
    T_REGEX_NON_MATCH = 295,
    T_EQ = 296,
    T_NE = 297,
    T_LT = 298,
    T_GT = 299,
    T_LE = 300,
    T_GE = 301,
    T_LIKE = 302,
    T_PLUS = 303,
    T_MINUS = 304,
    T_TIMES = 305,
    T_DIV = 306,
    T_MOD = 307,
    T_QUESTION = 308,
    T_COLON = 309,
    T_SCOPE = 310,
    T_RANGE = 311,
    T_COMMA = 312,
    T_OPEN = 313,
    T_CLOSE = 314,
    T_OBJECT_OPEN = 315,
    T_OBJECT_CLOSE = 316,
    T_ARRAY_OPEN = 317,
    T_ARRAY_CLOSE = 318,
    T_OUTBOUND = 319,
    T_INBOUND = 320,
    T_ANY = 321,
    T_ALL = 322,
    T_NONE = 323,
    UMINUS = 324,
    UPLUS = 325,
    FUNCCALL = 326,
    REFERENCE = 327,
    INDEXED = 328,
    EXPANSION = 329
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 19 "Aql/grammar.y" /* yacc.c:355  */

  arangodb::aql::AstNode*  node;
  struct {
    char*                  value;
    size_t                 length;
  }                        strval;
  bool                     boolval;
  int64_t                  intval;

#line 208 "Aql/grammar.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif



int Aqlparse (arangodb::aql::Parser* parser);

#endif /* !YY_AQL_AQL_GRAMMAR_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */
#line 29 "Aql/grammar.y" /* yacc.c:358  */


using namespace arangodb::aql;

/// @brief shortcut macro for signaling out of memory
#define ABORT_OOM                                   \
  parser->registerError(TRI_ERROR_OUT_OF_MEMORY);   \
  YYABORT;

#define scanner parser->scanner()

/// @brief forward for lexer function defined in Aql/tokens.ll
int Aqllex(YYSTYPE*, YYLTYPE*, void*);
 
/// @brief register parse error (this will also abort the currently running query)
void Aqlerror(YYLTYPE* locp, 
              arangodb::aql::Parser* parser,
              char const* message) {
  parser->registerParseError(TRI_ERROR_QUERY_PARSE, message, locp->first_line, locp->first_column);
}

/// @brief check if any of the variables used in the INTO expression were
/// introduced by the COLLECT itself, in which case it would fail
static Variable const* CheckIntoVariables(AstNode const* collectVars,
                                          std::unordered_set<Variable const*> const& vars) {
  if (collectVars == nullptr || collectVars->type != NODE_TYPE_ARRAY) {
    return nullptr;
  }

  size_t const n = collectVars->numMembers();
  for (size_t i = 0; i < n; ++i) {
    auto member = collectVars->getMember(i);

    if (member != nullptr) {
      TRI_ASSERT(member->type == NODE_TYPE_ASSIGN);
      auto v = static_cast<Variable*>(member->getMember(0)->getData());
      if (vars.find(v) != vars.end()) {
        return v;
      }
    }
  }

  return nullptr;
}

/// @brief register variables in the scope
static void RegisterAssignVariables(arangodb::aql::Scopes* scopes, AstNode const* vars) { 
  size_t const n = vars->numMembers();
  for (size_t i = 0; i < n; ++i) {
    auto member = vars->getMember(i);

    if (member != nullptr) {
      TRI_ASSERT(member->type == NODE_TYPE_ASSIGN);
      auto v = static_cast<Variable*>(member->getMember(0)->getData());
      scopes->addVariable(v);
    }
  }
}

/// @brief validate the aggregate variables expressions
static bool ValidateAggregates(Parser* parser, AstNode const* aggregates) {
  size_t const n = aggregates->numMembers();

  for (size_t i = 0; i < n; ++i) {
    auto member = aggregates->getMember(i);

    if (member != nullptr) {
      TRI_ASSERT(member->type == NODE_TYPE_ASSIGN);
      auto func = member->getMember(1);

      bool isValid = true;
      if (func->type != NODE_TYPE_FCALL) {
        // aggregate expression must be a function call
        isValid = false;
      }
      else {
        auto f = static_cast<arangodb::aql::Function*>(func->getData());
        if (!Aggregator::isSupported(f->name)) {
          // aggregate expression must be a call to MIN|MAX|LENGTH...
          isValid = false;
        }
      }

      if (! isValid) {
        parser->registerError(TRI_ERROR_QUERY_INVALID_AGGREGATE_EXPRESSION);
        return false;
      }
    }
  }

  return true;
}

/// @brief start a new scope for the collect
static bool StartCollectScope(arangodb::aql::Scopes* scopes) { 
  // check if we are in the main scope
  if (scopes->type() == arangodb::aql::AQL_SCOPE_MAIN) {
    return false;
  }

  // end the active scopes
  scopes->endNested();
  // start a new scope
  scopes->start(arangodb::aql::AQL_SCOPE_COLLECT);
  return true;
}

/// @brief get the INTO variable stored in a node (may not exist)
static AstNode const* GetIntoVariable(Parser* parser, AstNode const* node) {
  if (node == nullptr) {
    return nullptr;
  }

  if (node->type == NODE_TYPE_VALUE) {
    // node is a string containing the variable name
    return parser->ast()->createNodeVariable(node->getStringValue(), node->getStringLength(), true);
  }

  // node is an array with the variable name as the first member
  TRI_ASSERT(node->type == NODE_TYPE_ARRAY);
  TRI_ASSERT(node->numMembers() == 2);

  auto v = node->getMember(0);
  TRI_ASSERT(v->type == NODE_TYPE_VALUE);
  return parser->ast()->createNodeVariable(v->getStringValue(), v->getStringLength(), true);
}

/// @brief get the INTO variable = expression stored in a node (may not exist)
static AstNode const* GetIntoExpression(AstNode const* node) {
  if (node == nullptr || node->type == NODE_TYPE_VALUE) {
    return nullptr;
  }

  // node is an array with the expression as the second member
  TRI_ASSERT(node->type == NODE_TYPE_ARRAY);
  TRI_ASSERT(node->numMembers() == 2);

  return node->getMember(1);
}


#line 379 "Aql/grammar.cpp" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1525

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  76
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  94
/* YYNRULES -- Number of rules.  */
#define YYNRULES  225
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  385

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   329

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,    75,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   344,   344,   347,   360,   364,   368,   375,   377,   377,
     388,   393,   398,   400,   403,   406,   409,   412,   418,   420,
     425,   427,   429,   431,   433,   435,   437,   439,   441,   443,
     445,   450,   456,   462,   464,   469,   474,   479,   487,   495,
     506,   514,   519,   521,   526,   533,   543,   543,   557,   566,
     577,   607,   674,   699,   732,   734,   739,   746,   749,   752,
     761,   775,   792,   792,   806,   806,   816,   816,   827,   830,
     836,   842,   845,   848,   851,   857,   862,   869,   877,   880,
     886,   896,   906,   914,   925,   930,   938,   949,   954,   957,
     963,   967,   963,  1019,  1022,  1025,  1031,  1031,  1041,  1047,
    1050,  1053,  1056,  1059,  1062,  1068,  1071,  1087,  1087,  1096,
    1096,  1106,  1109,  1112,  1118,  1121,  1124,  1127,  1130,  1133,
    1136,  1139,  1142,  1145,  1148,  1151,  1154,  1157,  1160,  1163,
    1169,  1175,  1182,  1185,  1188,  1191,  1194,  1197,  1200,  1203,
    1209,  1212,  1218,  1220,  1225,  1228,  1228,  1244,  1247,  1253,
    1256,  1262,  1262,  1271,  1273,  1278,  1281,  1287,  1290,  1304,
    1304,  1313,  1315,  1320,  1322,  1327,  1341,  1345,  1354,  1361,
    1364,  1370,  1373,  1379,  1382,  1385,  1391,  1394,  1400,  1403,
    1406,  1410,  1416,  1420,  1427,  1432,  1432,  1440,  1444,  1453,
    1456,  1459,  1465,  1468,  1474,  1506,  1509,  1512,  1519,  1529,
    1529,  1542,  1557,  1571,  1585,  1585,  1628,  1631,  1637,  1644,
    1654,  1657,  1660,  1663,  1666,  1672,  1675,  1678,  1684,  1687,
    1690,  1700,  1707,  1713,  1716,  1721
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of query string\"", "error", "$undefined", "\"FOR declaration\"",
  "\"LET declaration\"", "\"FILTER declaration\"",
  "\"RETURN declaration\"", "\"COLLECT declaration\"",
  "\"SORT declaration\"", "\"LIMIT declaration\"", "\"ASC keyword\"",
  "\"DESC keyword\"", "\"IN keyword\"", "\"WITH keyword\"",
  "\"INTO keyword\"", "\"AGGREGATE keyword\"", "\"VIEW keyword\"",
  "\"GRAPH keyword\"", "\"SHORTEST_PATH keyword\"",
  "\"DISTINCT modifier\"", "\"REMOVE command\"", "\"INSERT command\"",
  "\"UPDATE command\"", "\"REPLACE command\"", "\"UPSERT command\"",
  "\"null\"", "\"true\"", "\"false\"", "\"identifier\"",
  "\"quoted string\"", "\"integer number\"", "\"number\"",
  "\"bind parameter\"", "\"bind data source parameter\"", "\"assignment\"",
  "\"not operator\"", "\"and operator\"", "\"or operator\"",
  "\"not in operator\"", "\"~= operator\"", "\"~! operator\"",
  "\"== operator\"", "\"!= operator\"", "\"< operator\"", "\"> operator\"",
  "\"<= operator\"", "\">= operator\"", "\"like operator\"",
  "\"+ operator\"", "\"- operator\"", "\"* operator\"", "\"/ operator\"",
  "\"% operator\"", "\"?\"", "\":\"", "\"::\"", "\"..\"", "\",\"", "\"(\"",
  "\")\"", "\"{\"", "\"}\"", "\"[\"", "\"]\"", "\"outbound modifier\"",
  "\"inbound modifier\"", "\"any modifier\"", "\"all modifier\"",
  "\"none modifier\"", "UMINUS", "UPLUS", "FUNCCALL", "REFERENCE",
  "INDEXED", "EXPANSION", "'.'", "$accept", "with_collection",
  "with_collection_list", "optional_with", "$@1", "queryStart", "query",
  "final_statement", "optional_statement_block_statements",
  "statement_block_statement", "for_statement", "traversal_statement",
  "shortest_path_statement", "filter_statement", "let_statement",
  "let_list", "let_element", "count_into", "collect_variable_list", "$@2",
  "collect_statement", "collect_list", "collect_element",
  "collect_optional_into", "variable_list", "keep", "$@3", "aggregate",
  "$@4", "sort_statement", "$@5", "sort_list", "sort_element",
  "sort_direction", "limit_statement", "return_statement",
  "in_or_into_collection", "remove_statement", "insert_statement",
  "update_parameters", "update_statement", "replace_parameters",
  "replace_statement", "update_or_replace", "upsert_statement", "$@6",
  "$@7", "quantifier", "distinct_expression", "$@8", "expression",
  "function_name", "function_call", "$@9", "$@10", "operator_unary",
  "operator_binary", "operator_ternary",
  "optional_function_call_arguments", "expression_or_query", "$@11",
  "function_arguments_list", "compound_value", "array", "$@12",
  "optional_array_elements", "array_elements_list", "options", "object",
  "$@13", "optional_object_elements", "object_elements_list",
  "object_element", "array_filter_operator", "optional_array_filter",
  "optional_array_limit", "optional_array_return", "graph_collection",
  "graph_collection_list", "graph_subject", "$@14", "graph_direction",
  "graph_direction_steps", "reference", "$@15", "$@16", "simple_value",
  "numeric_value", "value_literal", "collection_name", "view_name",
  "bind_parameter", "object_element_name", "variable_name", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,    46
};
# endif

#define YYPACT_NINF -269

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-269)))

#define YYTABLE_NINF -224

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      17,  -269,  -269,    24,   102,  -269,   324,  -269,  -269,  -269,
    -269,  -269,    74,  -269,    20,    20,  1425,  1231,   151,  -269,
     204,  1425,  1425,  1425,  1425,  -269,  -269,  -269,  -269,  -269,
    -269,    -1,  -269,  -269,  -269,  -269,     6,    10,    11,    18,
      26,   102,  -269,  -269,  -269,  -269,    -8,     7,  -269,    22,
    -269,  -269,  -269,    46,  -269,  -269,  -269,  1425,    14,  1425,
    1425,  1425,  -269,  -269,  1062,    54,  -269,  -269,  -269,  -269,
    -269,  -269,  -269,   -39,  -269,  -269,  -269,  -269,  -269,  1062,
      48,  -269,    60,    20,    78,  1425,    43,  -269,  -269,   725,
     725,  -269,   548,  -269,   593,  1425,    20,    60,    82,    78,
    -269,  1189,    20,    20,  1425,  -269,  -269,  -269,  -269,   767,
    -269,    -7,  1425,  1425,  1425,  1425,  1425,  1425,  1425,  1425,
    1425,  1425,  1425,  1425,  1425,  1425,  1425,  1425,  1425,  1425,
    1425,  1311,  1425,  -269,  -269,  -269,   241,    83,  -269,  1349,
     111,  1425,   105,    20,    72,  -269,    96,  -269,   120,    60,
     100,  -269,   461,   204,  1463,   127,    60,    60,  1425,    60,
    1425,    60,  1062,   156,  -269,    72,    60,  -269,    60,   134,
    -269,  -269,  -269,   635,   150,  1425,    -3,  -269,  1062,  1387,
    -269,   133,   140,  -269,   143,  1425,   138,   144,  -269,   148,
    1062,   149,   159,   319,  1145,  1104,   319,    77,    77,    77,
      77,   304,   304,   304,   304,    77,   175,   175,  -269,  -269,
    -269,  1425,   809,   328,  1425,  1425,  1425,  1425,  1425,  1425,
    1425,  1425,  -269,  1387,  -269,   852,   169,  -269,  -269,  1062,
      20,    96,  -269,    20,  1425,  -269,  1425,  -269,  -269,  -269,
    -269,  -269,   426,    38,  -269,   200,  -269,  -269,  -269,  -269,
    -269,  -269,   725,  -269,   725,  -269,   217,  1425,    20,  -269,
    -269,  -269,  -269,  -269,  -269,   254,  -269,  1425,   503,  1269,
      20,  1062,   184,  -269,  -269,   187,  -269,  1425,   894,  -269,
      -7,  1425,  -269,  1425,  1062,  1425,   319,   319,    77,    77,
     304,   304,   304,   304,   186,  -269,  -269,   242,  -269,  -269,
    1062,  -269,    60,    60,  1425,  1062,   191,  -269,   936,   181,
    -269,   193,    60,   113,  -269,   635,   233,  1425,   240,  -269,
    -269,  1425,  1062,   201,  -269,  1062,  1062,  1062,  -269,  1425,
     245,  -269,  -269,   682,    20,  1425,  -269,  -269,  -269,  -269,
    -269,  -269,  1425,   503,  1269,  -269,  1425,  1062,  1425,   250,
    -269,  -269,  1425,  -269,   503,   -13,   978,    60,  -269,  1425,
    1062,  1020,  1425,   197,   725,    60,  -269,   205,  1425,  -269,
     503,  1425,  1062,  -269,    60,  -269,   -13,   503,    60,  1062,
    -269,  -269,    60,  -269,  -269
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       7,     8,    18,     0,     0,    10,     0,     1,     2,   222,
     221,     4,     9,     3,     0,     0,     0,     0,    46,    66,
       0,     0,     0,     0,     0,    90,    11,    19,    20,    22,
      21,    57,    23,    24,    25,    12,    26,    27,    28,    29,
      30,     0,     6,   225,    33,    34,     0,    41,    42,     0,
     212,   213,   214,   194,   210,   208,   209,     0,     0,     0,
       0,   199,   159,   151,    40,     0,   197,    99,   100,   101,
     195,   149,   150,   103,   211,   102,   196,    96,    77,    98,
       0,    64,   157,     0,    57,     0,    75,   206,   207,     0,
       0,    84,     0,    87,     0,     0,     0,   157,   157,    57,
       5,     0,     0,     0,     0,   113,   109,   111,   112,     0,
      18,   161,   153,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    94,    93,    95,     0,     0,   107,     0,
       0,     0,     0,     0,     0,    48,    47,    54,     0,   157,
      67,    68,    71,     0,     0,     0,   157,   157,     0,   157,
       0,   157,    91,    58,    49,    62,   157,    52,   157,     0,
     189,   190,   191,    32,   192,     0,     0,    43,    44,   145,
     198,     0,   165,   224,     0,     0,     0,   162,   163,     0,
     155,     0,   154,   127,   115,   114,   128,   130,   131,   121,
     122,   123,   124,   125,   126,   129,   116,   117,   118,   119,
     120,     0,     0,   104,     0,     0,     0,     0,     0,     0,
       0,     0,   106,   145,   169,     0,   204,   201,   202,    97,
       0,    65,   158,     0,     0,    50,     0,    72,    73,    70,
      74,    76,   194,   210,    78,   196,   215,   216,    79,   217,
      80,    81,     0,    82,     0,    85,     0,     0,     0,    53,
      51,   218,   219,   220,    31,   191,   193,     0,     0,     0,
       0,   144,     0,   147,    18,   143,   200,     0,     0,   160,
       0,     0,   152,     0,   141,     0,   138,   139,   132,   133,
     134,   135,   136,   137,     0,   203,   170,   171,    45,    55,
      56,    69,   157,   157,     0,    59,    63,    60,     0,     0,
     178,   184,   157,     0,   179,     0,   192,     0,     0,   110,
     146,   145,   167,     0,   164,   166,   156,   140,   108,     0,
     173,    83,    86,     0,     0,     0,   188,   187,   185,    35,
     180,   181,     0,     0,     0,   148,     0,   172,     0,   176,
      88,    89,     0,    61,     0,     0,     0,   157,   192,     0,
     168,   174,     0,     0,     0,   157,   182,   186,     0,    36,
       0,     0,   177,   205,   157,    38,     0,     0,   157,   175,
      92,   183,   157,    37,    39
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -269,    16,  -269,  -269,  -269,  -269,  -109,  -269,  -269,  -269,
    -269,  -269,  -269,  -269,  -269,  -269,   158,   232,  -269,  -269,
    -269,   122,    34,   -67,  -269,  -269,  -269,   238,  -269,  -269,
    -269,  -269,    44,  -269,  -269,  -269,   -61,  -269,  -269,  -269,
    -269,  -269,  -269,  -269,  -269,  -269,  -269,  -269,  -269,  -269,
      57,  -269,  -269,  -269,  -269,  -269,  -269,  -269,    58,   -33,
    -269,  -269,  -269,  -269,  -269,  -269,  -269,   -63,   -94,  -269,
    -269,  -269,     9,  -269,  -269,  -269,  -269,  -268,  -269,  -230,
    -269,   -74,  -262,  -269,  -269,  -269,  -113,  -269,   -15,   135,
    -269,    -4,  -269,   -12
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    11,    12,     2,     4,     3,     5,    26,     6,    27,
      28,    44,    45,    29,    30,    47,    48,    82,    31,    83,
      32,   146,   147,    98,   306,   166,   258,    84,   143,    33,
      85,   150,   151,   239,    34,    35,   156,    36,    37,    91,
      38,    93,    39,   352,    40,    95,   256,   136,    78,   141,
     271,    65,    66,   223,   179,    67,    68,    69,   272,   273,
     274,   275,    70,    71,   112,   191,   192,   145,    72,   111,
     186,   187,   188,   226,   330,   349,   363,   311,   367,   312,
     355,   313,   175,    73,   110,   297,    86,    74,    75,   244,
     264,    76,   189,   148
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      13,   181,    46,    49,   101,    87,   -13,   317,    13,   269,
     -14,   -15,    80,    96,    81,   310,    88,   149,   -16,     9,
      10,   182,   183,   139,     7,   184,   -17,   174,    42,   157,
       1,   159,   168,   161,   164,   167,   140,    13,  -216,   240,
     241,  -216,  -216,  -216,  -216,  -216,  -216,  -216,    43,   102,
     232,   170,   171,   172,   270,   185,   104,   100,  -216,  -216,
    -216,  -216,  -216,   -13,   103,   -13,  -216,   -14,   -15,   -14,
     -15,   232,   106,    64,    79,   -16,   142,   -16,    89,    90,
      92,    94,   359,   -17,   163,   -17,   235,   366,   144,   113,
     176,    49,    96,   250,   251,  -216,   253,  -216,   255,   266,
     153,  -105,     8,   259,  -105,   260,     9,    10,   381,   137,
     165,   222,   138,   357,   105,   116,   107,   108,   109,   230,
     121,   122,   123,   124,   365,   126,   127,   128,   129,   130,
       8,    41,    62,   132,     9,    10,   228,    87,    87,   227,
     378,   340,   152,     9,    10,     9,    10,   382,    88,    88,
     245,   249,   162,   233,   234,   246,   247,   236,   173,     9,
      10,   178,   261,   262,    80,   320,    81,   263,   267,   190,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   212,   213,
     257,   302,   276,   303,  -223,   316,   225,   277,   229,   279,
    -217,   280,   281,  -217,  -217,  -217,  -217,  -217,  -217,  -217,
     336,   193,   282,     9,    10,   252,   283,   254,   298,   296,
    -217,  -217,  -217,  -217,  -217,   128,   129,   130,  -217,    50,
      51,    52,   268,    54,    55,    56,     9,    10,   304,   331,
     332,   266,   278,   319,   321,   328,   307,   329,   334,   339,
     338,   342,   344,   214,   348,   346,   362,  -217,   318,  -217,
     373,   177,   376,    97,   314,   231,   -94,   299,   284,    99,
     358,   286,   287,   288,   289,   290,   291,   292,   293,   215,
     301,   294,   216,   217,   218,   219,   220,   221,   345,   324,
     248,   300,   -94,   152,   369,   -94,   -94,   -94,   -94,   -94,
     -94,     0,   375,   374,     0,   337,     0,     0,     0,   341,
       0,   380,     0,     0,   305,   383,     0,     0,     0,   384,
       0,     0,   353,     0,   308,     0,   315,    14,    15,    16,
      17,    18,    19,    20,   322,     0,     0,     0,   325,   314,
     326,     0,   327,     0,    21,    22,    23,    24,    25,     0,
     314,   314,   126,   127,   128,   129,   130,     0,     0,     0,
     132,   333,   121,   122,   123,   124,   314,   126,   127,   128,
     129,   130,   314,   314,   343,   132,   126,   127,   128,   129,
     130,     0,     0,     0,     0,     0,   347,     0,     0,     0,
       0,     0,   354,     0,     0,     0,     0,     0,     0,   356,
       0,   315,     0,   360,     0,   361,     0,     0,     0,   364,
       0,     0,     0,     0,     0,     0,   370,     0,     0,   372,
       0,     0,     0,     0,     0,   377,  -215,     0,   379,  -215,
    -215,  -215,  -215,  -215,  -215,  -215,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -215,  -215,  -215,  -215,
    -215,     0,     0,     0,  -215,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   237,   238,   113,     0,     0,     0,     0,     0,     0,
       0,  -105,     0,  -215,  -105,  -215,    50,    51,    52,     0,
      54,    55,    56,     9,    10,     0,     0,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   113,     0,   132,     0,     0,
     309,     0,     0,     0,     0,     0,     0,   133,   134,   135,
       0,   310,     0,     0,     0,     9,    10,     0,     0,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,     0,     0,   132,
     154,   158,   155,     0,     0,     0,     0,   170,   171,   265,
     134,   135,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,     0,     0,   132,   154,   160,   155,     0,     0,
       0,     0,     0,     0,   133,   134,   135,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   113,     0,   132,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   133,
     134,   135,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,     0,
       0,   132,     0,     0,   113,     0,     0,     0,     0,   170,
     171,   265,   134,   135,   350,   351,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,     0,   154,   132,   155,
       0,     0,     0,     0,     0,     0,     0,     0,   133,   134,
     135,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   113,
       0,   132,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   133,   134,   135,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   113,     0,   132,     0,     0,   180,     0,     0,     0,
       0,     0,     0,   133,   134,   135,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   285,   113,   132,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   133,   134,   135,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   113,     0,   132,     0,
       0,     0,     0,     0,     0,   295,     0,     0,   133,   134,
     135,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   113,     0,
     132,     0,     0,     0,     0,     0,     0,   323,     0,     0,
     133,   134,   135,     0,   335,     0,     0,     0,     0,     0,
       0,     0,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     113,     0,   132,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   133,   134,   135,     0,   368,     0,     0,     0,
       0,     0,     0,     0,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   113,     0,   132,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   133,   134,   135,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   113,     0,   132,   371,     0,     0,
       0,     0,     0,     0,     0,     0,   133,   134,   135,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   113,     0,   132,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   133,   134,
     135,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     114,     0,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   113,     0,     0,
     132,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     133,   134,   135,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,     0,     0,
       0,   132,     0,     0,     0,   169,     0,     0,     0,     0,
       0,   133,   134,   135,    50,    51,    52,    53,    54,    55,
      56,     9,    10,     0,    57,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    58,    59,    60,     0,
       0,     0,     0,     0,     0,     0,     0,    61,     0,    62,
      77,    63,     0,   170,   171,   172,    50,    51,    52,    53,
      54,    55,    56,     9,    10,     0,    57,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    58,    59,
      60,     0,     0,     0,     0,     0,     0,     0,     0,    61,
       0,    62,     0,    63,    50,    51,    52,    53,    54,    55,
      56,     9,    10,     0,    57,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    58,    59,    60,     0,
       0,     0,     0,     0,     0,     0,     0,    61,     0,    62,
       0,    63,     0,   170,   171,   172,    50,    51,    52,    53,
      54,    55,    56,     9,    10,     0,    57,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    58,    59,
      60,     0,     0,     0,     0,   211,     0,     0,     0,    61,
       0,    62,     0,    63,    50,    51,    52,    53,    54,    55,
      56,     9,    10,     0,    57,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    58,    59,    60,   224,
       0,     0,     0,     0,     0,     0,     0,    61,     0,    62,
       0,    63,    50,    51,    52,    53,    54,    55,    56,     9,
      10,     0,    57,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    58,    59,    60,     0,     0,     0,
       0,     0,     0,     0,     0,    61,  -142,    62,     0,    63,
      50,    51,    52,    53,    54,    55,    56,     9,    10,     0,
      57,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    58,    59,    60,     0,     0,     0,     0,     0,
       0,     0,     0,    61,     0,    62,     0,    63,    50,    51,
      52,   242,   243,    55,    56,     9,    10,     0,    57,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      58,    59,    60,     0,     0,     0,     0,     0,     0,     0,
       0,    61,     0,    62,     0,    63
};

static const yytype_int16 yycheck[] =
{
       4,   110,    14,    15,    12,    20,     0,   269,    12,    12,
       0,     0,    13,    14,    15,    28,    20,    84,     0,    32,
      33,    28,    29,    62,     0,    32,     0,   101,    12,    90,
      13,    92,    99,    94,    97,    98,    75,    41,     0,   152,
     153,     3,     4,     5,     6,     7,     8,     9,    28,    57,
     144,    64,    65,    66,    57,    62,    34,    41,    20,    21,
      22,    23,    24,    57,    57,    59,    28,    57,    57,    59,
      59,   165,    58,    16,    17,    57,    28,    59,    21,    22,
      23,    24,   344,    57,    96,    59,   149,   355,    28,    12,
     102,   103,    14,   156,   157,    57,   159,    59,   161,   173,
      57,    55,    28,   166,    58,   168,    32,    33,   376,    55,
      28,    28,    58,   343,    57,    38,    59,    60,    61,    14,
      43,    44,    45,    46,   354,    48,    49,    50,    51,    52,
      28,    57,    60,    56,    32,    33,   140,   152,   153,    28,
     370,    28,    85,    32,    33,    32,    33,   377,   152,   153,
     154,   155,    95,    57,    34,    28,    29,    57,   101,    32,
      33,   104,    28,    29,    13,   274,    15,    33,    18,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
      34,   252,    59,   254,    54,   269,   139,    54,   141,    61,
       0,    57,    54,     3,     4,     5,     6,     7,     8,     9,
      29,   154,    63,    32,    33,   158,    57,   160,   230,    50,
      20,    21,    22,    23,    24,    50,    51,    52,    28,    25,
      26,    27,   175,    29,    30,    31,    32,    33,    21,   302,
     303,   315,   185,    59,    57,    59,   258,     5,    57,   312,
      57,    18,    12,    12,     9,    54,     6,    57,   270,    59,
      63,   103,    57,    31,   268,   143,    12,   233,   211,    31,
     344,   214,   215,   216,   217,   218,   219,   220,   221,    38,
     236,   223,    41,    42,    43,    44,    45,    46,   321,   280,
     155,   234,    38,   236,   357,    41,    42,    43,    44,    45,
      46,    -1,   365,   364,    -1,   309,    -1,    -1,    -1,   313,
      -1,   374,    -1,    -1,   257,   378,    -1,    -1,    -1,   382,
      -1,    -1,   334,    -1,   267,    -1,   269,     3,     4,     5,
       6,     7,     8,     9,   277,    -1,    -1,    -1,   281,   343,
     283,    -1,   285,    -1,    20,    21,    22,    23,    24,    -1,
     354,   355,    48,    49,    50,    51,    52,    -1,    -1,    -1,
      56,   304,    43,    44,    45,    46,   370,    48,    49,    50,
      51,    52,   376,   377,   317,    56,    48,    49,    50,    51,
      52,    -1,    -1,    -1,    -1,    -1,   329,    -1,    -1,    -1,
      -1,    -1,   335,    -1,    -1,    -1,    -1,    -1,    -1,   342,
      -1,   344,    -1,   346,    -1,   348,    -1,    -1,    -1,   352,
      -1,    -1,    -1,    -1,    -1,    -1,   359,    -1,    -1,   362,
      -1,    -1,    -1,    -1,    -1,   368,     0,    -1,   371,     3,
       4,     5,     6,     7,     8,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,
      24,    -1,    -1,    -1,    28,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    10,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    55,    -1,    57,    58,    59,    25,    26,    27,    -1,
      29,    30,    31,    32,    33,    -1,    -1,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    12,    -1,    56,    -1,    -1,
      17,    -1,    -1,    -1,    -1,    -1,    -1,    66,    67,    68,
      -1,    28,    -1,    -1,    -1,    32,    33,    -1,    -1,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    -1,    56,
      12,    13,    14,    -1,    -1,    -1,    -1,    64,    65,    66,
      67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    -1,    56,    12,    13,    14,    -1,    -1,
      -1,    -1,    -1,    -1,    66,    67,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    12,    -1,    56,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,
      67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    -1,
      -1,    56,    -1,    -1,    12,    -1,    -1,    -1,    -1,    64,
      65,    66,    67,    68,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    -1,    12,    56,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,    67,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    12,
      -1,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    12,    -1,    56,    -1,    -1,    59,    -1,    -1,    -1,
      -1,    -1,    -1,    66,    67,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    12,    56,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    66,    67,    68,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    12,    -1,    56,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    -1,    -1,    66,    67,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    12,    -1,
      56,    -1,    -1,    -1,    -1,    -1,    -1,    63,    -1,    -1,
      66,    67,    68,    -1,    28,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      12,    -1,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    66,    67,    68,    -1,    28,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    12,    -1,    56,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    66,    67,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    12,    -1,    56,    57,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    66,    67,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    12,    -1,    56,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,    67,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      36,    -1,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    12,    -1,    -1,
      56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      66,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    -1,    -1,
      -1,    56,    -1,    -1,    -1,    16,    -1,    -1,    -1,    -1,
      -1,    66,    67,    68,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    -1,    35,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    49,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    -1,    60,
      19,    62,    -1,    64,    65,    66,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    -1,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,
      49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,
      -1,    60,    -1,    62,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    -1,    35,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    49,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    -1,    60,
      -1,    62,    -1,    64,    65,    66,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    -1,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,
      49,    -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,    58,
      -1,    60,    -1,    62,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    -1,    35,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    49,    50,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    -1,    60,
      -1,    62,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    -1,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    47,    48,    49,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    58,    59,    60,    -1,    62,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    -1,
      35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    58,    -1,    60,    -1,    62,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    -1,    35,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      47,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    58,    -1,    60,    -1,    62
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    13,    79,    81,    80,    82,    84,     0,    28,    32,
      33,    77,    78,   167,     3,     4,     5,     6,     7,     8,
       9,    20,    21,    22,    23,    24,    83,    85,    86,    89,
      90,    94,    96,   105,   110,   111,   113,   114,   116,   118,
     120,    57,    77,    28,    87,    88,   169,    91,    92,   169,
      25,    26,    27,    28,    29,    30,    31,    35,    47,    48,
      49,    58,    60,    62,   126,   127,   128,   131,   132,   133,
     138,   139,   144,   159,   163,   164,   167,    19,   124,   126,
      13,    15,    93,    95,   103,   106,   162,   164,   167,   126,
     126,   115,   126,   117,   126,   121,    14,    93,    99,   103,
      77,    12,    57,    57,    34,   126,    58,   126,   126,   126,
     160,   145,   140,    12,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    56,    66,    67,    68,   123,    55,    58,    62,
      75,   125,    28,   104,    28,   143,    97,    98,   169,    99,
     107,   108,   126,    57,    12,    14,   112,   112,    13,   112,
      13,   112,   126,   169,   143,    28,   101,   143,    99,    16,
      64,    65,    66,   126,   157,   158,   169,    92,   126,   130,
      59,    82,    28,    29,    32,    62,   146,   147,   148,   168,
     126,   141,   142,   126,   126,   126,   126,   126,   126,   126,
     126,   126,   126,   126,   126,   126,   126,   126,   126,   126,
     126,    54,   126,   126,    12,    38,    41,    42,    43,    44,
      45,    46,    28,   129,    50,   126,   149,    28,   167,   126,
      14,    97,   144,    57,    34,   143,    57,    10,    11,   109,
     162,   162,    28,    29,   165,   167,    28,    29,   165,   167,
     143,   143,   126,   143,   126,   143,   122,    34,   102,   143,
     143,    28,    29,    33,   166,    66,   157,    18,   126,    12,
      57,   126,   134,   135,   136,   137,    59,    54,   126,    61,
      57,    54,    63,    57,   126,    54,   126,   126,   126,   126,
     126,   126,   126,   126,   134,    63,    50,   161,   169,    98,
     126,   108,   112,   112,    21,   126,   100,   169,   126,    17,
      28,   153,   155,   157,   167,   126,   157,   158,   169,    59,
      82,    57,   126,    63,   148,   126,   126,   126,    59,     5,
     150,   143,   143,   126,    57,    28,    29,   167,    57,   143,
      28,   167,    18,   126,    12,   135,    54,   126,     9,   151,
      22,    23,   119,   169,   126,   156,   126,   155,   157,   158,
     126,   126,     6,   152,   126,   155,   153,   154,    28,   143,
     126,    57,   126,    63,   112,   143,    57,   126,   155,   126,
     143,   153,   155,   143,   143
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    76,    77,    77,    78,    78,    78,    79,    80,    79,
      81,    82,    83,    83,    83,    83,    83,    83,    84,    84,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    86,    86,    86,    86,    87,    87,    87,    88,    88,
      89,    90,    91,    91,    92,    93,    95,    94,    96,    96,
      96,    96,    96,    96,    97,    97,    98,    99,    99,    99,
     100,   100,   102,   101,   104,   103,   106,   105,   107,   107,
     108,   109,   109,   109,   109,   110,   110,   111,   112,   112,
     113,   114,   115,   115,   116,   117,   117,   118,   119,   119,
     121,   122,   120,   123,   123,   123,   125,   124,   124,   126,
     126,   126,   126,   126,   126,   127,   127,   129,   128,   130,
     128,   131,   131,   131,   132,   132,   132,   132,   132,   132,
     132,   132,   132,   132,   132,   132,   132,   132,   132,   132,
     132,   132,   132,   132,   132,   132,   132,   132,   132,   132,
     133,   133,   134,   134,   135,   136,   135,   137,   137,   138,
     138,   140,   139,   141,   141,   142,   142,   143,   143,   145,
     144,   146,   146,   147,   147,   148,   148,   148,   148,   149,
     149,   150,   150,   151,   151,   151,   152,   152,   153,   153,
     153,   153,   154,   154,   155,   156,   155,   155,   155,   157,
     157,   157,   158,   158,   159,   159,   159,   159,   159,   160,
     159,   159,   159,   159,   161,   159,   162,   162,   163,   163,
     164,   164,   164,   164,   164,   165,   165,   165,   166,   166,
     166,   167,   167,   168,   168,   169
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     2,     0,     0,     3,
       2,     2,     1,     1,     1,     1,     1,     1,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     5,     4,     2,     2,     6,     8,    10,     9,    11,
       2,     2,     1,     3,     3,     4,     0,     3,     3,     3,
       4,     4,     3,     4,     1,     3,     3,     0,     2,     4,
       1,     3,     0,     3,     0,     3,     0,     3,     1,     3,
       2,     0,     1,     1,     1,     2,     4,     2,     2,     2,
       4,     4,     3,     5,     2,     3,     5,     2,     1,     1,
       0,     0,    10,     1,     1,     1,     0,     3,     1,     1,
       1,     1,     1,     1,     3,     1,     3,     0,     5,     0,
       5,     2,     2,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     4,     4,     4,     4,     4,     4,     4,     4,
       5,     4,     0,     1,     1,     0,     2,     1,     3,     1,
       1,     0,     4,     0,     1,     1,     3,     0,     2,     0,
       4,     0,     1,     1,     3,     1,     3,     3,     5,     1,
       2,     0,     2,     0,     2,     4,     0,     2,     1,     1,
       2,     2,     1,     3,     1,     0,     4,     2,     2,     1,
       1,     1,     1,     2,     1,     1,     1,     1,     3,     0,
       4,     3,     3,     4,     0,     8,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (&yylloc, parser, YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location, parser); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, arangodb::aql::Parser* parser)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  YYUSE (parser);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, arangodb::aql::Parser* parser)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, parser);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule, arangodb::aql::Parser* parser)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       , parser);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, parser); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, arangodb::aql::Parser* parser)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (parser);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/*----------.
| yyparse.  |
`----------*/

int
yyparse (arangodb::aql::Parser* parser)
{
/* The lookahead symbol.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

/* Location data for the lookahead symbol.  */
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
YYLTYPE yylloc = yyloc_default;

    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex (&yylval, &yylloc, scanner);
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 344 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.node) = parser->ast()->createNodeValueString((yyvsp[0].strval).value, (yyvsp[0].strval).length);
    }
#line 2110 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 347 "Aql/grammar.y" /* yacc.c:1646  */
    {
      char const* p = (yyvsp[0].node)->getStringValue();
      size_t const len = (yyvsp[0].node)->getStringLength();

      if (len < 2 || *p != '@') {
        parser->registerParseError(TRI_ERROR_QUERY_BIND_PARAMETER_TYPE, TRI_errno_string(TRI_ERROR_QUERY_BIND_PARAMETER_TYPE), p, yylloc.first_line, yylloc.first_column);
      }

      (yyval.node) = (yyvsp[0].node);
    }
#line 2125 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 360 "Aql/grammar.y" /* yacc.c:1646  */
    {
       auto node = static_cast<AstNode*>(parser->peekStack());
       node->addMember((yyvsp[0].node));
     }
#line 2134 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 364 "Aql/grammar.y" /* yacc.c:1646  */
    {
       auto node = static_cast<AstNode*>(parser->peekStack());
       node->addMember((yyvsp[0].node));
     }
#line 2143 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 368 "Aql/grammar.y" /* yacc.c:1646  */
    {
       auto node = static_cast<AstNode*>(parser->peekStack());
       node->addMember((yyvsp[0].node));
     }
#line 2152 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 375 "Aql/grammar.y" /* yacc.c:1646  */
    {
     }
#line 2159 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 377 "Aql/grammar.y" /* yacc.c:1646  */
    {
      auto node = parser->ast()->createNodeArray();
      parser->pushStack(node);
     }
#line 2168 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 380 "Aql/grammar.y" /* yacc.c:1646  */
    {
      auto node = static_cast<AstNode*>(parser->popStack());
      auto withNode = parser->ast()->createNodeWithCollections(node);
      parser->ast()->addOperation(withNode);
     }
#line 2178 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 388 "Aql/grammar.y" /* yacc.c:1646  */
    {
    }
#line 2185 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 393 "Aql/grammar.y" /* yacc.c:1646  */
    {
    }
#line 2192 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 398 "Aql/grammar.y" /* yacc.c:1646  */
    {
    }
#line 2199 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 400 "Aql/grammar.y" /* yacc.c:1646  */
    {
      parser->ast()->scopes()->endNested();
    }
#line 2207 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 403 "Aql/grammar.y" /* yacc.c:1646  */
    {
      parser->ast()->scopes()->endNested();
    }
#line 2215 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 406 "Aql/grammar.y" /* yacc.c:1646  */
    {
      parser->ast()->scopes()->endNested();
    }
#line 2223 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 409 "Aql/grammar.y" /* yacc.c:1646  */
    {
      parser->ast()->scopes()->endNested();
    }
#line 2231 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 412 "Aql/grammar.y" /* yacc.c:1646  */
    {
      parser->ast()->scopes()->endNested();
    }
#line 2239 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 418 "Aql/grammar.y" /* yacc.c:1646  */
    {
    }
#line 2246 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 420 "Aql/grammar.y" /* yacc.c:1646  */
    {
    }
#line 2253 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 425 "Aql/grammar.y" /* yacc.c:1646  */
    {
    }
#line 2260 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 427 "Aql/grammar.y" /* yacc.c:1646  */
    {
    }
#line 2267 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 429 "Aql/grammar.y" /* yacc.c:1646  */
    {
    }
#line 2274 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 431 "Aql/grammar.y" /* yacc.c:1646  */
    {
    }
#line 2281 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 433 "Aql/grammar.y" /* yacc.c:1646  */
    {
    }
#line 2288 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 435 "Aql/grammar.y" /* yacc.c:1646  */
    {
    }
#line 2295 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 437 "Aql/grammar.y" /* yacc.c:1646  */
    {
    }
#line 2302 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 439 "Aql/grammar.y" /* yacc.c:1646  */
    {
    }
#line 2309 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 441 "Aql/grammar.y" /* yacc.c:1646  */
    {
    }
#line 2316 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 443 "Aql/grammar.y" /* yacc.c:1646  */
    {
    }
#line 2323 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 445 "Aql/grammar.y" /* yacc.c:1646  */
    {
    }
#line 2330 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 450 "Aql/grammar.y" /* yacc.c:1646  */
    {
      parser->ast()->scopes()->start(arangodb::aql::AQL_SCOPE_FOR);

      auto node = parser->ast()->createNodeFor((yyvsp[-3].strval).value, (yyvsp[-3].strval).length, (yyvsp[0].node), true);
      parser->ast()->addOperation(node);
    }
#line 2341 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 456 "Aql/grammar.y" /* yacc.c:1646  */
    {
      parser->ast()->scopes()->start(arangodb::aql::AQL_SCOPE_FOR);

      auto node = parser->ast()->createNodeFor((yyvsp[-2].strval).value, (yyvsp[-2].strval).length, (yyvsp[0].node), true);
      parser->ast()->addOperation(node);
    }
#line 2352 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 462 "Aql/grammar.y" /* yacc.c:1646  */
    {
    }
#line 2359 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 464 "Aql/grammar.y" /* yacc.c:1646  */
    {
    }
#line 2366 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 469 "Aql/grammar.y" /* yacc.c:1646  */
    {
      parser->ast()->scopes()->start(arangodb::aql::AQL_SCOPE_FOR);
      auto node = parser->ast()->createNodeTraversal((yyvsp[-5].strval).value, (yyvsp[-5].strval).length, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
      parser->ast()->addOperation(node);
    }
#line 2376 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 474 "Aql/grammar.y" /* yacc.c:1646  */
    {
      parser->ast()->scopes()->start(arangodb::aql::AQL_SCOPE_FOR);
      auto node = parser->ast()->createNodeTraversal((yyvsp[-7].strval).value, (yyvsp[-7].strval).length, (yyvsp[-5].strval).value, (yyvsp[-5].strval).length, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
      parser->ast()->addOperation(node);
    }
#line 2386 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 479 "Aql/grammar.y" /* yacc.c:1646  */
    {
      parser->ast()->scopes()->start(arangodb::aql::AQL_SCOPE_FOR);
      auto node = parser->ast()->createNodeTraversal((yyvsp[-9].strval).value, (yyvsp[-9].strval).length, (yyvsp[-7].strval).value, (yyvsp[-7].strval).length, (yyvsp[-5].strval).value, (yyvsp[-5].strval).length, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
      parser->ast()->addOperation(node);
    }
#line 2396 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 487 "Aql/grammar.y" /* yacc.c:1646  */
    {
      if (!TRI_CaseEqualString((yyvsp[-3].strval).value, "TO")) {
        parser->registerParseError(TRI_ERROR_QUERY_PARSE, "unexpected qualifier '%s', expecting 'TO'", (yyvsp[-3].strval).value, yylloc.first_line, yylloc.first_column);
      }
      parser->ast()->scopes()->start(arangodb::aql::AQL_SCOPE_FOR);
      auto node = parser->ast()->createNodeShortestPath((yyvsp[-8].strval).value, (yyvsp[-8].strval).length, (yyvsp[-6].intval), (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
      parser->ast()->addOperation(node);
    }
#line 2409 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 495 "Aql/grammar.y" /* yacc.c:1646  */
    {
      if (!TRI_CaseEqualString((yyvsp[-3].strval).value, "TO")) {
        parser->registerParseError(TRI_ERROR_QUERY_PARSE, "unexpected qualifier '%s', expecting 'TO'", (yyvsp[-3].strval).value, yylloc.first_line, yylloc.first_column);
      }
      parser->ast()->scopes()->start(arangodb::aql::AQL_SCOPE_FOR);
      auto node = parser->ast()->createNodeShortestPath((yyvsp[-10].strval).value, (yyvsp[-10].strval).length, (yyvsp[-8].strval).value, (yyvsp[-8].strval).length, (yyvsp[-6].intval), (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
      parser->ast()->addOperation(node);
    }
#line 2422 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 506 "Aql/grammar.y" /* yacc.c:1646  */
    {
      // operand is a reference. can use it directly
      auto node = parser->ast()->createNodeFilter((yyvsp[0].node));
      parser->ast()->addOperation(node);
    }
#line 2432 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 514 "Aql/grammar.y" /* yacc.c:1646  */
    {
    }
#line 2439 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 519 "Aql/grammar.y" /* yacc.c:1646  */
    {
    }
#line 2446 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 521 "Aql/grammar.y" /* yacc.c:1646  */
    {
    }
#line 2453 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 526 "Aql/grammar.y" /* yacc.c:1646  */
    {
      auto node = parser->ast()->createNodeLet((yyvsp[-2].strval).value, (yyvsp[-2].strval).length, (yyvsp[0].node), true);
      parser->ast()->addOperation(node);
    }
#line 2462 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 533 "Aql/grammar.y" /* yacc.c:1646  */
    {
      if (! TRI_CaseEqualString((yyvsp[-2].strval).value, "COUNT")) {
        parser->registerParseError(TRI_ERROR_QUERY_PARSE, "unexpected qualifier '%s', expecting 'COUNT'", (yyvsp[-2].strval).value, yylloc.first_line, yylloc.first_column);
      }

      (yyval.strval) = (yyvsp[0].strval);
    }
#line 2474 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 543 "Aql/grammar.y" /* yacc.c:1646  */
    {
      auto node = parser->ast()->createNodeArray();
      parser->pushStack(node);
    }
#line 2483 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 546 "Aql/grammar.y" /* yacc.c:1646  */
    {
      auto list = static_cast<AstNode*>(parser->popStack());

      if (list == nullptr) {
        ABORT_OOM
      }
      (yyval.node) = list;
    }
#line 2496 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 557 "Aql/grammar.y" /* yacc.c:1646  */
    {
      /* COLLECT WITH COUNT INTO var OPTIONS ... */
      auto scopes = parser->ast()->scopes();

      StartCollectScope(scopes);

      auto node = parser->ast()->createNodeCollectCount(parser->ast()->createNodeArray(), (yyvsp[-1].strval).value, (yyvsp[-1].strval).length, (yyvsp[0].node));
      parser->ast()->addOperation(node);
    }
#line 2510 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 566 "Aql/grammar.y" /* yacc.c:1646  */
    {
      /* COLLECT var = expr WITH COUNT INTO var OPTIONS ... */
      auto scopes = parser->ast()->scopes();

      if (StartCollectScope(scopes)) {
        RegisterAssignVariables(scopes, (yyvsp[-2].node));
      }

      auto node = parser->ast()->createNodeCollectCount((yyvsp[-2].node), (yyvsp[-1].strval).value, (yyvsp[-1].strval).length, (yyvsp[0].node));
      parser->ast()->addOperation(node);
    }
#line 2526 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 577 "Aql/grammar.y" /* yacc.c:1646  */
    {
      /* AGGREGATE var = expr OPTIONS ... */
      auto scopes = parser->ast()->scopes();

      if (StartCollectScope(scopes)) {
        RegisterAssignVariables(scopes, (yyvsp[-2].node));
      }

      // validate aggregates
      if (! ValidateAggregates(parser, (yyvsp[-2].node))) {
        YYABORT;
      }

      if ((yyvsp[-1].node) != nullptr && (yyvsp[-1].node)->type == NODE_TYPE_ARRAY) {
        std::unordered_set<Variable const*> vars;
        Ast::getReferencedVariables((yyvsp[-1].node)->getMember(1), vars);

        Variable const* used = CheckIntoVariables((yyvsp[-2].node), vars);
        if (used != nullptr) {
          std::string msg("use of COLLECT variable '" + used->name + "' IN INTO expression");
          parser->registerParseError(TRI_ERROR_QUERY_PARSE, msg.c_str(), yylloc.first_line, yylloc.first_column);
        }
      }

      AstNode const* into = GetIntoVariable(parser, (yyvsp[-1].node));
      AstNode const* intoExpression = GetIntoExpression((yyvsp[-1].node));

      auto node = parser->ast()->createNodeCollect(parser->ast()->createNodeArray(), (yyvsp[-2].node), into, intoExpression, nullptr, (yyvsp[-1].node));
      parser->ast()->addOperation(node);
    }
#line 2561 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 607 "Aql/grammar.y" /* yacc.c:1646  */
    {
      /* COLLECT var = expr AGGREGATE var = expr OPTIONS ... */
      auto scopes = parser->ast()->scopes();

      if (StartCollectScope(scopes)) {
        RegisterAssignVariables(scopes, (yyvsp[-3].node));
        RegisterAssignVariables(scopes, (yyvsp[-2].node));
      }

      if (! ValidateAggregates(parser, (yyvsp[-2].node))) {
        YYABORT;
      }

      if ((yyvsp[-1].node) != nullptr && (yyvsp[-1].node)->type == NODE_TYPE_ARRAY) {
        std::unordered_set<Variable const*> vars;
        Ast::getReferencedVariables((yyvsp[-1].node)->getMember(1), vars);

        Variable const* used = CheckIntoVariables((yyvsp[-3].node), vars);
        if (used != nullptr) {
          std::string msg("use of COLLECT variable '" + used->name + "' IN INTO expression");
          parser->registerParseError(TRI_ERROR_QUERY_PARSE, msg.c_str(), yylloc.first_line, yylloc.first_column);
        }
        used = CheckIntoVariables((yyvsp[-2].node), vars);
        if (used != nullptr) {
          std::string msg("use of COLLECT variable '" + used->name + "' IN INTO expression");
          parser->registerParseError(TRI_ERROR_QUERY_PARSE, msg.c_str(), yylloc.first_line, yylloc.first_column);
        }
      }

      // note all group variables
      std::unordered_set<Variable const*> groupVars;
      size_t n = (yyvsp[-3].node)->numMembers();
      for (size_t i = 0; i < n; ++i) {
        auto member = (yyvsp[-3].node)->getMember(i);

        if (member != nullptr) {
          TRI_ASSERT(member->type == NODE_TYPE_ASSIGN);
          groupVars.emplace(static_cast<Variable const*>(member->getMember(0)->getData()));
        }
      }

      // now validate if any aggregate refers to one of the group variables
      n = (yyvsp[-2].node)->numMembers();
      for (size_t i = 0; i < n; ++i) {
        auto member = (yyvsp[-2].node)->getMember(i);

        if (member != nullptr) {
          TRI_ASSERT(member->type == NODE_TYPE_ASSIGN);
          std::unordered_set<Variable const*> variablesUsed;
          Ast::getReferencedVariables(member->getMember(1), variablesUsed);

          for (auto& it : groupVars) {
            if (variablesUsed.find(it) != variablesUsed.end()) {
              parser->registerParseError(TRI_ERROR_QUERY_VARIABLE_NAME_UNKNOWN,
                "use of unknown variable '%s' in aggregate expression", it->name.c_str(), yylloc.first_line, yylloc.first_column);
              break;
            }
          }
        }
      }

      AstNode const* into = GetIntoVariable(parser, (yyvsp[-1].node));
      AstNode const* intoExpression = GetIntoExpression((yyvsp[-1].node));

      auto node = parser->ast()->createNodeCollect((yyvsp[-3].node), (yyvsp[-2].node), into, intoExpression, nullptr, (yyvsp[0].node));
      parser->ast()->addOperation(node);
    }
#line 2633 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 674 "Aql/grammar.y" /* yacc.c:1646  */
    {
      /* COLLECT var = expr INTO var OPTIONS ... */
      auto scopes = parser->ast()->scopes();

      if (StartCollectScope(scopes)) {
        RegisterAssignVariables(scopes, (yyvsp[-2].node));
      }

      if ((yyvsp[-1].node) != nullptr && (yyvsp[-1].node)->type == NODE_TYPE_ARRAY) {
        std::unordered_set<Variable const*> vars;
        Ast::getReferencedVariables((yyvsp[-1].node)->getMember(1), vars);

        Variable const* used = CheckIntoVariables((yyvsp[-2].node), vars);
        if (used != nullptr) {
          std::string msg("use of COLLECT variable '" + used->name + "' IN INTO expression");
          parser->registerParseError(TRI_ERROR_QUERY_PARSE, msg.c_str(), yylloc.first_line, yylloc.first_column);
        }
      }

      AstNode const* into = GetIntoVariable(parser, (yyvsp[-1].node));
      AstNode const* intoExpression = GetIntoExpression((yyvsp[-1].node));

      auto node = parser->ast()->createNodeCollect((yyvsp[-2].node), parser->ast()->createNodeArray(), into, intoExpression, nullptr, (yyvsp[0].node));
      parser->ast()->addOperation(node);
    }
#line 2663 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 699 "Aql/grammar.y" /* yacc.c:1646  */
    {
      /* COLLECT var = expr INTO var KEEP ... OPTIONS ... */
      auto scopes = parser->ast()->scopes();

      if (StartCollectScope(scopes)) {
        RegisterAssignVariables(scopes, (yyvsp[-3].node));
      }

      if ((yyvsp[-2].node) == nullptr &&
          (yyvsp[-1].node) != nullptr) {
        parser->registerParseError(TRI_ERROR_QUERY_PARSE, "use of 'KEEP' without 'INTO'", yylloc.first_line, yylloc.first_column);
      }

      if ((yyvsp[-2].node) != nullptr && (yyvsp[-2].node)->type == NODE_TYPE_ARRAY) {
        std::unordered_set<Variable const*> vars;
        Ast::getReferencedVariables((yyvsp[-2].node)->getMember(1), vars);

        Variable const* used = CheckIntoVariables((yyvsp[-3].node), vars);
        if (used != nullptr) {
          std::string msg("use of COLLECT variable '" + used->name + "' IN INTO expression");
          parser->registerParseError(TRI_ERROR_QUERY_PARSE, msg.c_str(), yylloc.first_line, yylloc.first_column);
        }
      }

      AstNode const* into = GetIntoVariable(parser, (yyvsp[-2].node));
      AstNode const* intoExpression = GetIntoExpression((yyvsp[-2].node));

      auto node = parser->ast()->createNodeCollect((yyvsp[-3].node), parser->ast()->createNodeArray(), into, intoExpression, (yyvsp[-1].node), (yyvsp[0].node));
      parser->ast()->addOperation(node);
    }
#line 2698 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 732 "Aql/grammar.y" /* yacc.c:1646  */
    {
    }
#line 2705 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 734 "Aql/grammar.y" /* yacc.c:1646  */
    {
    }
#line 2712 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 739 "Aql/grammar.y" /* yacc.c:1646  */
    {
      auto node = parser->ast()->createNodeAssign((yyvsp[-2].strval).value, (yyvsp[-2].strval).length, (yyvsp[0].node));
      parser->pushArrayElement(node);
    }
#line 2721 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 746 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.node) = nullptr;
    }
#line 2729 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 749 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.node) = parser->ast()->createNodeValueString((yyvsp[0].strval).value, (yyvsp[0].strval).length);
    }
#line 2737 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 752 "Aql/grammar.y" /* yacc.c:1646  */
    {
      auto node = parser->ast()->createNodeArray();
      node->addMember(parser->ast()->createNodeValueString((yyvsp[-2].strval).value, (yyvsp[-2].strval).length));
      node->addMember((yyvsp[0].node));
      (yyval.node) = node;
    }
#line 2748 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 761 "Aql/grammar.y" /* yacc.c:1646  */
    {
      if (! parser->ast()->scopes()->existsVariable((yyvsp[0].strval).value, (yyvsp[0].strval).length)) {
        parser->registerParseError(TRI_ERROR_QUERY_PARSE, "use of unknown variable '%s' for KEEP", (yyvsp[0].strval).value, yylloc.first_line, yylloc.first_column);
      }

      auto node = parser->ast()->createNodeReference((yyvsp[0].strval).value, (yyvsp[0].strval).length);
      if (node == nullptr) {
        ABORT_OOM
      }

      // indicate the this node is a reference to the variable name, not the variable value
      node->setFlag(FLAG_KEEP_VARIABLENAME);
      parser->pushArrayElement(node);
    }
#line 2767 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 775 "Aql/grammar.y" /* yacc.c:1646  */
    {
      if (! parser->ast()->scopes()->existsVariable((yyvsp[0].strval).value, (yyvsp[0].strval).length)) {
        parser->registerParseError(TRI_ERROR_QUERY_PARSE, "use of unknown variable '%s' for KEEP", (yyvsp[0].strval).value, yylloc.first_line, yylloc.first_column);
      }

      auto node = parser->ast()->createNodeReference((yyvsp[0].strval).value, (yyvsp[0].strval).length);
      if (node == nullptr) {
        ABORT_OOM
      }

      // indicate the this node is a reference to the variable name, not the variable value
      node->setFlag(FLAG_KEEP_VARIABLENAME);
      parser->pushArrayElement(node);
    }
#line 2786 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 792 "Aql/grammar.y" /* yacc.c:1646  */
    {
      if (! TRI_CaseEqualString((yyvsp[0].strval).value, "KEEP")) {
        parser->registerParseError(TRI_ERROR_QUERY_PARSE, "unexpected qualifier '%s', expecting 'KEEP'", (yyvsp[0].strval).value, yylloc.first_line, yylloc.first_column);
      }

      auto node = parser->ast()->createNodeArray();
      parser->pushStack(node);
    }
#line 2799 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 799 "Aql/grammar.y" /* yacc.c:1646  */
    {
      auto list = static_cast<AstNode*>(parser->popStack());
      (yyval.node) = list;
    }
#line 2808 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 806 "Aql/grammar.y" /* yacc.c:1646  */
    {
      auto node = parser->ast()->createNodeArray();
      parser->pushStack(node);
    }
#line 2817 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 809 "Aql/grammar.y" /* yacc.c:1646  */
    {
      auto list = static_cast<AstNode*>(parser->popStack());
      (yyval.node) = list;
    }
#line 2826 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 816 "Aql/grammar.y" /* yacc.c:1646  */
    {
      auto node = parser->ast()->createNodeArray();
      parser->pushStack(node);
    }
#line 2835 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 819 "Aql/grammar.y" /* yacc.c:1646  */
    {
      auto list = static_cast<AstNode const*>(parser->popStack());
      auto node = parser->ast()->createNodeSort(list);
      parser->ast()->addOperation(node);
    }
#line 2845 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 827 "Aql/grammar.y" /* yacc.c:1646  */
    {
      parser->pushArrayElement((yyvsp[0].node));
    }
#line 2853 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 830 "Aql/grammar.y" /* yacc.c:1646  */
    {
      parser->pushArrayElement((yyvsp[0].node));
    }
#line 2861 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 836 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.node) = parser->ast()->createNodeSortElement((yyvsp[-1].node), (yyvsp[0].node));
    }
#line 2869 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 842 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.node) = parser->ast()->createNodeValueBool(true);
    }
#line 2877 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 845 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.node) = parser->ast()->createNodeValueBool(true);
    }
#line 2885 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 848 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.node) = parser->ast()->createNodeValueBool(false);
    }
#line 2893 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 851 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.node) = (yyvsp[0].node);
    }
#line 2901 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 857 "Aql/grammar.y" /* yacc.c:1646  */
    {
      auto offset = parser->ast()->createNodeValueInt(0);
      auto node = parser->ast()->createNodeLimit(offset, (yyvsp[0].node));
      parser->ast()->addOperation(node);
    }
#line 2911 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 862 "Aql/grammar.y" /* yacc.c:1646  */
    {
      auto node = parser->ast()->createNodeLimit((yyvsp[-2].node), (yyvsp[0].node));
      parser->ast()->addOperation(node);
    }
#line 2920 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 869 "Aql/grammar.y" /* yacc.c:1646  */
    {
      auto node = parser->ast()->createNodeReturn((yyvsp[0].node));
      parser->ast()->addOperation(node);
      parser->ast()->scopes()->endNested();
    }
#line 2930 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 877 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.node) = (yyvsp[0].node);
    }
#line 2938 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 880 "Aql/grammar.y" /* yacc.c:1646  */
    {
       (yyval.node) = (yyvsp[0].node);
     }
#line 2946 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 886 "Aql/grammar.y" /* yacc.c:1646  */
    {
      if (! parser->configureWriteQuery((yyvsp[-1].node), (yyvsp[0].node))) {
        YYABORT;
      }
      auto node = parser->ast()->createNodeRemove((yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
      parser->ast()->addOperation(node);
    }
#line 2958 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 896 "Aql/grammar.y" /* yacc.c:1646  */
    {
      if (! parser->configureWriteQuery((yyvsp[-1].node), (yyvsp[0].node))) {
        YYABORT;
      }
      auto node = parser->ast()->createNodeInsert((yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
      parser->ast()->addOperation(node);
    }
#line 2970 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 906 "Aql/grammar.y" /* yacc.c:1646  */
    {
      if (! parser->configureWriteQuery((yyvsp[-1].node), (yyvsp[0].node))) {
        YYABORT;
      }

      AstNode* node = parser->ast()->createNodeUpdate(nullptr, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
      parser->ast()->addOperation(node);
    }
#line 2983 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 914 "Aql/grammar.y" /* yacc.c:1646  */
    {
      if (! parser->configureWriteQuery((yyvsp[-1].node), (yyvsp[0].node))) {
        YYABORT;
      }

      AstNode* node = parser->ast()->createNodeUpdate((yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
      parser->ast()->addOperation(node);
    }
#line 2996 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 925 "Aql/grammar.y" /* yacc.c:1646  */
    {
    }
#line 3003 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 930 "Aql/grammar.y" /* yacc.c:1646  */
    {
      if (! parser->configureWriteQuery((yyvsp[-1].node), (yyvsp[0].node))) {
        YYABORT;
      }

      AstNode* node = parser->ast()->createNodeReplace(nullptr, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
      parser->ast()->addOperation(node);
    }
#line 3016 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 938 "Aql/grammar.y" /* yacc.c:1646  */
    {
      if (! parser->configureWriteQuery((yyvsp[-1].node), (yyvsp[0].node))) {
        YYABORT;
      }

      AstNode* node = parser->ast()->createNodeReplace((yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
      parser->ast()->addOperation(node);
    }
#line 3029 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 949 "Aql/grammar.y" /* yacc.c:1646  */
    {
    }
#line 3036 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 954 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.intval) = static_cast<int64_t>(NODE_TYPE_UPDATE);
    }
#line 3044 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 957 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.intval) = static_cast<int64_t>(NODE_TYPE_REPLACE);
    }
#line 3052 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 963 "Aql/grammar.y" /* yacc.c:1646  */
    {
      // reserve a variable named "$OLD", we might need it in the update expression
      // and in a later return thing
      parser->pushStack(parser->ast()->createNodeVariable(TRI_CHAR_LENGTH_PAIR(Variable::NAME_OLD), true));
    }
#line 3062 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 967 "Aql/grammar.y" /* yacc.c:1646  */
    {
      AstNode* variableNode = static_cast<AstNode*>(parser->popStack());

      auto scopes = parser->ast()->scopes();

      scopes->start(arangodb::aql::AQL_SCOPE_SUBQUERY);
      parser->ast()->startSubQuery();

      scopes->start(arangodb::aql::AQL_SCOPE_FOR);
      std::string const variableName = parser->ast()->variables()->nextName();
      auto forNode = parser->ast()->createNodeFor(variableName.c_str(), variableName.size(), parser->ast()->createNodeArray(), false);
      parser->ast()->addOperation(forNode);

      auto filterNode = parser->ast()->createNodeUpsertFilter(parser->ast()->createNodeReference(variableName), (yyvsp[0].node));
      parser->ast()->addOperation(filterNode);

      auto offsetValue = parser->ast()->createNodeValueInt(0);
      auto limitValue = parser->ast()->createNodeValueInt(1);
      auto limitNode = parser->ast()->createNodeLimit(offsetValue, limitValue);
      parser->ast()->addOperation(limitNode);

      auto refNode = parser->ast()->createNodeReference(variableName);
      auto returnNode = parser->ast()->createNodeReturn(refNode);
      parser->ast()->addOperation(returnNode);
      scopes->endNested();

      AstNode* subqueryNode = parser->ast()->endSubQuery();
      scopes->endCurrent();

      std::string const subqueryName = parser->ast()->variables()->nextName();
      auto subQuery = parser->ast()->createNodeLet(subqueryName.c_str(), subqueryName.size(), subqueryNode, false);
      parser->ast()->addOperation(subQuery);

      auto index = parser->ast()->createNodeValueInt(0);
      auto firstDoc = parser->ast()->createNodeLet(variableNode, parser->ast()->createNodeIndexedAccess(parser->ast()->createNodeReference(subqueryName), index));
      parser->ast()->addOperation(firstDoc);
      
      parser->pushStack(forNode);
    }
#line 3106 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 1005 "Aql/grammar.y" /* yacc.c:1646  */
    {
      AstNode* forNode = static_cast<AstNode*>(parser->popStack());
      forNode->changeMember(1, (yyvsp[-1].node)); 

      if (!parser->configureWriteQuery((yyvsp[-1].node), (yyvsp[0].node))) {
        YYABORT;
      }

      auto node = parser->ast()->createNodeUpsert(static_cast<AstNodeType>((yyvsp[-3].intval)), parser->ast()->createNodeReference(TRI_CHAR_LENGTH_PAIR(Variable::NAME_OLD)), (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
      parser->ast()->addOperation(node);
    }
#line 3122 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 1019 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.node) = parser->ast()->createNodeQuantifier(Quantifier::ALL);
    }
#line 3130 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 1022 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.node) = parser->ast()->createNodeQuantifier(Quantifier::ANY);
    }
#line 3138 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 1025 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.node) = parser->ast()->createNodeQuantifier(Quantifier::NONE);
    }
#line 3146 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 1031 "Aql/grammar.y" /* yacc.c:1646  */
    {
      auto const scopeType = parser->ast()->scopes()->type();

      if (scopeType == AQL_SCOPE_MAIN ||
          scopeType == AQL_SCOPE_SUBQUERY) {
        parser->registerParseError(TRI_ERROR_QUERY_PARSE, "cannot use DISTINCT modifier on top-level query element", yylloc.first_line, yylloc.first_column);
      }
    }
#line 3159 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 1038 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.node) = parser->ast()->createNodeDistinct((yyvsp[0].node));
    }
#line 3167 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 1041 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.node) = (yyvsp[0].node);
    }
#line 3175 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 1047 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.node) = (yyvsp[0].node);
    }
#line 3183 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 1050 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.node) = (yyvsp[0].node);
    }
#line 3191 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 1053 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.node) = (yyvsp[0].node);
    }
#line 3199 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 1056 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.node) = (yyvsp[0].node);
    }
#line 3207 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 1059 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.node) = (yyvsp[0].node);
    }
#line 3215 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 1062 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.node) = parser->ast()->createNodeRange((yyvsp[-2].node), (yyvsp[0].node));
    }
#line 3223 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 1068 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.strval) = (yyvsp[0].strval);
    }
#line 3231 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 1071 "Aql/grammar.y" /* yacc.c:1646  */
    {
      std::string temp((yyvsp[-2].strval).value, (yyvsp[-2].strval).length);
      temp.append("::");
      temp.append((yyvsp[0].strval).value, (yyvsp[0].strval).length);
      auto p = parser->query()->registerString(temp);

      if (p == nullptr) {
        ABORT_OOM
      }

      (yyval.strval).value = p;
      (yyval.strval).length = temp.size();
    }
#line 3249 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 1087 "Aql/grammar.y" /* yacc.c:1646  */
    {
      parser->pushStack((yyvsp[-1].strval).value);

      auto node = parser->ast()->createNodeArray();
      parser->pushStack(node);
    }
#line 3260 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 1092 "Aql/grammar.y" /* yacc.c:1646  */
    {
      auto list = static_cast<AstNode const*>(parser->popStack());
      (yyval.node) = parser->ast()->createNodeFunctionCall(static_cast<char const*>(parser->popStack()), list);
    }
#line 3269 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 1096 "Aql/grammar.y" /* yacc.c:1646  */
    {
      auto node = parser->ast()->createNodeArray();
      parser->pushStack(node);
    }
#line 3278 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 1099 "Aql/grammar.y" /* yacc.c:1646  */
    {
      auto list = static_cast<AstNode const*>(parser->popStack());
      (yyval.node) = parser->ast()->createNodeFunctionCall(TRI_CHAR_LENGTH_PAIR("LIKE"), list);
    }
#line 3287 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 1106 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.node) = parser->ast()->createNodeUnaryOperator(NODE_TYPE_OPERATOR_UNARY_PLUS, (yyvsp[0].node));
    }
#line 3295 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 1109 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.node) = parser->ast()->createNodeUnaryOperator(NODE_TYPE_OPERATOR_UNARY_MINUS, (yyvsp[0].node));
    }
#line 3303 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 1112 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.node) = parser->ast()->createNodeUnaryOperator(NODE_TYPE_OPERATOR_UNARY_NOT, (yyvsp[0].node));
    }
#line 3311 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 1118 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.node) = parser->ast()->createNodeBinaryOperator(NODE_TYPE_OPERATOR_BINARY_OR, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 3319 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 1121 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.node) = parser->ast()->createNodeBinaryOperator(NODE_TYPE_OPERATOR_BINARY_AND, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 3327 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 1124 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.node) = parser->ast()->createNodeBinaryOperator(NODE_TYPE_OPERATOR_BINARY_PLUS, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 3335 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 1127 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.node) = parser->ast()->createNodeBinaryOperator(NODE_TYPE_OPERATOR_BINARY_MINUS, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 3343 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 1130 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.node) = parser->ast()->createNodeBinaryOperator(NODE_TYPE_OPERATOR_BINARY_TIMES, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 3351 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 1133 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.node) = parser->ast()->createNodeBinaryOperator(NODE_TYPE_OPERATOR_BINARY_DIV, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 3359 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 1136 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.node) = parser->ast()->createNodeBinaryOperator(NODE_TYPE_OPERATOR_BINARY_MOD, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 3367 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 1139 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.node) = parser->ast()->createNodeBinaryOperator(NODE_TYPE_OPERATOR_BINARY_EQ, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 3375 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 1142 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.node) = parser->ast()->createNodeBinaryOperator(NODE_TYPE_OPERATOR_BINARY_NE, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 3383 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 1145 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.node) = parser->ast()->createNodeBinaryOperator(NODE_TYPE_OPERATOR_BINARY_LT, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 3391 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 1148 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.node) = parser->ast()->createNodeBinaryOperator(NODE_TYPE_OPERATOR_BINARY_GT, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 3399 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 1151 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.node) = parser->ast()->createNodeBinaryOperator(NODE_TYPE_OPERATOR_BINARY_LE, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 3407 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 1154 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.node) = parser->ast()->createNodeBinaryOperator(NODE_TYPE_OPERATOR_BINARY_GE, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 3415 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 1157 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.node) = parser->ast()->createNodeBinaryOperator(NODE_TYPE_OPERATOR_BINARY_IN, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 3423 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 1160 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.node) = parser->ast()->createNodeBinaryOperator(NODE_TYPE_OPERATOR_BINARY_NIN, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 3431 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 1163 "Aql/grammar.y" /* yacc.c:1646  */
    {
      AstNode* arguments = parser->ast()->createNodeArray(2);
      arguments->addMember((yyvsp[-2].node));
      arguments->addMember((yyvsp[0].node));
      (yyval.node) = parser->ast()->createNodeFunctionCall(TRI_CHAR_LENGTH_PAIR("LIKE"), arguments);
    }
#line 3442 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 1169 "Aql/grammar.y" /* yacc.c:1646  */
    {
      AstNode* arguments = parser->ast()->createNodeArray(2);
      arguments->addMember((yyvsp[-2].node));
      arguments->addMember((yyvsp[0].node));
      (yyval.node) = parser->ast()->createNodeFunctionCall(TRI_CHAR_LENGTH_PAIR("REGEX_TEST"), arguments);
    }
#line 3453 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 131:
#line 1175 "Aql/grammar.y" /* yacc.c:1646  */
    {
      AstNode* arguments = parser->ast()->createNodeArray(2);
      arguments->addMember((yyvsp[-2].node));
      arguments->addMember((yyvsp[0].node));
      AstNode* node = parser->ast()->createNodeFunctionCall(TRI_CHAR_LENGTH_PAIR("REGEX_TEST"), arguments);
      (yyval.node) = parser->ast()->createNodeUnaryOperator(NODE_TYPE_OPERATOR_UNARY_NOT, node);
    }
#line 3465 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 1182 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.node) = parser->ast()->createNodeBinaryArrayOperator(NODE_TYPE_OPERATOR_BINARY_ARRAY_EQ, (yyvsp[-3].node), (yyvsp[0].node), (yyvsp[-2].node));
    }
#line 3473 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 1185 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.node) = parser->ast()->createNodeBinaryArrayOperator(NODE_TYPE_OPERATOR_BINARY_ARRAY_NE, (yyvsp[-3].node), (yyvsp[0].node), (yyvsp[-2].node));
    }
#line 3481 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 1188 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.node) = parser->ast()->createNodeBinaryArrayOperator(NODE_TYPE_OPERATOR_BINARY_ARRAY_LT, (yyvsp[-3].node), (yyvsp[0].node), (yyvsp[-2].node));
    }
#line 3489 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 1191 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.node) = parser->ast()->createNodeBinaryArrayOperator(NODE_TYPE_OPERATOR_BINARY_ARRAY_GT, (yyvsp[-3].node), (yyvsp[0].node), (yyvsp[-2].node));
    }
#line 3497 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 1194 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.node) = parser->ast()->createNodeBinaryArrayOperator(NODE_TYPE_OPERATOR_BINARY_ARRAY_LE, (yyvsp[-3].node), (yyvsp[0].node), (yyvsp[-2].node));
    }
#line 3505 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 1197 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.node) = parser->ast()->createNodeBinaryArrayOperator(NODE_TYPE_OPERATOR_BINARY_ARRAY_GE, (yyvsp[-3].node), (yyvsp[0].node), (yyvsp[-2].node));
    }
#line 3513 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 1200 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.node) = parser->ast()->createNodeBinaryArrayOperator(NODE_TYPE_OPERATOR_BINARY_ARRAY_IN, (yyvsp[-3].node), (yyvsp[0].node), (yyvsp[-2].node));
    }
#line 3521 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 1203 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.node) = parser->ast()->createNodeBinaryArrayOperator(NODE_TYPE_OPERATOR_BINARY_ARRAY_NIN, (yyvsp[-3].node), (yyvsp[0].node), (yyvsp[-2].node));
    }
#line 3529 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 140:
#line 1209 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.node) = parser->ast()->createNodeTernaryOperator((yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 3537 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 1212 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.node) = parser->ast()->createNodeTernaryOperator((yyvsp[-3].node), (yyvsp[-3].node), (yyvsp[0].node));
    }
#line 3545 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 1218 "Aql/grammar.y" /* yacc.c:1646  */
    {
    }
#line 3552 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 143:
#line 1220 "Aql/grammar.y" /* yacc.c:1646  */
    {
    }
#line 3559 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 144:
#line 1225 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.node) = (yyvsp[0].node);
    }
#line 3567 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 145:
#line 1228 "Aql/grammar.y" /* yacc.c:1646  */
    {
      parser->ast()->scopes()->start(arangodb::aql::AQL_SCOPE_SUBQUERY);
      parser->ast()->startSubQuery();
    }
#line 3576 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 146:
#line 1231 "Aql/grammar.y" /* yacc.c:1646  */
    {
      AstNode* node = parser->ast()->endSubQuery();
      parser->ast()->scopes()->endCurrent();

      std::string const variableName = parser->ast()->variables()->nextName();
      auto subQuery = parser->ast()->createNodeLet(variableName.c_str(), variableName.size(), node, false);
      parser->ast()->addOperation(subQuery);

      (yyval.node) = parser->ast()->createNodeReference(variableName);
    }
#line 3591 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 147:
#line 1244 "Aql/grammar.y" /* yacc.c:1646  */
    {
      parser->pushArrayElement((yyvsp[0].node));
    }
#line 3599 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 148:
#line 1247 "Aql/grammar.y" /* yacc.c:1646  */
    {
      parser->pushArrayElement((yyvsp[0].node));
    }
#line 3607 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 149:
#line 1253 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.node) = (yyvsp[0].node);
    }
#line 3615 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 150:
#line 1256 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.node) = (yyvsp[0].node);
    }
#line 3623 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 151:
#line 1262 "Aql/grammar.y" /* yacc.c:1646  */
    {
      auto node = parser->ast()->createNodeArray();
      parser->pushStack(node);
    }
#line 3632 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 152:
#line 1265 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.node) = static_cast<AstNode*>(parser->popStack());
    }
#line 3640 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 153:
#line 1271 "Aql/grammar.y" /* yacc.c:1646  */
    {
    }
#line 3647 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 154:
#line 1273 "Aql/grammar.y" /* yacc.c:1646  */
    {
    }
#line 3654 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 155:
#line 1278 "Aql/grammar.y" /* yacc.c:1646  */
    {
      parser->pushArrayElement((yyvsp[0].node));
    }
#line 3662 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 156:
#line 1281 "Aql/grammar.y" /* yacc.c:1646  */
    {
      parser->pushArrayElement((yyvsp[0].node));
    }
#line 3670 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 157:
#line 1287 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.node) = nullptr;
    }
#line 3678 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 158:
#line 1290 "Aql/grammar.y" /* yacc.c:1646  */
    {
      if ((yyvsp[0].node) == nullptr) {
        ABORT_OOM
      }

      if (! TRI_CaseEqualString((yyvsp[-1].strval).value, "OPTIONS")) {
        parser->registerParseError(TRI_ERROR_QUERY_PARSE, "unexpected qualifier '%s', expecting 'OPTIONS'", (yyvsp[-1].strval).value, yylloc.first_line, yylloc.first_column);
      }

      (yyval.node) = (yyvsp[0].node);
    }
#line 3694 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 159:
#line 1304 "Aql/grammar.y" /* yacc.c:1646  */
    {
      auto node = parser->ast()->createNodeObject();
      parser->pushStack(node);
    }
#line 3703 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 160:
#line 1307 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.node) = static_cast<AstNode*>(parser->popStack());
    }
#line 3711 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 161:
#line 1313 "Aql/grammar.y" /* yacc.c:1646  */
    {
    }
#line 3718 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 162:
#line 1315 "Aql/grammar.y" /* yacc.c:1646  */
    {
    }
#line 3725 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 163:
#line 1320 "Aql/grammar.y" /* yacc.c:1646  */
    {
    }
#line 3732 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 164:
#line 1322 "Aql/grammar.y" /* yacc.c:1646  */
    {
    }
#line 3739 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 165:
#line 1327 "Aql/grammar.y" /* yacc.c:1646  */
    {
      // attribute-name-only (comparable to JS enhanced object literals, e.g. { foo, bar })
      auto ast = parser->ast();
      auto variable = ast->scopes()->getVariable((yyvsp[0].strval).value, (yyvsp[0].strval).length, true);

      if (variable == nullptr) {
        // variable does not exist
        parser->registerParseError(TRI_ERROR_QUERY_VARIABLE_NAME_UNKNOWN, "use of unknown variable '%s' in object literal", (yyvsp[0].strval).value, yylloc.first_line, yylloc.first_column);
      }

      // create a reference to the variable
      auto node = ast->createNodeReference(variable);
      parser->pushObjectElement((yyvsp[0].strval).value, (yyvsp[0].strval).length, node);
    }
#line 3758 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 166:
#line 1341 "Aql/grammar.y" /* yacc.c:1646  */
    {
      // attribute-name : attribute-value
      parser->pushObjectElement((yyvsp[-2].strval).value, (yyvsp[-2].strval).length, (yyvsp[0].node));
    }
#line 3767 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 167:
#line 1345 "Aql/grammar.y" /* yacc.c:1646  */
    {
      // bind-parameter : attribute-value
      if ((yyvsp[-2].strval).length < 1 || (yyvsp[-2].strval).value[0] == '@') {
        parser->registerParseError(TRI_ERROR_QUERY_BIND_PARAMETER_TYPE, TRI_errno_string(TRI_ERROR_QUERY_BIND_PARAMETER_TYPE), (yyvsp[-2].strval).value, yylloc.first_line, yylloc.first_column);
      }

      auto param = parser->ast()->createNodeParameter((yyvsp[-2].strval).value, (yyvsp[-2].strval).length);
      parser->pushObjectElement(param, (yyvsp[0].node));
    }
#line 3781 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 168:
#line 1354 "Aql/grammar.y" /* yacc.c:1646  */
    {
      // [ attribute-name-expression ] : attribute-value
      parser->pushObjectElement((yyvsp[-3].node), (yyvsp[0].node));
    }
#line 3790 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 169:
#line 1361 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.intval) = 1;
    }
#line 3798 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 170:
#line 1364 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.intval) = (yyvsp[-1].intval) + 1;
    }
#line 3806 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 171:
#line 1370 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.node) = nullptr;
    }
#line 3814 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 172:
#line 1373 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.node) = (yyvsp[0].node);
    }
#line 3822 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 173:
#line 1379 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.node) = nullptr;
    }
#line 3830 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 174:
#line 1382 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.node) = parser->ast()->createNodeArrayLimit(nullptr, (yyvsp[0].node));
    }
#line 3838 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 175:
#line 1385 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.node) = parser->ast()->createNodeArrayLimit((yyvsp[-2].node), (yyvsp[0].node));
    }
#line 3846 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 176:
#line 1391 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.node) = nullptr;
    }
#line 3854 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 177:
#line 1394 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.node) = (yyvsp[0].node);
    }
#line 3862 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 178:
#line 1400 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.node) = parser->ast()->createNodeValueString((yyvsp[0].strval).value, (yyvsp[0].strval).length);
    }
#line 3870 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 179:
#line 1403 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.node) = (yyvsp[0].node);
    }
#line 3878 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 180:
#line 1406 "Aql/grammar.y" /* yacc.c:1646  */
    {
      auto tmp = parser->ast()->createNodeValueString((yyvsp[0].strval).value, (yyvsp[0].strval).length);
      (yyval.node) = parser->ast()->createNodeCollectionDirection((yyvsp[-1].intval), tmp);
    }
#line 3887 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 181:
#line 1410 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.node) = parser->ast()->createNodeCollectionDirection((yyvsp[-1].intval), (yyvsp[0].node));
    }
#line 3895 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 182:
#line 1416 "Aql/grammar.y" /* yacc.c:1646  */
    {
       auto node = static_cast<AstNode*>(parser->peekStack());
       node->addMember((yyvsp[0].node));
     }
#line 3904 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 183:
#line 1420 "Aql/grammar.y" /* yacc.c:1646  */
    {
       auto node = static_cast<AstNode*>(parser->peekStack());
       node->addMember((yyvsp[0].node));
     }
#line 3913 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 184:
#line 1427 "Aql/grammar.y" /* yacc.c:1646  */
    {
      auto node = parser->ast()->createNodeArray();
      node->addMember((yyvsp[0].node));
      (yyval.node) = parser->ast()->createNodeCollectionList(node);
    }
#line 3923 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 185:
#line 1432 "Aql/grammar.y" /* yacc.c:1646  */
    {
      auto node = parser->ast()->createNodeArray();
      parser->pushStack(node);
      node->addMember((yyvsp[-1].node));
    }
#line 3933 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 186:
#line 1436 "Aql/grammar.y" /* yacc.c:1646  */
    {
      auto node = static_cast<AstNode*>(parser->popStack());
      (yyval.node) = parser->ast()->createNodeCollectionList(node);
    }
#line 3942 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 187:
#line 1440 "Aql/grammar.y" /* yacc.c:1646  */
    {
      // graph name
      (yyval.node) = (yyvsp[0].node);
    }
#line 3951 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 188:
#line 1444 "Aql/grammar.y" /* yacc.c:1646  */
    {
      // graph name
      (yyval.node) = parser->ast()->createNodeValueString((yyvsp[0].strval).value, (yyvsp[0].strval).length);
    }
#line 3960 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 189:
#line 1453 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.intval) = 2;
    }
#line 3968 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 190:
#line 1456 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.intval) = 1;
    }
#line 3976 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 191:
#line 1459 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.intval) = 0;
    }
#line 3984 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 192:
#line 1465 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.node) = parser->ast()->createNodeDirection((yyvsp[0].intval), 1);
    }
#line 3992 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 193:
#line 1468 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.node) = parser->ast()->createNodeDirection((yyvsp[0].intval), (yyvsp[-1].node));
    }
#line 4000 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 194:
#line 1474 "Aql/grammar.y" /* yacc.c:1646  */
    {
      // variable or collection
      auto ast = parser->ast();
      AstNode* node = nullptr;

      auto variable = ast->scopes()->getVariable((yyvsp[0].strval).value, (yyvsp[0].strval).length, true);

      if (variable == nullptr) {
        // variable does not exist
        // now try special variables
        if (ast->scopes()->canUseCurrentVariable() && strcmp((yyvsp[0].strval).value, "CURRENT") == 0) {
          variable = ast->scopes()->getCurrentVariable();
        }
        else if (strcmp((yyvsp[0].strval).value, Variable::NAME_CURRENT) == 0) {
          variable = ast->scopes()->getCurrentVariable();
        }
      }

      if (variable != nullptr) {
        // variable alias exists, now use it
        node = ast->createNodeReference(variable);
      }

      if (node == nullptr) {
        // variable not found. so it must have been a collection
        node = ast->createNodeCollection((yyvsp[0].strval).value, arangodb::AccessMode::Type::READ);
      }

      TRI_ASSERT(node != nullptr);

      (yyval.node) = node;
    }
#line 4037 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 195:
#line 1506 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.node) = (yyvsp[0].node);
    }
#line 4045 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 196:
#line 1509 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.node) = (yyvsp[0].node);
    }
#line 4053 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 197:
#line 1512 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.node) = (yyvsp[0].node);

      if ((yyval.node) == nullptr) {
        ABORT_OOM
      }
    }
#line 4065 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 198:
#line 1519 "Aql/grammar.y" /* yacc.c:1646  */
    {
      if ((yyvsp[-1].node)->type == NODE_TYPE_EXPANSION) {
        // create a dummy passthru node that reduces and evaluates the expansion first
        // and the expansion on top of the stack won't be chained with any other expansions
        (yyval.node) = parser->ast()->createNodePassthru((yyvsp[-1].node));
      }
      else {
        (yyval.node) = (yyvsp[-1].node);
      }
    }
#line 4080 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 199:
#line 1529 "Aql/grammar.y" /* yacc.c:1646  */
    {
      parser->ast()->scopes()->start(arangodb::aql::AQL_SCOPE_SUBQUERY);
      parser->ast()->startSubQuery();
    }
#line 4089 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 200:
#line 1532 "Aql/grammar.y" /* yacc.c:1646  */
    {
      AstNode* node = parser->ast()->endSubQuery();
      parser->ast()->scopes()->endCurrent();

      std::string const variableName = parser->ast()->variables()->nextName();
      auto subQuery = parser->ast()->createNodeLet(variableName.c_str(), variableName.size(), node, false);
      parser->ast()->addOperation(subQuery);

      (yyval.node) = parser->ast()->createNodeReference(variableName);
    }
#line 4104 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 201:
#line 1542 "Aql/grammar.y" /* yacc.c:1646  */
    {
      // named variable access, e.g. variable.reference
      if ((yyvsp[-2].node)->type == NODE_TYPE_EXPANSION) {
        // if left operand is an expansion already...
        // dive into the expansion's right-hand child nodes for further expansion and
        // patch the bottom-most one
        auto current = const_cast<AstNode*>(parser->ast()->findExpansionSubNode((yyvsp[-2].node)));
        TRI_ASSERT(current->type == NODE_TYPE_EXPANSION);
        current->changeMember(1, parser->ast()->createNodeAttributeAccess(current->getMember(1), (yyvsp[0].strval).value, (yyvsp[0].strval).length));
        (yyval.node) = (yyvsp[-2].node);
      }
      else {
        (yyval.node) = parser->ast()->createNodeAttributeAccess((yyvsp[-2].node), (yyvsp[0].strval).value, (yyvsp[0].strval).length);
      }
    }
#line 4124 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 202:
#line 1557 "Aql/grammar.y" /* yacc.c:1646  */
    {
      // named variable access, e.g. variable.@reference
      if ((yyvsp[-2].node)->type == NODE_TYPE_EXPANSION) {
        // if left operand is an expansion already...
        // patch the existing expansion
        auto current = const_cast<AstNode*>(parser->ast()->findExpansionSubNode((yyvsp[-2].node)));
        TRI_ASSERT(current->type == NODE_TYPE_EXPANSION);
        current->changeMember(1, parser->ast()->createNodeBoundAttributeAccess(current->getMember(1), (yyvsp[0].node)));
        (yyval.node) = (yyvsp[-2].node);
      }
      else {
        (yyval.node) = parser->ast()->createNodeBoundAttributeAccess((yyvsp[-2].node), (yyvsp[0].node));
      }
    }
#line 4143 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 203:
#line 1571 "Aql/grammar.y" /* yacc.c:1646  */
    {
      // indexed variable access, e.g. variable[index]
      if ((yyvsp[-3].node)->type == NODE_TYPE_EXPANSION) {
        // if left operand is an expansion already...
        // patch the existing expansion
        auto current = const_cast<AstNode*>(parser->ast()->findExpansionSubNode((yyvsp[-3].node)));
        TRI_ASSERT(current->type == NODE_TYPE_EXPANSION);
        current->changeMember(1, parser->ast()->createNodeIndexedAccess(current->getMember(1), (yyvsp[-1].node)));
        (yyval.node) = (yyvsp[-3].node);
      }
      else {
        (yyval.node) = parser->ast()->createNodeIndexedAccess((yyvsp[-3].node), (yyvsp[-1].node));
      }
    }
#line 4162 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 204:
#line 1585 "Aql/grammar.y" /* yacc.c:1646  */
    {
      // variable expansion, e.g. variable[*], with optional FILTER, LIMIT and RETURN clauses
      if ((yyvsp[0].intval) > 1 && (yyvsp[-2].node)->type == NODE_TYPE_EXPANSION) {
        // create a dummy passthru node that reduces and evaluates the expansion first
        // and the expansion on top of the stack won't be chained with any other expansions
        (yyvsp[-2].node) = parser->ast()->createNodePassthru((yyvsp[-2].node));
      }

      // create a temporary iterator variable
      std::string const nextName = parser->ast()->variables()->nextName() + "_";

      if ((yyvsp[-2].node)->type == NODE_TYPE_EXPANSION) {
        auto iterator = parser->ast()->createNodeIterator(nextName.c_str(), nextName.size(), (yyvsp[-2].node)->getMember(1));
        parser->pushStack(iterator);
      }
      else {
        auto iterator = parser->ast()->createNodeIterator(nextName.c_str(), nextName.size(), (yyvsp[-2].node));
        parser->pushStack(iterator);
      }

      auto scopes = parser->ast()->scopes();
      scopes->stackCurrentVariable(scopes->getVariable(nextName));
    }
#line 4190 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 205:
#line 1607 "Aql/grammar.y" /* yacc.c:1646  */
    {
      auto scopes = parser->ast()->scopes();
      scopes->unstackCurrentVariable();

      auto iterator = static_cast<AstNode const*>(parser->popStack());
      auto variableNode = iterator->getMember(0);
      TRI_ASSERT(variableNode->type == NODE_TYPE_VARIABLE);
      auto variable = static_cast<Variable const*>(variableNode->getData());

      if ((yyvsp[-7].node)->type == NODE_TYPE_EXPANSION) {
        auto expand = parser->ast()->createNodeExpansion((yyvsp[-5].intval), iterator, parser->ast()->createNodeReference(variable->name), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node));
        (yyvsp[-7].node)->changeMember(1, expand);
        (yyval.node) = (yyvsp[-7].node);
      }
      else {
        (yyval.node) = parser->ast()->createNodeExpansion((yyvsp[-5].intval), iterator, parser->ast()->createNodeReference(variable->name), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node));
      }
    }
#line 4213 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 206:
#line 1628 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.node) = (yyvsp[0].node);
    }
#line 4221 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 207:
#line 1631 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.node) = (yyvsp[0].node);
    }
#line 4229 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 208:
#line 1637 "Aql/grammar.y" /* yacc.c:1646  */
    {
      if ((yyvsp[0].node) == nullptr) {
        ABORT_OOM
      }

      (yyval.node) = (yyvsp[0].node);
    }
#line 4241 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 209:
#line 1644 "Aql/grammar.y" /* yacc.c:1646  */
    {
      if ((yyvsp[0].node) == nullptr) {
        ABORT_OOM
      }

      (yyval.node) = (yyvsp[0].node);
    }
#line 4253 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 210:
#line 1654 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.node) = parser->ast()->createNodeValueString((yyvsp[0].strval).value, (yyvsp[0].strval).length);
    }
#line 4261 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 211:
#line 1657 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.node) = (yyvsp[0].node);
    }
#line 4269 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 212:
#line 1660 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.node) = parser->ast()->createNodeValueNull();
    }
#line 4277 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 213:
#line 1663 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.node) = parser->ast()->createNodeValueBool(true);
    }
#line 4285 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 214:
#line 1666 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.node) = parser->ast()->createNodeValueBool(false);
    }
#line 4293 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 215:
#line 1672 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.node) = parser->ast()->createNodeCollection((yyvsp[0].strval).value, arangodb::AccessMode::Type::WRITE);
    }
#line 4301 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 216:
#line 1675 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.node) = parser->ast()->createNodeCollection((yyvsp[0].strval).value, arangodb::AccessMode::Type::WRITE);
    }
#line 4309 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 217:
#line 1678 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.node) = (yyvsp[0].node);
    }
#line 4317 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 218:
#line 1684 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.node) = parser->ast()->createNodeView((yyvsp[0].strval).value);
    }
#line 4325 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 219:
#line 1687 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.node) = parser->ast()->createNodeView((yyvsp[0].strval).value);
    }
#line 4333 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 220:
#line 1690 "Aql/grammar.y" /* yacc.c:1646  */
    {
      if ((yyvsp[0].strval).length < 2 || (yyvsp[0].strval).value[0] != '@') {
        parser->registerParseError(TRI_ERROR_QUERY_BIND_PARAMETER_TYPE, TRI_errno_string(TRI_ERROR_QUERY_BIND_PARAMETER_TYPE), (yyvsp[0].strval).value, yylloc.first_line, yylloc.first_column);
      }

      (yyval.node) = parser->ast()->createNodeParameter((yyvsp[0].strval).value, (yyvsp[0].strval).length);
    }
#line 4345 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 221:
#line 1700 "Aql/grammar.y" /* yacc.c:1646  */
    {
      if ((yyvsp[0].strval).length < 2 || (yyvsp[0].strval).value[0] != '@') {
        parser->registerParseError(TRI_ERROR_QUERY_BIND_PARAMETER_TYPE, TRI_errno_string(TRI_ERROR_QUERY_BIND_PARAMETER_TYPE), (yyvsp[0].strval).value, yylloc.first_line, yylloc.first_column);
      }

      (yyval.node) = parser->ast()->createNodeParameter((yyvsp[0].strval).value, (yyvsp[0].strval).length);
    }
#line 4357 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 222:
#line 1707 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.node) = parser->ast()->createNodeParameter((yyvsp[0].strval).value, (yyvsp[0].strval).length);
    }
#line 4365 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 223:
#line 1713 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.strval) = (yyvsp[0].strval);
    }
#line 4373 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 224:
#line 1716 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.strval) = (yyvsp[0].strval);
    }
#line 4381 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;

  case 225:
#line 1721 "Aql/grammar.y" /* yacc.c:1646  */
    {
      (yyval.strval) = (yyvsp[0].strval);
    }
#line 4389 "Aql/grammar.cpp" /* yacc.c:1646  */
    break;


#line 4393 "Aql/grammar.cpp" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (&yylloc, parser, YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (&yylloc, parser, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc, parser);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp, parser);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (&yylloc, parser, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc, parser);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp, parser);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
