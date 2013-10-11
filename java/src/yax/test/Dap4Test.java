/**
 This software is released under the terms of the Apache License version 2.
 For details of the license, see http://www.apache.org/licenses/LICENSE-2.0.
 */

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

public abstract class Dap4Test
{

    //////////////////////////////////////////////////
    // Constants

    //////////////////////////////////////////////////

    static public void
    main(String[] argv)
    {
        int flags = Util.FLAG_NONE;

        try {
            Dap4Parser dap4pushparser = null;
            Dap4EventHandler dap4eventhandler = null;

	    TestOptions.getoptions(argv);

            // 1. push parser
            dap4pushparser = new Dap4Parser();
            if(TestOptions.parsetrace)
                dap4pushparser.setDebugLevel(1);

            // 2. event handler
            dap4eventhandler = new Dap4EventHandler(TestOptions.document, dap4pushparser);
	    dap4eventhandler.setFlags(TestOptions.flags);	    
	    if(TestOptions.saxtrace)
		dap4eventhandler.setTrace(true);

            if(!dap4eventhandler.parse()) {
                System.err.println("Parse failed");
            }
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
        System.err.println("No error");
        System.exit(0);
    }
} // class Dap4Test




