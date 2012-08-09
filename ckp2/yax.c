/* Copyright 2009, UCAR/Unidata
   See the COPYRIGHT file for more information.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "yax.h"

/*************************************************
Limitations vis-a-vis true xml:
1. no mixed content
2. no % support
3. limited support for xml prolog and DOCTYPE
**************************************************/

#undef XDEBUG

/* Alias for '\0' */
#define EOFCHAR '\0'

/* Whitespace characters */
#define whitespace(c) ((c) > '\0' && (c) <= ' ')

/* UTF8 characters; note that this is a way
   over-relaxed test because it basically will
   take any character greater than the 7bit
   ascii.
*/
#define utf8(c) (((c) & 0x80) != 0)

/* Ascii alpha chars */
#define alpha(c) (((c) >= 'a' && (c) <= 'z') || ((c) >= 'A' && (c) <= 'Z'))

/* Ascii numeric chars */
#define digit(c) ((c) >= '0' && (c) <= '9')

/* Characters legal as first char of an element or attribute name */
#define namechar1(c) (strchr(":_?",(c)) != NULL || alpha(c) || utf8(c))

/* Characters legal as greater than first char of an element or attribute name */
#define namecharn(c) (namechar1(c) || digit(c) || strchr("-.",(c)) != NULL)

/* Characters legal as character in a non-quoted attribute value;
   note that the quote chars are handled specially in collectattribute
*/
#define valuechar(c) (!whitespace(c) && strchr("=<>/",(char)(c)) == NULL)

#define incdata(c,state) \
        (c == '!' \
           && peek(0,state) == CLB \
           && peek(1,state) == 'C' \
           && peek(2,state) == 'D' \
           && peek(3,state) == 'A' \
           && peek(4,state) == 'T' \
           && peek(5,state) == 'A' \
           && peek(6,state) == CLB ? 1 : 0)

#define inprolog(c,state) \
        (c == '?' \
         && (peek(0,state) == 'x' || peek(0,state) == 'X') \
         && (peek(1,state) == 'm' || peek(1,state) == 'M') \
         && (peek(2,state) == 'l' || peek(2,state) == 'L') ? 1 : 0)

#define indoctype(c,state) \
        (c == '!' \
         && peek(0,state) == 'D' \
         && peek(1,state) == 'O' \
         && peek(2,state) == 'C' \
         && peek(3,state) == 'T' \
         && peek(4,state) == 'Y' \
         && peek(5,state) == 'P' \
         && peek(6,state) == 'E' ? 1 : 0)

/* Two versions */
#define incomment(c,state) \
        (c == '!' \
           && peek(0,state) == '-' \
           && peek(1,state) == '-' ? 1 : 0)

#define atcomment(c,state) \
        (c == CLT \
           && peek(0,state) == '!' \
           && peek(1,state) == '-' \
           && peek(2,state) == '-' ? 1 : 0)

/**************************************************/

#define SGT ">"
#define SLT "<"
#define CGT '>'
#define CLT '<'
#define CLB '['
#define CRB ']'
#define CQUOTE '"'
#define CSQUOTE '\''

#define ERROR 0

#define MAXTRACESIZE (1<<16)
#define MAXBACKUP (16)
#define MAXTEXT (12)

/**************************************************/
yax_token emptytoken = {0,NULL,NULL,0};

/* Define the lexer states */
typedef enum yax_lexstate { /* assign numbers for debugging */
YX_EOF = 0,             /* EOF^ */
YX_OPEN = 1,    /* ^<... */
YX_TEXT = 2,    /* >^... */
YX_EMPTYCLOSE = 3,      /* ^/>... */
YX_ATTRIBUTE = 4,   /* ...^aname=value... */
YX_UNDEFINED = 5,       /* need to search for a state */
} yax_lexstate;

struct yax_state {
    char* input; /* null-terminated string copy of the whole xml text */
    char* pos; /* next character to read */
    yax_lexstate state;
    char* lastelement;
    int  pushed;
    int flags;
};

