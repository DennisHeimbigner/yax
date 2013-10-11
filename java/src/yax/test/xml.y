/**
This software is released under the terms of the Apache License version 2.
For details of the license, see http://www.apache.org/licenses/LICENSE-2.0.
*/

%language "Java"
%define api.push-pull push
%define parse.error verbose

%define public
%define parser_class_name {XmlParser}
%define package {yax.test}

%code imports {
import yax.*;
import org.w3c.dom.*;
import org.xml.sax.Locator;
import javax.xml.parsers.*;
import java.util.*;
class AttributeMap extends HashMap<String,String> {}
class NList extends ArrayList<Node> {}
}

%code lexer {
public Object getLVal() {return null;}
public int yylex() {return 0;}
public void yyerror(String s) {System.err.println(s);}
}

%code {
    public DocumentBuilderFactory factory;
    public DocumentBuilder builder;
    public DOMImplementation impl;
    public Document document;
}

%code init {
    try {
        factory = DocumentBuilderFactory.newInstance();
        builder = factory.newDocumentBuilder();
        impl = builder.getDOMImplementation();
        factory.setNamespaceAware(false);
        factory.setValidating(false);
        factory.setFeature(SaxEventHandler.LOAD_EXTERNAL_DTD, false);
    } catch (Exception e) {
	yyerror("Initialization failure: "+e);
	e.printStackTrace();
    }
}

%code {

public Document getDocument() {return this.document;}

void startdocument(SaxEvent open, AttributeMap attrs)
{
    Locator loc = open.getLocator();
    DocumentType doctype
	= impl.createDocumentType(/*qualifiedName*/ "document",
				  /*publicId*/ loc.getPublicId(),
				  /*systemId*/ loc.getSystemId());
    this.document = impl.createDocument(/*namespaceURI*/ "",
                                        /*qualifiedName*/ open.name,
                                        (DocumentType)doctype);
    Element root = (Element)this.document.getDocumentElement();
    for(String key: attrs.keySet()) {
	String value = attrs.get(key);
	root.setAttribute(key,value);
    }
}

void doctype(SaxEvent startdoc)
{
}

void enddocument(SaxEvent close, NList body)
{
    Node root = this.document.getDocumentElement();
    if(!root.getLocalName().equals(close.name)) {
	yyerror("Open/close name mismatch: %s :: %s".format(root.getLocalName(),close.name));
	return;
    }    
    for(Node node: body)
	root.appendChild(node);
    return;
}

NList body(NList list, Node node)
{
    if(list == null) list = new NList();
    if(node != null) list.add(node);
    return list;
}

Node element(SaxEvent open,
             AttributeMap attrs,
             List<Node> body,
	     SaxEvent close)
{
    if(!open.name.equals(close.name)) {
	yyerror("Open/close name mismatch: %s :: %s".format(open.name,close.name));
	return null;
    }    
    Element element = document.createElement(open.name);
    for(String key: attrs.keySet()) {
	String value = attrs.get(key);
	element.setAttribute(key,value);
    }
    for(Node node: body)
	element.appendChild(node);
    return element;
}

Node text(SaxEvent text)
{
    Text textnode = document.createTextNode(text.text);
    return textnode;
}

AttributeMap attribute_map(AttributeMap map, SaxEvent attr)
{
    if(map == null) map = new AttributeMap();
    if(attr != null)
        map.put(attr.name,attr.value);
    return map;
}

}

%token <SaxEvent> OPEN CLOSE ATTRIBUTE TEXT DOCTYPE

%type <Node> document doctype node
%type <NList> body
%type <AttributeMap> attribute_map

/* Error support tokens */
%token <token> ERROR

%start document

/* Note that the sax parser will suppress
   any <?xml ... ?> line.
*/

%%

/* For the Java DOM code, creating the document object
   also requires specifying the root element
*/
document:
	doctype
	OPEN
        attribute_map
	    {startdocument($2,$3);}
	body
	CLOSE
	    {enddocument($6,$5);}
	;

doctype:
	DOCTYPE
		{doctype($1);}
	;

body:
	  /*empty*/
		{$$=body(null,null);}
	| body node
		{$$=body($1,$2);}
	;

node:
	  OPEN
	  attribute_map
	  body
	  CLOSE
	    {$$=element($1,$2,$3,$4);}
	| TEXT
	    {$$=text($1);}
	;

attribute_map:
	  /*empty*/
		{$$=attribute_map(null,null);}
	| attribute_map ATTRIBUTE
		{$$=attribute_map($1,$2);}
	;
