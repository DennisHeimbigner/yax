/* A Bison parser, made by GNU Bison 2.4.2.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2006, 2009-2010 Free Software
   Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0

/* Substitute the variable and function names.  */
#define yyparse         dap4parse
#define yylex           dap4lex
#define yyerror         dap4error
#define yylval          dap4lval
#define yychar          dap4char
#define yydebug         dap4debug
#define yynerrs         dap4nerrs


/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 7 "dap4.y"

#include "yxlist.h"
#include "yax.h"
#include "dap4parse.h"

#define YYDEBUG 1
#define TRACE
#define TEST

#ifdef TEST
#define CHECK(x)
#else
#define CHECK(x) {if((x)==NULL) YYABORT;}
#endif

/* Forward */

union YYSTYPE;

int dap4lex(YYSTYPE* lvalp, DAP4parser* parser);
int dap4error(DAP4parser* state, const char* msg);



/* Line 189 of yacc.c  */
#line 105 "dap4.tab.c"

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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     GROUP_ = 258,
     _GROUP = 259,
     ENUMERATION_ = 260,
     _ENUMERATION = 261,
     ENUMCONST_ = 262,
     _ENUMCONST = 263,
     NAMESPACE_ = 264,
     _NAMESPACE = 265,
     DIMENSION_ = 266,
     _DIMENSION = 267,
     DIM_ = 268,
     _DIM = 269,
     ENUM_ = 270,
     _ENUM = 271,
     MAP_ = 272,
     _MAP = 273,
     STRUCTURE_ = 274,
     _STRUCTURE = 275,
     VALUE_ = 276,
     _VALUE = 277,
     ATTRIBUTE_ = 278,
     _ATTRIBUTE = 279,
     CHAR_ = 280,
     _CHAR = 281,
     BYTE_ = 282,
     _BYTE = 283,
     INT8_ = 284,
     _INT8 = 285,
     UINT8_ = 286,
     _UINT8 = 287,
     INT16_ = 288,
     _INT16 = 289,
     UINT16_ = 290,
     _UINT16 = 291,
     INT32_ = 292,
     _INT32 = 293,
     UINT32_ = 294,
     _UINT32 = 295,
     INT64_ = 296,
     _INT64 = 297,
     UINT64_ = 298,
     _UINT64 = 299,
     FLOAT32_ = 300,
     _FLOAT32 = 301,
     FLOAT64_ = 302,
     _FLOAT64 = 303,
     STRING_ = 304,
     _STRING = 305,
     URL_ = 306,
     _URL = 307,
     OPAQUE_ = 308,
     _OPAQUE = 309,
     ATTR_BASE = 310,
     ATTR_BASETYPE = 311,
     ATTR_DAPVERSION = 312,
     ATTR_DDXVERSION = 313,
     ATTR_ENUM = 314,
     ATTR_HREF = 315,
     ATTR_NAME = 316,
     ATTR_NAMESPACE = 317,
     ATTR_SIZE = 318,
     ATTR_TYPE = 319,
     ATTR_VALUE = 320,
     ATTR_NS = 321,
     ATTR_XMLNS = 322,
     UNKNOWN_ATTR = 323,
     UNKNOWN_ELEMENT_ = 324,
     _UNKNOWN_ELEMENT = 325,
     TEXT = 326,
     OTHERXML = 327,
     ERROR = 328,
     UNKNOWN = 329,
     UNEXPECTED = 330
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 31 "dap4.y"

   void* object;
   YXlist* list;
   yax_token token;