/**************************************************/
#ifdef XDEBUG
#define XFAIL(e) {err=xbreakpoint(e);goto done;}
#define XTHROW(e) ((e)!=YAX_OK?xbreakpoint(e):(e))
#define XASSERT(expr) {if(!(expr)) {xbreakpoint(YAX_EINVAL);}}
#define XSTATE(state) xtracestate(state)
#else
#define XFAIL(e) {err=(e);goto done;}
#define XTHROW(e) (e)
#define XASSERT(expr) assert(expr)
#define XSTATE(state) (state)
#endif

#ifdef XDEBUG
static yax_err xbreakpoint(yax_err err) {
return err;
}

static char* statenames[] = {
"EOF",
"OPEN",
"TEXT",
"EMPTYCLOSE",
"ATTRIBUTE",
"UNDEFINED",
};

static yax_lexstate xtracestate(yax_lexstate state)
{
fprintf(stderr,"Moving to state: %s\n",statenames[(int)state]);
fflush(stderr);
return state;
}
#endif
/**************************************************/

#define charoffset(state) ((int)((state)->pos - (state)->input))

#define backup(state) {(state)->pos--;}
#define peek(i,state) ((state)->pos[(i)])

#define push(c,state) {(state)->pushed = (c);}
#define testpush(state) ((state)->pushed != 0)
#define unpush(c,state) {(c)=(state)->pushed;(state)->pushed = 0;}

#define skipn(i,state) {(state)->pos += (i);}

/* Point to current position */
#define mark(state) ((state)->pos)

/* Point to position preceding current  */
#define markprev(state) ((state)->pos-1)

#define terminate(pos) {*(pos) = '\0';}

/* return char at state->pos and incr state->pos */
static int
nextch(yax_state* state)
{
    int c;
    c = *state->pos++;
    return c;
}

/* skip whitespace and leave so nextch will pick up the char
   after the whitespace
*/

static void
skipwhitespace(yax_state* state)
{
    int c;
    for(;;) {
        c = nextch(state);
        if(!whitespace(c)) {backup(state); break;}
    }
}

/* Skip past a comment and any trailing whitespace */
static yax_err
skipcomment(yax_state* lexstate, int atstart)
{
    yax_err err = YAX_OK;
    int c;
#ifdef XDEBUG
    char* pos = NULL;
#endif

    if(atstart) skipn(1,lexstate);
    skipn(2,lexstate);
    /*case: <!--^ */
#ifdef XDEBUG
    pos = mark(lexstate);
#endif
    /* scan for end of comment */
    for(;;) {
        c = nextch(lexstate);
        /*case: <!--...X^, <!--...EOF */
        if(c == EOFCHAR) XFAIL(YAX_ECOMMENT);
        if(c == '-' && peek(0,lexstate) == '-'
                    && peek(1,lexstate) == CGT) {/* this is the end */
            /*case: <!--...-^-> */
            backup(lexstate);
            break;
        }
    }
#ifdef XDEBUG
    {char* end = mark(lexstate);
     int c = *end;
     *end = '\0';
     fprintf(stderr,"COMMENT = |%s|\n",pos);
     *end = c;
    }
#endif
    /*case: <!--...^--> */
    skipn(3,lexstate);      
    /*case: <!--...-->^_ */
    skipwhitespace(lexstate);
    /*case: <!--...-->_^ */
done:
    return XTHROW(err);
}

/**************************************************/
/* Forward */

static yax_err findstate(yax_state* lexstate);
static yax_err collecttext(yax_state*, yax_token*);
static yax_err collectattribute(yax_state*, yax_token*);
static yax_err collectcdata(yax_state*, yax_token*);
static yax_err collectprolog(yax_state*, yax_token*);
static yax_err collectdoctype(yax_state*, yax_token*);

/**************************************************/
/*
Strings found in the input are null terminated, which means
that characters in the input are overwritten.
With the following exceptions, those characters will have
been already processed (trailing quote) or can be ignored (whitespace).
The exceptions occur when the text to be null terminated ends by
abutting immediately against a lexical element.
Specifically:
1. If the last attribute is non-quoted and is immediately
   followed by e.g. '>' or '/>'.
2. For text between a the ending '>' of a group open and the next '<'.
Special casing is required for these cases and is marked by comments.
*/

