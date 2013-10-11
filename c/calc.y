/**
This software is released under the terms of the Apache License version 2.
For details of the license, see http://www.apache.org/licenses/LICENSE-2.0.
*/

%define api.pure full
%define api.push-pull push
%error-verbose

%parse-param {CalcEventHandler* ceh}
%printer {fprintf(yyoutput, "%d", $$); } <integer>
%printer {if($$ != NULL) fprintf(yyoutput, "%s", saxeventtypename($$->event)); } <event>

%union {
  int integer;
  SaxEvent* event;
}

%code requires {
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <calctest.h>
}

%code {
    static int calc(CalcEventHandler*,int n);
    static int bin_add(CalcEventHandler*,int n1, int n2);
    static int bin_sub(CalcEventHandler*,int n1, int n2);
    static int bin_mul(CalcEventHandler*,int n1, int n2);
    static int bin_div(CalcEventHandler*,int n1, int n2);
    static int bin_exp(CalcEventHandler*,int n1, int n2);
    static int un_neg(CalcEventHandler*,int n1);
    static int number(CalcEventHandler*,SaxEvent* event);
    static int constant(CalcEventHandler*,int n);

    void
    calcerror(CalcEventHandler* ceh, const char* msg, ...)
    {
        fprintf(stderr,"%s\n",msg);
	fflush(stderr);
    }
}

%token <event> CALC_ _CALC
%token <event> EQ_ _EQ
%token <event> ADD_ _ADD
%token <event> SUB_ _SUB
%token <event> MUL_ _MUL
%token <event> DIV_ _DIV
%token <event> EXP_ _EXP
%token <event> NEG_ _NEG
%token <event> INT_ _INT
%token <event> ATTR_N
%token <event> TEXT
%token <event> UNKNOWN_ATTR UNKNOWN_ELEMENT_ _UNKNOWN_ELEMENT

%type <integer> calc expr integer

%start calc

%%
calc:
	CALC_ exprlist _CALC {$$ = 0;}
	;

exprlist:
	  /*empty*/
	| exprlist expr
		{calc(ceh,$2);}
	;

expr:
	  EQ_ expr expr _EQ
		{$$ = ($2 == $3 ? 1 : 0);}
	| ADD_ expr expr _ADD
		{$$=bin_add(ceh,$2,$3);}
	| SUB_ expr expr _SUB
		{$$=bin_sub(ceh,$2,$3);}
	| MUL_ expr expr _MUL
		{$$=bin_mul(ceh,$2,$3);}
	| DIV_ expr expr _DIV
		{$$=bin_div(ceh,$2,$3);}
	| EXP_ expr expr _EXP
		{$$=bin_exp(ceh,$2,$3);}
	| NEG_ expr _NEG
		{$$=un_neg(ceh,$2);}
	| integer
		{$$=$1;}
	| error _CALC
		{$$=constant(ceh,0);}
	;

integer:
	  INT_ ATTR_N _INT
		{$$=number(ceh,$2);}
	| INT_ TEXT _INT
		{$$=number(ceh,$2);}
	;
%%

static int
calc(CalcEventHandler* ceh, int n)
{
    printf("result=%d\n",n);
    return 0;
}

static int
bin_add(CalcEventHandler* ceh, int n1, int n2)
{
    return n1 + n2;
}

static int
bin_sub(CalcEventHandler* ceh, int n1, int n2)
{
    return n1 - n2;
}

static int
bin_mul(CalcEventHandler* ceh, int n1, int n2)
{
    return n1 * n2;
}

static int
bin_div(CalcEventHandler* ceh, int n1, int n2)
{
    return n1 / n2;
}

static int
bin_exp(CalcEventHandler* ceh, int n1, int n2)
{
    return (int)powf(((float)n1),((float)n2));
}

static int
un_neg(CalcEventHandler* ceh, int n1)
{
    return - n1;
}

static int
number(CalcEventHandler* ceh, SaxEvent* event)
{
    int n;
    if(event->event == CHARACTERS) {
	sscanf(event->text,"%d",&n);
        return n;
    } else if(event->event == ATTRIBUTE) {
	sscanf(event->value,"%d",&n);
	return n;
    } else {
	char s[1024];
	snprintf(s,sizeof(s),"Illegal number: %s",
                saxeventstring(event,SXFLAG_NONE));
        yyerror(ceh,s);
    }
    return 0;
}

static int
constant(CalcEventHandler* ceh, int n)
{
    return n;
}
