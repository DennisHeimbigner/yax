# A Bison parser, made by GNU Bison 3.0.

# Skeleton implementation for Bison LALR(1) parsers in Python

# Copyright (C) 2013 Free Software Foundation, Inc.

# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.

# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

# As a special exception, you may create a larger work that contains
# part or all of the Bison parser skeleton and distribute that work
# under terms of your choice, so long as that work isn't itself a
# parser generator using the skeleton or a modified version thereof
# as a parser skeleton.  Alternatively, if you modify or redistribute
# the parser skeleton itself, you may (at your option) remove this
# special exception, which will cause the skeleton and the resulting
# Bison output files to be licensed under the GNU General Public
# License without this special exception.

# This special exception was added by the Free Software Foundation in
# version 2.2 of Bison.

# A Bison parser, automatically generated from
#  <tt>./yax/test/calc.y</tt>.
#
# @author LALR (1) parser skeleton written by Dennis Heimbigner,
#          derived from the Java parser skeleton.

# Parser skeleton starts here

# First part of user declarations.

# "./yax/test/CalcParser.py":44 # python.skel:415

# "./yax/test/CalcParser.py":46 # python.skel:416

# Import modules required for parser operation
import sys
import traceback
# Additional, user specified, imports
# #                    "%code imports" blocks.
# "./yax/test/calc.y":11 # python.skel:422

import sys
import math
from saxeventtype import *

# "./yax/test/CalcParser.py":59 # python.skel:422


# %code top


##################################################
# Module Level Declarations
##################################################

# Returned by a Bison action in order to stop the parsing process and
# return success (<tt>true</tt>).
YYACCEPT = 0

# Returned by a Bison action in order to stop the parsing process and
# return failure (<tt>false</tt>).
YYABORT = 1
# Returned by a Bison action in order to start error recovery without
# printing an error message.
YYERROR = 2


# Returned by a Bison action in order to request a new token.
YYPUSH_MORE = 4

# Internal return codes that are not supported for user semantic
# actions.

YYERRLAB = 3
YYNEWSTATE = 4
YYDEFAULT = 5
YYREDUCE = 6
YYERRLAB1 = 7
YYRETURN = 8

YYGETTOKEN = 9 # Signify that a new token
               # is expected when doing push-parsing.


# Define a symbol for use with our fake switch statement in yyaction ()
YYACTION = 10

# Map internal labels to strings for those that occur in the "switch".
LABELNAMES = (
"YYACCEPT",
"YYABORT",
"YYERROR",
"YYERRLAB",
"YYNEWSTATE",
"YYDEFAULT",
"YYREDUCE",
"YYERRLAB1",
"YYRETURN",
"YYGETTOKEN",
"YYACTION"
)

# For Python, the Token identifiers are define
# at the module level rather than inside
# the Lexer class. Given python's name scoping,
# this simplifiesthings.

# Token returned by the scanner to signal the end of its input.
EOF = 0


# Tokens.
CALC = 258
CALC_ = 259
EQ = 260
EQ_ = 261
ADD = 262
ADD_ = 263
SUB = 264
SUB_ = 265
MUL = 266
MUL_ = 267
DIV = 268
DIV_ = 269
EXP = 270
EXP_ = 271
NEG = 272
NEG_ = 273
INT = 274
INT_ = 275
ATTR_N = 276
TEXT = 277
UNKNOWN_ATTR = 278
UNKNOWN_ELEMENT = 279
UNKNOWN_ELEMENT_ = 280


# %code requires


# %code provides


##################################################
# Table data and methods
##################################################

# Whether the given <code>yypact_</code> value indicates a defaulted state.
# @param yyvalue   the value to check

def yy_pact_value_is_default_ (yyvalue) :
  return yyvalue == yypact_ninf_

# Whether the given <code>yytable_</code>
# value indicates a syntax error.
# @param yyvalue the value to check

def yy_table_value_is_error_ (yyvalue) :
  return yyvalue == yytable_ninf_

##################################################
# Define the parsing tables
##################################################

yypact_ = (
      26,    -2,     2,    -1,    -2,    33,    -2,     0,     0,     0,
       0,     0,     0,     0,     6,    -2,    -2,    -2,     0,     0,
       0,     0,     0,     0,    12,    18,    19,    34,    35,    31,
      30,    32,    28,    -2,    -2,    -2,    -2,    -2,    -2,    -2,
      -2,    -2
  )

