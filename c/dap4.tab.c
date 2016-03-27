/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 1

/* Pull parsers.  */
#define YYPULL 0

/* Using locations.  */
#define YYLSP_NEEDED 0

/* Substitute the variable and function names.  */
#define yypush_parse    dap4push_parse
#define yypstate_new    dap4pstate_new
#define yypstate_delete dap4pstate_delete
#define yypstate        dap4pstate
#define yylex           dap4lex
#define yyerror         dap4error
#define yylval          dap4lval
#define yychar          dap4char
#define yydebug         dap4debug
#define yynerrs         dap4nerrs


/* Copy the first part of user declarations.  */


/* Line 268 of yacc.c  */
#line 82 "dap4.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

/* "%code requires" blocks.  */

/* Line 288 of yacc.c  */
#line 14 "dap4.y"

#include "dap4test.h"
#define TOKENFLAGS (SXFLAG_ESCAPE|SXFLAG_ELIDETEXT)



/* Line 288 of yacc.c  */
#line 113 "dap4.tab.c"

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     DATASET_ = 258,
     _DATASET = 259,
     GROUP_ = 260,
     _GROUP = 261,
     ENUMERATION_ = 262,
     _ENUMERATION = 263,
     ENUMCONST_ = 264,
     _ENUMCONST = 265,
     NAMESPACE_ = 266,
     _NAMESPACE = 267,
     DIMENSION_ = 268,
     _DIMENSION = 269,
     DIM_ = 270,
     _DIM = 271,
     ENUM_ = 272,
     _ENUM = 273,
     MAP_ = 274,
     _MAP = 275,
     STRUCTURE_ = 276,
     _STRUCTURE = 277,
     VALUE_ = 278,
     _VALUE = 279,
     ATTRIBUTE_ = 280,
     _ATTRIBUTE = 281,
     CHAR_ = 282,
     _CHAR = 283,
     BYTE_ = 284,
     _BYTE = 285,
     INT8_ = 286,
     _INT8 = 287,
     UINT8_ = 288,
     _UINT8 = 289,
     INT16_ = 290,
     _INT16 = 291,
     UINT16_ = 292,
     _UINT16 = 293,
     INT32_ = 294,
     _INT32 = 295,
     UINT32_ = 296,
     _UINT32 = 297,
     INT64_ = 298,
     _INT64 = 299,
     UINT64_ = 300,
     _UINT64 = 301,
     FLOAT32_ = 302,
     _FLOAT32 = 303,
     FLOAT64_ = 304,
     _FLOAT64 = 305,
     STRING_ = 306,
     _STRING = 307,
     URL_ = 308,
     _URL = 309,
     OPAQUE_ = 310,
     _OPAQUE = 311,
     ATTR_BASE = 312,
     ATTR_BASETYPE = 313,
     ATTR_DAPVERSION = 314,
     ATTR_DDXVERSION = 315,
     ATTR_ENUM = 316,
     ATTR_HREF = 317,
     ATTR_NAME = 318,
     ATTR_NAMESPACE = 319,
     ATTR_SIZE = 320,
     ATTR_TYPE = 321,
     ATTR_VALUE = 322,
     ATTR_NS = 323,
     ATTR_XMLNS = 324,
     UNKNOWN_ATTR = 325,
     UNKNOWN_ELEMENT_ = 326,
     _UNKNOWN_ELEMENT = 327,
     TEXT = 328,
     ERROR = 329,
     UNKNOWN = 330,
     UNEXPECTED = 331
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

#ifndef YYPUSH_DECLS
#  define YYPUSH_DECLS
struct yypstate;
typedef struct yypstate yypstate;
enum { YYPUSH_MORE = 4 };

#if defined __STDC__ || defined __cplusplus
int yypush_parse (yypstate *yyps, int yypushed_char, YYSTYPE const *yypushed_val, Dap4EventHandler* handler);
#else
int yypush_parse ();
#endif

#if defined __STDC__ || defined __cplusplus
yypstate * yypstate_new (void);
#else
yypstate * yypstate_new ();
#endif
#if defined __STDC__ || defined __cplusplus
void yypstate_delete (yypstate *yyps);
#else
void yypstate_delete ();
#endif
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 236 "dap4.tab.c"
/* Unqualified %code blocks.  */

