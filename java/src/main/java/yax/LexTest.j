package yax;

import org.apache.commons.cli.*;

import java.io.*;

public class LexTest
{

static public void
main(String[] argv)
{
    Yax lexer;
    Yax.Token token;
    int flags = Yax.FLAG_NONE;

    String input;
    int i,c;
  
    try {

        Options options = new Options();
        options.addOption("t",false,"trim text");
        options.addOption("e",false,"Limit size of text printout");

        CommandLineParser parser = new PosixParser();
        CommandLine cmd = parser.parse(options, argv);

        argv = cmd.getArgs();

        if(argv.length == 0) {
          System.err.printf("no input\n");
          System.exit(1);
        }

        input = getinput(argv[0]);

        if(cmd.hasOption('t'))
            flags |= Yax.FLAG_TRIMTEXT;
        if(cmd.hasOption('e'))
            flags |= Yax.FLAG_ELIDETEXT;

        lexer = new Yax(input,flags);
	token = new Yax.Token();
        
        for(i=0;i<200;i++) {
            String trace = null;
            lexer.nextToken(token);
            trace = lexer.trace(token);
	    System.out.printf("%s\n",trace);
	    System.out.flush();
	    if(token.tokentype == Yax.TokenType.YAX_EOF)
		break;
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


} //LexTest
