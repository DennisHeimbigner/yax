/* Copyright 2009, UCAR/Unidata and OPeNDAP, Inc.
   See the COPYRIGHT file for more information. */

/*The lines down to DO NOT DELETE ... comment are specific to the C Parser.
  They will be commennted out when building a java parser.
*/
%error-verbose
%pure-parser
%lex-param {Parser* parser}
%parse-param {Parser* parser}


%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define YYDEBUG 1
#undef TRACE

#define CHECK(x) {if((x)==NULL) YYABORT;}
#define whitespace(c) ((c) > '\0' && (c) <= ' ')

#include "yax.h"

#define YXFLAGS (YXFLAG_ESCAPE|YXFLAG_TRIMTEXT)

typedef void* Object;

enum Operator {plus,minus,constant};

typedef struct Expr {
    enum Operator op;
    struct Expr* lhs;
    struct Expr* rhs;
    int number;
} Expr;

typedef struct Parser {
    yax_lexer* lexer;
    Expr* expr;
} Parser;

%}

%union {
   Expr* expr;
   yax_token token;
}

%{
/* Forward */
static Expr* number(Parser*, const char*);
static Expr* expr(Parser*, enum Operator, Expr*, Expr*);

int yylex(YYSTYPE *lvalp, Parser* parser);
int yyerror(Parser* state, const char* msg);
%}

%token <token> PLUS MINUS
%token <token> PLUSCLOSE MINUSCLOSE
%token <token> PLUSVALUE MINUSVALUE
%token <token> NUMBEROPEN NUMBERCLOSE
%token <token> VALUEATTR
%token <token> TEXT
%token <token> ERROR UNKNOWN UNEXPECTED

%type <expr> expr term number

%start expr

%%

expr: term {parser->expr = $1;} ;

term:
       number {$$=$1; CHECK($$);}
     | PLUS term term PLUSCLOSE
	{$$=expr(parser,plus,$2,$3); CHECK($$);}
     | MINUS term term MINUSCLOSE
	{$$=expr(parser,minus,$2,$3); CHECK($$);}
     ;

number:
       NUMBEROPEN VALUEATTR NUMBERCLOSE {$$=number(parser,$2.text); CHECK($$);}
     | NUMBEROPEN TEXT NUMBERCLOSE {$$=number(parser,$2.text); CHECK($$);}
     ;
%%


static int
allwhitespace(const char* text)
{
    int c;
    const char* p = text;
    if(p != NULL) {
        while((c=*p++)) {if(!whitespace(c)) return 0;}
    }
    return 1;
}


static Expr*
newexpr(Parser* parser)
{
    Expr* expr = (Expr*)calloc(1,sizeof(Expr));
    if(expr == NULL)
	yyerror(parser,"out of memory\n");
    return expr;
}

static Expr*
number(Parser* parser, const char* value)
{
    Expr* expr;

    if(value == NULL) {
        yyerror(parser,"<number> has no value\n");
	value = "0";
    }
    if(!(expr = newexpr(parser))) return expr;
    expr->op = constant;
    expr->number = atoi(value);
    return expr;
}

static Expr*
expr(Parser* parser, enum Operator op, Expr* e1, Expr* e2)
{
    Expr* expr;
    if(!(expr = newexpr(parser))) return expr;
    expr->op = op;
    expr->lhs = (Expr*)e1;
    expr->rhs = (Expr*)e2;
    return expr;
}

