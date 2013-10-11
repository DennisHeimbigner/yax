/**
This software is released under the terms of the Apache License version 2.
For details of the license, see http://www.apache.org/licenses/LICENSE-2.0.
*/

package yax.test;

import yax.*;
import org.xml.sax.*;
import org.w3c.dom.*;

import java.util.*;

import static yax.test.XmlParser.*;
import static yax.test.XmlParser.Lexer.*;


public class XmlEventHandler extends SaxEventHandler
{
    //////////////////////////////////////////////////
    // Instance variables

    XmlParser pushparser = null;
    boolean accepted = false;

    //////////////////////////////////////////////////
    // Constructor(s)

    public XmlEventHandler(String document, XmlParser pushparser)
        throws SAXException
    {
        super(document);
        this.pushparser = pushparser;
    }

    //////////////////////////////////////////////////
    // Abstract method overrides
    public Document getDocument() {return pushparser.getDocument();}

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

        switch (yaxtoken) {

        case STARTELEMENT:
	    yytoken = OPEN;
            break;

        case ATTRIBUTE:
            yytoken = ATTRIBUTE;
            break;

        case ENDELEMENT:
            yytoken = CLOSE;
            break;

        case CHARACTERS:
            yytoken = TEXT;
            break;

        case STARTDOCUMENT:
	    yytoken = DOCTYPE;
	    break;

        case ENDDOCUMENT:
            yytoken = EOF;
            break;

        default:
            pushparser.yyerror(String.format("unknown token type: %s\n",
                yaxtoken.name()));
            yytoken = ERROR;
            break;
        } // switch

        int status = 0;
        try {
            status = pushparser.push_parse(yytoken, saxevent);
        } catch (Exception e) {
            throw new SAXException(e);
        }
        if(status == YYABORT)
            throw new SAXException("YYABORT");
        else if(status == YYACCEPT)
            accepted = true;
    }


} // class XmlEventHandler
