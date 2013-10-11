#This software is released under the terms of the Apache License version 2.
#For details of the license, see http://www.apache.org/licenses/LICENSE-2.0.

import getopt
import codecs
import util

document = None;
flags = util.FLAG_NONE
parsetrace = False
saxtrace = False

def getOptions(argv):
  global document, flags, parsetrace, saxtrace
  try:
    opts, args = getopt.getopt(argv[1:], "x:t:", ["help", "output="])
  except getopt.GetoptError as err:
    # print help information and exit:
    print(err) # will print something like "option -a not recognized"
    raise Exception(err)

  if (len(args) == 0) :
    raise Exception("no input")

  flags = util.FLAG_NOCR # always
  for o, a in opts:
    if o == "-t":
      if (a != None) and (len(a) != 0) :
        for c in a :
          if c == 'l': saxtrace = True
          elif c == 'p': parsetrace = True
          else:
            raise Exception("unknown -t flag: "+c)
    elif o == "-x" :
      if (a != None) and (len(a) != 0) :
        for c in a :
          if c == 'w': flags = flags + util.FLAG_TRIMTEXT
          elif c == 'l': flags = flags + util.FLAG_ELIDETEXT
          elif c == 'e': flags = flags + util.FLAG_ESCAPE
          else:
            raise Exception("unknown -x flag: "+c)
    else:
      raise Exception("unknown option flag: "+o)

  # read the document as utf
  document = codecs.open(args[0], encoding='utf-8').read()

#end getoptions
