package yax;

import org.apache.commons.cli.*;

import javax.xml.*;
import javax.xml.parsers.*;
import javax.xml.validation.*;
import java.io.*;

import org.w3c.dom.*;
import org.xml.sax.InputSource;

public class DomTest
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

        printNode(document);

    } catch (Exception e) {
        e.printStackTrace();
        System.exit(1);
    }

}

static DocumentBuilderFactory
newFactory()
        throws Exception
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


}