yydefact_ = (
       0,     3,     0,     0,     1,     0,     2,     0,     0,     0,
       0,     0,     0,     0,     0,     4,    12,    13,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    11,    14,    15,     5,     6,     7,     8,
       9,    10
  )

yypgoto_ = (
      -2,    -2,    -2,    13,    -2
  )

yydefgoto_ = (
      -1,     2,     3,    15,    16
  )

yytable_ = (
       5,     5,     4,     6,     7,     7,     8,     8,     9,     9,
      10,    10,    11,    11,    12,    12,    13,    13,    14,    14,
      18,    19,    20,    21,    22,    23,    24,    25,    26,     1,
      33,    27,    28,    29,    30,    31,    32,    17,    34,    35,
      36,    38,    39,    37,    41,     0,    40
  )

yycheck_ = (
       1,     1,     0,     4,     5,     5,     7,     7,     9,     9,
      11,    11,    13,    13,    15,    15,    17,    17,    19,    19,
       7,     8,     9,    10,    11,    12,    13,    21,    22,     3,
      18,    18,    19,    20,    21,    22,    23,     4,    20,    20,
       6,    10,    12,     8,    16,    -1,    14
  )

yystos_ = (
       0,     3,    27,    28,     0,     1,     4,     5,     7,     9,
      11,    13,    15,    17,    19,    29,    30,     4,    29,    29,
      29,    29,    29,    29,    29,    21,    22,    29,    29,    29,
      29,    29,    29,    18,    20,    20,     6,     8,    10,    12,
      14,    16
  )

yyr1_ = (
       0,    26,    27,    28,    28,    29,    29,    29,    29,    29,
      29,    29,    29,    29,    30,    30
  )

yyr2_ = (
       0,     2,     3,     0,     2,     4,     4,     4,     4,     4,
       4,     3,     1,     2,     3,     3
  )


yytoken_number_ = (
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280
  )

# YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
#   First, the terminals, then, starting at yyntokens_, nonterminals.
yytname_ = (
  "$end", "error", "$undefined", "CALC", "CALC_", "EQ", "EQ_", "ADD",
  "ADD_", "SUB", "SUB_", "MUL", "MUL_", "DIV", "DIV_", "EXP", "EXP_",
  "NEG", "NEG_", "INT", "INT_", "ATTR_N", "TEXT", "UNKNOWN_ATTR",
  "UNKNOWN_ELEMENT", "UNKNOWN_ELEMENT_", "$accept", "calc", "exprlist",
  "expr", "integer", None
  )

yyrline_ = (
       0,    41,    41,    45,    46,    54,    59,    61,    63,    65,
      67,    69,    71,    73,    78,    80
  )

# YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.
yytranslate_table_ = (
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
      25
  )

def yytranslate_ (t) :
  if (t >= 0 and t <= yyuser_token_number_max_) :
    return yytranslate_table_[t]
  else :
    return yyundef_token_

  # Return whether error recovery is being done.  In this state, the parser
  # reads token until it reaches a known state, and then restarts normal
  # operation.
  def recovering (self) :
    return self.yyerrstatus_ == 0

# Table variable related constants
yylast_ = 46
yynnts_ = 5
yyempty_ = -2
yyfinal_ = 4
yyterror_ = 1
yyerrcode_ = 256
yyntokens_ = 26

yyuser_token_number_max_ = 280
yyundef_token_ = 2

yypact_ninf_ = -2
yytable_ninf_ = -1

##################################################
# Auxilliary Classes
##################################################



class YYStack :

  def __init__ (self) :
    self.size = 16
    self.height = -1
    self.stateStack=[]
    self.valueStack=[]
    

  def push (self, state, value, ) :
    self.height += 1
    self.stateStack.append(state)
    self.valueStack.append(value)
    

  def pop (self, num) :
    if (num > 0) :
      for i in range(num) :
        self.valueStack.pop()
        self.stateStack.pop()
        
    self.height -= num

  def stateAt (self, i) :
    return self.stateStack[self.height - i]

  
  def valueAt (self, i) :
    return self.valueStack[self.height - i]

  # Print the state stack on the debug stream.
  # Note: needs to be renamed for Python
  def yyprint (self, out) :
    out.write ("Stack now")
    for x in self.stateStack[:] :
        out.write (' ')
        out.write (str(x))
    out.write ('\n')
# end class YYStack

##################################################
# Class Lexer
##################################################

