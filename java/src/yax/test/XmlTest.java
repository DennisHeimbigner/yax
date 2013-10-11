/**
 This software is released under the terms of the Apache License version 2.
 For details of the license, see http://www.apache.org/licenses/LICENSE-2.0.
 */

package yax.test;

import org.apache.commons.cli.CommandLine;
import org.apache.commons.cli.CommandLineParser;
import org.apache.commons.cli.Options;
import org.apache.commons.cli.PosixParser;
import org.w3c.dom.*;
import org.w3c.dom.NodeList;
import yax.*;

import java.io.FileReader;
import java.io.IOException;
import java.nio.charset.Charset;

import static org.w3c.dom.Node.*;

public abstract class XmlTest
{

    //////////////////////////////////////////////////
    // Constants

    //////////////////////////////////////////////////

    static public void
    main(String[] argv)
    {
        int flags = Util.FLAG_NONE;

        try {
            XmlParser xmlpushparser = null;
            XmlEventHandler xmleventhandler = null;

            TestOptions.getoptions(argv);

            // 1. push parser
            xmlpushparser = new XmlParser();
            if(TestOptions.parsetrace)
                xmlpushparser.setDebugLevel(1);

            // 2. event handler
            xmleventhandler = new XmlEventHandler(TestOptions.document, xmlpushparser);
            xmleventhandler.setFlags(TestOptions.flags);            
            if(TestOptions.saxtrace)
                xmleventhandler.setTrace(true);

            if(!xmleventhandler.parse()) {
                System.err.println("Parse failed");
            }
            /* Dump the document */
            String sdoc = dumpnode(xmleventhandler.getDocument());
            System.out.println(sdoc);

        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
        System.err.println("No error");
        System.exit(0);
    }


    static String dumpnode(Document document)
        throws Exception
    {
        StringBuilder buf = new StringBuilder();
        dumpnode((Node)document,0,buf);
        return buf.toString();
    }

    static void dumpnode(Node node, int depth, StringBuilder buf)
        throws Exception
    {
        switch (node.getNodeType()) {
        case DOCUMENT_NODE:
            Node root = ((Document)node).getDocumentElement();
            buf.append("<?xml version=\"1.0\"?>\n");
            buf.append("<!DOCTYPE>\n");
            dumpnode(root,0,buf);
            break;
        case ELEMENT_NODE:
	    Element enode = (Element)node;
            buf.append(String.format("%s<%s",
                       indent(depth),enode.getTagName()));
            NamedNodeMap attrs = enode.getAttributes();
            if(attrs != null) {
                for(int i=0;i<attrs.getLength();i++) {
                    Attr attr = (Attr)attrs.item(i);
                    buf.append(String.format(" %s=\"%s\"",
                               attr.getName(),attr.getValue()));
                }
            }       
            buf.append(">\n");
            NodeList children = enode.getChildNodes();
            if(children != null) {
                for(int i=0;i<children.getLength();i++) {
                    Node child = children.item(i);
                    dumpnode(child,depth+1,buf);
                }
            }
            buf.append(String.format("%s</%s>",
                       indent(depth),enode.getTagName()));
            break;
        case TEXT_NODE:
            buf.append(String.format("%s|%s|",
                       indent(depth),((Text)node).getData()));
            break;
        default:
            String typename = node.getNodeName();
            throw new Exception("dumpnode: unexpected node type: "+typename);
        }
    }

    static String indent(int depth)
    {
        String blanks = "";
        while(depth-- > 0) blanks += "  ";
        return blanks;
    }

} // class XmlTest
