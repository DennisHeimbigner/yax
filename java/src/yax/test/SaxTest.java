package yax.test;

import yax.lex.*;

import org.apache.commons.cli.*;
import org.w3c.dom.*;
import org.xml.sax.*;

import java.io.*;

public class SaxTest
{

    // Simple subclass of SaxEventHandler
    static public class SaxTestHandler extends SaxEventHandler
    {
	public SaxTestHandler(String document) throws SAXException
		{super(document);}
	// Define the abstract methods
	public String[] orderedAttributes(String element) {return null;}

	public void yyevent(SaxToken token)
	    throws SAXException
	{
            String trace = null;
            trace = Util.trace(token,0);
            System.out.printf("saxtest: %s\n",trace);
            System.out.flush();
	}
    }

    static public void
    main(String[] argv)
    {
        SaxTestHandler handler;
        int flags = Util.FLAG_NONE;
        Type tokentype = null;
	Node[] nodep = new Node[]{null};
	
        String input;
        int i,c;

        try {
            Options options = new Options();
            options.addOption("t",false,"trim text");
            options.addOption("l",false,"Limit size of text printout");
            options.addOption("e",false,"Escape control characters");

            CommandLineParser parser = new PosixParser();
            CommandLine cmd = parser.parse(options, argv);

            argv = cmd.getArgs();

            if(argv.length == 0) {
              System.err.printf("no input\n");
              System.exit(1);
            }

            input = getinput(argv[0]);

            flags = Util.FLAG_NOCR; // always
            if(cmd.hasOption('t'))
                flags |= Util.FLAG_TRIMTEXT;
            if(cmd.hasOption('l'))
                flags |= Util.FLAG_ELIDETEXT;
            if(cmd.hasOption('e'))
                flags |= Util.FLAG_ESCAPE;

            handler = new SaxTestHandler(input);
	    handler.parse();

        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
        System.out.println("No error");
        System.exit(0);
    }

    static String
    getinput(String filename)
        throws IOException
    {
        StringBuilder buf = new StringBuilder();
        FileReader file = new FileReader(filename);
        int c;

        while((c=file.read()) > 0) {
            buf.append((char)c);
        }
        return buf.toString();
    }


} //SaxTest