# This class defines the  Communication interface between the
# scanner and the Bison-generated parser <tt>CalcParser</tt>.
#
# For Python there are some things to note.
# 1. Lexer is defined as a class because Java-like interfaces
#    are not supported.
# 2. The lexer class is defined at module scope.
# 3. Python allows for the return of multiple values, so
#    yylex can return the token and lval all at one time.
#    Location information is still obtained by calling
#    Lexer methods.
# 4. The lexer also supports the user's yyerror method,
#    but see the note at the push_parse method.

class Lexer :

  def __init__ (self) :
    pass


  # Entry point for the scanner.
  # Returns two values: (1) the token identifier corresponding
  # to the next token, and 2) the semantic value associated with the token.
  # 
  # @return the token identifier corresponding to the next token
  #          and the semantic value.

  def yylex (self) :
    return (0,None)

  # Entry point for error reporting.  Emits an error
  # 
  # in a user-defined way.
  #
  # @param msg The string for the error message.
  # 

  def yyerror (self, msg) :
    s = msg
    
    sys.stderr.write(s+'\n')


# If the user specifies %code lexer ...
# Then insert it here
class YYLexer (Lexer) :
  # #                    "%code lexer" blocks.
  # "./yax/test/calc.y":17 # python.skel:701
  
  def yylex(self) : return ("0",None)
  def yyerror(self,s) : sys.stderr.write(s+'\n')
  
  # "./yax/test/CalcParser.py":420 # python.skel:701
  


# The yyaction functions now all become global 
# We also need a class to act as a call by reference
# return for yyval.
class YYVAL:
  def __init__(self,yyval): self.yyval = yyval
#end YYVAL

##################################################
# Primary Parser Class
##################################################

