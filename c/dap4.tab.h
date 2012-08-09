/* A Bison parser, made by GNU Bison 2.4.2.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

/* Line 1685 of yacc.c  */
#line 31 "dap4.y"

   void* object;
   YXlist* list;
   yax_token token;



/* Line 1685 of yacc.c  */
#line 134 "dap4.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif




