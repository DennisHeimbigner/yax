#This software is released under the terms of the Apache License version 2.
#For details of the license, see http://www.apache.org/licenses/LICENSE-2.0.

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
from CalcParser import CalcParser
from calceventhandler import CalcEventHandler

def main() :
  testoptions.getOptions(sys.argv);

  # push parser
  calcpushparser = CalcParser()
  if (testoptions.parsetrace) :
    calcpushparser.setDebugLevel(1);

  # Create handler
  handler = CalcEventHandler(testoptions.document,calcpushparser)
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