yax_err
yax(yax_state* lexstate, yax_token* xmltoken)
{
    yax_err err = YAX_OK;
    int closure;
    int c;
    char* namestop = NULL;
    
    /* reset token */
    xmltoken->name = NULL;
    xmltoken->text = NULL;

retry:

    xmltoken->charno = charoffset(lexstate); /* default */

    if(lexstate->state == YX_UNDEFINED) {
        err = findstate(lexstate);
        if(err) {XFAIL(err);}
    }
    XASSERT(lexstate->state != YX_UNDEFINED);

    switch (lexstate->state) {

    case YX_OPEN: /*case: <^...*/
        c = nextch(lexstate);
        /*case: <^...*/
        if(c == EOFCHAR) {XFAIL(YAX_EEOF);}
        /* Check for comments, CDATA, prolog and DOCTYPE */
        if(incomment(c,lexstate)) {
            err = skipcomment(lexstate,0);
            if(err) XFAIL(err);
            lexstate->state = XSTATE(YX_UNDEFINED);
            goto retry;
        } else if(incdata(c,lexstate)) {
            err = collectcdata(lexstate,xmltoken);
            if(err) XFAIL(err);
            /* collect cdata will set the next state */
            break;
        } else if(inprolog(c,lexstate)) {
            err = collectprolog(lexstate,xmltoken);
            if(err) XFAIL(err);
            break;
        } else if(indoctype(c,lexstate)) {
            err = collectdoctype(lexstate,xmltoken);
            if(err) XFAIL(err);
            break;
        } 
        closure = (c == '/' ? 1 : 0);
        if(closure) {
	    xmltoken->charno = charoffset(lexstate);
	    c = nextch(lexstate);
	}
        /*cases: <n^ame... , </n^ame... */
        if(!namechar1(c)) {
            XFAIL(YAX_ENAMECHAR);
        }               
        xmltoken->name = markprev(lexstate);
        for(;;) {
            c = nextch(lexstate);
            if(c==EOFCHAR) XFAIL(YAX_EEOF);
            if(!namecharn(c)) break;
        }
        namestop = markprev(lexstate);
        /*cases: <name?^... , </name?^...; ? is any char */     
        if(whitespace(c)) {
            skipwhitespace(lexstate);
            c = nextch(lexstate);
        }
        /*cases: ...a^ttr=value, .../^>, ...>^ , <^!--*/
        while(atcomment(c,lexstate)) {
            /*cases:  <^!--*/
            err = skipcomment(lexstate,1);
            if(err) XFAIL(err);
            c = nextch(lexstate);
        }
        /*cases: ...a^ttr=value, .../^>, ...>^ */
        if(c == '/' && peek(0,lexstate) == CGT) {
            if(closure) {XFAIL(YAX_EGT);}
            c = nextch(lexstate);
            /*case: />^ */
            lexstate->state = XSTATE(YX_EMPTYCLOSE); 
        } else if(c == CGT) {
            if(closure) {
                /* closures have no text, only whitespace */
                lexstate->state = XSTATE(YX_UNDEFINED);
            } else              
                lexstate->state = XSTATE(YX_TEXT);
        } else {/* test for case: ...a^ttr=value */
            if(namechar1(c)) {
                /*cases: a^ttr=value */
                lexstate->state = XSTATE(YX_ATTRIBUTE);             
                backup(lexstate);
                /*cases: ^attr=value */
            } else {
                XFAIL(YAX_ECLOSURE);
            }
        }
        xmltoken->tokentype = (closure ? YAX_CLOSE : YAX_OPEN);
        if(namestop) {
            terminate(namestop);
            lexstate->lastelement = xmltoken->name;
        }
        if(xmltoken->name == NULL || strlen(xmltoken->name) == 0)
            XFAIL(YAX_ENAMENULL);
        break;

    case YX_EMPTYCLOSE: /*case: />^  */
        xmltoken->charno = charoffset(lexstate) - 2;
        xmltoken->tokentype = YAX_EMPTYCLOSE;
        /* Reuse the last element name */
        xmltoken->name = lexstate->lastelement;
        lexstate->state = XSTATE(YX_UNDEFINED);
        break;  

    case YX_TEXT: /*case: >^ */
        xmltoken->tokentype = YAX_TEXT;
        err = collecttext(lexstate,xmltoken);
        if(err) XFAIL(err);
        /* collect text will set the next state */
        break;

    case YX_ATTRIBUTE: /*case: <element...attr=value...,-->^*/
        err = collectattribute(lexstate,xmltoken);
        /* collect attribute will have properly set the state */
        if(err) XFAIL(err);
        xmltoken->tokentype = YAX_ATTRIBUTE;
        if(xmltoken->name == NULL || strlen(xmltoken->name)==0)
            XFAIL(YAX_ENAMENULL);
        break;  

    case YX_EOF:
        xmltoken->tokentype = YAX_EOF;
        lexstate->state = XSTATE(YX_EOF);
        break;

    default: XASSERT(0); break;
    }

done:
    return XTHROW(err);
}

