/**
This software is released under the terms of the Apache License version 2.
For details of the license, see http://www.apache.org/licenses/LICENSE-2.0.
*/

%define api.push-pull push
%define parse.error verbose

%define parser_class_name {CalcParser}

%code imports {
import sys
import math
from saxeventtype import *
}

%code lexer {
def yylex(self) : return ("0",None)
def yyerror(self,s) : sys.stderr.write(s+'\n')
}

%token <object>   CALC CALC_
%token <SaxEvent> EQ EQ_
%token <SaxEvent> ADD ADD_
%token <SaxEvent> SUB SUB_
%token <SaxEvent> MUL MUL_
%token <SaxEvent> DIV DIV_
%token <SaxEvent> EXP EXP_
%token <SaxEvent> NEG NEG_
%token <SaxEvent> INT INT_
%token <SaxEvent> ATTR_N
%token <SaxEvent> TEXT
%token <SaxEvent> UNKNOWN_ATTR UNKNOWN_ELEMENT UNKNOWN_ELEMENT_

%type <Integer> calc expr integer exprlist

%start calc

%%
calc:
        CALC exprlist CALC_ {$$=None}
        ;

exprlist: 
          /*empty*/  {$$=None}
        | exprlist expr
                {
                calc(self,$2)
                $$=None
                }
        ;

expr:
          EQ expr expr EQ_
                {
                if $2 == $3 : $$= 1
                else: $$ = 0
                }
        | ADD expr expr ADD_
                {$$=bin_add(self,$2,$3)}
        | SUB expr expr SUB_
                {$$=bin_sub(self,$2,$3)}
        | MUL expr expr MUL_
                {$$=bin_mul(self,$2,$3)}
        | DIV expr expr DIV_
                {$$=bin_div(self,$2,$3)}
        | EXP expr expr EXP_
                {$$=bin_exp(self,$2,$3)}
        | NEG expr NEG_
                {$$=un_neg(self,$2)}
        | integer
                {$$=$1}
        | error CALC_
                {$$=0}
        ;

integer:
          INT ATTR_N INT_
                {$$=number(self,$2)}
        | INT TEXT INT_
                {$$=number(self,$2)}
        ;
%%

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

