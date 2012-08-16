/* Copyright 2009, UCAR/Unidata
   See the COPYRIGHT file for more information.
*/

//////////////////////////////////////////////////

package yax;

/*
Common Definitions
for YaxYax and YaxDom
*/

abstract public class Yax {

//////////////////////////////////////////////////
// publically accessible classes and constants

/* Define the token types */
public enum Type {
EOF,
OPEN,
CLOSE,
EMPTYCLOSE,
ATTRIBUTE,
TEXT,
CDATA,
PROLOG,
DOCTYPE,
UNDEFINED;
public static final int size() {return UNDEFINED.ordinal()+1;}
public static final int ordinalToType(int index)
{
    for(Type t: Type.values()) {if(t.ordinal()==index) return t;}
    return Type.UNDEFINED;
}

};

/* Common Flag Set */
static public final int FLAG_NONE	  = 0;
static public final int FLAG_ESCAPE	  = 1; //convert \n,\r, etc to \\ form
static public final int FLAG_NOCR	  = 2; // elide \r
static public final int FLAG_ELIDETEXT  = 4; // only print the first 12 characters of text
static public final int FLAG_TRIMTEXT   = 8; //remove leading and trailing whitespace;
                                     // if result is empty, then ignore

//////////////////////////////////////////////////
// Misc. Constants
static final int MAXTEXT = 12;

//////////////////////////////////////////////////
// Define an empty token
static public Token emptytoken = new Token();

static public class Exception extends java.lang.Exception
{
    public Exception() {super();}
    public Exception(String message) {super(message);}
    public Exception(String message, Throwable cause) {super(message,cause);}
    public Exception(Throwable cause) {super(cause);}
    public Exception(Yax.Error errcode) {super(Yax.errstring(errcode));}
}

static public String[][] DEFAULTTRANSTABLE = {
{"amp","&"},
{"lt","<"},
{"gt",">"},
{"quot","\""},
{"apos","'"},
};

//////////////////////////////////////////////////

static enum Error {
OK,
ENOMEM,
EINVAL,
EEOF,
ECLOSURE,
EGT,
ELT,
ENAMECHAR,
ENATTR,
EEQUAL,
EVALUE,
ECOMMENT,
ECDATA,
EPROLOG,
EDOCTYPE,
ENAMENULL,
ETEXT
};

static final boolean XDEBUG = false;

//////////////////////////////////////////////////
// Static nested classes

/* Define the state associated with a token */
static public class Token
{
    public Type type;
    // Depending on token type, only some of these will have values
    public String name; // element or attribute name
    public String text; // text or attribute value
    public int charno;  // YaxDom does not support
    public Token(Token t)
    {
	this.type = t.type;
	this.name = t.name;
	this.text = t.text;
	this.charno = t.charno;
    }

    public Token()
    {
	type = Type.UNDEFINED;
	name = null;
	text = null;
	charno = 0;
    }
}

//////////////////////////////////////////////////
// Debug

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

public String
trace(Token token)
{
    StringBuilder result = new StringBuilder();
    String tmp = null;

    result.append(token.charno);
    result.append(": ");
    result.append(token.type.name());
    switch(token.type) {
    case OPEN:
    case CLOSE:
    case EMPTYCLOSE:
	result.append(": element=|");
        result.append(token.name);
        result.append("|");
        break;
    case TEXT:
        result.append(" text=");
        addtext(result,token.text,getFlags());
        String trans = unescape(token.text);
        result.append(" translation=");
        addtext(result,trans,getFlags());
        break;
    case ATTRIBUTE:
        result.append(": name=");
        addtext(result,token.name,getFlags());
        result.append(" value=");
        addtext(result,token.text,getFlags());
        break;
    case CDATA:
        result.append(": text=");
        addtext(result,token.text,getFlags());
        break;
    case DOCTYPE:
    case PROLOG:
        result.append(": name=");
        addtext(result,token.name,getFlags());
        result.append(" value=");
        addtext(result,token.text,getFlags());
        break;
    case EOF:
        break;
    default:
        assert(false);
    }
    return result.toString();
}

// Convert an error code to a human readable string 
static String
errstring(Error err)
{
    String msg = null;
        switch(err) {
	case OK: msg = "No error"; break;
        case ENOMEM: msg = "Out of Memory"; break;
        case EINVAL: msg = "Invalid argument"; break;
        case EEOF: msg = "Unexpected EOF"; break;
        case ECLOSURE: msg = "Expected /,>,or attribute name"; break;
        case EGT: msg = "Expected >"; break;
        case ELT: msg = "Expected <"; break;
        case ENAMECHAR: msg = "Illegal leading name character"; break;
        case ENATTR: msg = "Too many attributes"; break;
        case EEQUAL: msg = "Expected '=' after attribute name"; break;
        case EVALUE: msg = "Expected attribute value"; break;
        case ECOMMENT: msg = "Comment is missing trailing '-->'"; break;
        case ECDATA: msg = "Cdata is missing trailing ']]>'"; break;
        case EPROLOG: msg = "Malformed <?xml...> prolog"; break;
        case EDOCTYPE: msg = "Malformed <!DOCTYPE...>"; break;
        case ENAMENULL: msg = "Name is zero length"; break;
        case ETEXT: msg = "Non-whitespace text encountered"; break;

        default: msg = "Undefined error code"; break;
        }
    return msg;
}

//////////////////////////////////////////////////
// Public API

/* Unescape entities in a string.
   The translations argument is in envv form
   with position n being the entity name and
   position n+1 being the translation and last
   position being null.
*/
static public String
unescape(String s)
{
    return unescape(s,null);
}

static public String
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

//////////////////////////////////////////////////
// Abstract methods
abstract public int getFlags();

} // Yax
