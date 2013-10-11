/**
This software is released under the terms of the Apache License version 2.
For details of the license, see http://www.apache.org/licenses/LICENSE-2.0.
*/

package yax.test;

import yax.*;
import org.xml.sax.*;

import java.util.*;

import static yax.test.CalcParser.*;
import static yax.test.CalcParser.Lexer.*;

public class CalcEventHandler extends SaxEventHandler
{

    //////////////////////////////////////////////////
    // static fields

    static Map<String, Lexeme> elementmap;
    static Map<String, Lexeme> attributemap;

    static {
        elementmap = new HashMap<String, Lexeme>();
        attributemap = new HashMap<String, Lexeme>();

	elementmap.put("calc", new Lexeme("calc", CALC_, _CALC, null));
	elementmap.put("eq", new Lexeme("eq", EQ_, _EQ, null));
	elementmap.put("add", new Lexeme("add", ADD_, _ADD, null));
	elementmap.put("sub", new Lexeme("sub", SUB_, _SUB, null));
	elementmap.put("mul", new Lexeme("mul", MUL_, _MUL, null));
	elementmap.put("div", new Lexeme("div", DIV_, _DIV, null));
	elementmap.put("neg", new Lexeme("neg", NEG_, _NEG, null));
	elementmap.put("exp", new Lexeme("exp", EXP_, _EXP, null));
	elementmap.put("int", new Lexeme("int", INT_, _INT, new String[]{"n"}));

        // Always insert the lowercase name
        attributemap.put("n", new Lexeme("n", ATTR_N));
    };

    //////////////////////////////////////////////////
    // Instance variables

    CalcParser pushparser = null;
    boolean textok = false;
    boolean accepted = false;

    //////////////////////////////////////////////////
    // Constructor(s)

    public CalcEventHandler(String document, CalcParser pushparser)
        throws SAXException
    {
        super(document);
        this.pushparser = pushparser;
    }

    //////////////////////////////////////////////////
    // Abstract method overrides

    // Push the token to the parser
    // @throws SAXException if parser return YYABORT

    public void yyevent(SaxEvent saxevent)
        throws SAXException
    {
        if(accepted) {
            throw new SAXException("yyevent called after parser has accepted");
        }

        SaxEventType yaxtoken = saxevent.event;
        String name = saxevent.name;
        int yytoken = 0;
        Lexeme element = null;
        Lexeme attr = null;

        element = elementmap.get(name);

        switch (yaxtoken) {

        case STARTELEMENT:
            if(element == null) {// undefined
                yytoken = UNKNOWN_ELEMENT_;
            } else {
                yytoken = element.open;
                // Check for the special cases
                if(element.textok)
                    textok = true;
            }
            break;

        case ATTRIBUTE:
            attr = attributemap.get(name.toLowerCase());
            if(attr == null) {
                yytoken = UNKNOWN_ATTR;
            } else {
                yytoken = attr.atoken;
            }
            break;

        case ENDELEMENT:
            if(element == null) {// undefined
                yytoken = _UNKNOWN_ELEMENT;
            } else {
                yytoken = element.close;
                textok = false;
            }
            break;

        case CHARACTERS:
            if(!textok) return; // ignore
            yytoken = TEXT;
            break;

        case STARTDOCUMENT:
            return; // ignore

        case ENDDOCUMENT:
            yytoken = EOF;
            break;

        default:
            throw new IllegalStateException(String.format("unknown token type: %s\n",
                yaxtoken.name()));
        } // switch

        int status = 0;
        try {
            status = pushparser.push_parse(yytoken, saxevent);
        } catch (Exception e) {
	    e.printStackTrace();
            throw new SAXException(e);
        }
        if(status == YYABORT)
            throw new SAXException("YYABORT");
        else if(status == YYACCEPT)
            accepted = true;
    }


} // class CalcEventHandler
