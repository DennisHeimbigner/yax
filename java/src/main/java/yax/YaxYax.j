/* Copyright 2009, UCAR/Unidata
   See the COPYRIGHT file for more information.
*/

//////////////////////////////////////////////////
/*
Limitations vis-a-vis true xml:
1. no mixed content
2. no % support
3. limited support for xml prolog and DOCTYPE
*/
//////////////////////////////////////////////////

package yax;


public class YaxYax {

//////////////////////////////////////////////////
// publically accessible classes and constants

/* Define the token types */
public enum TokenType { /* assign number for trace function */
YAX_EOF,
YAX_OPEN,
YAX_CLOSE,
YAX_EMPTYCLOSE,
YAX_ATTRIBUTE,
YAX_TEXT,
YAX_CDATA,
YAX_PROLOG,
YAX_DOCTYPE;
};

/* Common Flag Set */
static public final int FLAG_NONE	  = 0;
static public final int FLAG_ESCAPE	  = 1; //convert \n,\r, etc to \\ form
static public final int FLAG_NOCR	  = 2; // elide \r
static public final int FLAG_ELIDETEXT  = 4; // only print the first 12 characters of text
static public final int FLAG_TRIMTEXT   = 8; //remove leading and trailing whitespace;
                                     // if result is empty, then ignore

/* Define the state associated with a token */
static public class Token
{
    public TokenType tokentype; // Do not use get/set for this field
    // Depending on token type, only some of these will have values
    public String name; // element or attribute name
    public String text; // text or attribute value
    public int charno;  // Position of this token in input
    public Token(Token t)
    {
	this.tokentype = t.tokentype;
	this.name = t.name;
	this.text = t.text;
	this.charno = t.charno;
    }

    public Token()
    {
	tokentype = TokenType.YAX_EOF;
	name = null;
	text = null;
	charno = 0;
    }
}

// Define an empty token
public Token emptytoken = new Token();

static public class Exception extends java.lang.Exception
{
    public Exception() {super();}
    public Exception(String message) {super(message);}
    public Exception(String message, Throwable cause) {super(message,cause);}
    public Exception(Throwable cause) {super(cause);}
    public Exception(int errcode) {super(Yax.errstring(errcode));}
}

public static String[][] DEFAULTTRANSTABLE = {
{"amp","&"},
{"lt","<"},
{"gt",">"},
{"quot","\""},
{"apos","'"},
};

//////////////////////////////////////////////////

static final int YAX_OK		= (  0);
static final int YAX_ENOMEM	= ( -1);
static final int YAX_EINVAL	= ( -2);
static final int YAX_EEOF	= ( -3);
static final int YAX_ECLOSURE	= ( -4);
static final int YAX_EGT	= ( -5);
static final int YAX_ELT	= ( -6);
static final int YAX_ENAMECHAR	= ( -7);
static final int YAX_ENATTR	= ( -8);
static final int YAX_EEQUAL	= ( -9);
static final int YAX_EVALUE	= (-10);
static final int YAX_ECOMMENT	= (-11);
static final int YAX_ECDATA	= (-12);
static final int YAX_EPROLOG	= (-13);
static final int YAX_EDOCTYPE	= (-14);
static final int YAX_ENAMENULL	= (-15);
static final int YAX_ETEXT	= (-16);

static final boolean XDEBUG = false;

// Alias for '\0' 
static final char EOFCHAR = '\0';

static final String SGT = ">";
static final String SLT = "<";
static final char CGT = '>';
static final char CLT = '<';
static final char CLB = '[';
static final char CRB = ']';
static final char CQUOTE = '"';
static final char CSQUOTE = '\'';

static final int ERROR = 0;

static final int MAXTRACESIZE = (1<<16);
static final int MAXBACKUP = (16);
static final int MAXTEXT = (12);

static final int NULLPOS = -1;

//////////////////////////////////////////////////
// Character class tests 

// Whitespace characters 
static boolean whitespace(char c) {return ((c) > '\0' && (c) <= ' ');}

/* UTF8 characters; note that this is a way
   over-relaxed test because it basically will
   take any character greater than the 7bit
   ascii.
*/

static boolean utf8(char c) {return (((c) & 0x80) != 0);}

// Ascii alpha chars 
static boolean alpha(char c)
{
    return (((c) >= 'a' && (c) <= 'z') || ((c) >= 'A' && (c) <= 'Z'));
}

// Ascii numeric chars 
static boolean digit(char c) {return ((c) >= '0' && (c) <= '9');}

// Characters legal as first char of an element or attribute name 
static boolean namechar1(char c) 
{
    return (":_".indexOf(c) >= 0 || alpha(c) || utf8(c));
}

// Characters legal as greater than first char of an element or attribute name 
static boolean namecharn(char c)
{
    return (namechar1(c) || digit(c) || "-._:".indexOf(c) >= 0);
}

// Characters legal as character in a non-quoted attribute value;
// note that the quote chars are handled specially in collectattribute

static boolean valuechar(char c)
{
    return (!whitespace(c) && "=<>/".indexOf(c) >= 0);
}

//////////////////////////////////////////////////

// Define the lexer states 
enum LexState { // assign numbers for debugging 
YX_EOF,             // EOF^ 
YX_OPEN,    // ^<... 
YX_TEXT,    // >^... 
YX_EMPTYCLOSE,      // ^/>... 
YX_ATTRIBUTE,   // ...^aname=value... 
YX_UNDEFINED;       // need to search for a state 
};

static String[] statenames = {
"EOF",
"OPEN",
"TEXT",
"EMPTYCLOSE",
"ATTRIBUTE",
"UNDEFINED",
};


//////////////////////////////////////////////////
// Debug


//////////////////////////////////////////////////
// Instance variables 

String input = null; // whole xml document
int pos = 0; // next character to read 
LexState state = null;
String lastelement = null;
char  pushed = EOFCHAR;
int flags = 0;

//////////////////////////////////////////////////
// Constructor

public
YaxYax(String input, int flags)
    throws Yax.Exception
{
    if(input == null) throw new Yax.Exception(YAX_EINVAL);
    this.input = input;
    this.pos = 0;
    this.state = LexState.YX_UNDEFINED;
    this.flags = flags;
}

//////////////////////////////////////////////////
// Instance Methods

//////////////////////////////////////////////////
// Debug

LexState
xtracestate(LexState lexstate)
{
if(XDEBUG) {
  System.err.printf("Moving to state: %s\n",statenames[lexstate.ordinal()]);
  System.err.flush();
}
  return lexstate;
}

// Character class tests

boolean
incdata(char c)
{
    return
        (c == '!'
           && peek(0) == CLB
           && peek(1) == 'C'
           && peek(2) == 'D'
           && peek(3) == 'A'
           && peek(4) == 'T'
           && peek(5) == 'A'
           && peek(6) == CLB);
}

boolean
inprolog(char c)
{
    return
        (c == '?'
         && (peek(0) == 'x' || peek(0) == 'X')
         && (peek(1) == 'm' || peek(1) == 'M')
         && (peek(2) == 'l' || peek(2) == 'L'));
}

boolean
indoctype(char c)
{
    return
        (c == '!'
         && peek(0) == 'D'
         && peek(1) == 'O'
         && peek(2) == 'C'
         && peek(3) == 'T'
         && peek(4) == 'Y'
         && peek(5) == 'P'
         && peek(6) == 'E');
}

// Two versions 
boolean
incomment(char c)
{
    return
        (c == '!'
           && peek(0) == '-'
           && peek(1) == '-');
}

boolean
atcomment(char c)
{
    return
        (c == CLT
           && peek(0) == '!'
           && peek(1) == '-'
           && peek(2) == '-');
}

// Misc. Support methods

int charoffset() {return ((int)(pos));}

void backup() {pos--;}

char peek(int i) {return (input.charAt(pos+(i)));}

// Get ith char
char ith(int i) {return (input.charAt((i)));}

// Pull out the null terminated string at offset pos
String
xcstring(int pos)
{
    int nulpos;
    for(nulpos=pos;input.charAt(nulpos) != EOFCHAR;nulpos++);
    return input.substring(pos,nulpos);
}

boolean
strnequal(String match,int pos)
{
    int len = match.length();
    if(pos+len > input.length()) return false;
    return match.equals(input.substring(pos,pos+len));
}

void push(char c) 
{
    assert(c != 0);
    pushed = (c);
}
boolean testpush() {return pushed != EOFCHAR;}
char unpush() {char c=pushed; pushed = EOFCHAR; return c;}

void skipn(int i) {pos += (i);}

// Point to current position 
int mark() {return pos;}

// Point to position preceding current  
int markprev() {return pos-1;}

String
getString(int start, int stop)
{
    return input.substring(start,stop);
}

// return char at state.pos and incr state.pos 
char
nextch()
{
    char c;
    if(pos >= input.length())
        c = EOFCHAR;
    else
        c = input.charAt(pos);
    pos++;
    return c;
}

// skip whitespace and leave so nextch will pick up the char
//   after the whitespace

void
skipwhitespace()
{
    for(;;) {
        char c = nextch();
        if(!whitespace(c)) {
            if(pos <= input.length()) backup();
            break;
        }
    }
}

// Skip past a comment and any trailing whitespace 
void
skipcomment(boolean atstart)
    throws Yax.Exception
{
    char c;

    if(atstart) skipn(1);
    skipn(2);
    //case: <!--^ 
if(XDEBUG) {
    int pos = mark();
}
    // scan for end of comment 
    for(;;) {
        c = nextch();
        //case: <!--...X^, <!--...EOF 
        if(c == EOFCHAR) throw new Yax.Exception(YAX_ECOMMENT);
        if(c == '-' && peek(0) == '-'
                    && peek(1) == CGT) {// this is the end 
            //case: <!--...-^->
            backup();
            break;
        }
    }
if(XDEBUG) {
    {int end = mark();
     System.err.printf("COMMENT = |%s|\n",getString(pos,end));
    }
}
    //case: <!--...^-->
    skipn(3);      
    //case: <!--...-->^_ 
    skipwhitespace();
    //case: <!--...-->_^ 
}

// set the lexstate properly 
LexState
findstate()
    throws Yax.Exception
{
    LexState st = null;
    char c;
    skipwhitespace();
    c = nextch();
    if(c == CLT) st = xtracestate(LexState.YX_OPEN);
    else if(c == EOFCHAR) st = xtracestate(LexState.YX_EOF);
    else {throw new Yax.Exception(YAX_ELT);}
    return st;
}

void
collectcdata(Token xmltoken)
    throws Yax.Exception
{
    int pos;
    int textstart = NULLPOS;
    int textstop = NULLPOS;
    char c;

    //case: <!^[CDATA[ 
    skipn(7);
    //case: <![CDATA[^ 
    pos = mark();
    // scan for end of cdata 
    for(;;) {
        c = nextch();
        //case: <![CDATA[...X^, <![CDATA[...EOF 
        if(c == EOFCHAR) throw new Yax.Exception(YAX_ECDATA);
        if(c == CRB && peek(0) == CRB
                    && peek(1) == CGT) {// this is the end 
            //case: <![CDATA[...]^]> 
            break;
        }
    }
    //case: <![CDATA[...]^]> 
    textstop = markprev();
    skipn(2);      
    //case: <![CDATA[...]]>^ 
    xmltoken.text = getString(textstart,textstop);
    xmltoken.tokentype = TokenType.YAX_CDATA;
    // Set the state to undefined 
    state = xtracestate(LexState.YX_UNDEFINED);
}

void
collectprolog(Token xmltoken)
    throws Yax.Exception
{
    char c;
    int namestart = NULLPOS;

    //case: <?^xml 
    // force the version to be 1.0
    xmltoken.name = "version";
    xmltoken.text = "1.0";

    // scan for trailing '?>' 
    for(;;) {
        c = nextch();
        if(c == EOFCHAR) throw new Yax.Exception(YAX_EPROLOG);
        if(c == '?' && peek(0) == CGT) {// this is the end 
            break;
        }
    }
    //case: <?xml...?^> 
    nextch();
    //case: <?xml...?>^ 
    xmltoken.tokentype = TokenType.YAX_PROLOG;
    // Set the state to undefined 
    state = xtracestate(LexState.YX_UNDEFINED);
}

void
collectdoctype(Token xmltoken)
    throws Yax.Exception
{
    int textstart = NULLPOS;
    int namestart = NULLPOS;
    int textstop = NULLPOS;
    int namestop = NULLPOS;
    char c;

    //case: <!^DOCTYPE 
    skipn(7);
    //case: <!DOCTYPE^ 
    // Scan for starting name 
    skipwhitespace();
    c = nextch();    
    if(!namechar1(c)) throw new Yax.Exception(YAX_EDOCTYPE);
    namestart = markprev();
    for(;;) {
        if(c == EOFCHAR) throw new Yax.Exception(YAX_EDOCTYPE);
        if(!namecharn(c)) break;
        c = nextch();
    }
    namestop = markprev();
    // check for empty start name 
    if(namestart == namestop)
        throw new Yax.Exception(YAX_EDOCTYPE);

    //case: ...name?^... 

    if(whitespace(c)) {
        skipwhitespace();
        c = nextch();
    }

    //<|expected cases: ...[^..., ...>^, ...N^NNN... |]
    if(c == CLB) {
        //[| collect everything upto the final ']'
        //   and make it be the text field of the token 
        //<|case: ...[^...>   |]
        textstart = markprev();
        //[| scan for ']' 
        for(;;) {
            if(c == EOFCHAR) throw new Yax.Exception(YAX_EDOCTYPE);
            if(c == CRB) break;
            c = nextch();
        }
        //[<|case: ...]^> 
        textstop = mark();
        skipwhitespace();
        //[<|case: ...]_^> 
        c = nextch();
        //[<|case: ...]_>^ 
        if(c != CGT) throw new Yax.Exception(YAX_EDOCTYPE);
    } else if(c == CGT) {
        //<|case: ...>^
        textstart = NULLPOS;
    } else if(namechar1(c)) {
        //case: ...N^NN...
        textstart = markprev();
        for(;;) {
            if(c == EOFCHAR) throw new Yax.Exception(YAX_EDOCTYPE);
            if(!namecharn(c)) break;
            c = nextch();
        }
        //case: ...ID^...     
        // ID must be either "SYSTEM" or "PUBLIC" 
        if(!strnequal("SYSTEM",textstart)
           && !strnequal("PUBLIC",textstart)) {
            throw new Yax.Exception(YAX_EDOCTYPE);
        }
        // collect everything upto the final CGT and make it be the text field of the token 
        for(;;) {
            if(c == EOFCHAR) throw new Yax.Exception(YAX_EDOCTYPE);
            if(c == CGT) break;
            c = nextch();
        }
        assert(c == CGT);
        //<case: ...ID....>^ 
        textstop = markprev();  
    } else {
        throw new Yax.Exception(YAX_EDOCTYPE);
    }
    xmltoken.text = getString(textstart,textstop);
    xmltoken.name = getString(namestart,namestop);
    xmltoken.tokentype = TokenType.YAX_DOCTYPE;
    // Set the state to undefined 
    state = xtracestate(LexState.YX_UNDEFINED);
}

void
collecttext(Token xmltoken)
    throws Yax.Exception
{
    boolean nonwhite; //1 => not all white space 
    char c;
    int textstart = NULLPOS;
    int textstop = NULLPOS;

    //case: >^... <
    textstart = mark();
    nonwhite = false;
    for(;;) {
        c = nextch();
        if(c == EOFCHAR)
            break;
        if(c == CLT)
            break;
        if(!whitespace(c))
            nonwhite = true;
        // move to next character 
    }//for
    if(c == EOFCHAR) {
        if(nonwhite) throw new Yax.Exception(YAX_ETEXT);
        // all white space => treat as eof instead of text
        xmltoken.tokentype = TokenType.YAX_EOF;
        state = xtracestate(LexState.YX_EOF);
    } else {
        assert(c == CLT);
        textstop = markprev();
        // In this case, we know the next state 
        state = LexState.YX_OPEN;
    }
    xmltoken.text = getString(textstart,textstop);
    if((flags & FLAG_TRIMTEXT)!= 0) {
	xmltoken.text = xmltoken.text.trim();
    }
}

// Collect and return an attribute; set state for next pass 
void
collectattribute(Token token)
    throws Yax.Exception
{
    int namestart = NULLPOS;
    int valuestart = NULLPOS;
    int namestop = NULLPOS;
    int valuestop = NULLPOS;
    char c,quote;

    //cases: ...^_attrname... 
    skipwhitespace();
    assert(namechar1(peek(0)));
    // capture the attribute name 
    namestart = mark();
    valuestart = NULLPOS;
    for(;;) {
        c=nextch(); // skip current name char 
        if(c == EOFCHAR) break;
        //cases: ...NNN^NNN... ...NNN?^...; N is a namechar ? is any char
        if(!namecharn(c)) {
            //cases: ...NNN?^... 
            namestop = markprev(); // save termination point 
            break;
        }
    }
    //cases: ...NNN?^..., EOF 
    if(whitespace(c)) {
        skipwhitespace();
        c = nextch();
    }
    if(c == EOFCHAR) {throw new Yax.Exception(YAX_EEQUAL);}
    if(c != '=')  {throw new Yax.Exception(YAX_EEQUAL);}
    //cases: ...NNN_=^_ ... ; _ is whitespace 
    skipwhitespace();
    c = nextch();
    // Collect attribute value 
    //cases: name_=_V^VV,name_=_Q^VVVQ, name_=_/^>, name_=_>^;
    //  V is value char,Q is quote 
    quote = EOFCHAR;
    if(c == CQUOTE || c == CSQUOTE) {
        quote = c;
        valuestart = mark();
    } else if(valuechar(c)) {
        valuestart = markprev();
    } else {
        throw new Yax.Exception(YAX_EVALUE);
    }
    //cases: ...name_=_^VVV ..., ...name_=_Q^VVVQ...
    for(;;) {
        //cases: ...^VVV, ...^VVVQ... 
        c=nextch();
        if(c == EOFCHAR) break;
        //cases: ...V^VV, ...V^VVQ..., ...VVVQ^...., EOF 
        if(quote != EOFCHAR && c == quote)
            break;
        //cases: ...V^VV, ...VVV?^; ? is not a value char 
        if(quote == EOFCHAR && !valuechar(c))
            break;
        //cases: ...V^VV, ...VVV^? 
    }
    //cases: ...QvalueQ^...value?^; where ? is not value char or quote 
    valuestop = markprev();
    //cases: ...value^_?, ...value?^, ...QvalueQ^...
    // move to the next possible attribute 
    if((quote != EOFCHAR && c == quote) || whitespace(c)) {
        skipwhitespace();
        c = nextch();
    }   
    // absorb any comments 
    while(atcomment(c)) {
        //cases:  <^!--
        skipcomment(true);
        c = nextch();
    }
    if(c == '/' && peek(0) == CGT ) {
        //cases: ..VVV/^> 
        nextch();
        //cases: ..VVV/>^ 
        state = xtracestate(LexState.YX_EMPTYCLOSE);
    } else if(c == CGT ) {
        //cases: ..VVV>^ 
        state = xtracestate(LexState.YX_TEXT);
    } else if(namechar1(c)) {
        backup();
        //case: ...^aname... 
        state = xtracestate(LexState.YX_ATTRIBUTE);
    } else {throw new Yax.Exception(YAX_ECLOSURE);}
    token.name = getString(namestart,namestop);
    token.text = getString(valuestart,valuestop);
}


static String[] tokennames = {
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

String
tokenname(TokenType token)
{
    int itoken = token.ordinal();
    int ntokens = tokennames.length;
    if(itoken >= 0 && itoken < ntokens) {
        return tokennames[itoken];
    }
    return "UNKNOWN";
}

void
addtext(StringBuilder dst, String txt, int flags)
{
    int len;
    int pos;
    boolean shortened = false;

    if(txt == null) {
        dst.append("null");
        return;
    }
    len = txt.length();
    if((flags & FLAG_ELIDETEXT) != 0 && len > MAXTEXT) {
        len = MAXTEXT;
        shortened = true;
    }
    dst.append('|');
    for(int i=0;i<txt.length();i++) {
	char c = txt.charAt(i);
        if(len-- <= 0) continue;
        if((flags & FLAG_ESCAPE) != 0 && c < ' ') {
            dst.append('\\');
            switch (c) {
            case '\n': dst.append('n'); break;
            case '\r': dst.append('r'); break;
            case '\f': dst.append('f'); break;
            case '\t': dst.append('t'); break;
            default: {// convert to octal 
                int uc = c;
                int oct;
                oct = ((uc >> 6) & 077);
                dst.append((char)('0'+ oct));
                oct = ((uc >> 3) & 077);
                dst.append((char)('0'+ oct));
                oct = ((uc) & 077);
                dst.append((char)('0'+ oct));
                } break;
            }
        } else if((flags & FLAG_NOCR) != 0 && c == '\r') {
            continue;
        } else {
            dst.append((char)c);
        }
    }
    if(shortened) {
        dst.append("...");
    }
    dst.append('|');
}

/*
  Provide a procedure for generating a string
  representing the contents of an Token instance.
  Primarily for use for debugging.
  Caller must free returned string.
*/

String
trace(Token token)
{
    StringBuilder result = new StringBuilder();
    String tmp = null;

    result.append(token.charno);
    result.append(": ");
    result.append(tokenname(token.tokentype));
    switch(token.tokentype) {
    case YAX_OPEN:
    case YAX_CLOSE:
    case YAX_EMPTYCLOSE:
	result.append(": element=|");
        result.append(token.name);
        result.append("|");
        break;
    case YAX_TEXT:
        result.append(" text=");
        addtext(result,token.text,flags);
        String trans = unescape(token.text);
        result.append(" translation=");
        addtext(result,trans,flags);
        break;
    case YAX_ATTRIBUTE:
        result.append(": name=");
        addtext(result,token.name,flags);
        result.append(" value=");
        addtext(result,token.text,flags);
        break;
    case YAX_CDATA:
        result.append(": text=");
        addtext(result,token.text,flags);
        break;
    case YAX_DOCTYPE:
    case YAX_PROLOG:
        result.append(": name=");
        addtext(result,token.name,flags);
        result.append(" value=");
        addtext(result,token.text,flags);
        break;
    case YAX_EOF:
        break;
    default:
        assert(false);
    }
    return result.toString();
}

// Convert an error code to a human readable string 
static String
errstring(int err)
{
    String msg = null;
        switch(err) {
	case YAX_OK: msg = "No error"; break;
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
    return msg;
}

//////////////////////////////////////////////////
// Public API

/*
Unlike the C code, strings found in the input are not null terminated.
Instead, they are converted to a Java String. This, of course, has
performance costs.
*/

public void
nextToken(Token xmltoken)
    throws Yax.Exception
{
    boolean closure;
    char c;
    int namestart = NULLPOS;
    int namestop = NULLPOS;
    
    // reset token 
    xmltoken.name = null;
    xmltoken.text = null;

retry: for(;;) {// We may need to repeat to get a usable token

    xmltoken.charno = charoffset(); // default 

    if(state == LexState.YX_UNDEFINED) {
        state = findstate();
    }
    assert(state != LexState.YX_UNDEFINED);

    switch (state) {

    case YX_OPEN: //case: <^...
        c = nextch();
        //case: <^...
        if(c == EOFCHAR) {throw new Yax.Exception(YAX_EEOF);}
        // Check for comments, CDATA, prolog and DOCTYPE 
        if(incomment(c)) {
            skipcomment(false);
            state = xtracestate(LexState.YX_UNDEFINED);
            continue retry;
        } else if(incdata(c)) {
            collectcdata(xmltoken);
            // collect cdata will set the next state 
            break;
        } else if(inprolog(c)) {
            collectprolog(xmltoken);
            break;
        } else if(indoctype(c)) {
            collectdoctype(xmltoken);
            break;
        } 
        closure = (c == '/');
        if(closure) {
	    xmltoken.charno = charoffset();
	    c = nextch();
	}
        //cases: <n^ame... , </n^ame... 
        if(!namechar1(c)) {
            throw new Yax.Exception(YAX_ENAMECHAR);
        }               
        namestart = markprev();
        for(;;) {
            c = nextch();
            if(c==EOFCHAR) throw new Yax.Exception(YAX_EEOF);
            if(!namecharn(c)) break;
        }
        namestop = markprev();
        //cases: <name?^... , </name?^...; ? is any char      
        if(whitespace(c)) {
            skipwhitespace();
            c = nextch();
        }
        //cases: ...a^ttr=value, .../^>, ...>^ , <^!--
        while(atcomment(c)) {
            //cases:  <^!--
            skipcomment(true);
            c = nextch();
        }
        //cases: ...a^ttr=value, .../^>, ...>^ 
        if(c == '/' && peek(0) == CGT) {
            if(closure) {throw new Yax.Exception(YAX_EGT);}
            c = nextch();
            //case: />^ 
            state = xtracestate(LexState.YX_EMPTYCLOSE); 
        } else if(c == CGT) {
            if(closure) {
                // closures have no text, only whitespace 
                state = xtracestate(LexState.YX_UNDEFINED);
            } else              
                state = xtracestate(LexState.YX_TEXT);
        } else {// test for case: ...a^ttr=value 
            if(namechar1(c)) {
                //cases: a^ttr=value 
                state = xtracestate(LexState.YX_ATTRIBUTE);             
                backup();
                //cases: ^attr=value 
            } else {
                throw new Yax.Exception(YAX_ECLOSURE);
            }
        }
        xmltoken.tokentype = (closure ? TokenType.YAX_CLOSE : TokenType.YAX_OPEN);
	xmltoken.name = getString(namestart,namestop);
        lastelement = xmltoken.name;
        if(xmltoken.name.length() == 0)
            throw new Yax.Exception(YAX_ENAMENULL);
        break;

    case YX_EMPTYCLOSE: //case: />^  
        xmltoken.charno = charoffset() - 2;
        xmltoken.tokentype = TokenType.YAX_EMPTYCLOSE;
        // Reuse the last element name 
        xmltoken.name = lastelement;
        state = xtracestate(LexState.YX_UNDEFINED);
        break;  

    case YX_TEXT: //case: >^ 
        xmltoken.tokentype = TokenType.YAX_TEXT;
        collecttext(xmltoken);
        // collect text will set the next state 
        break;

    case YX_ATTRIBUTE: //case: <element...attr=value...,-->^
        collectattribute(xmltoken);
        // collect attribute will have properly set the state 
        xmltoken.tokentype = TokenType.YAX_ATTRIBUTE;
        if(xmltoken.name.length() == 0)
            throw new Yax.Exception(YAX_ENAMENULL);
        break;  

    case YX_EOF:
        xmltoken.tokentype = TokenType.YAX_EOF;
        state = xtracestate(LexState.YX_EOF);
        break;

    default: assert(false); break;
    }

    break; // out of retry loop

    } //retry
}

int
getflags()
{
    return (flags);
}

void
setflags(int flags)
{
    this.flags = flags;
}

Token
tokendup(Token token)
{
    Token t = new Token(token);
    return t;
}

/* Unescape entities in a string.
   The translations argument is in envv form
   with position n being the entity name and
   position n+1 being the translation and last
   position being null.
*/
static String
unescape(String s)
{
    return unescape(s,null);
}

static String
unescape(String s, String[][] translations)
{
    int count,len;
    boolean found;
    StringBuilder u; // returned string with entities unescaped 
    int p; // insertion point into u 
    int q; // next char from s 
    int stop;
    StringBuilder entity;

    if(translations == null)
	translations = DEFAULTTRANSTABLE;

    if(s == null) len = 0;
    else len = s.length();
    u = new StringBuilder();
    if(u == null) return null;
    p = 0;
    q = 0;
    stop = (len);
    entity =  new StringBuilder();

    while(q < stop) {
        char c = s.charAt(q++);
        switch (c) {
        case '&': // see if this is a legitimate entity 
	    entity.setLength(0);
            // move forward looking for a semicolon; 
            for(found=true,count=0;;count++) {
		if(q+count >= len) break;
                c = s.charAt(q+count);
                if(c == ';')
                    break;
                if((count==0 && !namechar1(c))
                   || (count > 0 && !namecharn(c))) {
                    found=false; // not a legitimate entity 
                    break;
                }
                entity.append(c);
            }
            if(q+count >= len || count == 0 || !found) {
                // was not in correct form for entity 
                u.append('&');
            } else { // looks legitimate 
		String test = entity.toString();
		String replacement = null;
		for(String[] trans: translations) {
                    if(trans[0].equals(test)) {
                        replacement = trans[1];
                        break;
                    }
                }
                if(replacement == null) { // no translation, ignore 
                    u.append('&');
                } else { // found it 
                    q += (count+1) ; // skip input entity, including trailing semicolon 
		    u.append(replacement);
                }
            }
            break;
        default:
            u.append(c);
            break;
        }
    }
    return u.toString();
}



} // Yax