/* set the lexstate properly */
static yax_err
findstate(yax_state* lexstate)
{
    yax_err err = YAX_OK;
    int c;
    skipwhitespace(lexstate);
    c = nextch(lexstate);
    if(c == CLT) lexstate->state = XSTATE(YX_OPEN);
    else if(c == EOFCHAR) lexstate->state = XSTATE(YX_EOF);
    else {XFAIL(YAX_ELT);}
done:
    return err;
}

static yax_err
collectcdata(yax_state* lexstate, yax_token* xmltoken)
{
    yax_err err = YAX_OK;
    char* pos;
    char* textstop = NULL;
    int c;

    /*case: <!^[CDATA[ */
    skipn(7,lexstate);
    /*case: <![CDATA[^ */
    pos = mark(lexstate);
    /* scan for end of cdata */
    for(;;) {
        c = nextch(lexstate);
        /*case: <![CDATA[...X^, <![CDATA[...EOF */
        if(c == EOFCHAR) XFAIL(YAX_ECDATA);
        if(c == CRB && peek(0,lexstate) == CRB
                    && peek(1,lexstate) == CGT) {/* this is the end */
            /*case: <![CDATA[...]^]> */
            break;
        }
    }
    /*case: <![CDATA[...]^]> */
    textstop = markprev(lexstate);
    skipn(2,lexstate);      
    /*case: <![CDATA[...]]>^ */
    if(textstop) terminate(textstop);
    xmltoken->text = pos;
    xmltoken->tokentype = YAX_CDATA;
    /* Set the state to undefined */
    lexstate->state = XSTATE(YX_UNDEFINED);

done:
    return XTHROW(err);
}

static yax_err
collectprolog(yax_state* lexstate, yax_token* xmltoken)
{
    yax_err err = YAX_OK;
    int c;

    /*case: <?^xml */
    /* force the version to be 1.0 */
    xmltoken->name = "version";
    xmltoken->text = "1.0";

    /* scan for trailing '?>' */
    for(;;) {
        c = nextch(lexstate);
        if(c == EOFCHAR) XFAIL(YAX_EPROLOG);
        if(c == '?' && peek(0,lexstate) == CGT) {/* this is the end */
            break;
        }
    }
    /*case: <?xml...?^> */
    nextch(lexstate);
    /*case: <?xml...?>^ */
    xmltoken->tokentype = YAX_PROLOG;
    /* Set the state to undefined */
    lexstate->state = XSTATE(YX_UNDEFINED);

done:
    return XTHROW(err);
}

