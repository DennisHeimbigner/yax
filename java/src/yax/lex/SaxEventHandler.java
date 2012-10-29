/* Copyright 2009, UCAR/Unidata and OPeNDAP, Inc.
   See the COPYRIGHT file for more information. */

package yax.lex;


import javax.xml.parsers.*;
import org.xml.sax.*;
import org.xml.sax.helpers.*;

import java.util.*;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.nio.charset.Charset;

abstract public class SaxEventHandler extends DefaultHandler
{
    //////////////////////////////////////////////////
    // Constants

    static boolean TRACE = false;

    static Charset UTF8 = Charset.forName("UTF-8");

    static final String LOAD_EXTERNAL_DTD
	= "http://apache.org/xml/features/nonvalidating/load-external-dtd";

    //////////////////////////////////////////////////
    // static types

    //////////////////////////////////////////////////
    // static fields

    //////////////////////////////////////////////////
    // Instance variables
    
    String document = null;
    
    // Sax parser state
    Locator locator = null;
    SAXParserFactory spf = null;
    SAXParser saxparser = null;
    ByteArrayInputStream input = null;

    //////////////////////////////////////////////////
    // Constructor(s)

    public SaxEventHandler(String document)
	throws SAXException
    {
	this.document = document;
    }

    //////////////////////////////////////////////////
    // Abstract methods

    // get list of legal attribute names in desired order
    abstract public String[] orderedAttributes(String element);

    // Send the lexeme to the the subclass to process
    abstract public void yyevent(SaxToken token) throws SAXException;

    //////////////////////////////////////////////////
    // Get/Set

    //////////////////////////////////////////////////
    // Misc.
    void fail(String msg)
	throws SAXException
    {
	if(locator != null) {
	    msg = String.format("[%d.%d] ",
			locator.getLineNumber(),
			locator.getColumnNumber())
		  + msg;
	}
	throw new SAXException(msg);	
    }

    //////////////////////////////////////////////////
    // Public API

    public boolean parse()
	throws Exception
    {
        // Create the sax parser that will drive us with events
        spf = SAXParserFactory.newInstance();
        spf.setValidating(false);
        spf.setNamespaceAware(true);
        spf.setFeature(LOAD_EXTERNAL_DTD,false);
        saxparser = spf.newSAXParser();
        // Set up for the parse
        input = new ByteArrayInputStream(document.getBytes(UTF8));
        try {
            saxparser.parse(input,this);
            return true;
        } catch (SAXException se) {return false;}
    }

    //////////////////////////////////////////////////
    // DefaultHandler Overrides

    @Override
    public void setDocumentLocator(Locator locator)
    {
	this.locator = locator;
    }

    @Override
    public void startDocument()
	throws SAXException
    {
	SaxToken token = new SaxToken(Type.DOCTYPE);
if(TRACE) System.err.println("event.startDocument: "+token.toString());
	yyevent(token);
    }

    @Override
    public void endDocument()
	throws SAXException
    {
	SaxToken token = new SaxToken(Type.EOF);
if(TRACE) System.err.println("event.endDocument: "+token.toString());
	yyevent(token);
    }

    @Override
    public void startElement(String nsuri, String name, String qualname,
		      Attributes attributes)
	throws SAXException
    {
	SaxToken token = new SaxToken(Type.OPEN,name,qualname,nsuri);
if(TRACE) System.err.println("event.startElement: "+token.toString());
	yyevent(token);
	// Let subclass tell us what and in what order
	// to generate the attributes
	String[] userorder = orderedAttributes(name);
	int nattr = attributes.getLength();
	List<String> knowns = null;
	if(userorder != null) {
	    for(int i=0;i<userorder.length;i++) {
                String uname = userorder[i].toLowerCase();
	        String value = null;
                boolean found = false;
	        for(int j=0;j<nattr;j++) {
		    String aname = attributes.getLocalName(j).toLowerCase();
		    if("".equals(aname)) aname = attributes.getQName(i);
		    if(uname.equalsIgnoreCase(aname)) {// force case insensitive
		        value = attributes.getValue(i);
                        found = true;
		        break;
		    }
		}
		if(found) {// found it
		    token = new SaxToken(Type.ATTRIBUTE,uname);
		    token.value = value;
		    if(knowns == null) knowns = new ArrayList<String>();
		    knowns.add(uname);
if(TRACE) System.err.println("event.attribute: "+token.toString());
		    yyevent(token);
	        }
	    }
	    // Now pass on the given attributes that are unknown
	    for(int i=0;i<nattr;i++) {
		String aname = attributes.getLocalName(i).toLowerCase();
		if(!knowns.contains(aname)) {
		    token = new SaxToken(Type.ATTRIBUTE,aname);
		    token.value = attributes.getValue(i);
if(TRACE) System.err.println("event.attribute.unknown: "+token.toString());
		    yyevent(token);
		}
	    }
	} else {// no attribute ordering; just include as is
	    for(int i=0;i<nattr;i++) {
		String aname = attributes.getLocalName(i);
		if("".equals(aname)) aname = attributes.getQName(i);
		String value = attributes.getValue(i);
		token = new SaxToken(Type.ATTRIBUTE,aname);
	        token.value = value;
if(TRACE) System.err.println("event.attribute: "+token.toString());
	    	yyevent(token);
	    }
	}
    }

    @Override
    public void endElement(String nsuri, String name, String qualname)
	throws SAXException
    {
	SaxToken token = new SaxToken(Type.CLOSE,name,qualname,nsuri);
if(TRACE) System.err.println("event.endElement: "+token.toString());
    	yyevent(token);
    }

    @Override
    public void characters(char[] ch, int start, int length)
	throws SAXException
    {
	SaxToken token = new SaxToken(Type.TEXT);
	token.text = new String(ch,start,length);
if(TRACE) System.err.println("event.characters: "+token.toString());
    	yyevent(token);
    }

    @Override
    public void ignorableWhitespace(char[] ch, int start, int length)
	throws SAXException
    {
	// should never see this since not validating, but ignore
    }

    // Error handling

    @Override
    public void fatalError(SAXParseException e)
	throws SAXException
    {
	throw e;
    }	

    @Override
    public void error(SAXParseException e)
	throws SAXException
    {
	System.err.println("Sax error: "+e);	
    }

    @Override
    public void warning(SAXParseException e)
	throws SAXException
    {
	System.err.println("Sax error: "+e);	
    }



} // class SaxEventHandler

