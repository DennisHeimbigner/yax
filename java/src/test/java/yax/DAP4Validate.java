package yax;

import org.apache.commons.cli.*;

import javax.xml.*;
import javax.xml.parsers.*;
import javax.xml.validation.*;
import java.io.*;

import org.w3c.dom.*;
import org.xml.sax.InputSource;

public class DAP4Validate extends Yax
{

static public void
main(String[] argv)
{
    String file = null;

    CharArrayReader src = null;

    if (argv.length >= 1) {
        file = argv[0];
    } else {
        System.err.println("no file");
        System.exit(1);
    }

    try {    
	String input = getInput(file);
        src = new CharArrayReader(input.toCharArray());
    } catch (IOException ioe) {
	ioe.printStackTrace();
	System.exit(1);
    }

    try {
        DocumentBuilderFactory docfactory = null;

        docfactory = newFactory();
        DocumentBuilder builder = docfactory.newDocumentBuilder();

        Document document = builder.parse(new InputSource(src));

	DAP4Validate validator = new DAP4Validate(document);
	try {
	    validator.validate();
	} catch (Exception ye) {
	    ye.printStackTrace();
	    throw new java.lang.Exception("validation failed",ye);
	}

    } catch (java.lang.Exception e) {
        e.printStackTrace();
        System.exit(1);
    }

}

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

static String
getInput(String filename)
        throws IOException
{
    StringBuilder buf = new StringBuilder();
    FileReader file = new FileReader(filename);
    int c;

    while ((c = file.read()) > 0) {
        buf.append((char) c);
    }
    return buf.toString();
}

static void
printNode(Node rootNode)
{
    printNode(rootNode, "");
}

static void
printNode(Node rootNode, String spacer)
{
    System.out.println(spacer + rootNode.getNodeName() + " -> " + rootNode.getNodeValue());
    NodeList nl = rootNode.getChildNodes();
    for (int i = 0; i < nl.getLength(); i++) {
        printNode(nl.item(i), spacer + "   ");
    }
}


//////////////////////////////////////////////////
// Instance

public int getFlags() {return 0;}

enum LegalAttributes {
base,
basetype,
dapVersion,
ddxVersion,
enum,
href,
name,
ns,
size,
type,
value,
xmlns;

// Do equivalent of valueOf, but using null instead
// of returning an exception
public static LegalAttribute valueFor(String name)
{
    return table.get(name.trim());
}
private static Map<String, LegalAttribute> table =
    new EnumMap<String>(LegalAttribute.class);
static {
    for (LegalAttribute attr : LegalAttribute.values()) {
	table.put(att.name(),attr);
    }
}


};

// Define a Keyword enum 
enum LegalElements {
Attribute(
	EnumSet.of(LegalAttribute.name,LegalAttribute.type),
	EnumSet.noneOf(LegalAttribute.class)
),
Dim(
	EnumSet.noneOf(LegalAttribute.class),
	EnumSet.of(LegalAttribute.name,LegalAttribute.size)
),
Dimension(
	EnumSet.of(LegalAttribute.name,LegalAttribute.size),
	EnumSet.noneOf(LegalAttribute.class)
),
EnumConst(
	EnumSet.of(LegalAttribute.name,LegalAttribute.value),
	EnumSet.noneOf(LegalAttribute.class)
),
Enumeration(
	EnumSet.of(LegalAttribute.name,LegalAttribute.basetype),
	EnumSet.noneOf(LegalAttribute.class)
),
Group(
	EnumSet.of(LegalAttribute.name),
	EnumSet.of(LegalAttribute.dapversion,LegalAttribute.ns,LegalAttribute.base)
),
Map(
	EnumSet.of(LegalAttribute.name),
	EnumSet.noneOf(LegalAttribute.class)
),
Namespace(
	EnumSet.of(LegalAttribute.href),
	EnumSet.noneOf(LegalAttribute.class)
),
Structure(
	EnumSet.of(LegalAttribute.name),
	EnumSet.noneOf(LegalAttribute.class)
),
Value(
	EnumSet.of(LegalAttribute.value),
	EnumSet.noneOf(LegalAttribute.class)
),
Char(
	EnumSet.of(LegalAttribute.name),
	EnumSet.noneOf(LegalAttribute.class)
),
Byte(
	EnumSet.of(LegalAttribute.name),
	EnumSet.noneOf(LegalAttribute.class)
),
Int8(
	EnumSet.of(LegalAttribute.name),
	EnumSet.noneOf(LegalAttribute.class)
),
UInt8(
	EnumSet.of(LegalAttribute.name),
	EnumSet.noneOf(LegalAttribute.class)
),
Int16(
	EnumSet.of(LegalAttribute.name),
	EnumSet.noneOf(LegalAttribute.class)
),
UInt16(
	EnumSet.of(LegalAttribute.name),
	EnumSet.noneOf(LegalAttribute.class)
),
Int32(
	EnumSet.of(LegalAttribute.name),
	EnumSet.noneOf(LegalAttribute.class)
),
UInt32(
	EnumSet.of(LegalAttribute.name),
	EnumSet.noneOf(LegalAttribute.class)
),
Int64(
	EnumSet.of(LegalAttribute.name),
	EnumSet.noneOf(LegalAttribute.class)
),
UInt64(
	EnumSet.of(LegalAttribute.name),
	EnumSet.noneOf(LegalAttribute.class)
),
Float32(
	EnumSet.of(LegalAttribute.name),
	EnumSet.noneOf(LegalAttribute.class)
),
Float64(
	EnumSet.of(LegalAttribute.name),
	EnumSet.noneOf(LegalAttribute.class)
),
String(
	EnumSet.of(LegalAttribute.name),
	EnumSet.noneOf(LegalAttribute.class)
),
URL(
	EnumSet.of(LegalAttribute.name),
	EnumSet.noneOf(LegalAttribute.class)
),
Opaque(
	EnumSet.of(LegalAttribute.name),
	EnumSet.noneOf(LegalAttribute.class)
),
Enum(
	EnumSet.of(LegalAttribute.name),
	EnumSet.noneOf(LegalAttribute.class)
),
OtherXML(
	EnumSet.noneOf(LegalAttribute.class),
	EnumSet.noneOf(LegalAttribute.class)
);

private final EnumSet<LegalAttribute> required;
private final EnumSet<LegalAttribute> optional;
LegalElement(EnumSet<LegalAttribute> req, EnumSet<LegalAttribute> opt)
{
    this.required = req;
    this.optional = opt;
}
EnumSet<LegalAttribute> getRequiredAttributes() {return this.required;}
EnumSet<LegalAttribute> getOptionalAttributes() {return this.optional;}

private static Map<String, LegalElement> table =
    new EnumMap<String>(LegalElement.class);
static {
    for (LegalElement attr : LegalElement.values()) {
	table.put(att.name(),attr);
    }
}

// Do equivalent of valueOf, but using null instead
// of returning an exception
public static LegalElement valueFor(String name)
{
    return table.get(name.trim());
}
private static Map<String, LegalElement> table =
    new EnumMap<String>(LegalElement.class);
static {
    for (LegalElement attr : LegalElement.values()) {
	table.put(att.name(),attr);
    }
}

}//LegalElements

// Useful sets
static EnumSet<LegalElement> atomicTags = EnumSet.of(
    LegalElement.Char, LegalElement.Byte,
    LegalElement.Int8, LegalElement.UInt8,
    LegalElement.Int16, LegalElement.UInt16,
    LegalElement.Int32, LegalElement.UInt32,
    LegalElement.Int64, LegalElement.UInt64,
    LegalElement.Float32, LegalElement.Float64,
    LegalElement.String, LegalElement.URL,
    LegalElement.Enum, LegalElement.Opaque
);

static EnumSet<LegalElement> variableTags = EnumSet.of(LegalElement.Structure).addAll(atomicTags);

public DAP4Validate(Document document)
{
}


void
validate(Document ddx)
    throws Exception
{
    group(ddx,true)
}

boolean
group(Node node, boolean root)
    throws Exception
{
    if(!testElement("Group",node))
	throw new Exception();
    if(!group_attr_list(root)) return false;
    if(!group_body(ddx.getChildNodes())) return false;
}

boolean
group_attr_list(Node ddx, boolean root)
    throws Exception
{
    testAttributes(LegalElement.Group,ddx);
    return true;
}

boolean
group_body(NodeList list)
    throws Exception
{
    for(Node node: list) {
        if(testElement(LegalElement.Enumeration,node) && !enumdef(node))
	    throw new Exception(String.format("Malformed Enumeration definition");
        else if(testElement(LegalElement.Dimension,node) && !dimdef(node))
	    throw new Exception(String.format("Malformed Dimension definition");
        else if(testElement(LegalElement.Attribute,node) && !attribute(node))
	    throw new Exception(String.format("Malformed Attribute definition");
        else if(testElement(LegalElement.OtherXML,node) && !otherxml(node))
	    throw new Exception(String.format("Malformed OtherXML definition");
        else if(testElement(LegalElement.Group,node) && !group(node))
	    throw new Exception(String.format("Malformed Group definition");
        else if(testElement(variableTags,node) && !variable(node))
	    throw new Exception(String.format("Malformed Variable definition: %s",node.getName());
	else
	    return false;
    }
    return true;
}

boolean
enumdef(Node ddx)
{// ENUMERATION_ enum_attr_list enumconst_list _ENUMERATION
    LegalElement le = LegalElement.Enumeration;    
    if(!testElement(le,node))
	throw new Exception(String.format("Enumdef: Unexpected element: %s",node.getName());
    if(!enum_attr_list(ddx)) return false;
    if(!enumconst_list(ddx.getChildNodes())) return false;
    return true;
}

boolean
enum_attr_list(Node ddx)
    throws Exception
{
    testAttributes(LegalElement.Enumeration,ddx);
    return true;
}

boolean
enumconst_list(NodeList list)
    throws Exception
{
    for(Node node: list) {
        if(testElement(LegalElement.EnumConst,node) && !enumconst(node))
	    throw new Exception(String.format("Malformed Enumeration Definition");
    }	
    return true;
}

boolean
enumconst(Node ddx)
    throws Exception
{ // ENUMCONST_ enumconst_attr_list _ENUMCONST
    LegalElement element = LegalElement.EnumConst;
    NodeNameMap map = dds.getAttributes();
    List<Node> extras = getExtraAttributes(element,map);
    EnumSet<LegalAttribute> missing = getMissingAttributes(element,map);
    if(missing.size() > 0) {
	throw new Exception(String.format("Element %s: Missing required attributes: %s",
				element.name(),attributeString(missing)));
    if(extras.size() > 0) {
	throw new Exception(String.format("Element %s: Unexpected attributes: %s",
				element.name(),attributeString(extras)));
    return true;
}

boolean
enumconst_attr_list(Node ddx)
    throws Exception
{
	  ATTR_NAME ATTR_VALUE
	| ATTR_VALUE ATTR_NAME
	;
}

boolean
namespace_list(Node ddx)
    throws Exception
{
	  /*empty*/
	| namespace_list namespace
	;
}

boolean
namespace(Node ddx)
    throws Exception
{
	NAMESPACE_ ATTR_HREF _NAMESPACE
	;
}

boolean
dimdef(Node ddx)
    throws Exception
{
	DIMENSION_ dimdef_attr_list metadatalist _DIMENSION
	;
}

boolean
dimdef_attr_list(Node ddx)
    throws Exception
{
	  ATTR_NAME ATTR_SIZE
	| ATTR_SIZE ATTR_NAME
	;
}

boolean
dimref(Node ddx)
    throws Exception
{
	DIM_ dimref_attr_list _DIM
	;
}

boolean
dimref_attr_list(Node ddx)
    throws Exception
{
	  ATTR_NAME
	| ATTR_SIZE
	;
}

boolean
variable(Node ddx)
    throws Exception
{
	  simplevariable
	| structurevariable
n	;
/* Use atomic type to avoid rule explosion */
}

boolean
simplevariable(Node ddx)
    throws Exception
{
	natomictype_ ATTR_NAME variabledef _atomictype
	;

}

boolean
atomictype_(Node ddx)
    throws Exception
{
	  CHAR_
	| BYTE_
	| INT8_
	| UINT8_
	| INT16_
	| UINT16_
	| INT32_
	| UINT32_
	| INT64_
	| UINT64_
	| FLOAT32_
	| FLOAT64_
	| STRING_
	| URL_
	| OPAQUE_
	| ENUM_ ATTR_ENUM
	;
}

boolean
_atomictype(Node ddx)
    throws Exception
{
	  _CHAR
	| _BYTE
	| _INT8
	| _UINT8
	| _INT16
	| _UINT16
	| _INT32
	| _UINT32
	| _INT64
	| _UINT64
	| _FLOAT32
	| _FLOAT64
	| _STRING
	| _URL
	| _OPAQUE
	| _ENUM
	;
}

boolean
variabledef(Node ddx)
    throws Exception
{
	  /*empty*/
	| variabledef dimref
	| variabledef mapref
	| variabledef metadata
	;
}

boolean
mapref(Node ddx)
    throws Exception
{
	MAP_ ATTR_NAME _MAP
	;
}

boolean
structurevariable(Node ddx)
    throws Exception
{
	STRUCTURE_ ATTR_NAME structuredef _STRUCTURE
	;
}

boolean
structuredef(Node ddx)
    throws Exception
{
	  /*empty*/
	| structuredef dimref
	| structuredef variable
	| structuredef metadata
	;
}

boolean
metadatalist(Node ddx)
    throws Exception
{
	  /*empty*/
	| metadatalist metadata
	;
}

boolean
metadata(Node ddx)
    throws Exception
{
	  attribute
	| otherxml
	;
}

boolean
attribute(Node ddx)
    throws Exception
{
	ATTRIBUTE_ attribute_attr_list
                   namespace_list
                   attribute_value_list
		   _ATTRIBUTE
	;
}

boolean
attribute_attr_list(Node ddx)
    throws Exception
{
	  /*empty*/
	| attribute_attr_list ATTR_NAME
	| attribute_attr_list ATTR_TYPE
	| attribute_attr_list ATTR_NAMESPACE
	| attribute_attr_list ATTR_VALUE
	;
}

boolean
attribute_value_list(Node ddx)
    throws Exception
{
	  /*empty*/
	| attribute_value_list attribute_value
	;
}

boolean
attribute_value(Node ddx)
    throws Exception
{
	VALUE_ ATTR_VALUE _VALUE
	;
}

boolean
otherxml(Node ddx)
    throws Exception
{
	OTHERXML

//////////////////////////////////////////////////
// Support functions

// Get set of extra attributes (== !LegalAttribute)
static List<Node>
getExtraAttributes(LegalElement elem, NodeNameMap list)
{
    List<Node> extras = new ArrayList<Node>();
    for(int i=0;i<list.getLength();i++) {
	Node attr = list.item(i);
	LegalAttribute la = LegalAttribute.valueFor(attr.getName().trim());
	if(la == null)
	    extras.add(attr);
    }
}

// Get a list of missing required attributes
static EnumSet<LegalAttribute>
getMissingAttributes(LegalElement elem, NodeNameMap map)
{
    EnumSet<LegalAttribute> missing = EnumSet.noneOf(LegalAttribute.class);
    // assert required intersect optional = empty set
    EnumSet<LegalAttribute> required = elem.getRequired();
    // check for all required attributes
    if(required != NULL)
    for(LegalAttribute la: required) {
	if(NodeNameMap.getNamedItem(la.name()) == null)
	    missing.add(la);
    }
    return missing;
}

// Get a list of present optional attributes
static EnumSet<LegalAttribute>
getOptionalAttributes(LegalElement elem, NodeNameMap map)
{
    EnumSet<LegalAttribute> present = EnumSet.noneOf(LegalAttribute.class);
    // assert required intersect optional = empty set
    EnumSet<LegalAttribute> optional = elem.getOptional();
    // check for all required attributes
    if(optional != NULL)
    for(LegalAttribute la: optional) {
	if(NodeNameMap.getNamedItem(la.name()) != null)
	    presetn.add(la);
    }
    return present;
}

static String
attributeString(List<Node> list)
{
    boolean first = true;
    StringBuilder buf = new StringBuilder();
    for(Node node: list) {
	if(!first) buf.append(",");
	buf.append(node.getName());
	first = false;
    }
    return buf.toString();
}

static String
attributeString(EnumSet<LegalAttribute> set)
{
    boolean first = true;
    StringBuilder buf = new StringBuilder();
    for(LegalAttribute la: set) {
	if(!first) buf.append(",");
	buf.append(la.name());
	first = false;
    }
    return buf.toString();
}

static boolean
testElement(LegalElement elem, Node node)
{
    if(node.getNodeType() != ELEMENT_NODE)
	return false;
    return elem.name().equals(node.getNodeName());
}

static boolean
testElement(EnumSet<LegalElement> set, Node node)
{
    for(LegalElement le: set) {
	if(testElement(le,node))
	    return true;
    }
    return false;
}


static void
testAttributes(LegalElement element, Node ddx)
    throws Exception
{
    NodeNameMap map = ddx.getAttributes();
    List<Node> extras = getExtraAttributes(element,map);
    EnumSet<LegalAttribute> missing = getMissingAttributes(element,map);
    if(missing.size() > 0) {
	throw new Exception(String.format("Element %s: Missing required attributes: %s",
				element.name(),attributeString(missing)));
    if(extras.size() > 0) {
	throw new Exception(String.format("Element %s: Unexpected attributes: %s",
				element.name(),attributeString(extras)));
}
