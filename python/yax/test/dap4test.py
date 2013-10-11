# Copyright 2013, UCAR/Unidata.
#  See the COPYRIGHT file for more information.

import os
import sys
import getopt
import codecs
import xml.sax
import StringIO

sys.path.append(os.path.join(os.getcwd(),"yax"))

from saxevent import SaxEvent
from saxeventhandler import SaxEventHandler
import saxeventtype
import util
import testoptions
from Dap4Parser import Dap4Parser
from dap4eventhandler import Dap4EventHandler

def main() :
  testoptions.getOptions(sys.argv);

  # push parser
  dap4pushparser = Dap4Parser()
  if (testoptions.parsetrace) :
    dap4pushparser.setDebugLevel(1);

  # Create handler
  handler = Dap4EventHandler(testoptions.document,dap4pushparser)
  handler.setFlags(testoptions.flags)
  if(testoptions.saxtrace):
    handler.setTrace(True)

  # Parse the document
  handler.parse()

  sys.stdout.write("No error\n");
  sys.exit(0);
# end main()

if __name__ == '__main__':
  main()