static yax_err
collectdoctype(yax_state* lexstate, yax_token* xmltoken)
{
    yax_err err = YAX_OK;
    char* textstop = NULL;
    char* namestop = NULL;
    int c;

    /*case: <!^DOCTYPE */
    skipn(7,lexstate);
    /*case: <!DOCTYPE^ */
    /* Scan for starting name */
    skipwhitespace(lexstate);
    c = nextch(lexstate);    
    if(!namechar1(c)) XFAIL(YAX_EDOCTYPE);
    xmltoken->name = markprev(lexstate);
    for(;;) {
        if(c == EOFCHAR) XFAIL(YAX_EDOCTYPE);
        if(!namecharn(c)) break;
        c = nextch(lexstate);
    }
    namestop = markprev(lexstate);
    /* check for empty start name */
    if(xmltoken->name == namestop)
        XFAIL(YAX_EDOCTYPE);

    /*case: ...name?^... */

    if(whitespace(c)) {
        skipwhitespace(lexstate);
        c = nextch(lexstate);
    }

    /*<|expected cases: ...[^..., ...>^, ...N^NNN... |]*/
    if(c == CLB) {
        /*[| collect everything upto the final ']'
           and make it be the text field of the token */
        /*<|case: ...[^...>   |]*/
        xmltoken->text = markprev(lexstate);
        /*[| scan for ']' */
        for(;;) {
            if(c == EOFCHAR) XFAIL(YAX_EDOCTYPE);
            if(c == CRB) break;
            c = nextch(lexstate);
        }
        /*[<|case: ...]^> */
        textstop = mark(lexstate);
        skipwhitespace(lexstate);
        /*[<|case: ...]_^> */
        c = nextch(lexstate);
        /*[<|case: ...]_>^ */
        if(c != CGT) XFAIL(YAX_EDOCTYPE);
    } else if(c == CGT) {
        /*<|case: ...>^*/
        xmltoken->text = NULL;
    } else if(namechar1(c)) {
        /*case: ...N^NN...*/
        xmltoken->text = markprev(lexstate);
        for(;;) {
            if(c == EOFCHAR) XFAIL(YAX_EDOCTYPE);
            if(!namecharn(c)) break;
            c = nextch(lexstate);
        }
        /*case: ...ID^...*/     
        /* ID must be either "SYSTEM" or "PUBLIC" */
        if(strncmp("SYSTEM",xmltoken->text,strlen("SYSTEM")) != 0
           && strncmp("PUBLIC",xmltoken->text,strlen("PUBLIC")) != 0) {
            XFAIL(YAX_EDOCTYPE);
        }
        /* collect everything upto the final CGT and make it be the text field of the token */
        for(;;) {
            if(c == EOFCHAR) XFAIL(YAX_EDOCTYPE);
            if(c == CGT) break;
            c = nextch(lexstate);
        }
        assert(c == CGT);
        /*<case: ...ID....>^ */
        textstop = markprev(lexstate);  
    } else {
        XFAIL(YAX_EDOCTYPE);
    }
    if(textstop) terminate(textstop);
    if(namestop) terminate(namestop);
    xmltoken->tokentype = YAX_DOCTYPE;
    /* Set the state to undefined */
    lexstate->state = XSTATE(YX_UNDEFINED);

done:
    return XTHROW(err);
}

static yax_err
collecttext(yax_state* lexstate, yax_token* xmltoken)
{
    yax_err err = YAX_OK;
    int nonwhite; /*1 => not all white space */
    int c;
    char* textstop;
    int flags = lexstate->flags;

    /*case: >^... <*/
    xmltoken->text = mark(lexstate);
    nonwhite = 0;
    for(;;) {
        c = nextch(lexstate);
        if(c == EOFCHAR)
            break;
        if(c == CLT)
            break;
        if(!whitespace(c))
            nonwhite = 1;
        /* move to next character */
    }/*for*/
    if(c == EOFCHAR) {
        if(nonwhite) XFAIL(YAX_ETEXT);
        /* all white space => treat as eof instead of text*/
        xmltoken->tokentype = YAX_EOF;
        lexstate->state = XSTATE(YX_EOF);
    } else {
        assert(c == CLT);
        textstop = markprev(lexstate);
        if(flags & YXFLAG_TRIMTEXT) {
            if(nonwhite) {
                /* remove prefixed whitespace */
                while(whitespace(*xmltoken->text)) {
                    ++xmltoken->text;
                }
                /* remove suffixed whitespace */
                do {
                    textstop--;
                } while(whitespace(*textstop));
                /* now move forward 1 char */
                textstop++;
            } else {
                /* a zero-length trimmed text is treated as NULL */
                xmltoken->text = NULL;
                textstop = NULL;
            }
        }
        /* In this case, we know the next state */
        lexstate->state = YX_OPEN;
    }
    if(textstop) terminate(textstop);
done:
    return err;
}