/* Line 214 of yacc.c  */
#line 224 "dap4.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 236 "dap4.tab.c"

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
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

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   117

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  76
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  92
/* YYNRULES -- Number of states.  */
#define YYNSTATES  122

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   330

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
      75
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     8,     9,    12,    15,    18,    21,    24,
      27,    30,    31,    34,    37,    40,    43,    46,    51,    54,
      57,    59,    62,    66,    69,    72,    73,    76,    80,    85,
      88,    91,    95,    97,    99,   101,   103,   108,   110,   112,
     114,   116,   118,   120,   122,   124,   126,   128,   130,   132,
     134,   136,   138,   141,   143,   145,   147,   149,   151,   153,
     155,   157,   159,   161,   163,   165,   167,   169,   171,   173,
     174,   177,   180,   183,   187,   192,   193,   196,   199,   202,
     203,   206,   208,   210,   216,   217,   220,   223,   226,   229,
     230,   233,   237
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      77,     0,    -1,     3,    78,    79,     4,    -1,    -1,    78,
      61,    -1,    78,    57,    -1,    78,    58,    -1,    78,    66,
      -1,    78,    55,    -1,    78,    67,    -1,    78,    68,    -1,
      -1,    79,    80,    -1,    79,    87,    -1,    79,    91,    -1,
      79,   100,    -1,    79,    77,    -1,     5,    81,    82,     6,
      -1,    61,    56,    -1,    56,    61,    -1,    83,    -1,    82,
      83,    -1,     7,    84,     8,    -1,    61,    65,    -1,    65,
      61,    -1,    -1,    85,    86,    -1,     9,    60,    10,    -1,
      11,    88,    99,    12,    -1,    61,    63,    -1,    63,    61,
      -1,    13,    90,    14,    -1,    61,    -1,    63,    -1,    92,
      -1,    97,    -1,    93,    61,    95,    94,    -1,    25,    -1,
      27,    -1,    29,    -1,    31,    -1,    33,    -1,    35,    -1,
      37,    -1,    39,    -1,    41,    -1,    43,    -1,    45,    -1,
      47,    -1,    49,    -1,    51,    -1,    53,    -1,    15,    59,
      -1,    26,    -1,    28,    -1,    30,    -1,    32,    -1,    34,
      -1,    36,    -1,    38,    -1,    40,    -1,    42,    -1,    44,
      -1,    46,    -1,    48,    -1,    50,    -1,    52,    -1,    54,
      -1,    16,    -1,    -1,    95,    89,    -1,    95,    96,    -1,
      95,   100,    -1,    17,    61,    18,    -1,    19,    61,    98,
      20,    -1,    -1,    98,    89,    -1,    98,    91,    -1,    98,
     100,    -1,    -1,    99,   100,    -1,   101,    -1,   105,    -1,
      23,   102,    85,   103,    24,    -1,    -1,   102,    61,    -1,
     102,    64,    -1,   102,    62,    -1,   102,    65,    -1,    -1,
     103,   104,    -1,    21,    65,    22,    -1,    72,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   108,   108,   113,   114,   116,   118,   120,   122,   124,
     126,   132,   133,   135,   137,   139,   141,   146,   151,   156,
     164,   166,   172,   177,   182,   191,   192,   197,   202,   207,
     212,   220,   225,   229,   236,   237,   242,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   287,
     288,   290,   292,   297,   302,   308,   309,   311,   313,   319,
     320,   325,   326,   330,   339,   340,   342,   344,   346,   352,
     353,   357,   361
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "GROUP_", "_GROUP", "ENUMERATION_",
  "_ENUMERATION", "ENUMCONST_", "_ENUMCONST", "NAMESPACE_", "_NAMESPACE",
  "DIMENSION_", "_DIMENSION", "DIM_", "_DIM", "ENUM_", "_ENUM", "MAP_",
  "_MAP", "STRUCTURE_", "_STRUCTURE", "VALUE_", "_VALUE", "ATTRIBUTE_",
  "_ATTRIBUTE", "CHAR_", "_CHAR", "BYTE_", "_BYTE", "INT8_", "_INT8",
  "UINT8_", "_UINT8", "INT16_", "_INT16", "UINT16_", "_UINT16", "INT32_",
  "_INT32", "UINT32_", "_UINT32", "INT64_", "_INT64", "UINT64_", "_UINT64",
  "FLOAT32_", "_FLOAT32", "FLOAT64_", "_FLOAT64", "STRING_", "_STRING",
  "URL_", "_URL", "OPAQUE_", "_OPAQUE", "ATTR_BASE", "ATTR_BASETYPE",
  "ATTR_DAPVERSION", "ATTR_DDXVERSION", "ATTR_ENUM", "ATTR_HREF",
  "ATTR_NAME", "ATTR_NAMESPACE", "ATTR_SIZE", "ATTR_TYPE", "ATTR_VALUE",
  "ATTR_NS", "ATTR_XMLNS", "UNKNOWN_ATTR", "UNKNOWN_ELEMENT_",
  "_UNKNOWN_ELEMENT", "TEXT", "OTHERXML", "ERROR", "UNKNOWN", "UNEXPECTED",
  "$accept", "group", "group_attr_list", "group_body", "enumdef",
  "enum_attr_list", "enumconst_list", "enumconst", "enumconst_attr_list",
  "namespace_list", "namespace", "dimdef", "dimdef_attr_list", "dimref",
  "dimref_attr_list", "variable", "simplevariable", "atomictype_",
  "_atomictype", "variabledef", "mapref", "structurevariable",
  "structuredef", "metadatalist", "metadata", "attribute",
  "attribute_attr_list", "attribute_value_list", "attribute_value",
  "otherxml", 0
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
     325,   326,   327,   328,   329,   330
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    76,    77,    78,    78,    78,    78,    78,    78,    78,
      78,    79,    79,    79,    79,    79,    79,    80,    81,    81,
      82,    82,    83,    84,    84,    85,    85,    86,    87,    88,
      88,    89,    90,    90,    91,    91,    92,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    95,
      95,    95,    95,    96,    97,    98,    98,    98,    98,    99,
      99,   100,   100,   101,   102,   102,   102,   102,   102,   103,
     103,   104,   105
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     0,     2,     2,     2,     2,     2,     2,
       2,     0,     2,     2,     2,     2,     2,     4,     2,     2,
       1,     2,     3,     2,     2,     0,     2,     3,     4,     2,
       2,     3,     1,     1,     1,     1,     4,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       2,     2,     2,     3,     4,     0,     2,     2,     2,     0,
       2,     1,     1,     5,     0,     2,     2,     2,     2,     0,
       2,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     3,     0,    11,     1,     8,     5,     6,     4,     7,
       9,    10,     0,     2,     0,     0,     0,     0,    84,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    92,    16,    12,    13,    14,    34,
       0,    35,    15,    81,    82,     0,     0,     0,     0,     0,
      79,    52,    75,    25,    69,    19,    18,     0,     0,    20,
      29,    30,     0,     0,    85,    87,    86,    88,    89,     0,
       0,     0,     0,    17,    21,    28,    80,     0,    74,    76,
      77,    78,     0,    26,     0,    68,     0,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    70,    36,    71,    72,    23,    24,    22,    32,
      33,     0,     0,     0,    83,    90,     0,    31,    27,     0,
      73,    91
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,    12,    36,    47,    58,    59,    72,    68,
      83,    37,    50,    79,   111,    38,    39,    40,   103,    69,
     104,    41,    63,    62,    42,    43,    53,    84,   115,    44
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -57
static const yytype_int8 yypact[] =
{
      12,   -57,    19,    -1,   -57,   -57,   -57,   -57,   -57,   -57,
     -57,   -57,    -3,   -57,   -52,   -56,    -4,     3,   -57,   -57,
     -57,   -57,   -57,   -57,   -57,   -57,   -57,   -57,   -57,   -57,
     -57,   -57,   -57,   -57,   -57,   -57,   -57,   -57,   -57,   -57,
      15,   -57,   -57,   -57,   -57,    17,    24,    75,    21,    25,
     -57,   -57,   -57,    39,   -57,   -57,   -57,   -55,   100,   -57,
     -57,   -57,    -9,    -2,   -57,   -57,   -57,   -57,    79,    45,
      27,    29,    86,   -57,   -57,   -57,   -57,    11,   -57,   -57,
     -57,   -57,    36,   -57,    81,   -57,    37,   -57,   -57,   -57,
     -57,   -57,   -57,   -57,   -57,   -57,   -57,   -57,   -57,   -57,
     -57,   -57,   -57,   -57,   -57,   -57,   -57,   -57,   -57,   -57,
     -57,    94,    99,    46,   -57,   -57,    92,   -57,   -57,    90,
     -57,   -57
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -57,   101,   -57,   -57,   -57,   -57,   -57,    56,   -57,   -57,
     -57,   -57,   -57,    47,   -57,    52,   -57,   -57,   -57,   -57,
     -57,   -57,   -57,   -57,   -10,   -57,   -57,   -57,   -57,   -57
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
       1,    13,    14,    75,    45,    48,    70,    49,    15,    46,
      71,    77,    16,    16,    18,     1,    17,    17,    78,     4,
      18,    18,    19,    19,    20,    20,    21,    21,    22,    22,
      23,    23,    24,    24,    25,    25,    26,    26,    27,    27,
      28,    28,    29,    29,    30,    30,    31,    31,    32,    32,
      33,    33,    76,    81,     5,    51,     6,     7,    77,   105,
       8,    85,    86,    34,    52,     9,    10,    11,    18,    34,
      34,    87,   109,    88,   110,    89,    54,    90,    55,    91,
      56,    92,    57,    93,    60,    94,    61,    95,    82,    96,
     107,    97,   106,    98,   108,    99,   112,   100,   116,   101,
      64,    65,   113,    66,    67,   114,    73,    57,   117,   118,
     120,   119,   121,    35,    74,    80,   102,    34
};

