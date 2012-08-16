/* Copyright 2009, UCAR/Unidata
   See the COPYRIGHT file for more information.
*/

//////////////////////////////////////////////////

package yax;

import javax.xml.*;
import javax.xml.parsers.*;
import javax.xml.validation.*;
import java.io.*;
import java.util.Stack;

import org.w3c.dom.*;
import org.xml.sax.InputSource;

/*
Produce tokens by walking a DOM tree
left-to-right, depth first.
*/

public class YaxDom extends Yax
{

//////////////////////////////////////////////////
// Inner classes

static class ElementState
{
    Node element;
    NamedNodeMap attributes;
    int attrindex;
    int nattr;
    NodeList children;
    int childindex;
    int nchildren;

    ElementState()
    {
	this.element = null;
	attributes = null;
	attrindex = 0;
	nattr = 0;
        children = null;
	childindex = 0;
	nchildren = 0;
    }

    ElementState(Node element)
    {
	this();
	this.element = element;
	// set up to walk the attributes
	if(element.hasAttributes()) {
	    this.attributes = element.getAttributes();
	    this.nattr = this.attributes.getLength();
	    this.attrindex = 0;
	}
	// set up to walk the children (after the attributes)
	// set up to walk the attributes
	if(element.hasChildNodes()) {
	    this.children = element.getChildNodes();
	    this.nchildren = this.children.getLength();
	    this.childindex = 0;
	}
    }

    Node getElement() {return element;}
    boolean hasAttributes() {return element.hasAttributes();}
    boolean hasChildren() {return element.hasChildNodes();}

    boolean moreAttributes() {return attrindex < nattr;}
    boolean moreChildren() {return childindex < nchildren;}

    Node nextAttribute()
    {
	if(attributes == null)
	    return null;
	if(attrindex >= nattr)
	    return null;
	return attributes.item(attrindex++);
    }
    
    Node nextChild()
    {
	if(children == null)
	    return null;
	if(childindex >= nchildren)
	    return null;
	return children.item(childindex++);
    }

};

//////////////////////////////////////////////////
// Instance variables 


Stack<ElementState> elementStack = new Stack<ElementState>();

ElementState currentNode = null; /* Current Element */

String input = null; // whole xml document

int flags = 0;

/* XML Document related fields */
DocumentBuilderFactory docfactory = null;
DocumentBuilder builder = null;
Document document = null;

//////////////////////////////////////////////////
// Constructor

public
YaxDom(String input)
    throws Yax.Exception
{
    this(input,0);
}

public
YaxDom(String input, int flags)
    throws Yax.Exception
{
    if(input == null)
	throw new Yax.Exception(Yax.Error.EINVAL);
    this.input = input;
    this.flags = flags;

    try {
        CharArrayReader inputaschars = new CharArrayReader(input.toCharArray());
        docfactory = newFactory();
        builder = docfactory.newDocumentBuilder();
        document = builder.parse(new InputSource(inputaschars));
	if(Yax.XDEBUG)
            dump(document,"");
    } catch (java.lang.Exception e) {
        e.printStackTrace();
	throw new Yax.Exception(e);
    }
}

//////////////////////////////////////////////////
// Support Methods

static DocumentBuilderFactory
newFactory()
        throws java.lang.Exception
{
    DocumentBuilderFactory docfactory = DocumentBuilderFactory.newInstance();
    docfactory.setValidating(false);
    docfactory.setValidating(false);
    docfactory.setFeature("http://apache.org/xml/features/nonvalidating/load-external-dtd", false);

    if(false) {
	docfactory.setFeature("http://xml.org/sax/features/validation", false);
        docfactory.setNamespaceAware(false);
        docfactory.setFeature("http://xml.org/sax/features/namespaces", false);
        docfactory.setFeature("http://apache.org/xml/features/nonvalidating/load-dtd-grammar", false);
    }
    return docfactory;
}

//////////////////////////////////////////////////
// Debug


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
tokenname(Yax.Type token)
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
    if((flags & Yax.FLAG_ELIDETEXT) != 0 && len > Yax.MAXTEXT) {
        len = Yax.MAXTEXT;
        shortened = true;
    }
    dst.append('|');
    for(int i=0;i<txt.length();i++) {
	char c = txt.charAt(i);
        if(len-- <= 0) continue;
        if((flags & Yax.FLAG_ESCAPE) != 0 && c < ' ') {
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
        } else if((flags & Yax.FLAG_NOCR) != 0 && c == '\r') {
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

//////////////////////////////////////////////////
// Public API

/* Basically, we want to do this using a stack
walk(Node n)
{
    if(n.hasAttributes()) {
	NamedNodeList attrs = n.getAttributes();
	for(int i=0;i< attrs.getLength();i++) 
	    Node a=attrs.item(i);
	    walkattr(n,a);
    }
    //Walk children
    boolean hastext = false;
    boolean haschildren = false;
    for(Node child=n.getFirstChild();child != null;child=child.nextSibling()) {
	if(child.getNodeType() == Node.TEXT_NODE)
	    hastext = true;
	else if(child.getNodeType() == Node.ELEMENT_NODE)
	    haschildren = true;
	else
	    throw new Exception("Illegal content:"+child.getNodeType());
	if(hastext && haschildren)
	    throw new Exception("mixed content");
        walk(child);
    }
}
*/

public void
nextToken(Yax.Token token)
    throws Yax.Exception
{
    if(currentNode == null) {
	if(elementStack.size() == 0) {
	    token.type = Yax.Type.EOF;
	    return;
        } else {
	    currentNode = elementStack.pop();
	}
    }
    assert(currentNode != null);
    /* Since current node is not-null, we may be walking the attributes */
    if(currentNode.moreAttributes()) {
        Node attr = currentNode.nextAttribute();
	token.type = Yax.Type.ATTRIBUTE;
	token.name = attr.getNodeName();
	token.text = attr.getNodeValue();
    } else if(currentNode.hasChildren()) {
	// No more children, return OPENCLOSE
	token.type = Yax.Type.EMPTYCLOSE;
	token.name = currentNode.getElement().getNodeName();
    } else if(currentNode.moreChildren()) {
        // If we get here, then we are walking the children
        Node child = currentNode.nextChild();
	if(child.getNodeType() == Node.ELEMENT_NODE) {
            elementStack.push(currentNode);
	    currentNode = new ElementState(child);
	    token.type = Yax.Type.OPEN;
	    token.name = child.getNodeName();
	} else if(child.getNodeType() == Node.TEXT_NODE) { 
	    token.type = Yax.Type.TEXT;
	    token.text = child.getTextContent();
	} else
	    throw new Yax.Exception("Invalid node type: "+child.getNodeType());
    } else //!currentNode.moreChildren()
	token.type = Yax.Type.CLOSE;
	token.name = currentNode.getElement().getNodeName();
    }


//////////////////////////////////////////////////
// Accessors

public int
getFlags()
{
    return (flags);
}

public void
setFlags(int flags)
{
    this.flags = flags;
}

//////////////////////////////////////////////////
// Debug

static void
dump(Node rootNode, String spacer)
{
    System.out.println(spacer + rootNode.getNodeName() + " -> " + rootNode.getNodeValue());
    NodeList nl = rootNode.getChildNodes();
    for (int i = 0; i < nl.getLength(); i++) {
        dump(nl.item(i), spacer + "   ");
    }
}

} // Yax