class CalcParser :
  # Version number for the Bison executable that generated this parser.
  bisonVersion = "3.0"

  # Name of the skeleton that generated this parser.
  bisonSkeleton = "./yax/python.skel"



  ##################################################
  # Class CalcParser API
  ##################################################

  # Instance Variables

  # Return whether verbose error messages are enabled.
  def getErrorVerbose(self) :
    return self.yyErrorVerbose

  # Set the verbosity of error messages.
  # @param verbose True to request verbose error messages.
  def setErrorVerbose(self, verbose) :
    self.yyErrorVerbose = verbose

  # Return the <tt>PrintStream</tt> on which the debugging output is
  # printed.

  def getDebugStream (self) :
    return self.yyDebugStream

  # Set the <tt>PrintStream</tt> on which the debug output is printed.
  # @param s The stream that is used for debugging output.
  def setDebugStream(self, s) :
    self.yyDebugStream = s

  # Answer the verbosity of the debugging output 0 means that all kinds of
  # output from the parser are suppressed.
  def getDebugLevel (self) :
    return self.yydebug

  # Set the verbosity of the debugging output 0 means that all kinds of
  # output from the parser are suppressed.
  # @param level The verbosity level for debugging output.
  def setDebugLevel (self, level) :
    self.yydebug = level

  ##################################################
  # Class CalcParser Constructor
  ##################################################

  # Instantiates the Bison-generated parser.
  # 

  def __init__  (self):


    self.yylexer = YYLexer()

    self.yyDebugStream = sys.stderr
    self.yydebug = 0
    self.yyerrstatus_ = 0
    self.push_parse_initialized = False
    # True if verbose error messages are enabled.
    self.yyErrorVerbose = True
    self.yyswitch_init()
  # end __init__

  # Define the user action procedures here
  def yycase_2 (self, yyvalp, yyn, yystack, yylen, yyerror):
    yyval = yyvalp.yyval
    try :
      # "./yax/test/calc.y":41 # python.skel:784
          yyval=None
    finally :
      yyvalp.yyval = yyval
  #end yycase_2

  def yycase_3 (self, yyvalp, yyn, yystack, yylen, yyerror):
    yyval = yyvalp.yyval
    try :
      # "./yax/test/calc.y":45 # python.skel:784
          yyval=None
    finally :
      yyvalp.yyval = yyval
  #end yycase_3

  def yycase_4 (self, yyvalp, yyn, yystack, yylen, yyerror):
    yyval = yyvalp.yyval
    try :
      # "./yax/test/calc.y":47 # python.skel:784
          
                      calc(self,(yystack.valueAt (2-(2))))
                      yyval=None
                      
    finally :
      yyvalp.yyval = yyval
  #end yycase_4

  def yycase_5 (self, yyvalp, yyn, yystack, yylen, yyerror):
    yyval = yyvalp.yyval
    try :
      # "./yax/test/calc.y":55 # python.skel:784
          
                      if (yystack.valueAt (4-(2))) == (yystack.valueAt (4-(3))) : yyval= 1
                      else: yyval = 0
                      
    finally :
      yyvalp.yyval = yyval
  #end yycase_5

  def yycase_6 (self, yyvalp, yyn, yystack, yylen, yyerror):
    yyval = yyvalp.yyval
    try :
      # "./yax/test/calc.y":60 # python.skel:784
          yyval=bin_add(self,(yystack.valueAt (4-(2))),(yystack.valueAt (4-(3))))
    finally :
      yyvalp.yyval = yyval
  #end yycase_6

  def yycase_7 (self, yyvalp, yyn, yystack, yylen, yyerror):
    yyval = yyvalp.yyval
    try :
      # "./yax/test/calc.y":62 # python.skel:784
          yyval=bin_sub(self,(yystack.valueAt (4-(2))),(yystack.valueAt (4-(3))))
    finally :
      yyvalp.yyval = yyval
  #end yycase_7

  def yycase_8 (self, yyvalp, yyn, yystack, yylen, yyerror):
    yyval = yyvalp.yyval
    try :
      # "./yax/test/calc.y":64 # python.skel:784
          yyval=bin_mul(self,(yystack.valueAt (4-(2))),(yystack.valueAt (4-(3))))
    finally :
      yyvalp.yyval = yyval
  #end yycase_8

  def yycase_9 (self, yyvalp, yyn, yystack, yylen, yyerror):
    yyval = yyvalp.yyval
    try :
      # "./yax/test/calc.y":66 # python.skel:784
          yyval=bin_div(self,(yystack.valueAt (4-(2))),(yystack.valueAt (4-(3))))
    finally :
      yyvalp.yyval = yyval
  #end yycase_9

  def yycase_10 (self, yyvalp, yyn, yystack, yylen, yyerror):
    yyval = yyvalp.yyval
    try :
      # "./yax/test/calc.y":68 # python.skel:784
          yyval=bin_exp(self,(yystack.valueAt (4-(2))),(yystack.valueAt (4-(3))))
    finally :
      yyvalp.yyval = yyval
  #end yycase_10

  def yycase_11 (self, yyvalp, yyn, yystack, yylen, yyerror):
    yyval = yyvalp.yyval
    try :
      # "./yax/test/calc.y":70 # python.skel:784
          yyval=un_neg(self,(yystack.valueAt (3-(2))))
    finally :
      yyvalp.yyval = yyval
  #end yycase_11

  def yycase_12 (self, yyvalp, yyn, yystack, yylen, yyerror):
    yyval = yyvalp.yyval
    try :
      # "./yax/test/calc.y":72 # python.skel:784
          yyval=(yystack.valueAt (1-(1)))
    finally :
      yyvalp.yyval = yyval
  #end yycase_12

  def yycase_13 (self, yyvalp, yyn, yystack, yylen, yyerror):
    yyval = yyvalp.yyval
    try :
      # "./yax/test/calc.y":74 # python.skel:784
          yyval=0
    finally :
      yyvalp.yyval = yyval
  #end yycase_13

  def yycase_14 (self, yyvalp, yyn, yystack, yylen, yyerror):
    yyval = yyvalp.yyval
    try :
      # "./yax/test/calc.y":79 # python.skel:784
          yyval=number(self,(yystack.valueAt (3-(2))))
    finally :
      yyvalp.yyval = yyval
  #end yycase_14

  def yycase_15 (self, yyvalp, yyn, yystack, yylen, yyerror):
    yyval = yyvalp.yyval
    try :
      # "./yax/test/calc.y":81 # python.skel:784
          yyval=number(self,(yystack.valueAt (3-(2))))
    finally :
      yyvalp.yyval = yyval
  #end yycase_15


# "./yax/test/CalcParser.py":636 # python.skel:784

  # Build yyswitch
  def yyswitch_init(self):
    self.yyswitch = {}

    self.yyswitch[2] = self.yycase_2

    self.yyswitch[3] = self.yycase_3

    self.yyswitch[4] = self.yycase_4

    self.yyswitch[5] = self.yycase_5

    self.yyswitch[6] = self.yycase_6

    self.yyswitch[7] = self.yycase_7

    self.yyswitch[8] = self.yycase_8

    self.yyswitch[9] = self.yycase_9

    self.yyswitch[10] = self.yycase_10

    self.yyswitch[11] = self.yycase_11

    self.yyswitch[12] = self.yycase_12

    self.yyswitch[13] = self.yycase_13

    self.yyswitch[14] = self.yycase_14

    self.yyswitch[15] = self.yycase_15