static const yytype_uint8 yycheck[] =
{
       3,     4,     5,    12,    56,    61,    61,    63,    11,    61,
      65,    13,    15,    15,    23,     3,    19,    19,    20,     0,
      23,    23,    25,    25,    27,    27,    29,    29,    31,    31,
      33,    33,    35,    35,    37,    37,    39,    39,    41,    41,
      43,    43,    45,    45,    47,    47,    49,    49,    51,    51,
      53,    53,    62,    63,    55,    59,    57,    58,    13,    69,
      61,    16,    17,    72,    61,    66,    67,    68,    23,    72,
      72,    26,    61,    28,    63,    30,    61,    32,    61,    34,
      56,    36,     7,    38,    63,    40,    61,    42,     9,    44,
      61,    46,    65,    48,     8,    50,    60,    52,    61,    54,
      61,    62,    21,    64,    65,    24,     6,     7,    14,    10,
      18,    65,    22,    12,    58,    63,    69,    72
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    77,    78,     0,    55,    57,    58,    61,    66,
      67,    68,    79,     4,     5,    11,    15,    19,    23,    25,
      27,    29,    31,    33,    35,    37,    39,    41,    43,    45,
      47,    49,    51,    53,    72,    77,    80,    87,    91,    92,
      93,    97,   100,   101,   105,    56,    61,    81,    61,    63,
      88,    59,    61,   102,    61,    61,    56,     7,    82,    83,
      63,    61,    99,    98,    61,    62,    64,    65,    85,    95,
      61,    65,    84,     6,    83,    12,   100,    13,    20,    89,
      91,   100,     9,    86,   103,    16,    17,    26,    28,    30,
      32,    34,    36,    38,    40,    42,    44,    46,    48,    50,
      52,    54,    89,    94,    96,   100,    65,    61,     8,    61,
      63,    90,    60,    21,    24,   104,    61,    14,    10,    65,
      18,    22
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
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (parser, YY_("syntax error: cannot back up")); \
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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (&yylval, YYLEX_PARAM)
#else
# define YYLEX yylex (&yylval, parser)
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
		  Type, Value, parser); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, DAP4parser* parser)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, parser)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    DAP4parser* parser;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (parser);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, DAP4parser* parser)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, parser)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    DAP4parser* parser;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep, parser);
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
yy_reduce_print (YYSTYPE *yyvsp, int yyrule, DAP4parser* parser)
#else
static void
yy_reduce_print (yyvsp, yyrule, parser)
    YYSTYPE *yyvsp;
    int yyrule;
    DAP4parser* parser;
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
		       		       , parser);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule, parser); \
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, DAP4parser* parser)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, parser)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    DAP4parser* parser;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (parser);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (DAP4parser* parser);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */





