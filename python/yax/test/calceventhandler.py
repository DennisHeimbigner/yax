#This software is released under the terms of the Apache License version 2.
#For details of the license, see http://www.apache.org/licenses/LICENSE-2.0.

import saxeventtype
from xml.sax import SAXException
from saxeventhandler import SaxEventHandler
from lexeme import Lexeme
from CalcParser import *

def static () :
  global elementmap, attributemap

  elementmap = {}
  attributemap = {}

  elementmap[u"calc"] = Lexeme(u"calc", CALC, CALC_, None)
  elementmap[u"eq"]   = Lexeme(u"eq",  EQ, EQ_, None)
  elementmap[u"add"]  = Lexeme(u"add", ADD, ADD_, None)
  elementmap[u"sub"]  = Lexeme(u"sub", SUB, SUB_, None)
  elementmap[u"mul"]  = Lexeme(u"mul", MUL, MUL_, None)
  elementmap[u"div"]  = Lexeme(u"div", DIV, DIV_, None)
  elementmap[u"neg"]  = Lexeme(u"neg", NEG, NEG_, None)
  elementmap[u"exp"]  = Lexeme(u"exp", EXP, EXP_, None)
  elementmap[u"int"]  = Lexeme(u"int", INT, INT_, (u"n"), True)

  # Always insert the lowercase name
  attributemap[u"n"] = Lexeme(u"n",attr=ATTR_N)
# end static

static() # initialize static constants

#########################

class CalcEventHandler (SaxEventHandler) :

  #########################
  # Constructor(s)

  def __init__(self, document, pushparser) :
    SaxEventHandler.__init__(self,document)
    self.pushparser = pushparser
    self.accepted = False
    self.textok = False

  #########################
  # Abstract method overrides

  # Push the token to the parser
  # @raise SAXException if parser return YYABORT

  def yyevent(self,saxtoken) :
    global elementmap, attributemap    
    if(self.accepted) :
      raise SAXException("yyevent called after parser has accepted")
    yaxevent = saxtoken.event
    name = saxtoken.name
    yytoken = 0
    element = None
    attr = None

    if name in elementmap:
      element = elementmap[name]
    else: element = None

    # switch(yaxevent) simulate with if..elif...
    if (yaxevent == saxeventtype.STARTELEMENT) :
      if(element == None) : # undefined
        yytoken = UNKNOWN_ELEMENT
      else:
        yytoken = element.open
        # Check for the special cases
        if(element.textok) :
          self.textok = True

    elif (yaxevent == saxeventtype.ATTRIBUTE) :
      if name.lower() in attributemap:
        attr = attributemap[name.lower()]
      else:
        attr = None
      if(attr == None) :
        yytoken = UNKNOWN_ATTR
      else :
        yytoken = attr.attr

    elif (yaxevent == saxeventtype.ENDELEMENT) :
      if(element == None) : # undefined
        yytoken = UNKNOWN_ELEMENT_
      else :
        yytoken = element.close
        self.textok = False

    elif (yaxevent == saxeventtype.CHARACTERS) :
      if(not self.textok) :
        return # ignore
      yytoken = TEXT

    elif (yaxevent == saxeventtype.STARTDOCUMENT) :
      return # ignore

    elif (yaxevent == saxeventtype.ENDDOCUMENT) :
      yytoken = EOF

    else : #default
      self.pushparser.yyerror("unknown event type: %s\n".format(yaxevent.name))
      yytoken = ERROR

    status = 0
    try :
      status = self.pushparser.push_parse(yytoken,saxtoken)
    except SAXException as se :
      raise se
    except Exception as e :
      raise SAXException("Parse failure:"+str(e))
    if(status == YYABORT) :
      raise SAXException("YYABORT")
    elif(status == YYACCEPT) :
      accepted = True
  # end yyevent

# end class CalcEventHandler
  