# "./yax/test/CalcParser.py":671 # python.skel:790

  # end yyswitch_init


    # Lookahead and lookahead in internal form.
    self.yychar = yyempty_
    self.yytoken = 0

    # State.
    self.yyn = 0
    self.yylen = 0
    self.yystate = 0
    self.yystack = YYStack ()
    self.label = YYNEWSTATE

    # Error handling.
    self.yynerrs_ = 0
    
    # Semantic value of the lookahead.
    self.yylval = None


  ##################################################
  # User defined action invocation.
  ##################################################

  # For python, pass in the yyerror function
  # to simplify access so the caller does not need to prefix it.
  def yyaction (self, yyn, yystack, yylen, yyerror) :
    yylval = None
    

    # If YYLEN is nonzero, implement the default value of the action:
    #   '$$ = $1'.  Otherwise, use the top of the stack.
    #    Otherwise, the following line sets YYVAL to garbage.
    #    This behavior is undocumented and Bison
    #    users should not rely upon it.
    if (yylen > 0) :
      yyval = yystack.valueAt (yylen - 1)
    else :
      yyval = yystack.valueAt (0)

    self.yy_reduce_print (yyn, yystack)

    # Simulate a switch in python using a dictionary
    # that maps states to functions defining the user defined
    # actions. (See just be for the YYParser class definition
    # above). This depends on the fact that passing mutable objects
    # into a function allows the function to modify that object.
    # Note that the action body is indentation sensitive

    if (yyn in self.yyswitch) :
      action = self.yyswitch[yyn]
      yyvalp = YYVAL(yyval)
      status = action(yyvalp, yyn, yystack, yylen, yyerror)
      yyval = yyvalp.yyval
      if(status != None) : return status
    else: # no such action index; ignore
      pass

    self.yy_symbol_print ("-> $$ =",
                          yyr1_[yyn], yyval)

    yystack.pop (yylen)
    yylen = 0

    # Shift the result of the reduction.
    yyn = yyr1_[yyn]
    tmp = yyntokens_ # quote problem
    yystate = yypgoto_[yyn - tmp] + yystack.stateAt (0)
    if (0 <= yystate
        and yystate <= yylast_
        and yycheck_[yystate] == yystack.stateAt (0)) :
      yystate = yytable_[yystate]
    else :
      yystate = yydefgoto_[yyn - tmp]

    yystack.push (yystate, yyval)
    return YYNEWSTATE
  # end yyaction

  ##################################################
  # Debug output for rule reduction
  # Report on the debug stream that the rule yyrule is going to be reduced.
  ##################################################

  def yy_reduce_print (self, yyrule, yystack) :
    if (self.yydebug == 0) :
      return

    yylno = yyrline_[yyrule]
    yynrhs = yyr2_[yyrule]
    # Print the symbols being reduced, and their result.
    self.yycdebug ("Reducing stack by rule " + str(yyrule - 1)
               + " (line " + str(yylno) + "), ")

    # The symbols being reduced.
    for yyi in range(yynrhs) :
      self.yy_symbol_print ("   $" + str(yyi + 1) + " =",
                       yystos_[yystack.stateAt(yynrhs - (yyi + 1))],
                       (yystack.valueAt (yynrhs-(yyi + 1))))
  # end yy_reduce_print





  # Primary push parser API method
  # Push parse given input from an external lexer.
  # Position provided rather than Location.
  #
  # @param yylextoken current token
  # @param yylexval current lval
  # @param (Optional) location=None current position;
  #ignored if location tracking is disabled.
  #
  # @return <tt>YYACCEPT, YYABORT, YYPUSH_MORE</tt>

  def push_parse (self, yylextoken, yylexval) :



    if (not self.push_parse_initialized) :
      self.push_parse_initialize ()
      self.yycdebug ("Starting parse\n")
      self.yyerrstatus_ = 0
      # Initialize the stack.
      self.yystack.push (self.yystate,
                             self.yylval )

    else :
      self.label = YYGETTOKEN
    push_token_consumed = True



    ##################################################
    # Begin code common to push and pull parsing
    ##################################################

    while True :
      #sys.stderr.write("label=("+str(self.label)+")="
      #+LABELNAMES[self.label]+'\n')

      # For python we need to simulate switch using if statements
      # Because we have the enclosing while loop, we can exit the switch
      # using continue instead of break (assumes that there is no code
      # following the switch).
      # switch label :
      # New state.  Unlike in the C/C++ skeletons, the state is already
      # pushed when we come here.
      if self.label == YYNEWSTATE : # case YYNEWSTATE
        self.yycdebug ("Entering state " + str(self.yystate) + '\n')
        if (self.yydebug > 0) :
          self.yystack.yyprint (self.yyDebugStream)

        # Accept?
        if (self.yystate == yyfinal_) :
          self.label = YYACCEPT
          continue

        # Take a decision.  First try without lookahead.
        # Quote problem
        tmp = self.yystate
        self.yyn = yypact_[tmp]
        if (yy_pact_value_is_default_ (self.yyn)) :
            self.label = YYDEFAULT
            continue; # break switch

        self.label = YYGETTOKEN # Cheat to simulate fall thru
      elif self.label == YYGETTOKEN : # case YYGETTOKEN
        # Read a lookahead token.
        if (self.yychar == yyempty_) :
          if ( not push_token_consumed) :
            return YYPUSH_MORE
          self.yycdebug ("Reading a token: ")
          self.yychar = yylextoken
          self.yylval = yylexval
          push_token_consumed = False

        # Convert token to internal form.
        if (self.yychar <= EOF) :
          self.yychar = EOF
          self.yytoken = EOF
          self.yycdebug ("Now at end of input.\n")
        else :
          self.yytoken = yytranslate_ (self.yychar)
          self.yy_symbol_print ("Next token is",
                                self.yytoken,
                                self.yylval
                                
                                )

        # If the proper action on seeing token YYTOKEN is to reduce or to
        # detect an error, then take that action.
        self.yyn += self.yytoken
        tmp = self.yyn # Quote problem
        if (self.yyn < 0 
            or yylast_ < self.yyn
            or yycheck_[tmp] != self.yytoken) :
          self.label = YYDEFAULT

        # <= 0 means reduce or error.
        elif (yytable_[tmp] <= 0) :
          self.yyn = yytable_[tmp]
          if (yy_table_value_is_error_ (self.yyn)) :
            self.label = YYERRLAB
          else :
            self.yyn = -self.yyn
            self.label = YYREDUCE
        else :
          tmp = self.yyn # Quote problem
          self.yyn = yytable_[tmp]
          # Shift the lookahead token.
          self.yy_symbol_print ("Shifting",
                                self.yytoken,
                                self.yylval)

          # Discard the token being shifted.
          self.yychar = yyempty_

          # Count tokens shifted since error after three, turn off error
          # status.
          if (self.yyerrstatus_ > 0) :
              self.yyerrstatus_ -= 1

          self.yystate = self.yyn
          self.yystack.push (self.yystate, self.            yylval)
          self.label = YYNEWSTATE
      # end case YYNEWSTATE

      #-----------------------------------------------------------.
      #| yydefault -- do the default action for the current state.  |
      #-----------------------------------------------------------
      elif self.label == YYDEFAULT : #case YYDEFAULT
        tmp = self.yystate # Quote problem
        self.yyn = yydefact_[tmp]
        if (self.yyn == 0) :
          self.label = YYERRLAB
        else :
          self.label = YYREDUCE
      # end case YYDEFAULT

      #-----------------------------.
      #| yyreduce -- Do a reduction.  |
      #-----------------------------
      elif self.label == YYREDUCE : #case YYREDUCE
        tmp = self.yyn # Quote problem
        self.yylen = yyr2_[tmp]
        self.label = self.yyaction (self.yyn,         self.yystack, self.yylen, self.yylexer.yyerror)
        self.yystate = self.yystack.stateAt (0)
      # end case YYDEFAULT

      #------------------------------------.
      #| yyerrlab -- here on detecting error |
      #------------------------------------
      elif self.label == YYERRLAB: #case YYERRLAB
        # If not already recovering from an error, report this error.
        if (self.yyerrstatus_ == 0) :
          self.yynerrs_ += 1
          if (self.yychar == yyempty_) :
            self.yytoken = yyempty_
          tmp = self.yysyntax_error (self.yystate, self.yytoken)
          self.yyerror (tmp)

        
        if (self.yyerrstatus_ == 3) :
          # If just tried and failed to reuse lookahead token after an
          # error, discard it.

          if (self.yychar <= EOF) :
            # Return failure if at end of input.
            if (self.yychar == EOF) :
              self.label = YYABORT
              continue
          else :
            self.yychar = yyempty_

        # Else will try to reuse lookahead token after
        # shifting the error token.
        self.label = YYERRLAB1
      # end case YYERRLAB

      #-------------------------------------------------.
      #| errorlab -- error raised explicitly by YYERROR.  |
      #-------------------------------------------------
      elif self.label == YYERROR : #case YYERROR
        
        # Do not reclaim the symbols of the rule which action triggered
        # this YYERROR.
        self.yystack.pop (self.yylen)
        self.yylen = 0
        self.yystate = self.yystack.stateAt (0)
        self.label = YYERRLAB1
      # end case YYERROR

      #-------------------------------------------------------------.
      #| yyerrlab1 -- common code for both syntax error and YYERROR.  |
      #-------------------------------------------------------------
      elif self.label == YYERRLAB1 : #case YYERRLAB1
        self.yyerrstatus_ = 3 # Each real token shifted decrements this.
        while True :
          tmp = self.yystate # Quote problem
          self.yyn = yypact_[tmp]
          if ( not yy_pact_value_is_default_ (self.yyn)) :
            self.yyn += yyterror_
            tmp = self.yyn # Quote problem
            if (0 <= self.yyn and self.yyn <= yylast_ \
                and yycheck_[tmp] == yyterror_) :
              self.yyn = yytable_[tmp]
              if (0 < self.yyn) :
                break # leave while loop

            # Pop the current state because it cannot handle the
            # error token.
            if (self.yystack.height == 0) :
              self.label = YYABORT
              continue # Leave the switch

            
            self.yystack.pop (1)
            self.yystate = self.yystack.stateAt (0)
            if (self.yydebug > 0) :
              self.yystack.yyprint (self.yyDebugStream)

        if (self.label == YYABORT) :
          continue # Leave the switch.


        # Shift the error token.
        tmp = self.yyn
        self.yy_symbol_print ("Shifting", yystos_[tmp],
                         self.yylval)

        self.yystate = self.yyn
        self.yystack.push (self.yyn, self.yylval               )
        self.label = YYNEWSTATE
        continue # leave the switch
      # end case YYERRLAB1

      # Accept.
      elif self.label == YYACCEPT : # case YYACCEPT
        self.push_parse_initialized = False
        return YYACCEPT
      # end case YYACCEPT

      # Abort.
      elif self.label == YYABORT: # case YYABORT
        self.push_parse_initialized = False
        return YYABORT
      # end case YYABORT

      else :
        assert False, "Unknown State:" + str(self.label)

  # end push_parse




  # (Re-)Initialize the state of the push parser.

  def push_parse_initialize(self) :

    # Lookahead and lookahead in internal form.
    self.yychar = yyempty_
    self.yytoken = 0

    # State.
    self.yyn = 0
    self.yylen = 0
    self.yystate = 0
    self.yystack = YYStack ()
    self.label = YYNEWSTATE

    # Error handling.
    self.yynerrs_ = 0
    
    # Semantic value of the lookahead.
    self.yylval = None


    self.push_parse_initialized = True

  # end push_parse_initialize



  ##################################################
  # Class CalcParser Internal Methods
  ##################################################



  # Print an error message via the lexer.
  # @param msg The error message.
  # @param locaction (Optional) The location or position
  #                associated with the message.

  def yyerror (self, msg) :
    self.yylexer.yyerror (msg)
  # end yyerror

  def yycdebug (self, s) :
    if (self.yydebug > 0) :
      self.yyDebugStream.write (s+'\n')
  # end self.yycdebug


  # Return YYSTR after stripping away unnecessary quotes and
  # backslashes, so that it's suitable for yyerror.  The heuristic is
  # that double-quoting is unnecessary unless the string contains an
  # apostrophe, a comma, or backslash (other than backslash-backslash).
  # YYSTR is taken from yytname.
  def yytnamerr_ (self, yystr) :
    yyr = ""
    if (yystr[0] == '"')  :
      l = len(yystr)
      i = 1
      while (True) :
        if (i >= l) : break
        c = yystr[i]
        if(c == "'" or c == ',') :
          continue
        if( c == '"'):
          return yyr
        if(c == '\\') :
          i += 1
          c = yystr[i]
          if(c != '\\') :
            break
        yyr = yyr + c
        i += 1
      # end while
    elif (yystr ==  "$end") :
      return "end of input"
    return yystr;
  # end yytnamerr


  #--------------------------------.
  #| Print this symbol on YYOUTPUT.  |
  #--------------------------------

  def yy_symbol_print (self, s, yytype, yyvaluep ) :
    if (self.yydebug > 0) :
      tag = " nterm "
      if (yytype < yyntokens_) :
        tag = " token "
      if (yyvaluep is None) :
        vps = "None"
      else :
        vps = str(yyvaluep)
      tname = yytname_[yytype]
      line = s + tag + tname
      line += " ("
      
      line += vps
      line += ')'
      self.yycdebug (line)
  # end yy_symbol_print

  # Generate an error message.
  def yysyntax_error (self, yystate, tok) :
  
    if (self.yyErrorVerbose) :
      # There are many possibilities here to consider:
      # - If this state is a consistent state with a default action,
      #   then the only way this function was invoked is if the
      #   default action is an error action.  In that case, don't
      #   check for expected tokens because there are none.
      # - The only way there can be no lookahead present (in tok) is
      #   if this state is a consistent state with a default action.
      #   Thus, detecting the absence of a lookahead is sufficient to
      #   determine that there is no unexpected or expected token to
      #   report.  In that case, just report a simple 'syntax error'.
      # - Don't assume there isn't a lookahead just because this
      #   state is a consistent state with a default action.  There
      #   might have been a previous inconsistent state, consistent
      #   state with a non-default action, or user semantic action
      #   that manipulated self.yychar.  (However, self.yychar
      #   is currently out of scope during semantic actions.)
      # - Of course, the expected token list depends on states to
      #   have correct lookahead information, and it depends on the
      #   parser not to perform extra reductions after fetching a
      #   lookahead from the scanner and before detecting a syntax
      #   error.  Thus, state merging (from LALR or IELR) and default
      #   reductions corrupt the expected token list.  However, the
      #   list is correct for canonical LR with one exception: it
      #   will still contain any token that will not be accepted due
      #   to an error action in a later state.

      if (tok  != yyempty_) :
        # FIXME: This method of building the message is not compatible
        # with internationalization.
        res = "syntax error, unexpected "
        res += (self.yytnamerr_ (yytname_[tok]))
        tmp = self.yystate
        self.yyn = yypact_[tmp]
        if ( not yy_pact_value_is_default_ (self.yyn)) :
          # Start YYX at -YYN if negative to avoid negative
          # indexes in YYCHECK.  In other words, skip the first
          # -YYN actions for this state because they are default actions.
          yyxbegin = 0
          if (self.yyn < 0) :
            yyxbegin =  - self.yyn
          # Stay within bounds of both yycheck and yytname.
          yychecklim = yylast_ - self.yyn + 1
          yyxend = yychecklim
          if (yychecklim >= yyntokens_) :
            yyxend = yyntokens_
          count = 0
          for x in range(yyxbegin,yyxend) :
            tmp = self.yyn
            if (yycheck_[x + tmp] == x and x != yyterror_
                and  not yy_table_value_is_error_ (yytable_[x + tmp])) :
              count += 1
          if (count < 5) :
            count = 0
            for x in range(yyxbegin,yyxend) :
              tmp = self.yyn
              if (yycheck_[x + tmp] == x and x != yyterror_
                  and  not yy_table_value_is_error_ (yytable_[x + tmp])) :
                if (count == 0) :
                  res += ", expecting "
                else :
                  res += " or "
                count += 1
                res += (self.yytnamerr_ (yytname_[x]))
        return str(res)

    return "syntax error"
  # end yysyntax_error

# User implementation code; indented
  

# "./yax/test/calc.y":83 # python.skel:1396


def calc(ceh, n):
    sys.stdout.write("result={0}\n".format(str(n)))
#end calc

def bin_add(ceh, n1, n2):
  return n1 + n2
#end bin_add

def bin_sub(ceh, n1, n2):
  return n1 - n2
#end bin_sub

def bin_mul(ceh, n1, n2):
  return n1 * n2
#end bin_mul

def bin_exp(ceh, n1, n2):
  return int(math.pow(float(n1),float(n2)))
#end bin_exp

def un_neg(ceh, n1):
  return - n1
#end bin_neg

def number(ceh, event) :
    n = 0
    try :
      if(event.event == CHARACTERS):
        n = int(event.text)
      elif(event.event == ATTRIBUTE):
        n = int(event.value)
      else:
        yyerror("Unexpected event: "+ event.toString());
    except Exception as nfea:
        yyerror("Illegal number: "+ event.toString());
    return n;
#end number

