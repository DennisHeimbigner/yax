package yax.test;

import yax.lex.*;

import org.apache.commons.cli.*;
import org.w3c.dom.*;
import org.xml.sax.*;

import java.io.*;

public class SaxTest
{

    // Trivial implementation of SaxLexer
    static public class SaxTestLexer extends SaxLexer
    {
	public SaxTestLexer(String document) throws LexException
		{super(document);}
	public String[] orderedAttributes(String element) {return null;}
    }

    static public void
    main(String[] argv)
    {
        SaxLexer lexer;
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

            lexer = new SaxTestLexer(input);
	    lexer.lex(); // build token list

	    int ntokens = lexer.getTokenCount();
	    SaxToken[] tokens = lexer.getTokens(new SaxToken[ntokens]);

            for(i=0;i<ntokens;i++) {
                String trace = null;
                SaxToken token = tokens[i];
                trace = Util.trace(token,flags);
                System.out.printf("saxtest: %s\n",trace);
                System.out.flush();
            }

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