/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (DAP4parser* parser)
#else
int
yyparse (parser)
    DAP4parser* parser;
#endif
#endif
{
/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
        case 2:

/* Line 1464 of yacc.c  */
#line 109 "dap4.y"
    {(yyval.object)=d4group(parser,(yyvsp[(2) - (4)].list),(yyvsp[(3) - (4)].list)); CHECK((yyval.object)); ;}
    break;

  case 3:

/* Line 1464 of yacc.c  */
#line 113 "dap4.y"
    {(yyval.list)=d4attrlist(parser,NULL,emptytoken);;}
    break;

  case 4:

/* Line 1464 of yacc.c  */
#line 115 "dap4.y"
    {(yyval.list)=d4attrlist(parser,(yyvsp[(1) - (2)].list),(yyvsp[(2) - (2)].token));;}
    break;

  case 5:

/* Line 1464 of yacc.c  */
#line 117 "dap4.y"
    {(yyval.list)=d4attrlist(parser,(yyvsp[(1) - (2)].list),(yyvsp[(2) - (2)].token));;}
    break;

  case 6:

/* Line 1464 of yacc.c  */
#line 119 "dap4.y"
    {(yyval.list)=d4attrlist(parser,(yyvsp[(1) - (2)].list),(yyvsp[(2) - (2)].token));;}
    break;

  case 7:

/* Line 1464 of yacc.c  */
#line 121 "dap4.y"
    {(yyval.list)=d4attrlist(parser,(yyvsp[(1) - (2)].list),(yyvsp[(2) - (2)].token));;}
    break;

  case 8:

/* Line 1464 of yacc.c  */
#line 123 "dap4.y"
    {(yyval.list)=d4attrlist(parser,(yyvsp[(1) - (2)].list),(yyvsp[(2) - (2)].token));;}
    break;

  case 9:

/* Line 1464 of yacc.c  */
#line 125 "dap4.y"
    {(yyval.list)=d4attrlist(parser,(yyvsp[(1) - (2)].list),(yyvsp[(2) - (2)].token));;}
    break;

  case 10:

/* Line 1464 of yacc.c  */
#line 127 "dap4.y"
    {(yyval.list)=d4attrlist(parser,(yyvsp[(1) - (2)].list),(yyvsp[(2) - (2)].token));;}
    break;

  case 11:

/* Line 1464 of yacc.c  */
#line 132 "dap4.y"
    {(yyval.list)=d4list(parser,NULL,NULL);;}
    break;

  case 12:

/* Line 1464 of yacc.c  */
#line 134 "dap4.y"
    {(yyval.list)=d4list(parser,(yyvsp[(1) - (2)].list),(yyvsp[(2) - (2)].object));;}
    break;

  case 13:

/* Line 1464 of yacc.c  */
#line 136 "dap4.y"
    {(yyval.list)=d4list(parser,(yyvsp[(1) - (2)].list),(yyvsp[(2) - (2)].object));;}
    break;

  case 14:

/* Line 1464 of yacc.c  */
#line 138 "dap4.y"
    {(yyval.list)=d4list(parser,(yyvsp[(1) - (2)].list),(yyvsp[(2) - (2)].object));;}
    break;

  case 15:

/* Line 1464 of yacc.c  */
#line 140 "dap4.y"
    {(yyval.list)=d4list(parser,(yyvsp[(1) - (2)].list),(yyvsp[(2) - (2)].object));;}
    break;

  case 16:

/* Line 1464 of yacc.c  */
#line 142 "dap4.y"
    {(yyval.list)=d4list(parser,(yyvsp[(1) - (2)].list),(yyvsp[(2) - (2)].object));;}
    break;

  case 17:

/* Line 1464 of yacc.c  */
#line 147 "dap4.y"
    {(yyval.object)=d4enumdef(parser,(yyvsp[(2) - (4)].list),(yyvsp[(3) - (4)].list)); CHECK((yyval.object));;}
    break;

  case 18:

/* Line 1464 of yacc.c  */
#line 152 "dap4.y"
    {(yyval.list)=d4attrlist(parser,NULL,emptytoken);
		d4attrlist(parser,(yyval.list),(yyvsp[(1) - (2)].token));
		d4attrlist(parser,(yyval.list),(yyvsp[(2) - (2)].token));
	    ;}
    break;

  case 19:

/* Line 1464 of yacc.c  */
#line 157 "dap4.y"
    {(yyval.list)=d4attrlist(parser,NULL,emptytoken);
		d4attrlist(parser,(yyval.list),(yyvsp[(1) - (2)].token));
		d4attrlist(parser,(yyval.list),(yyvsp[(2) - (2)].token));
	    ;}
    break;

  case 20:

/* Line 1464 of yacc.c  */
#line 165 "dap4.y"
    {(yyval.list)=d4list(parser,NULL,NULL);;}
    break;

  case 21:

/* Line 1464 of yacc.c  */
#line 167 "dap4.y"
    {(yyval.list)=d4list(parser,(yyvsp[(1) - (2)].list),(yyvsp[(2) - (2)].object));;}
    break;

  case 22:

/* Line 1464 of yacc.c  */
#line 173 "dap4.y"
    {(yyval.object)=d4enumconst(parser,(yyvsp[(2) - (3)].list)); CHECK((yyval.object));;}
    break;

  case 23:

/* Line 1464 of yacc.c  */
#line 178 "dap4.y"
    {(yyval.list)=d4attrlist(parser,NULL,emptytoken);
		d4attrlist(parser,(yyval.list),(yyvsp[(1) - (2)].token));
		d4attrlist(parser,(yyval.list),(yyvsp[(2) - (2)].token));
	    ;}
    break;

  case 24:

/* Line 1464 of yacc.c  */
#line 183 "dap4.y"
    {(yyval.list)=d4attrlist(parser,NULL,emptytoken);
		d4attrlist(parser,(yyval.list),(yyvsp[(1) - (2)].token));
		d4attrlist(parser,(yyval.list),(yyvsp[(2) - (2)].token));
	    ;}
    break;

  case 25:

/* Line 1464 of yacc.c  */
#line 191 "dap4.y"
    {(yyval.list)=d4list(parser,NULL,NULL);;}
    break;

  case 26:

/* Line 1464 of yacc.c  */
#line 193 "dap4.y"
    {(yyval.list)=d4list(parser,(yyvsp[(1) - (2)].list),(yyvsp[(2) - (2)].object));;}
    break;

  case 27:

/* Line 1464 of yacc.c  */
#line 198 "dap4.y"
    {(yyval.object)=d4namespace(parser,(yyvsp[(2) - (3)].token)); CHECK((yyval.object));;}
    break;

  case 28:

/* Line 1464 of yacc.c  */
#line 203 "dap4.y"
    {(yyval.object)=d4dimdef(parser,(yyvsp[(2) - (4)].list),(yyvsp[(3) - (4)].list)); CHECK((yyval.object));;}
    break;

  case 29:

/* Line 1464 of yacc.c  */
#line 208 "dap4.y"
    {(yyval.list)=d4attrlist(parser,NULL,emptytoken);
		d4attrlist(parser,(yyval.list),(yyvsp[(1) - (2)].token));
		d4attrlist(parser,(yyval.list),(yyvsp[(2) - (2)].token));
	    ;}
    break;

  case 30:

/* Line 1464 of yacc.c  */
#line 213 "dap4.y"
    {(yyval.list)=d4attrlist(parser,NULL,emptytoken);
		d4attrlist(parser,(yyval.list),(yyvsp[(1) - (2)].token));
		d4attrlist(parser,(yyval.list),(yyvsp[(2) - (2)].token));
	    ;}
    break;

  case 31:

/* Line 1464 of yacc.c  */
#line 221 "dap4.y"
    {(yyval.object)=d4dimref(parser,(yyvsp[(2) - (3)].list)); CHECK((yyval.object));;}
    break;

  case 32:

/* Line 1464 of yacc.c  */
#line 226 "dap4.y"
    {(yyval.list)=d4attrlist(parser,NULL,emptytoken);
		d4attrlist(parser,(yyval.list),(yyvsp[(1) - (1)].token));
	    ;}
    break;

  case 33:

/* Line 1464 of yacc.c  */
#line 230 "dap4.y"
    {(yyval.list)=d4attrlist(parser,NULL,emptytoken);
		d4attrlist(parser,(yyval.list),(yyvsp[(1) - (1)].token));
	    ;}
    break;

  case 34:

/* Line 1464 of yacc.c  */
#line 236 "dap4.y"
    {(yyval.object)=(yyvsp[(1) - (1)].object);;}
    break;

  case 35:

/* Line 1464 of yacc.c  */
#line 237 "dap4.y"
    {(yyval.object)=(yyvsp[(1) - (1)].object);;}
    break;

  case 36:

/* Line 1464 of yacc.c  */
#line 243 "dap4.y"
    {(yyval.object)=d4simplevariable(parser,(yyvsp[(1) - (4)].token),(yyvsp[(2) - (4)].token),(yyvsp[(3) - (4)].object),(yyvsp[(4) - (4)].token)); CHECK((yyval.object));;}
    break;

  case 37:

/* Line 1464 of yacc.c  */
#line 248 "dap4.y"
    {(yyval.token)=(yyvsp[(1) - (1)].token);;}
    break;

  case 38:

/* Line 1464 of yacc.c  */
#line 249 "dap4.y"
    {(yyval.token)=(yyvsp[(1) - (1)].token);;}
    break;

  case 39:

/* Line 1464 of yacc.c  */
#line 250 "dap4.y"
    {(yyval.token)=(yyvsp[(1) - (1)].token);;}
    break;

  case 40:

/* Line 1464 of yacc.c  */
#line 251 "dap4.y"
    {(yyval.token)=(yyvsp[(1) - (1)].token);;}
    break;

  case 41:

/* Line 1464 of yacc.c  */
#line 252 "dap4.y"
    {(yyval.token)=(yyvsp[(1) - (1)].token);;}
    break;

  case 42:

/* Line 1464 of yacc.c  */
#line 253 "dap4.y"
    {(yyval.token)=(yyvsp[(1) - (1)].token);;}
    break;

  case 43:

/* Line 1464 of yacc.c  */
#line 254 "dap4.y"
    {(yyval.token)=(yyvsp[(1) - (1)].token);;}
    break;

  case 44:

/* Line 1464 of yacc.c  */
#line 255 "dap4.y"
    {(yyval.token)=(yyvsp[(1) - (1)].token);;}
    break;

  case 45:

/* Line 1464 of yacc.c  */
#line 256 "dap4.y"
    {(yyval.token)=(yyvsp[(1) - (1)].token);;}
    break;

  case 46:

/* Line 1464 of yacc.c  */
#line 257 "dap4.y"
    {(yyval.token)=(yyvsp[(1) - (1)].token);;}
    break;

  case 47:

/* Line 1464 of yacc.c  */
#line 258 "dap4.y"
    {(yyval.token)=(yyvsp[(1) - (1)].token);;}
    break;

  case 48:

/* Line 1464 of yacc.c  */
#line 259 "dap4.y"
    {(yyval.token)=(yyvsp[(1) - (1)].token);;}
    break;

  case 49:

/* Line 1464 of yacc.c  */
#line 260 "dap4.y"
    {(yyval.token)=(yyvsp[(1) - (1)].token);;}
    break;

  case 50:

/* Line 1464 of yacc.c  */
#line 261 "dap4.y"
    {(yyval.token)=(yyvsp[(1) - (1)].token);;}
    break;

  case 51:

/* Line 1464 of yacc.c  */
#line 262 "dap4.y"
    {(yyval.token)=(yyvsp[(1) - (1)].token);;}
    break;

  case 52:

/* Line 1464 of yacc.c  */
#line 263 "dap4.y"
    {(yyval.token)=(yyvsp[(1) - (2)].token);;}
    break;

  case 53:

/* Line 1464 of yacc.c  */
#line 267 "dap4.y"
    {(yyval.token)=(yyvsp[(1) - (1)].token);;}
    break;

  case 54:

/* Line 1464 of yacc.c  */
#line 268 "dap4.y"
    {(yyval.token)=(yyvsp[(1) - (1)].token);;}
    break;

  case 55:

/* Line 1464 of yacc.c  */
#line 269 "dap4.y"
    {(yyval.token)=(yyvsp[(1) - (1)].token);;}
    break;

  case 56:

/* Line 1464 of yacc.c  */
#line 270 "dap4.y"
    {(yyval.token)=(yyvsp[(1) - (1)].token);;}
    break;

  case 57:

/* Line 1464 of yacc.c  */
#line 271 "dap4.y"
    {(yyval.token)=(yyvsp[(1) - (1)].token);;}
    break;

  case 58:

/* Line 1464 of yacc.c  */
#line 272 "dap4.y"
    {(yyval.token)=(yyvsp[(1) - (1)].token);;}
    break;

  case 59:

/* Line 1464 of yacc.c  */
#line 273 "dap4.y"
    {(yyval.token)=(yyvsp[(1) - (1)].token);;}
    break;

  case 60:

/* Line 1464 of yacc.c  */
#line 274 "dap4.y"
    {(yyval.token)=(yyvsp[(1) - (1)].token);;}
    break;

  case 61:

/* Line 1464 of yacc.c  */
#line 275 "dap4.y"
    {(yyval.token)=(yyvsp[(1) - (1)].token);;}
    break;

  case 62:

/* Line 1464 of yacc.c  */
#line 276 "dap4.y"
    {(yyval.token)=(yyvsp[(1) - (1)].token);;}
    break;

  case 63:

/* Line 1464 of yacc.c  */
#line 277 "dap4.y"
    {(yyval.token)=(yyvsp[(1) - (1)].token);;}
    break;

  case 64:

/* Line 1464 of yacc.c  */
#line 278 "dap4.y"
    {(yyval.token)=(yyvsp[(1) - (1)].token);;}
    break;

  case 65:

/* Line 1464 of yacc.c  */
#line 279 "dap4.y"
    {(yyval.token)=(yyvsp[(1) - (1)].token);;}
    break;

  case 66:

/* Line 1464 of yacc.c  */
#line 280 "dap4.y"
    {(yyval.token)=(yyvsp[(1) - (1)].token);;}
    break;

  case 67:

/* Line 1464 of yacc.c  */
#line 281 "dap4.y"
    {(yyval.token)=(yyvsp[(1) - (1)].token);;}
    break;

  case 68:

/* Line 1464 of yacc.c  */
#line 282 "dap4.y"
    {(yyval.token)=(yyvsp[(1) - (1)].token);;}
    break;

  case 69:

/* Line 1464 of yacc.c  */
#line 287 "dap4.y"
    {(yyval.object)=d4list(parser,NULL,NULL);;}
    break;

  case 70:

/* Line 1464 of yacc.c  */
#line 289 "dap4.y"
    {(yyval.object)=d4list(parser,(yyvsp[(1) - (2)].object),(yyvsp[(2) - (2)].object));;}
    break;

  case 71:

/* Line 1464 of yacc.c  */
#line 291 "dap4.y"
    {(yyval.object)=d4list(parser,(yyvsp[(1) - (2)].object),(yyvsp[(2) - (2)].object));;}
    break;

  case 72:

/* Line 1464 of yacc.c  */
#line 293 "dap4.y"
    {(yyval.object)=d4list(parser,(yyvsp[(1) - (2)].object),(yyvsp[(2) - (2)].object));;}
    break;

  case 73:

/* Line 1464 of yacc.c  */
#line 298 "dap4.y"
    {(yyval.object)=d4mapref(parser,(yyvsp[(2) - (3)].token)); CHECK((yyval.object));;}
    break;

  case 74:

/* Line 1464 of yacc.c  */
#line 303 "dap4.y"
    {(yyval.object)=d4structurevariable(parser,(yyvsp[(2) - (4)].token),(yyvsp[(3) - (4)].object)); CHECK((yyval.object));;}
    break;

  case 75:

/* Line 1464 of yacc.c  */
#line 308 "dap4.y"
    {(yyval.object)=d4list(parser,NULL,NULL);;}
    break;

  case 76:

/* Line 1464 of yacc.c  */
#line 310 "dap4.y"
    {(yyval.object)=d4list(parser,(yyvsp[(1) - (2)].object),(yyvsp[(2) - (2)].object));;}
    break;

  case 77:

/* Line 1464 of yacc.c  */
#line 312 "dap4.y"
    {(yyval.object)=d4list(parser,(yyvsp[(1) - (2)].object),(yyvsp[(2) - (2)].object));;}
    break;

  case 78:

/* Line 1464 of yacc.c  */
#line 314 "dap4.y"
    {(yyval.object)=d4list(parser,(yyvsp[(1) - (2)].object),(yyvsp[(2) - (2)].object));;}
    break;

  case 79:

/* Line 1464 of yacc.c  */
#line 319 "dap4.y"
    {(yyval.list)=d4list(parser,NULL,NULL);;}
    break;

  case 80:

/* Line 1464 of yacc.c  */
#line 321 "dap4.y"
    {(yyval.list)=d4list(parser,(yyvsp[(1) - (2)].list),(yyvsp[(2) - (2)].object));;}
    break;

  case 81:

/* Line 1464 of yacc.c  */
#line 325 "dap4.y"
    {(yyval.object)=(yyvsp[(1) - (1)].object);;}
    break;

  case 82:

/* Line 1464 of yacc.c  */
#line 326 "dap4.y"
    {(yyval.object)=(yyvsp[(1) - (1)].object);;}
    break;

  case 83:

/* Line 1464 of yacc.c  */
#line 334 "dap4.y"
    {(yyval.object)=d4attribute(parser,(yyvsp[(2) - (5)].list),(yyvsp[(3) - (5)].list),(yyvsp[(4) - (5)].list)); CHECK((yyval.object));;}
    break;

  case 84:

/* Line 1464 of yacc.c  */
#line 339 "dap4.y"
    {(yyval.list)=d4attrlist(parser,NULL,emptytoken);;}
    break;

  case 85:

/* Line 1464 of yacc.c  */
#line 341 "dap4.y"
    {(yyval.list)=d4attrlist(parser,(yyvsp[(1) - (2)].list),(yyvsp[(2) - (2)].token));;}
    break;

  case 86:

/* Line 1464 of yacc.c  */
#line 343 "dap4.y"
    {(yyval.list)=d4attrlist(parser,(yyvsp[(1) - (2)].list),(yyvsp[(2) - (2)].token));;}
    break;

  case 87:

/* Line 1464 of yacc.c  */
#line 345 "dap4.y"
    {(yyval.list)=d4attrlist(parser,(yyvsp[(1) - (2)].list),(yyvsp[(2) - (2)].token));;}
    break;

  case 88:

/* Line 1464 of yacc.c  */
#line 347 "dap4.y"
    {(yyval.list)=d4attrlist(parser,(yyvsp[(1) - (2)].list),(yyvsp[(2) - (2)].token));;}
    break;

  case 89:

/* Line 1464 of yacc.c  */
#line 352 "dap4.y"
    {(yyval.list)=d4attrlist(parser,NULL,emptytoken);;}
    break;

  case 90:

/* Line 1464 of yacc.c  */
#line 354 "dap4.y"
    {(yyval.list)=d4attrlist(parser,(yyvsp[(1) - (2)].list),(yyvsp[(2) - (2)].token));;}
    break;

  case 91:

/* Line 1464 of yacc.c  */
#line 357 "dap4.y"
    {(yyval.token)=(yyvsp[(2) - (3)].token);;}
    break;

  case 92:

/* Line 1464 of yacc.c  */
#line 361 "dap4.y"
    {(yyval.object)=d4otherxml(parser,(yyvsp[(1) - (1)].list));;}
    break;



/* Line 1464 of yacc.c  */
#line 2241 "dap4.tab.c"
      default: break;
    }
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
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (parser, YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (parser, yymsg);
	  }
	else
	  {
	    yyerror (parser, YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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
		      yytoken, &yylval, parser);
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
      if (yyn != YYPACT_NINF)
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
		  yystos[yystate], yyvsp, parser);
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
  yyerror (parser, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, parser);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, parser);
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1684 of yacc.c  */
#line 363 "dap4.y"


