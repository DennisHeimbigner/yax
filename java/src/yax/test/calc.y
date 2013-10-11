/**
This software is released under the terms of the Apache License version 2.
For details of the license, see http://www.apache.org/licenses/LICENSE-2.0.
*/

%language "Java"
%define api.push-pull push
%define parse.error verbose

%define public
%define parser_class_name {CalcParser}
%define extends {CalcTest}
%define package {yax.test}

%code imports {
import yax.*;
}

%code lexer {
public Object getLVal() {return null;}
public int yylex() {return 0;}
public void yyerror(String s) {System.err.println(s);}
}

%code  {

void
calc(Object n)
{
    System.out.printf("result=%s\n",n.toString());
}

Integer bin_add(Integer n1, Integer n2) {return n1 + n2;}

Integer bin_sub(Integer n1, Integer n2) {return n1 - n2;}

Integer bin_mul(Integer n1, Integer n2) {return n1 * n2;}

Integer bin_div(Integer n1, Integer n2) {return n1 / n2;}

Integer bin_exp(Integer n1, Integer n2) {return n1 ^ n2;}

Integer un_neg(Integer n1) {return - n1;}

Integer
number(SaxEvent event)
{
    int n = 0;
    try {
      if(event.event == SaxEventType.CHARACTERS)
	n = Integer.parseInt(event.text);
      else if(event.event == SaxEventType.ATTRIBUTE)
	n = Integer.parseInt(event.value);
      else
	yyerror("Unexpected event: "+ event.toString());
    } catch (NumberFormatException nfe) {
	yyerror("Illegal number: "+ event.toString());
    }
    return n;
}

} /*%code*/

%token CALC_ _CALC
%token <SaxEvent> EQ_ _EQ
%token <SaxEvent> ADD_ _ADD
%token <SaxEvent> SUB_ _SUB
%token <SaxEvent> MUL_ _MUL
%token <SaxEvent> DIV_ _DIV
%token <SaxEvent> EXP_ _EXP
%token <SaxEvent> NEG_ _NEG
%token <SaxEvent> INT_ _INT
%token <SaxEvent> ATTR_N
%token <SaxEvent> TEXT
%token <SaxEvent> UNKNOWN_ATTR UNKNOWN_ELEMENT_ _UNKNOWN_ELEMENT

%type <Integer> calc expr integer exprlist

%start calc

%%
calc:
	CALC_ exprlist _CALC {$$=null;}
	;

exprlist: 
	  /*empty*/  {$$=null;}
	| exprlist expr
		{calc($2); $$=null;}
	;

expr:
	  EQ_ expr expr _EQ
		{$$ = ($2 == $3 ? new Integer(1) : new Integer(0));}
	| ADD_ expr expr _ADD
		{$$=bin_add($2,$3);}
	| SUB_ expr expr _SUB
		{$$=bin_sub($2,$3);}
	| MUL_ expr expr _MUL
		{$$=bin_mul($2,$3);}
	| DIV_ expr expr _DIV
		{$$=bin_div($2,$3);}
	| EXP_ expr expr _EXP
		{$$=bin_exp($2,$3);}
	| NEG_ expr _NEG
		{$$=un_neg($2);}
	| integer
		{$$=$1;}
	| error _CALC
		{$$=new Integer(0);}
	;

integer:
	  INT_ ATTR_N _INT
		{$$=number($2);}
	| INT_ TEXT _INT
		{$$=number($2);}
	;
%%
