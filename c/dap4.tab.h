/* A Bison parser, made by GNU Bison 3.0.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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

#ifndef YY_DAP4_DAP4_TAB_H_INCLUDED
# define YY_DAP4_DAP4_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int dap4debug;
#endif
/* "%code requires" blocks.  */
#line 14 "dap4.y" /* yacc.c:1909  */

#include "dap4test.h"
#define TOKENFLAGS (SXFLAG_ESCAPE|SXFLAG_ELIDETEXT)

#line 49 "dap4.tab.h" /* yacc.c:1909  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
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

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef SaxEvent* YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif



#ifndef YYPUSH_MORE_DEFINED
# define YYPUSH_MORE_DEFINED
enum { YYPUSH_MORE = 4 };
#endif

typedef struct dap4pstate dap4pstate;

int dap4push_parse (dap4pstate *ps, int pushed_char, YYSTYPE const *pushed_val, Dap4EventHandler* handler);

dap4pstate * dap4pstate_new (void);
void dap4pstate_delete (dap4pstate *ps);

#endif /* !YY_DAP4_DAP4_TAB_H_INCLUDED  */