int
yylex(YYSTYPE *lvalp, Parser* parser)
{
    yax_err err = YAX_OK;
    yax_token* token = &lvalp->token;
    int yytoken = UNKNOWN;
    while(yytoken == UNKNOWN) {
	err = yax_nexttoken(parser->lexer,token);
        if(err) goto done;

#ifdef TRACE
	{
	char* trace = yax_trace(parser->lexer,token);
	printf("yylex: yax token = %s\n",trace);
	fflush(stdout);
	if(trace) free(trace);
	}
#endif

	switch(token->tokentype) {

	case YAX_OPEN:
	    if(strcmp("number",token->name)==0)
		yytoken = NUMBEROPEN;
	    else if(strcmp("plus",token->name)==0)
		yytoken = PLUS;
	    else if(strcmp("minus",token->name)==0)
		yytoken = MINUS;
	    else
		{yytoken=UNEXPECTED; goto done;}
	    break;

	case YAX_CLOSE:
	    if(strcmp("number",token->name)==0)
		yytoken = NUMBERCLOSE;
	    else if(strcmp("plus",token->name)==0)
		yytoken = PLUSCLOSE;
	    else if(strcmp("minus",token->name)==0)
		yytoken = MINUSCLOSE;
	    break;

	case YAX_EMPTYCLOSE:
	    if(strcmp("number",token->name)!=0)
		{yytoken=UNEXPECTED; goto done;}
	    yytoken = NUMBERCLOSE;
	    break;


	case YAX_ATTRIBUTE: /* ignore */
	    if(strcmp("value",token->name)==0)
	        yytoken = VALUEATTR;
	    else
		yytoken = ERROR;
	    break;

	case YAX_TEXT: /* ignore if only whitespace */
	    if(!allwhitespace(token->text))
		yytoken = TEXT;
	    break;

	case YAX_COMMENT: /* ignore */
	    break;

	case YAX_EOF:
	    yytoken = YYEOF;
	    break;

	default: {
	    char msg[1024];
	    snprintf(msg,sizeof(msg),"unknown token type: %d\n",token->tokentype);
	    yyerror(parser,msg);
	    yytoken = ERROR;
	    } break;
	}
    }

done:
    if(err) {
	yyerror(parser,yax_errstring(err));
	return ERROR;
    }
    return yytoken;
}

int
yyerror(Parser* state, const char* msg)
{
    fprintf(stderr,"%s\n",msg);
    return 0;
}

int
xmlparse(char* input, Expr** ep)
{
    yax_err err = YAX_OK;
    int result;
    Parser* parser = (Parser*)calloc(1,sizeof(Parser));
    err = yax_create(input,YXFLAGS,&parser->lexer);
    if(err) {
      fprintf(stderr,"%s\n",yax_errstring(err));
      exit(1);
    }
    result = yyparse(parser);
    if(ep) {
	*ep = (result == 0 ? parser->expr : NULL);
    }
    yax_free(parser->lexer);
    free(parser);
    return result;
}

static void
dumpexpr1(Expr* expr)
{
    if(expr == NULL) {printf("?"); return;}
    switch (expr->op) {
    case plus:
	printf("+(");
	dumpexpr1(expr->lhs);
	printf(",");
	dumpexpr1(expr->rhs);
	printf(")");
	break;
    case minus:
	printf("-(");
	dumpexpr1(expr->lhs);
	printf(",");
	dumpexpr1(expr->rhs);
	printf(")");
	break;
    case constant:
	printf("%d",expr->number);
	break;
    }
}

static void
dumpexpr(Expr* expr)
{
    if(expr == NULL) return;
    printf("expr=|");
    dumpexpr1(expr);
    printf("|\n");
}

static char*
getinput(char* filename)
{
      static char data[1<<18];
      char* pos = data;
      int rem = sizeof(data);
      int fd = open(filename,0);
      if(fd < 0) {
	perror(filename);
	exit(1);
      }
      for(;;) {
	int count = read(fd,pos,rem);
	if(count < 0) {
	    perror(filename);
	    exit(1);
	}
	if(count == 0) break;
	pos += count;
	rem -= count;
      }
      *pos = '\0';
      return data;
}

int
main(int argc, char** argv)
{
    char* input;
    Expr* expr;
  
    if(argc == 1) {
      fprintf(stderr,"no input\n");
      exit(1);
    }

    input = getinput(argv[1]);
    yydebug = 1;
    xmlparse(input,&expr);
    dumpexpr(expr);
    return 0;
}
