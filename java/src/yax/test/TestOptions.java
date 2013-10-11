/**
This software is released under the terms of the Apache License version 2.
For details of the license, see http://www.apache.org/licenses/LICENSE-2.0.
*/

package yax.test;

import yax.*;
import org.apache.commons.cli.*;
import java.io.*;

public class TestOptions
{

    static public String document = null;
    static public int flags = Util.FLAG_NONE;
    static public boolean parsetrace = false;
    static public boolean saxtrace = false;

    static public void
    getoptions(String[] argv)
        throws Exception
    {    
        Options options = new Options();
        options.addOption("x", true, "text controls");
        options.addOption("t", true, "trace controls");
        options.getOption("t").setOptionalArg(true);

        CommandLineParser parser = new PosixParser();
        CommandLine cmd = parser.parse(options, argv);

        argv = cmd.getArgs();
        if(argv.length == 0)
            throw new Exception("no input");
            
        if(cmd.hasOption("t")) {
            String arg = cmd.getOptionValue("t");
            if(arg == null || arg.length() == 0)
               parsetrace = true;       
            else for(int i=0;i<arg.length();i++) {
                char c = arg.charAt(i);
                switch (c) {
                case 'l': saxtrace = true; break;
                case 'p': parsetrace = true; break;
                default:
                    throw new Exception("unknown -t flag: "+c);
                }
            }
        }

        flags = Util.FLAG_NOCR; // always
        if(cmd.hasOption("x")) {
            String arg = cmd.getOptionValue("x");
            if(arg != null)
            for(int i=0;i<arg.length();i++) {
                char c = arg.charAt(i);
                switch (c) {
                case 'w': flags |= Util.FLAG_TRIMTEXT; break;
                case 'l': flags |= Util.FLAG_ELIDETEXT; break;
                case 'e': flags |= Util.FLAG_ESCAPE; break;
                default:
                    throw new Exception("unknown -x flag: "+c);
                }
            }
        }
        document = getinput(argv[0]);
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
}



