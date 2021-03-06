/**
This software is released under the terms of the Apache License version 2.
For details of the license, see http://www.apache.org/licenses/LICENSE-2.0.
*/

package yax;

/**
 * Provide methods for unescaping entities in text.
 */

public class Util
{
    static final int MAXTEXT = 12;
    static public final String[][] DEFAULTTRANSTABLE = {
        {"amp", "&"},
        {"lt", "<"},
        {"gt", ">"},
        {"quot", "\""},
        {"apos", "'"},
    };

    /* Common Flag Set; Probably should use enum and enumset */
    static public final int FLAG_NONE = 0;
    static public final int FLAG_ESCAPE = 1; //convert \n,\r, etc to \\ form
    static public final int FLAG_NOCR = 2; // elide \r
    static public final int FLAG_ELIDETEXT = 4; // only print the first 12 characters of text
    static public final int FLAG_TRIMTEXT = 8; //remove leading and trailing whitespace;
    // if result is empty, then ignore
    static public final int FLAG_TRACE = 16;   // Trace tokens

    static public final int DEFAULTFLAGS = (FLAG_ELIDETEXT | FLAG_ESCAPE | FLAG_NOCR | FLAG_TRIMTEXT);

    /* Characters legal as first char of an element or attribute name */
    static boolean namechar1(char c)
    {
        return (":_?".indexOf(c) >= 0
            || "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ".indexOf(c) >= 0
            || ((int) c) > 127);
    }

    /* Characters legal as greater than first char of an element or attribute name */
    static boolean namecharn(char c)
    {
        return (namechar1(c)
            || "-.".indexOf(c) >= 0
            || "0123456789".indexOf(c) >= 0);
    }

    /*
      Provide a procedure for generating a string
      representing the contents of an Token instance.
      Primarily for use for debugging.
      Caller must free returned string.
	@param type token type
	@param node token node 
	@param flags to control trace output
    */

    /* Unescape entities in a string.
       The translations argument is in envv form
       with position n being the entity name and
       position n+1 being the translation and last
       position being null.
    */
    static public String
    unescape(String s)
    {
        return unescape(s, null);
    }

    static public String
    unescape(String s, String[][] translations)
    {
        int count, len;
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
        entity = new StringBuilder();

        while(q < stop) {
            char c = s.charAt(q++);
            switch (c) {
            case '&': // see if this is a legitimate entity 
                entity.setLength(0);
                // move forward looking for a semicolon; 
                for(found = true, count = 0;;count++) {
                    if(q + count >= len) break;
                    c = s.charAt(q + count);
                    if(c == ';')
                        break;
                    if((count == 0 && !namechar1(c))
                        || (count > 0 && !namecharn(c))) {
                        found = false; // not a legitimate entity
                        break;
                    }
                    entity.append(c);
                }
                if(q + count >= len || count == 0 || !found) {
                    // was not in correct form for entity 
                    u.append('&');
                } else { // looks legitimate 
                    String test = entity.toString();
                    String replacement = null;
                    for(String[] trans : translations) {
                        if(trans[0].equals(test)) {
                            replacement = trans[1];
                            break;
                        }
                    }
                    if(replacement == null) { // no translation, ignore 
                        u.append('&');
                    } else { // found it 
                        q += (count + 1); // skip input entity, including trailing semicolon
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

    static void
    addtext(StringBuilder dst, String txt, int flags)
    {
        int len;
        int pos;
        boolean shortened = false;

        if(txt == null) {
            dst.append("null");
            return;
        }
        if((flags & Util.FLAG_TRIMTEXT) != 0) {
            txt = txt.trim();
        }
        len = txt.length();
        if((flags & Util.FLAG_ELIDETEXT) != 0 && len > MAXTEXT) {
            len = MAXTEXT;
            shortened = true;
        }
        dst.append('|');
        for(int i = 0;i < txt.length();i++) {
            char c = txt.charAt(i);
            if(len-- <= 0) continue;
            if((flags & Util.FLAG_ESCAPE) != 0 && c < ' ') {
                dst.append('\\');
                switch (c) {
                case '\n':
                    dst.append('n');
                    break;
                case '\r':
                    dst.append('r');
                    break;
                case '\f':
                    dst.append('f');
                    break;
                case '\t':
                    dst.append('t');
                    break;
                default: {// convert to octal 
                    int uc = c;
                    int oct;
                    oct = ((uc >> 6) & 077);
                    dst.append((char) ('0' + oct));
                    oct = ((uc >> 3) & 077);
                    dst.append((char) ('0' + oct));
                    oct = ((uc) & 077);
                    dst.append((char) ('0' + oct));
                }
                break;
                }
            } else if((flags & Util.FLAG_NOCR) != 0 && c == '\r') {
                continue;
            } else {
                dst.append((char) c);
            }
        }
        if(shortened) {
            dst.append("...");
        }
        dst.append('|');
    }

    // Trace a SAX event
    static public String
    trace(SaxEvent token)
    {
        return trace(token, DEFAULTFLAGS);
    }

    static public String
    trace(SaxEvent token, int flags)
    {
        StringBuilder result = new StringBuilder();
        String name = "UNDEFINED";
        String value = "";
        String text = "";
        SaxEventType event = null;

        name = token.name;
        value = token.value;
        text = token.text;
        event = token.event;

        result.append("[" + event.name() + "] ");

        switch (event) {
        case STARTELEMENT:
        case ENDELEMENT:
            result.append(": element=|");
            result.append(name);
            result.append("|");
            break;
        case CHARACTERS:
            result.append(" text=");
            addtext(result, text, flags);
            String trans = unescape(text);
            result.append(" translation=");
            addtext(result, trans, flags);
            break;
        case ATTRIBUTE:
            result.append(": name=");
            addtext(result, name, flags);
            result.append(" value=");
            addtext(result, value, flags);
            break;
        case STARTDOCUMENT:
            break;
        case ENDDOCUMENT:
            break;
        default:
            assert (false) : "Unexpected tokentype";
        }
        return result.toString();
    }

} // class Util