/* Collect and return an attribute; set state for next pass */
static yax_err
collectattribute(yax_state* lexstate, yax_token* token)
{
    yax_err err = YAX_OK;
    char* namestop = NULL;
    char* valuestop = NULL;
    int c,quote;

    /*cases: ...^_attrname... */
    skipwhitespace(lexstate);
    XASSERT(namechar1(peek(0,lexstate)));
    /* capture the attribute name */
    token->name = mark(lexstate);
    token->text = NULL;
    for(;;) {
        c=nextch(lexstate); /* skip current name char */
        if(c == EOFCHAR) break;
        /*cases: ...NNN^NNN... ...NNN?^...; N is a namechar ? is any char*/
        if(!namecharn(c)) {
            /*cases: ...NNN?^... */
            namestop = markprev(lexstate); /* save termination point */
            break;
        }
    }
    /*cases: ...NNN?^..., EOF */
    if(whitespace(c)) {
        skipwhitespace(lexstate);
        c = nextch(lexstate);
    }
    if(c == EOFCHAR) {XFAIL(YAX_EEQUAL);}
    if(c != '=')  {XFAIL(YAX_EEQUAL);}
    /*cases: ...NNN_=^_ ... ; _ is whitespace */
    skipwhitespace(lexstate);
    c = nextch(lexstate);
    /* Collect attribute value */
    /*cases: name_=_V^VV,name_=_Q^VVVQ, name_=_/^>, name_=_>^;
      V is value char,Q is quote */
    quote = 0;
    if(c == CQUOTE || c == CSQUOTE) {
        quote = c;
        token->text = mark(lexstate);
    } else if(valuechar(c)) {
        token->text = markprev(lexstate);
    } else {
        XFAIL(YAX_EVALUE);
    }
    /*cases: ...name_=_^VVV ..., ...name_=_Q^VVVQ...*/
    for(;;) {
        /*cases: ...^VVV, ...^VVVQ... */
        c=nextch(lexstate);
        if(c == EOFCHAR) break;
        /*cases: ...V^VV, ...V^VVQ..., ...VVVQ^...., EOF */
        if(quote && c == quote)
            break;
        /*cases: ...V^VV, ...VVV?^; ? is not a value char */
        if(!quote && !valuechar(c))
            break;
        /*cases: ...V^VV, ...VVV^? */
    }
    /*cases: ...QvalueQ^...value?^; where ? is not value char or quote */
    valuestop = markprev(lexstate);
    /*cases: ...value^_?, ...value?^, ...QvalueQ^...*/
    /* move to the next possible attribute */
    if((quote && c == quote) || whitespace(c)) {
        skipwhitespace(lexstate);
        c = nextch(lexstate);
    }   
    /* absorb any comments */
    while(atcomment(c,lexstate)) {
        /*cases:  <^!--*/
        err = skipcomment(lexstate,1);
        if(err) XFAIL(err);
        c = nextch(lexstate);
    }
    if(c == '/' && peek(0,lexstate) == CGT ) {
        /*cases: ..VVV/^> */
        nextch(lexstate);
        /*cases: ..VVV/>^ */
        lexstate->state = XSTATE(YX_EMPTYCLOSE);
    } else if(c == CGT ) {
        /*cases: ..VVV>^ */
        lexstate->state = XSTATE(YX_TEXT);
    } else if(namechar1(c)) {
        backup(lexstate);
        /*case: ...^aname... */
        lexstate->state = XSTATE(YX_ATTRIBUTE);
    } else {XFAIL(YAX_ECLOSURE);}
    if(namestop) {
        terminate(namestop);
    }
    if(valuestop) terminate(valuestop);
done:
    return err;
}

yax_err
yax_create(const char* input, int flags, yax_state** statep)
{
    yax_err err = YAX_OK;
    yax_state* state = (yax_state*)calloc(1,sizeof(yax_state));
    if(state == NULL) return YAX_ENOMEM;
    if(input == NULL) return YAX_EINVAL;
    state->input = strdup(input);
    state->pos = state->input;
    state->state = YX_UNDEFINED;
    state->flags = flags;
    if(!err && statep) *statep = state;
    return err;
}

yax_err
yax_free(yax_state* state)
{
    if(state != NULL) {
        if(state->input) free(state->input);
        free(state);
    }
    return YAX_OK;
}

int
yax_getflags(yax_state* state)
{
    return (state?state->flags:0);
}

void
yax_setflags(yax_state* state, int flags)
{
    if(state != NULL) {
        state->flags = flags;
    }
}

