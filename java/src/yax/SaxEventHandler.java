/**
 This software is released under the terms of the Apache License version 2.
 For details of the license, see http://www.apache.org/licenses/LICENSE-2.0.
 */

package yax;


import javax.xml.parsers.*;

import org.xml.sax.*;
import org.xml.sax.helpers.*;

import java.io.ByteArrayInputStream;
import java.nio.charset.Charset;

abstract public class SaxEventHandler extends DefaultHandler
{
    //////////////////////////////////////////////////
    // Constants

    static public String VERSION = "2.00";

    static public Charset UTF8 = Charset.forName("UTF-8");

    static public final String LOAD_EXTERNAL_DTD
        = "http://apache.org/xml/features/nonvalidating/load-external-dtd";

    //////////////////////////////////////////////////
    // Type Decls
    static public class NullLocator implements Locator
    {
	public int getColumnNumber() {return 0;}
	public int getLineNumber() {return 0;}
	public String getSystemId() {return "";}
	public String getPublicId() {return "";}
    }

    //////////////////////////////////////////////////
    // Static methods

    static public String getVersion() {return VERSION;}

    //////////////////////////////////////////////////
    // Instance variables

    String document = null;

    // Sax parser state
    Locator locator = new NullLocator();
    SAXParserFactory spf = null;
    SAXParser saxparser = null;
    ByteArrayInputStream input = null;

    // Trace flags
    int flags = Util.FLAG_NONE;
    boolean trace = false;

    //////////////////////////////////////////////////
    // Constructor(s)

    public SaxEventHandler(String document)
        throws SAXException
    {
        this.document = document;
    }

    //////////////////////////////////////////////////
    // Abstract method(s)

    // Send the lexeme to the the subclass to process
    abstract public void yyevent(SaxEvent token) throws SAXException;

    //////////////////////////////////////////////////
    // Subclass defined with default behavior

    public SaxEvent factory(SaxEventType set)
        throws SAXException
    {
        return factory(set, null, null);
    }

    public SaxEvent factory(SaxEventType set, Locator locator)
        throws SAXException
    {
        return factory(set, null, locator);
    }

    public SaxEvent factory(SaxEventType set, String name)
        throws SAXException
    {
	return factory(set, name, null);
    }

    public SaxEvent factory(SaxEventType set, String name, Locator locator)
        throws SAXException
    {
        SaxEvent event = new SaxEvent(set,name);
	event.setLocator(locator);
        return event;
    }

    //////////////////////////////////////////////////
    // Get/Set

    public int getFlags() {return this.flags;}
    public void setFlags(int flags) {this.flags = flags;}

    public void setTrace(boolean trace) {this.trace = trace;}

    //////////////////////////////////////////////////
    // Public API

    public boolean parse()
        throws Exception
    {
        // Create the sax parser that will drive us with events
        spf = SAXParserFactory.newInstance();
        spf.setValidating(false);
        spf.setNamespaceAware(true);
        spf.setFeature(LOAD_EXTERNAL_DTD, false);
        saxparser = spf.newSAXParser();
        // Set up for the parse
        input = new ByteArrayInputStream(document.getBytes(UTF8));
        try {
            saxparser.parse(input, this);
            return true;
        } catch (SAXException se) {
            return false;
        }
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
        SaxEvent event = factory(SaxEventType.STARTDOCUMENT,locator);
        if(trace) trace_event(event,flags);
        yyevent(event);
    }

    @Override
    public void endDocument()
        throws SAXException
    {
        SaxEvent event = factory(SaxEventType.ENDDOCUMENT,locator);
        if(trace) trace_event(event,flags);
        yyevent(event);
    }

    @Override
    public void startElement(String nsuri, String name, String qualname,
                             Attributes attributes)
        throws SAXException
    {
        SaxEvent event = factory(SaxEventType.STARTELEMENT, name, locator);
        event.fullname = qualname;
        event.namespace = nsuri;
        if(trace) trace_event(event,flags);
        yyevent(event);
        // Now pass the attributes as events
        int nattr = attributes.getLength();
        for(int i = 0;i < nattr;i++) {
            String aname = attributes.getLocalName(i);
            if("".equals(aname)) aname = attributes.getQName(i);
            String value = attributes.getValue(i);
            event = factory(SaxEventType.ATTRIBUTE, aname);
            event.value = value;
            if(trace) trace_event(event,flags);
            yyevent(event);
        }
    }

    @Override
    public void endElement(String nsuri, String name, String qualname)
        throws SAXException
    {
        SaxEvent event = factory(SaxEventType.ENDELEMENT, name, locator);
        event.fullname = qualname;
        event.namespace = nsuri;
        if(trace) trace_event(event,flags);
        yyevent(event);
    }

    @Override
    public void characters(char[] ch, int start, int length)
        throws SAXException
    {
        SaxEvent event = factory(SaxEventType.CHARACTERS,locator);
        event.text = new String(ch, start, length);
        if(trace) trace_event(event,flags);
        yyevent(event);
    }

    // Following events are suppressed

    @Override
    public void ignorableWhitespace(char[] ch, int start, int length)
        throws SAXException
    {
        // should never see this since not validating
        return;
    }

    @Override
    public void endPrefixMapping(String prefix)
        throws SAXException
    {
        return;
    }

    @Override
    public void notationDecl(String name, String publicId, String systemId)
        throws SAXException
    {
        return;
    }

    @Override
    public void processingInstruction(String target, String data)
        throws SAXException
    {
        return;
    }

    @Override
    public void skippedEntity(String name)
        throws SAXException
    {
        return;
    }

    @Override
    public void startPrefixMapping(String prefix, String uri)
        throws SAXException
    {
        return;
    }

    @Override
    public void unparsedEntityDecl(String name, String publicId, String systemId, String notationName)
        throws SAXException
    {
        return;
    }

    //////////////////////////////////////////////////
    // Entity resolution

    @Override
    public InputSource resolveEntity(String publicId, String systemId)
    {
        if(trace) System.err.printf("event.RESOLVEENTITY: %s.%s\n",
            publicId, systemId);
        return null;
    }

    //////////////////////////////////////////////////
    // Error handling Events

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
        System.err.println("Sax error: %s\n" + e);
    }

    @Override
    public void warning(SAXParseException e)
        throws SAXException
    {
        System.err.println("Sax warning: " + e);
    }

    static public void trace_event(SaxEvent event, int flags)
    {
        System.err.println(Util.trace(event,flags));
    }

} // class SaxEventHandler
