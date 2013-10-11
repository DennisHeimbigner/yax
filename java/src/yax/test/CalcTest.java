package yax.test;

import org.apache.commons.cli.CommandLine;
import org.apache.commons.cli.CommandLineParser;
import org.apache.commons.cli.Options;
import org.apache.commons.cli.PosixParser;
import org.w3c.dom.Node;
import yax.*;

import java.io.FileReader;
import java.io.IOException;
import java.nio.charset.Charset;

public abstract class CalcTest
{

    //////////////////////////////////////////////////

    static public void
    main(String[] argv)
    {
        int flags = Util.FLAG_NONE;

        try {
	    CalcParser calcpushparser = null;
	    CalcEventHandler calceventhandler = null;

	    TestOptions.getoptions(argv);

            // 1. push parser
            calcpushparser = new CalcParser();
            if(TestOptions.parsetrace)
                calcpushparser.setDebugLevel(1);

            // 2. event handler
            calceventhandler = new CalcEventHandler(TestOptions.document, calcpushparser);
	    if(TestOptions.saxtrace)
		calceventhandler.setTrace(true);

            boolean ok = calceventhandler.parse();
            if(!ok)
                System.err.println("Parse failed");

        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
        System.err.println("No error");
        System.exit(0);
    }

    static String
    getinput(String filename)
        throws IOException
    {
        StringBuilder buf = new StringBuilder();
        FileReader file = new FileReader(filename);
        int c;

        while((c = file.read()) > 0) {
            buf.append((char) c);
        }
        return buf.toString();
    }
} // class CalcTest