/* Line 344 of yacc.c  */
#line 19 "dap4.y"

void
dap4error(Dap4EventHandler* deh, const char* msg)
{
    fprintf(stderr,"%s\n",msg);
}




/* Line 344 of yacc.c  */
#line 252 "dap4.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   143

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  77
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  93
/* YYNRULES -- Number of states.  */
#define YYNSTATES  126

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   331

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     8,    13,    14,    17,    20,    23,    26,
      29,    32,    35,    36,    39,    42,    45,    48,    51,    56,
      59,    62,    64,    67,    71,    74,    77,    78,    81,    85,
      90,    93,    96,   100,   102,   104,   106,   108,   113,   115,
     117,   119,   121,   123,   125,   127,   129,   131,   133,   135,
     137,   139,   141,   143,   146,   148,   150,   152,   154,   156,
     158,   160,   162,   164,   166,   168,   170,   172,   174,   176,
     178,   179,   182,   185,   188,   192,   197,   198,   201,   204,
     207,   208,   211,   213,   219,   220,   223,   226,   229,   230,
     233,   237,   241,   242
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      78,     0,    -1,     3,    80,    81,     4,    -1,     5,    80,
      81,     6,    -1,    -1,    80,    63,    -1,    80,    59,    -1,
      80,    60,    -1,    80,    68,    -1,    80,    57,    -1,    80,
      69,    -1,    80,    70,    -1,    -1,    81,    82,    -1,    81,
      89,    -1,    81,    93,    -1,    81,   102,    -1,    81,    79,
      -1,     7,    83,    84,     8,    -1,    63,    58,    -1,    58,
      63,    -1,    85,    -1,    84,    85,    -1,     9,    86,    10,
      -1,    63,    67,    -1,    67,    63,    -1,    -1,    87,    88,
      -1,    11,    62,    12,    -1,    13,    90,   101,    14,    -1,
      63,    65,    -1,    65,    63,    -1,    15,    92,    16,    -1,
      63,    -1,    65,    -1,    94,    -1,    99,    -1,    95,    63,
      97,    96,    -1,    27,    -1,    29,    -1,    31,    -1,    33,
      -1,    35,    -1,    37,    -1,    39,    -1,    41,    -1,    43,
      -1,    45,    -1,    47,    -1,    49,    -1,    51,    -1,    53,
      -1,    55,    -1,    17,    61,    -1,    28,    -1,    30,    -1,
      32,    -1,    34,    -1,    36,    -1,    38,    -1,    40,    -1,
      42,    -1,    44,    -1,    46,    -1,    48,    -1,    50,    -1,
      52,    -1,    54,    -1,    56,    -1,    18,    -1,    -1,    97,
      91,    -1,    97,    98,    -1,    97,   102,    -1,    19,    63,
      20,    -1,    21,    63,   100,    22,    -1,    -1,   100,    91,
      -1,   100,    93,    -1,   100,   102,    -1,    -1,   101,   102,
      -1,   103,    -1,    25,   104,    87,   105,    26,    -1,    -1,
     104,    63,    -1,   104,    66,    -1,   104,    64,    -1,    -1,
     105,   106,    -1,    23,    67,    24,    -1,    23,   107,    24,
      -1,    -1,   107,    73,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    77,    77,    81,    84,    86,    87,    88,    89,    90,
      91,    92,    95,    97,    98,    99,   100,   101,   105,   109,
     110,   114,   115,   120,   124,   125,   128,   130,   134,   138,
     142,   143,   147,   151,   152,   156,   157,   162,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     204,   206,   207,   208,   212,   216,   219,   221,   222,   223,
     226,   228,   232,   236,   242,   244,   245,   246,   249,   251,
     255,   256,   259,   261
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DATASET_", "_DATASET", "GROUP_",
  "_GROUP", "ENUMERATION_", "_ENUMERATION", "ENUMCONST_", "_ENUMCONST",
  "NAMESPACE_", "_NAMESPACE", "DIMENSION_", "_DIMENSION", "DIM_", "_DIM",
  "ENUM_", "_ENUM", "MAP_", "_MAP", "STRUCTURE_", "_STRUCTURE", "VALUE_",
  "_VALUE", "ATTRIBUTE_", "_ATTRIBUTE", "CHAR_", "_CHAR", "BYTE_", "_BYTE",
  "INT8_", "_INT8", "UINT8_", "_UINT8", "INT16_", "_INT16", "UINT16_",
  "_UINT16", "INT32_", "_INT32", "UINT32_", "_UINT32", "INT64_", "_INT64",
  "UINT64_", "_UINT64", "FLOAT32_", "_FLOAT32", "FLOAT64_", "_FLOAT64",
  "STRING_", "_STRING", "URL_", "_URL", "OPAQUE_", "_OPAQUE", "ATTR_BASE",
  "ATTR_BASETYPE", "ATTR_DAPVERSION", "ATTR_DDXVERSION", "ATTR_ENUM",
  "ATTR_HREF", "ATTR_NAME", "ATTR_NAMESPACE", "ATTR_SIZE", "ATTR_TYPE",
  "ATTR_VALUE", "ATTR_NS", "ATTR_XMLNS", "UNKNOWN_ATTR",
  "UNKNOWN_ELEMENT_", "_UNKNOWN_ELEMENT", "TEXT", "ERROR", "UNKNOWN",
  "UNEXPECTED", "$accept", "dataset", "group", "group_attr_list",
  "group_body", "enumdef", "enum_attr_list", "enumconst_list", "enumconst",
  "enumconst_attr_list", "namespace_list", "namespace", "dimdef",
  "dimdef_attr_list", "dimref", "dimref_attr_list", "variable",
  "simplevariable", "atomictype_", "_atomictype", "variabledef", "mapref",
  "structurevariable", "structuredef", "metadatalist", "metadata",
  "attribute", "attribute_attr_list", "value_list", "value", "text_list", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    77,    78,    79,    80,    80,    80,    80,    80,    80,
      80,    80,    81,    81,    81,    81,    81,    81,    82,    83,
      83,    84,    84,    85,    86,    86,    87,    87,    88,    89,
      90,    90,    91,    92,    92,    93,    93,    94,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      97,    97,    97,    97,    98,    99,   100,   100,   100,   100,
     101,   101,   102,   103,   104,   104,   104,   104,   105,   105,
     106,   106,   107,   107
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     4,     0,     2,     2,     2,     2,     2,
       2,     2,     0,     2,     2,     2,     2,     2,     4,     2,
       2,     1,     2,     3,     2,     2,     0,     2,     3,     4,
       2,     2,     3,     1,     1,     1,     1,     4,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     2,     2,     2,     3,     4,     0,     2,     2,     2,
       0,     2,     1,     5,     0,     2,     2,     2,     0,     2,
       3,     3,     0,     2
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     4,     0,    12,     1,     9,     6,     7,     5,     8,
      10,    11,     0,     2,     4,     0,     0,     0,     0,    84,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    17,    13,    14,    15,    35,
       0,    36,    16,    82,    12,     0,     0,     0,     0,     0,
      80,    53,    76,    26,    70,     0,    20,    19,     0,     0,
      21,    30,    31,     0,     0,    85,    87,    86,    88,     0,
       3,     0,     0,     0,    18,    22,    29,    81,     0,    75,
      77,    78,    79,     0,    27,     0,    69,     0,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    71,    37,    72,    73,    24,    25,    23,
      33,    34,     0,     0,    92,    83,    89,     0,    32,    28,
       0,     0,    74,    90,    91,    93
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    35,     3,    12,    36,    47,    59,    60,    73,
      68,    84,    37,    50,    80,   112,    38,    39,    40,   104,
      69,   105,    41,    64,    63,    42,    43,    53,    85,   116,
     121
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -50
static const yytype_int8 yypact[] =
{
       8,   -50,     2,    73,   -50,   -50,   -50,   -50,   -50,   -50,
     -50,   -50,    -4,   -50,   -50,   -48,     6,   -39,   -10,   -50,
     -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,
     -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,
      14,   -50,   -50,   -50,    73,    16,    23,    48,    18,    22,
     -50,   -50,   -50,    36,   -50,    -1,   -50,   -50,   -49,    54,
     -50,   -50,   -50,    -6,    76,   -50,   -50,   -50,    78,    40,
     -50,    20,    32,    94,   -50,   -50,   -50,   -50,    10,   -50,
     -50,   -50,   -50,    44,   -50,    41,   -50,    45,   -50,   -50,
     -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,
     -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,
     -50,   -50,    96,    98,    47,   -50,   -50,   100,   -50,   -50,
      92,   -17,   -50,   -50,   -50,   -50
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -50,   -50,   -50,   104,    80,   -50,   -50,   -50,    63,   -50,
     -50,   -50,   -50,   -50,    57,   -50,    64,   -50,   -50,   -50,
     -50,   -50,   -50,   -50,   -50,    -3,   -50,   -50,   -50,   -50,
     -50
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      13,    14,     4,    15,    14,    70,    15,   124,    76,    16,
      45,     1,    16,    17,    71,    46,    17,    18,    72,    19,
      18,    19,    51,    20,    19,    21,    20,    22,    21,    23,
      22,    24,    23,    25,    24,    26,    25,    27,    26,    28,
      27,    29,    28,    30,    29,    31,    30,    32,    31,    33,
      32,    34,    33,    52,    34,    78,   125,    58,    86,    87,
      77,    82,    74,    58,   114,    19,   106,   115,    88,    48,
      89,    49,    90,   110,    91,   111,    92,    54,    93,    56,
      94,    57,    95,    61,    96,    62,    97,   107,    98,    83,
      99,    78,   100,    17,   101,   108,   102,    18,    79,    65,
      66,    19,    67,    20,   109,    21,   113,    22,   117,    23,
     119,    24,   118,    25,   120,    26,   123,    27,    44,    28,
     122,    29,    75,    30,    55,    31,   103,    32,    81,    33,
       5,    34,     6,     7,     0,     0,     8,     0,     0,     0,
       0,     9,    10,    11
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-50))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int8 yycheck[] =
{
       4,     5,     0,     7,     5,     6,     7,    24,    14,    13,
      58,     3,    13,    17,    63,    63,    17,    21,    67,    25,
      21,    25,    61,    27,    25,    29,    27,    31,    29,    33,
      31,    35,    33,    37,    35,    39,    37,    41,    39,    43,
      41,    45,    43,    47,    45,    49,    47,    51,    49,    53,
      51,    55,    53,    63,    55,    15,    73,     9,    18,    19,
      63,    64,     8,     9,    23,    25,    69,    26,    28,    63,
      30,    65,    32,    63,    34,    65,    36,    63,    38,    63,
      40,    58,    42,    65,    44,    63,    46,    67,    48,    11,
      50,    15,    52,    17,    54,    63,    56,    21,    22,    63,
      64,    25,    66,    27,    10,    29,    62,    31,    63,    33,
      12,    35,    16,    37,    67,    39,    24,    41,    14,    43,
      20,    45,    59,    47,    44,    49,    69,    51,    64,    53,
      57,    55,    59,    60,    -1,    -1,    63,    -1,    -1,    -1,
      -1,    68,    69,    70
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    78,    80,     0,    57,    59,    60,    63,    68,
      69,    70,    81,     4,     5,     7,    13,    17,    21,    25,
      27,    29,    31,    33,    35,    37,    39,    41,    43,    45,
      47,    49,    51,    53,    55,    79,    82,    89,    93,    94,
      95,    99,   102,   103,    80,    58,    63,    83,    63,    65,
      90,    61,    63,   104,    63,    81,    63,    58,     9,    84,
      85,    65,    63,   101,   100,    63,    64,    66,    87,    97,
       6,    63,    67,    86,     8,    85,    14,   102,    15,    22,
      91,    93,   102,    11,    88,   105,    18,    19,    28,    30,
      32,    34,    36,    38,    40,    42,    44,    46,    48,    50,
      52,    54,    56,    91,    96,    98,   102,    67,    63,    10,
      63,    65,    92,    62,    23,    26,   106,    63,    16,    12,
      67,   107,    20,    24,    24,    73
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (handler, YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (&yylval, YYLEX_PARAM)
#else
# define YYLEX yylex (&yylval)
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, handler); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, Dap4EventHandler* handler)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, handler)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    Dap4EventHandler* handler;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (handler);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      case 3: /* "DATASET_" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 917 "dap4.tab.c"
	break;
      case 4: /* "_DATASET" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 926 "dap4.tab.c"
	break;
      case 5: /* "GROUP_" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 935 "dap4.tab.c"
	break;
      case 6: /* "_GROUP" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 944 "dap4.tab.c"
	break;
      case 7: /* "ENUMERATION_" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 953 "dap4.tab.c"
	break;
      case 8: /* "_ENUMERATION" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 962 "dap4.tab.c"
	break;
      case 9: /* "ENUMCONST_" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 971 "dap4.tab.c"
	break;
      case 10: /* "_ENUMCONST" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 980 "dap4.tab.c"
	break;
      case 11: /* "NAMESPACE_" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 989 "dap4.tab.c"
	break;
      case 12: /* "_NAMESPACE" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 998 "dap4.tab.c"
	break;
      case 13: /* "DIMENSION_" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1007 "dap4.tab.c"
	break;
      case 14: /* "_DIMENSION" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1016 "dap4.tab.c"
	break;
      case 15: /* "DIM_" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1025 "dap4.tab.c"
	break;
      case 16: /* "_DIM" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1034 "dap4.tab.c"
	break;
      case 17: /* "ENUM_" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1043 "dap4.tab.c"
	break;
      case 18: /* "_ENUM" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1052 "dap4.tab.c"
	break;
      case 19: /* "MAP_" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1061 "dap4.tab.c"
	break;
      case 20: /* "_MAP" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1070 "dap4.tab.c"
	break;
      case 21: /* "STRUCTURE_" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1079 "dap4.tab.c"
	break;
      case 22: /* "_STRUCTURE" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1088 "dap4.tab.c"
	break;
      case 23: /* "VALUE_" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1097 "dap4.tab.c"
	break;
      case 24: /* "_VALUE" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1106 "dap4.tab.c"
	break;
      case 25: /* "ATTRIBUTE_" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1115 "dap4.tab.c"
	break;
      case 26: /* "_ATTRIBUTE" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1124 "dap4.tab.c"
	break;
      case 27: /* "CHAR_" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1133 "dap4.tab.c"
	break;
      case 28: /* "_CHAR" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1142 "dap4.tab.c"
	break;
      case 29: /* "BYTE_" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1151 "dap4.tab.c"
	break;
      case 30: /* "_BYTE" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1160 "dap4.tab.c"
	break;
      case 31: /* "INT8_" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1169 "dap4.tab.c"
	break;
      case 32: /* "_INT8" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1178 "dap4.tab.c"
	break;
      case 33: /* "UINT8_" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1187 "dap4.tab.c"
	break;
      case 34: /* "_UINT8" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1196 "dap4.tab.c"
	break;
      case 35: /* "INT16_" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1205 "dap4.tab.c"
	break;
      case 36: /* "_INT16" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1214 "dap4.tab.c"
	break;
      case 37: /* "UINT16_" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1223 "dap4.tab.c"
	break;
      case 38: /* "_UINT16" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1232 "dap4.tab.c"
	break;
      case 39: /* "INT32_" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1241 "dap4.tab.c"
	break;
      case 40: /* "_INT32" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1250 "dap4.tab.c"
	break;
      case 41: /* "UINT32_" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1259 "dap4.tab.c"
	break;
      case 42: /* "_UINT32" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1268 "dap4.tab.c"
	break;
      case 43: /* "INT64_" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1277 "dap4.tab.c"
	break;
      case 44: /* "_INT64" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1286 "dap4.tab.c"
	break;
      case 45: /* "UINT64_" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1295 "dap4.tab.c"
	break;
      case 46: /* "_UINT64" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1304 "dap4.tab.c"
	break;
      case 47: /* "FLOAT32_" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1313 "dap4.tab.c"
	break;
      case 48: /* "_FLOAT32" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1322 "dap4.tab.c"
	break;
      case 49: /* "FLOAT64_" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1331 "dap4.tab.c"
	break;
      case 50: /* "_FLOAT64" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1340 "dap4.tab.c"
	break;
      case 51: /* "STRING_" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1349 "dap4.tab.c"
	break;
      case 52: /* "_STRING" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1358 "dap4.tab.c"
	break;
      case 53: /* "URL_" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1367 "dap4.tab.c"
	break;
      case 54: /* "_URL" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1376 "dap4.tab.c"
	break;
      case 55: /* "OPAQUE_" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1385 "dap4.tab.c"
	break;
      case 56: /* "_OPAQUE" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1394 "dap4.tab.c"
	break;
      case 57: /* "ATTR_BASE" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1403 "dap4.tab.c"
	break;
      case 58: /* "ATTR_BASETYPE" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1412 "dap4.tab.c"
	break;
      case 59: /* "ATTR_DAPVERSION" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1421 "dap4.tab.c"
	break;
      case 60: /* "ATTR_DDXVERSION" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1430 "dap4.tab.c"
	break;
      case 61: /* "ATTR_ENUM" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1439 "dap4.tab.c"
	break;
      case 62: /* "ATTR_HREF" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1448 "dap4.tab.c"
	break;
      case 63: /* "ATTR_NAME" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1457 "dap4.tab.c"
	break;
      case 64: /* "ATTR_NAMESPACE" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1466 "dap4.tab.c"
	break;
      case 65: /* "ATTR_SIZE" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1475 "dap4.tab.c"
	break;
      case 66: /* "ATTR_TYPE" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1484 "dap4.tab.c"
	break;
      case 67: /* "ATTR_VALUE" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1493 "dap4.tab.c"
	break;
      case 68: /* "ATTR_NS" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1502 "dap4.tab.c"
	break;
      case 69: /* "ATTR_XMLNS" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1511 "dap4.tab.c"
	break;
      case 70: /* "UNKNOWN_ATTR" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1520 "dap4.tab.c"
	break;
      case 71: /* "UNKNOWN_ELEMENT_" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1529 "dap4.tab.c"
	break;
      case 72: /* "_UNKNOWN_ELEMENT" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1538 "dap4.tab.c"
	break;
      case 73: /* "TEXT" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1547 "dap4.tab.c"
	break;
      case 74: /* "ERROR" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1556 "dap4.tab.c"
	break;
      case 75: /* "UNKNOWN" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1565 "dap4.tab.c"
	break;
      case 76: /* "UNEXPECTED" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1574 "dap4.tab.c"
	break;
      case 78: /* "dataset" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1583 "dap4.tab.c"
	break;
      case 79: /* "group" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1592 "dap4.tab.c"
	break;
      case 80: /* "group_attr_list" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1601 "dap4.tab.c"
	break;
      case 81: /* "group_body" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1610 "dap4.tab.c"
	break;
      case 82: /* "enumdef" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1619 "dap4.tab.c"
	break;
      case 83: /* "enum_attr_list" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1628 "dap4.tab.c"
	break;
      case 84: /* "enumconst_list" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1637 "dap4.tab.c"
	break;
      case 85: /* "enumconst" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1646 "dap4.tab.c"
	break;
      case 86: /* "enumconst_attr_list" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1655 "dap4.tab.c"
	break;
      case 87: /* "namespace_list" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1664 "dap4.tab.c"
	break;
      case 88: /* "namespace" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1673 "dap4.tab.c"
	break;
      case 89: /* "dimdef" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1682 "dap4.tab.c"
	break;
      case 90: /* "dimdef_attr_list" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1691 "dap4.tab.c"
	break;
      case 91: /* "dimref" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1700 "dap4.tab.c"
	break;
      case 92: /* "dimref_attr_list" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1709 "dap4.tab.c"
	break;
      case 93: /* "variable" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1718 "dap4.tab.c"
	break;
      case 94: /* "simplevariable" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1727 "dap4.tab.c"
	break;
      case 95: /* "atomictype_" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1736 "dap4.tab.c"
	break;
      case 96: /* "_atomictype" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1745 "dap4.tab.c"
	break;
      case 97: /* "variabledef" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1754 "dap4.tab.c"
	break;
      case 98: /* "mapref" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1763 "dap4.tab.c"
	break;
      case 99: /* "structurevariable" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1772 "dap4.tab.c"
	break;
      case 100: /* "structuredef" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1781 "dap4.tab.c"
	break;
      case 101: /* "metadatalist" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1790 "dap4.tab.c"
	break;
      case 102: /* "metadata" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1799 "dap4.tab.c"
	break;
      case 103: /* "attribute" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1808 "dap4.tab.c"
	break;
      case 104: /* "attribute_attr_list" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1817 "dap4.tab.c"
	break;
      case 105: /* "value_list" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1826 "dap4.tab.c"
	break;
      case 106: /* "value" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1835 "dap4.tab.c"
	break;
      case 107: /* "text_list" */