#ifdef ENTITYPARSE
static int
skipentity(yax_state* lexstate)
{
    char* save;
    int count,c;
    save = mark1(lexstate);
    /* skip the entity name, but leave in the collected text */
    c=nextch(lexstate); /* skip the ampersand */
    count = 1;
    for(;;) {
        c=nextch(lexstate);
        if(c == EOFCHAR) break;
        if(c != ';' && !namecharn(c)) break;
        count++;
        if(c == ';') {
            return count;
        }           
    }
    /* wasn't an entity after all */
    setmark1(lexstate,save); 
    return 1; /* always skip the ampersand */
}
#endif

/* Unescape entities in a string.
   The translations argument is in envv form
   with position n being the entity name and
   position n+1 being the translation and last
   position being null.
*/
char*
yax_unescape(char* s, char** translations)
{
    int count,found,len;
    char* u; /* returned string with entities unescaped */
    char* p; /* insertion point into u */
    char* q; /* next char from s */
    char* stop;
    char entity[16];

    if(s == NULL) len = 0;
    else len = strlen(s);
    u = (char*)malloc(len+1);
    if(u == NULL) return NULL;
    p = u;
    q = s;
    stop = (s + len);

    while(q < stop) {
        int c = *q++;
        switch (c) {
        case '&': /* see if this is a legitimate entity */
            /* move forward looking for a semicolon; */
            for(found=1,count=0;count < sizeof(entity);count++) {
                c = q[count];
                if(c == ';')
                    break;
                if(   (count==0 && !namechar1(c))
                   || (count > 0 && !namecharn(c))) {
                    found=0; /* not a legitimate entity */
                    break;
                }
                entity[count] = c;
            }
            if(count == sizeof(entity) || count == 0 || !found) {
                /* was not in correct form for entity */
                *p++ = '&';
            } else { /* looks legitimate */
                char** pos = translations;
                char* replacement = NULL;
                entity[count] = '\0'; /* null terminate */
                /* check the translation table */
                while(*pos) {
                    if(strcmp(*pos,entity)==0) {
                        replacement = pos[1];
                        break;
                    }
                    pos += 2;                   
                }
                if(replacement == NULL) { /* no translation, ignore */
                    *p++ = '&';
                } else { /* found it */
                    int replen = strlen(replacement);
                    q += (count+1) ; /* skip input entity, including trailing semicolon */
                    memcpy(p,replacement,replen);
                    p += replen;
                }
            }
            break;
        default:
            *p++ = (char)c;
            break;
        }
    }
    *p = '\0';
    return u;
}

static char* tokennames[] = {
"EOF",
"OPEN",
"CLOSE",
"EMPTYCLOSE",
"ATTRIBUTE",
"TEXT",
"CDATA",
"PROLOG",
"DOCTYPE",
};

static char* tracetranstable[] = {
"amp","&",
"lt","<",
"gt",">",
"quot","\"",
"apos","'",
NULL
};

static const char*
tokenname(yax_tokentype token)
{
    int itoken = (int)token;
    int ntokens = (sizeof(tokennames)/sizeof(char*));
    if(itoken >= 0 && itoken < ntokens) {
        return tokennames[itoken];
    }
    return "UNKNOWN";
}

static void
addtext(char* dst, const char* txt, int flags)
{
    int c;
    int len;
    char* pos;
    int shortened = 0;

    if(txt == NULL) {
        strcat(dst,"null");
        return;
    }
    len = strlen(txt);
    if(flags & YXFLAG_ELIDETEXT && len > MAXTEXT) {
        len = MAXTEXT;
        shortened = 1;
    }
    pos = dst + strlen(dst);
    *pos++ = '|';
    while((c=*txt++)) {
        if(len-- <= 0) continue;
        if((flags & YXFLAG_ESCAPE) && c < ' ') {
            *pos++ = '\\';
            switch (c) {
            case '\n': *pos++ = 'n'; break;
            case '\r': *pos++ = 'r'; break;
            case '\f': *pos++ = 'f'; break;
            case '\t': *pos++ = 't'; break;
            default: {/* convert to octal */
                unsigned int uc = (unsigned int)c;
                unsigned int oct;
                oct = ((uc >> 6) & 077);
                *pos++ = (char)('0'+ oct);
                oct = ((uc >> 3) & 077);
                *pos++ = (char)('0'+ oct);
                oct = ((uc) & 077);
                *pos++ = (char)('0'+ oct);
                } break;
            }
        } else if((flags & YXFLAG_NOCR) && c == '\r') {
            continue;
        } else {
            *pos++ = (char)c;       
        }
    }
    if(shortened) {
        *pos++ = '.'; *pos++ = '.'; *pos++ = '.';
    }
    *pos++ = '|';
    *pos = '\0';
}

