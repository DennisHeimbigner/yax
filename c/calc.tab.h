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

#ifndef YY_CALC_CALC_TAB_H_INCLUDED
# define YY_CALC_CALC_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int calcdebug;
#endif
/* "%code requires" blocks.  */
#line 19 "calc.y" /* yacc.c:1909  */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <calctest.h>

#line 51 "calc.tab.h" /* yacc.c:1909  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    CALC_ = 258,
    _CALC = 259,
    EQ_ = 260,
    _EQ = 261,
    ADD_ = 262,
    _ADD = 263,
    SUB_ = 264,
    _SUB = 265,
    MUL_ = 266,
    _MUL = 267,
    DIV_ = 268,
    _DIV = 269,
    EXP_ = 270,
    _EXP = 271,
    NEG_ = 272,
    _NEG = 273,
    INT_ = 274,
    _INT = 275,
    ATTR_N = 276,
    TEXT = 277,
    UNKNOWN_ATTR = 278,
    UNKNOWN_ELEMENT_ = 279,
    _UNKNOWN_ELEMENT = 280
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 14 "calc.y" /* yacc.c:1909  */

  int integer;
  SaxEvent* event;

#line 94 "calc.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif



#ifndef YYPUSH_MORE_DEFINED
# define YYPUSH_MORE_DEFINED
enum { YYPUSH_MORE = 4 };
#endif

typedef struct calcpstate calcpstate;

int calcpush_parse (calcpstate *ps, int pushed_char, YYSTYPE const *pushed_val, CalcEventHandler* ceh);

calcpstate * calcpstate_new (void);
void calcpstate_delete (calcpstate *ps);

#endif /* !YY_CALC_CALC_TAB_H_INCLUDED  */