/* Line 819 of yacc.c  */
#line 12 "dap4.y"
	{if((*yyvaluep) != NULL) fprintf(yyoutput, "%s", saxeventtypename((*yyvaluep)->event)); };

/* Line 819 of yacc.c  */
#line 1844 "dap4.tab.c"
	break;
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, Dap4EventHandler* handler)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, handler)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    Dap4EventHandler* handler;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep, handler);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule, Dap4EventHandler* handler)
#else
static void
yy_reduce_print (yyvsp, yyrule, handler)
    YYSTYPE *yyvsp;
    int yyrule;
    Dap4EventHandler* handler;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       , handler);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule, handler); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
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

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

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

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, Dap4EventHandler* handler)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, handler)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    Dap4EventHandler* handler;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (handler);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


struct yypstate
  {
    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;
    /* Used to determine if this is the first time this instance has
       been used.  */
    int yynew;
  };

/* Initialize the parser data structure.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
yypstate *
yypstate_new (void)
#else
yypstate *
yypstate_new ()

#endif
{
  yypstate *yyps;
  yyps = (yypstate *) malloc (sizeof *yyps);
  if (!yyps)
    return 0;
  yyps->yynew = 1;
  return yyps;
}

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void
yypstate_delete (yypstate *yyps)
#else
void
yypstate_delete (yyps)
    yypstate *yyps;
#endif
{
#ifndef yyoverflow
  /* If the stack was reallocated but the parse did not complete, then the
     stack still needs to be freed.  */
  if (!yyps->yynew && yyps->yyss != yyps->yyssa)
    YYSTACK_FREE (yyps->yyss);
#endif
  free (yyps);
}

#define dap4nerrs yyps->dap4nerrs
#define yystate yyps->yystate
#define yyerrstatus yyps->yyerrstatus
#define yyssa yyps->yyssa
#define yyss yyps->yyss
#define yyssp yyps->yyssp
#define yyvsa yyps->yyvsa
#define yyvs yyps->yyvs
#define yyvsp yyps->yyvsp
#define yystacksize yyps->yystacksize


/*---------------.
| yypush_parse.  |
`---------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yypush_parse (yypstate *yyps, int yypushed_char, YYSTYPE const *yypushed_val, Dap4EventHandler* handler)
#else
int
yypush_parse (yyps, yypushed_char, yypushed_val, handler)
    yypstate *yyps;
    int yypushed_char;
    YYSTYPE const *yypushed_val;
    Dap4EventHandler* handler;
#endif
{
/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  if (!yyps->yynew)
    {
      yyn = yypact[yystate];
      goto yyread_pushed_token;
    }

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

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
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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
      if (!yyps->yynew)
        {
          YYDPRINTF ((stderr, "Return for a new token:\n"));
          yyresult = YYPUSH_MORE;
          goto yypushreturn;
        }
      yyps->yynew = 0;
yyread_pushed_token:
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yypushed_char;
      if (yypushed_val)
        yylval = *yypushed_val;
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
      

/* Line 1806 of yacc.c  */
#line 2588 "dap4.tab.c"
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

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (handler, YY_("syntax error"));
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
        yyerror (handler, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



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
		      yytoken, &yylval, handler);
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

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


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, handler);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (handler, YY_("memory exhausted"));
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
                  yytoken, &yylval, handler);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, handler);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  yyps->yynew = 1;

yypushreturn:
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 2067 of yacc.c  */
#line 264 "dap4.y"