/*
  Provide a procedure for generating a string
  representing the contents of an yax_token instance.
  Primarily for use for debugging.
  Caller must free returned string.

*/

char*
yax_trace(yax_state* lexstate, yax_token* token)
{
    char tmp[1<<12];
    char* result;
    const char* tname;
    char* trans;

    result = (char*)malloc(MAXTRACESIZE+1);
    if(result == NULL) return NULL;
    result[0] = '\0';

    snprintf(tmp,sizeof(tmp),"%d: ",token->charno);
    strcat(result,tmp);
    tname = tokenname(token->tokentype);
    strcat(result,tname);
    switch(token->tokentype) {
    case YAX_OPEN:
    case YAX_CLOSE:
    case YAX_EMPTYCLOSE:
        strcat(result,": element=|");
        strcat(result,token->name);
        strcat(result,"|");
        break;
    case YAX_TEXT:
        trans = NULL;
        strcat(result," text=");
        addtext(result,token->text,lexstate->flags);
        trans = yax_unescape(token->text,tracetranstable);
        strcat(result," translation=");
        addtext(result,trans,lexstate->flags);
        if(trans) free(trans);
        break;
    case YAX_ATTRIBUTE:
        strcat(result,": name=");
        addtext(result,token->name,lexstate->flags);
        strcat(result," value=");
        addtext(result,token->text,lexstate->flags);
        break;
    case YAX_CDATA:
        strcat(result,": text=");
        addtext(result,token->text,lexstate->flags);
        break;
    case YAX_DOCTYPE:
    case YAX_PROLOG:
        strcat(result,": name=");
        addtext(result,token->name,lexstate->flags);
        strcat(result," value=");
        addtext(result,token->text,lexstate->flags);
        break;
    case YAX_EOF:
        break;
    default:
        XASSERT(0);
    }
    return result;
}

/* Convert an error code to a human readable string */
const char*
yax_errstring(yax_err err)
{
    const char* msg = NULL;
    if(err == 0)
        msg = "No error";
    else if(err > 0) {
      msg = (const char *) strerror((int)err);
      if(msg == NULL) msg = "Unknown Error";
    } else {/*err < 0 */
        switch(err) {
        case YAX_ENOMEM: msg = "Out of Memory"; break;
        case YAX_EINVAL: msg = "Invalid argument"; break;
        case YAX_EEOF: msg = "Unexpected EOF"; break;
        case YAX_ECLOSURE: msg = "Expected /,>,or attribute name"; break;
        case YAX_EGT: msg = "Expected >"; break;
        case YAX_ELT: msg = "Expected <"; break;
        case YAX_ENAMECHAR: msg = "Illegal leading name character"; break;
        case YAX_ENATTR: msg = "Too many attributes"; break;
        case YAX_EEQUAL: msg = "Expected '=' after attribute name"; break;
        case YAX_EVALUE: msg = "Expected attribute value"; break;
        case YAX_ECOMMENT: msg = "Comment is missing trailing '-->'"; break;
        case YAX_ECDATA: msg = "Cdata is missing trailing ']]>'"; break;
        case YAX_EPROLOG: msg = "Malformed <?xml...> prolog"; break;
        case YAX_EDOCTYPE: msg = "Malformed <!DOCTYPE...>"; break;
        case YAX_ENAMENULL: msg = "Name is zero length"; break;
        case YAX_ETEXT: msg = "Non-whitespace text encountered"; break;

        default: msg = "Undefined error code"; break;
        }
    }
    return msg;
}

yax_token*
yax_tokendup(yax_token token)
{
    yax_token* t = (yax_token*)malloc(sizeof(yax_token));
    if(t != NULL)
	*t = token;
    return t;
}
