/* A Bison parser, made by GNU Bison 2.4.2.  */

/* Skeleton implementation for Bison LALR(1) parsers in Java
   
      Copyright (C) 2007-2010 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

package yax;
/* First part of user declarations.  */

/* "%code imports" blocks.  */

/* Line 33 of lalr1.java  */
/* Line 10 of "dap4.y"  */

import opendap.dap.*;
import opendap.dap.BaseTypeFactory;
import opendap.dap.parsers.ParseException;
import java.io.*;



/* Line 33 of lalr1.java  */
/* Line 50 of "DAP4Parser.java"  */

/**
 * A Bison parser, automatically generated from <tt>dap4.y</tt>.
 *
 * @author LALR (1) parser skeleton written by Paolo Bonzini.
 */
public class DAP4Parser extends DAP4parse
{
    /** Version number for the Bison executable that generated this parser.  */
  public static final String bisonVersion = "2.4.2";

  /** Name of the skeleton that generated this parser.  */
  public static final String bisonSkeleton = "lalr1.java";


  /** True if verbose error messages are enabled.  */
  public boolean errorVerbose = true;



  /** Token returned by the scanner to signal the end of its input.  */
  public static final int EOF = 0;

/* Tokens.  */
  /** Token number, to be returned by the scanner.  */
  public static final int GROUP_ = 258;
  /** Token number, to be returned by the scanner.  */
  public static final int _GROUP = 259;
  /** Token number, to be returned by the scanner.  */
  public static final int ENUMERATION_ = 260;
  /** Token number, to be returned by the scanner.  */
  public static final int _ENUMERATION = 261;
  /** Token number, to be returned by the scanner.  */
  public static final int ENUMCONST_ = 262;
  /** Token number, to be returned by the scanner.  */
  public static final int _ENUMCONST = 263;
  /** Token number, to be returned by the scanner.  */
  public static final int NAMESPACE_ = 264;
  /** Token number, to be returned by the scanner.  */
  public static final int _NAMESPACE = 265;
  /** Token number, to be returned by the scanner.  */
  public static final int DIMENSION_ = 266;
  /** Token number, to be returned by the scanner.  */
  public static final int _DIMENSION = 267;
  /** Token number, to be returned by the scanner.  */
  public static final int DIM_ = 268;
  /** Token number, to be returned by the scanner.  */
  public static final int _DIM = 269;
  /** Token number, to be returned by the scanner.  */
  public static final int ENUM_ = 270;
  /** Token number, to be returned by the scanner.  */
  public static final int _ENUM = 271;
  /** Token number, to be returned by the scanner.  */
  public static final int MAP_ = 272;
  /** Token number, to be returned by the scanner.  */
  public static final int _MAP = 273;
  /** Token number, to be returned by the scanner.  */
  public static final int STRUCTURE_ = 274;
  /** Token number, to be returned by the scanner.  */
  public static final int _STRUCTURE = 275;
  /** Token number, to be returned by the scanner.  */
  public static final int VALUE_ = 276;
  /** Token number, to be returned by the scanner.  */
  public static final int _VALUE = 277;
  /** Token number, to be returned by the scanner.  */
  public static final int ATTRIBUTE_ = 278;
  /** Token number, to be returned by the scanner.  */
  public static final int _ATTRIBUTE = 279;
  /** Token number, to be returned by the scanner.  */
  public static final int CHAR_ = 280;
  /** Token number, to be returned by the scanner.  */
  public static final int _CHAR = 281;
  /** Token number, to be returned by the scanner.  */
  public static final int BYTE_ = 282;
  /** Token number, to be returned by the scanner.  */
  public static final int _BYTE = 283;
  /** Token number, to be returned by the scanner.  */
  public static final int INT8_ = 284;
  /** Token number, to be returned by the scanner.  */
  public static final int _INT8 = 285;
  /** Token number, to be returned by the scanner.  */
  public static final int UINT8_ = 286;
  /** Token number, to be returned by the scanner.  */
  public static final int _UINT8 = 287;
  /** Token number, to be returned by the scanner.  */
  public static final int INT16_ = 288;
  /** Token number, to be returned by the scanner.  */
  public static final int _INT16 = 289;
  /** Token number, to be returned by the scanner.  */
  public static final int UINT16_ = 290;
  /** Token number, to be returned by the scanner.  */
  public static final int _UINT16 = 291;
  /** Token number, to be returned by the scanner.  */
  public static final int INT32_ = 292;
  /** Token number, to be returned by the scanner.  */
  public static final int _INT32 = 293;
  /** Token number, to be returned by the scanner.  */
  public static final int UINT32_ = 294;
  /** Token number, to be returned by the scanner.  */
  public static final int _UINT32 = 295;
  /** Token number, to be returned by the scanner.  */
  public static final int INT64_ = 296;
  /** Token number, to be returned by the scanner.  */
  public static final int _INT64 = 297;
  /** Token number, to be returned by the scanner.  */
  public static final int UINT64_ = 298;
  /** Token number, to be returned by the scanner.  */
  public static final int _UINT64 = 299;
  /** Token number, to be returned by the scanner.  */
  public static final int FLOAT32_ = 300;
  /** Token number, to be returned by the scanner.  */
  public static final int _FLOAT32 = 301;
  /** Token number, to be returned by the scanner.  */
  public static final int FLOAT64_ = 302;
  /** Token number, to be returned by the scanner.  */
  public static final int _FLOAT64 = 303;
  /** Token number, to be returned by the scanner.  */
  public static final int STRING_ = 304;
  /** Token number, to be returned by the scanner.  */
  public static final int _STRING = 305;
  /** Token number, to be returned by the scanner.  */
  public static final int URL_ = 306;
  /** Token number, to be returned by the scanner.  */
  public static final int _URL = 307;
  /** Token number, to be returned by the scanner.  */
  public static final int OPAQUE_ = 308;
  /** Token number, to be returned by the scanner.  */
  public static final int _OPAQUE = 309;
  /** Token number, to be returned by the scanner.  */
  public static final int ATTR_BASE = 310;
  /** Token number, to be returned by the scanner.  */
  public static final int ATTR_BASETYPE = 311;
  /** Token number, to be returned by the scanner.  */
  public static final int ATTR_DAPVERSION = 312;
  /** Token number, to be returned by the scanner.  */
  public static final int ATTR_DDXVERSION = 313;
  /** Token number, to be returned by the scanner.  */
  public static final int ATTR_ENUM = 314;
  /** Token number, to be returned by the scanner.  */
  public static final int ATTR_HREF = 315;
  /** Token number, to be returned by the scanner.  */
  public static final int ATTR_NAME = 316;
  /** Token number, to be returned by the scanner.  */
  public static final int ATTR_NAMESPACE = 317;
  /** Token number, to be returned by the scanner.  */
  public static final int ATTR_SIZE = 318;
  /** Token number, to be returned by the scanner.  */
  public static final int ATTR_TYPE = 319;
  /** Token number, to be returned by the scanner.  */
  public static final int ATTR_VALUE = 320;
  /** Token number, to be returned by the scanner.  */
  public static final int ATTR_NS = 321;
  /** Token number, to be returned by the scanner.  */
  public static final int ATTR_XMLNS = 322;
  /** Token number, to be returned by the scanner.  */
  public static final int UNKNOWN_ATTR = 323;
  /** Token number, to be returned by the scanner.  */
  public static final int UNKNOWN_ELEMENT_ = 324;
  /** Token number, to be returned by the scanner.  */
  public static final int _UNKNOWN_ELEMENT = 325;
  /** Token number, to be returned by the scanner.  */
  public static final int TEXT = 326;
  /** Token number, to be returned by the scanner.  */
  public static final int OTHERXML = 327;
  /** Token number, to be returned by the scanner.  */
  public static final int ERROR = 328;
  /** Token number, to be returned by the scanner.  */
  public static final int UNKNOWN = 329;
  /** Token number, to be returned by the scanner.  */
  public static final int UNEXPECTED = 330;



  

  /**
   * Communication interface between the scanner and the Bison-generated
   * parser <tt>DAP4Parser</tt>.
   */
  public interface Lexer {
    

    /**
     * Method to retrieve the semantic value of the last scanned token.
     * @return the semantic value of the last scanned token.  */
    Object getLVal ();

    /**
     * Entry point for the scanner.  Returns the token identifier corresponding
     * to the next token and prepares to return the semantic value
     * of the token.
     * @return the token identifier corresponding to the next token. */
    int yylex () throws Exception;

    /**
     * Entry point for error reporting.  Emits an error
     * in a user-defined way.
     *
     * 
     * @param s The string for the error message.  */
     void yyerror (String s);
  }

  /** The object doing lexical analysis for us.  */
  private Lexer yylexer;
  
  



  /**
   * Instantiates the Bison-generated parser.
   * @param yylexer The scanner that will supply tokens to the parser.
   */
  public DAP4Parser (Lexer yylexer) {
    this.yylexer = yylexer;
    
  }

  private java.io.PrintStream yyDebugStream = System.err;

  /**
   * Return the <tt>PrintStream</tt> on which the debugging output is
   * printed.
   */
  public final java.io.PrintStream getDebugStream () { return yyDebugStream; }

  /**
   * Set the <tt>PrintStream</tt> on which the debug output is printed.
   * @param s The stream that is used for debugging output.
   */
  public final void setDebugStream(java.io.PrintStream s) { yyDebugStream = s; }

  private int yydebug = 0;

  /**
   * Answer the verbosity of the debugging output; 0 means that all kinds of
   * output from the parser are suppressed.
   */
  public final int getDebugLevel() { return yydebug; }

  /**
   * Set the verbosity of the debugging output; 0 means that all kinds of
   * output from the parser are suppressed.
   * @param level The verbosity level for debugging output.
   */
  public final void setDebugLevel(int level) { yydebug = level; }

  private final int yylex () throws Exception {
    return yylexer.yylex ();
  }
  protected final void yyerror (String s) {
    yylexer.yyerror (s);
  }

  

  protected final void yycdebug (String s) {
    if (yydebug > 0)
      yyDebugStream.println (s);
  }

  private final class YYStack {
    private int[] stateStack = new int[16];
    
    private Object[] valueStack = new Object[16];

    public int size = 16;
    public int height = -1;

    public final void push (int state, Object value			    ) {
      height++;
      if (size == height)
        {
	  int[] newStateStack = new int[size * 2];
	  System.arraycopy (stateStack, 0, newStateStack, 0, height);
	  stateStack = newStateStack;
	  

	  Object[] newValueStack = new Object[size * 2];
	  System.arraycopy (valueStack, 0, newValueStack, 0, height);
	  valueStack = newValueStack;

	  size *= 2;
	}

      stateStack[height] = state;
      
      valueStack[height] = value;
    }

    public final void pop () {
      height--;
    }

    public final void pop (int num) {
      // Avoid memory leaks... garbage collection is a white lie!
      if (num > 0) {
	java.util.Arrays.fill (valueStack, height - num + 1, height, null);
        
      }
      height -= num;
    }

    public final int stateAt (int i) {
      return stateStack[height - i];
    }

    public final Object valueAt (int i) {
      return valueStack[height - i];
    }

    // Print the state stack on the debug stream.
    public void print (java.io.PrintStream out)
    {
      out.print ("Stack now");

      for (int i = 0; i < height; i++)
        {
	  out.print (' ');
	  out.print (stateStack[i]);
        }
      out.println ();
    }
  }

  /**
   * Returned by a Bison action in order to stop the parsing process and
   * return success (<tt>true</tt>).  */
  public static final int YYACCEPT = 0;

  /**
   * Returned by a Bison action in order to stop the parsing process and
   * return failure (<tt>false</tt>).  */
  public static final int YYABORT = 1;

  /**
   * Returned by a Bison action in order to start error recovery without
   * printing an error message.  */
  public static final int YYERROR = 2;

  /**
   * Returned by a Bison action in order to print an error message and start
   * error recovery.  Formally deprecated in Bison 2.4.2's NEWS entry, where
   * a plan to phase it out is discussed.  */
  public static final int YYFAIL = 3;

  private static final int YYNEWSTATE = 4;
  private static final int YYDEFAULT = 5;
  private static final int YYREDUCE = 6;
  private static final int YYERRLAB1 = 7;
  private static final int YYRETURN = 8;

  private int yyerrstatus_ = 0;

  /**
   * Return whether error recovery is being done.  In this state, the parser
   * reads token until it reaches a known state, and then restarts normal
   * operation.  */
  public final boolean recovering ()
  {
    return yyerrstatus_ == 0;
  }

  private int yyaction (int yyn, YYStack yystack, int yylen) throws Exception
  {
    Object yyval;
    

    /* If YYLEN is nonzero, implement the default value of the action:
       `$$ = $1'.  Otherwise, use the top of the stack.

       Otherwise, the following line sets YYVAL to garbage.
       This behavior is undocumented and Bison
       users should not rely upon it.  */
    if (yylen > 0)
      yyval = yystack.valueAt (yylen - 1);
    else
      yyval = yystack.valueAt (0);

    yy_reduce_print (yyn, yystack);

    switch (yyn)
      {
	  case 2:
  if (yyn == 2)
    
/* Line 354 of lalr1.java  */
/* Line 110 of "dap4.y"  */
    {yyval=d4group(parser,((List)(yystack.valueAt (4-(2)))),((List)(yystack.valueAt (4-(3))))); CHECK(yyval); };
  break;
    

  case 3:
  if (yyn == 3)
    
/* Line 354 of lalr1.java  */
/* Line 114 of "dap4.y"  */
    {yyval=d4attrlist(parser,NULL,emptytoken);};
  break;
    

  case 4:
  if (yyn == 4)
    
/* Line 354 of lalr1.java  */
/* Line 116 of "dap4.y"  */
    {yyval=d4attrlist(parser,((List)(yystack.valueAt (2-(1)))),((YaxToken)(yystack.valueAt (2-(2)))));};
  break;
    

  case 5:
  if (yyn == 5)
    
/* Line 354 of lalr1.java  */
/* Line 118 of "dap4.y"  */
    {yyval=d4attrlist(parser,((List)(yystack.valueAt (2-(1)))),((YaxToken)(yystack.valueAt (2-(2)))));};
  break;
    

  case 6:
  if (yyn == 6)
    
/* Line 354 of lalr1.java  */
/* Line 120 of "dap4.y"  */
    {yyval=d4attrlist(parser,((List)(yystack.valueAt (2-(1)))),((YaxToken)(yystack.valueAt (2-(2)))));};
  break;
    

  case 7:
  if (yyn == 7)
    
/* Line 354 of lalr1.java  */
/* Line 122 of "dap4.y"  */
    {yyval=d4attrlist(parser,((List)(yystack.valueAt (2-(1)))),((YaxToken)(yystack.valueAt (2-(2)))));};
  break;
    

  case 8:
  if (yyn == 8)
    
/* Line 354 of lalr1.java  */
/* Line 124 of "dap4.y"  */
    {yyval=d4attrlist(parser,((List)(yystack.valueAt (2-(1)))),((YaxToken)(yystack.valueAt (2-(2)))));};
  break;
    

  case 9:
  if (yyn == 9)
    
/* Line 354 of lalr1.java  */
/* Line 126 of "dap4.y"  */
    {yyval=d4attrlist(parser,((List)(yystack.valueAt (2-(1)))),((YaxToken)(yystack.valueAt (2-(2)))));};
  break;
    

  case 10:
  if (yyn == 10)
    
/* Line 354 of lalr1.java  */
/* Line 128 of "dap4.y"  */
    {yyval=d4attrlist(parser,((List)(yystack.valueAt (2-(1)))),((YaxToken)(yystack.valueAt (2-(2)))));};
  break;
    

  case 11:
  if (yyn == 11)
    
/* Line 354 of lalr1.java  */
/* Line 133 of "dap4.y"  */
    {yyval=d4list(parser,NULL,NULL);};
  break;
    

  case 12:
  if (yyn == 12)
    
/* Line 354 of lalr1.java  */
/* Line 135 of "dap4.y"  */
    {yyval=d4list(parser,((List)(yystack.valueAt (2-(1)))),((Object)(yystack.valueAt (2-(2)))));};
  break;
    

  case 13:
  if (yyn == 13)
    
/* Line 354 of lalr1.java  */
/* Line 137 of "dap4.y"  */
    {yyval=d4list(parser,((List)(yystack.valueAt (2-(1)))),((Object)(yystack.valueAt (2-(2)))));};
  break;
    

  case 14:
  if (yyn == 14)
    
/* Line 354 of lalr1.java  */
/* Line 139 of "dap4.y"  */
    {yyval=d4list(parser,((List)(yystack.valueAt (2-(1)))),((Object)(yystack.valueAt (2-(2)))));};
  break;
    

  case 15:
  if (yyn == 15)
    
/* Line 354 of lalr1.java  */
/* Line 141 of "dap4.y"  */
    {yyval=d4list(parser,((List)(yystack.valueAt (2-(1)))),((Object)(yystack.valueAt (2-(2)))));};
  break;
    

  case 16:
  if (yyn == 16)
    
/* Line 354 of lalr1.java  */
/* Line 143 of "dap4.y"  */
    {yyval=d4list(parser,((List)(yystack.valueAt (2-(1)))),((Object)(yystack.valueAt (2-(2)))));};
  break;
    

  case 17:
  if (yyn == 17)
    
/* Line 354 of lalr1.java  */
/* Line 148 of "dap4.y"  */
    {yyval=d4enumdef(parser,((List)(yystack.valueAt (4-(2)))),((List)(yystack.valueAt (4-(3))))); CHECK(yyval);};
  break;
    

  case 18:
  if (yyn == 18)
    
/* Line 354 of lalr1.java  */
/* Line 153 of "dap4.y"  */
    {yyval=d4attrlist(parser,NULL,emptytoken);
		d4attrlist(parser,yyval,((YaxToken)(yystack.valueAt (2-(1)))));
		d4attrlist(parser,yyval,((YaxToken)(yystack.valueAt (2-(2)))));
	    };
  break;
    

  case 19:
  if (yyn == 19)
    
/* Line 354 of lalr1.java  */
/* Line 158 of "dap4.y"  */
    {yyval=d4attrlist(parser,NULL,emptytoken);
		d4attrlist(parser,yyval,((YaxToken)(yystack.valueAt (2-(1)))));
		d4attrlist(parser,yyval,((YaxToken)(yystack.valueAt (2-(2)))));
	    };
  break;
    

  case 20:
  if (yyn == 20)
    
/* Line 354 of lalr1.java  */
/* Line 166 of "dap4.y"  */
    {yyval=d4list(parser,NULL,NULL);};
  break;
    

  case 21:
  if (yyn == 21)
    
/* Line 354 of lalr1.java  */
/* Line 168 of "dap4.y"  */
    {yyval=d4list(parser,((List)(yystack.valueAt (2-(1)))),((Object)(yystack.valueAt (2-(2)))));};
  break;
    

  case 22:
  if (yyn == 22)
    
/* Line 354 of lalr1.java  */
/* Line 174 of "dap4.y"  */
    {yyval=d4enumconst(parser,((List)(yystack.valueAt (3-(2))))); CHECK(yyval);};
  break;
    

  case 23:
  if (yyn == 23)
    
/* Line 354 of lalr1.java  */
/* Line 179 of "dap4.y"  */
    {yyval=d4attrlist(parser,NULL,emptytoken);
		d4attrlist(parser,yyval,((YaxToken)(yystack.valueAt (2-(1)))));
		d4attrlist(parser,yyval,((YaxToken)(yystack.valueAt (2-(2)))));
	    };
  break;
    

  case 24:
  if (yyn == 24)
    
/* Line 354 of lalr1.java  */
/* Line 184 of "dap4.y"  */
    {yyval=d4attrlist(parser,NULL,emptytoken);
		d4attrlist(parser,yyval,((YaxToken)(yystack.valueAt (2-(1)))));
		d4attrlist(parser,yyval,((YaxToken)(yystack.valueAt (2-(2)))));
	    };
  break;
    

  case 25:
  if (yyn == 25)
    
/* Line 354 of lalr1.java  */
/* Line 192 of "dap4.y"  */
    {yyval=d4list(parser,NULL,NULL);};
  break;
    

  case 26:
  if (yyn == 26)
    
/* Line 354 of lalr1.java  */
/* Line 194 of "dap4.y"  */
    {yyval=d4list(parser,((List)(yystack.valueAt (2-(1)))),((Object)(yystack.valueAt (2-(2)))));};
  break;
    

  case 27:
  if (yyn == 27)
    
/* Line 354 of lalr1.java  */
/* Line 199 of "dap4.y"  */
    {yyval=d4namespace(parser,((YaxToken)(yystack.valueAt (3-(2))))); CHECK(yyval);};
  break;
    

  case 28:
  if (yyn == 28)
    
/* Line 354 of lalr1.java  */
/* Line 204 of "dap4.y"  */
    {yyval=d4dimdef(parser,((List)(yystack.valueAt (4-(2)))),((List)(yystack.valueAt (4-(3))))); CHECK(yyval);};
  break;
    

  case 29:
  if (yyn == 29)
    
/* Line 354 of lalr1.java  */
/* Line 209 of "dap4.y"  */
    {yyval=d4attrlist(parser,NULL,emptytoken);
		d4attrlist(parser,yyval,((YaxToken)(yystack.valueAt (2-(1)))));
		d4attrlist(parser,yyval,((YaxToken)(yystack.valueAt (2-(2)))));
	    };
  break;
    

  case 30:
  if (yyn == 30)
    
/* Line 354 of lalr1.java  */
/* Line 214 of "dap4.y"  */
    {yyval=d4attrlist(parser,NULL,emptytoken);
		d4attrlist(parser,yyval,((YaxToken)(yystack.valueAt (2-(1)))));
		d4attrlist(parser,yyval,((YaxToken)(yystack.valueAt (2-(2)))));
	    };
  break;
    

  case 31:
  if (yyn == 31)
    
/* Line 354 of lalr1.java  */
/* Line 222 of "dap4.y"  */
    {yyval=d4dimref(parser,((List)(yystack.valueAt (3-(2))))); CHECK(yyval);};
  break;
    

  case 32:
  if (yyn == 32)
    
/* Line 354 of lalr1.java  */
/* Line 227 of "dap4.y"  */
    {yyval=d4attrlist(parser,NULL,emptytoken);
		d4attrlist(parser,yyval,((YaxToken)(yystack.valueAt (1-(1)))));
	    };
  break;
    

  case 33:
  if (yyn == 33)
    
/* Line 354 of lalr1.java  */
/* Line 231 of "dap4.y"  */
    {yyval=d4attrlist(parser,NULL,emptytoken);
		d4attrlist(parser,yyval,((YaxToken)(yystack.valueAt (1-(1)))));
	    };
  break;
    

  case 34:
  if (yyn == 34)
    
/* Line 354 of lalr1.java  */
/* Line 237 of "dap4.y"  */
    {yyval=((Object)(yystack.valueAt (1-(1))));};
  break;
    

  case 35:
  if (yyn == 35)
    
/* Line 354 of lalr1.java  */
/* Line 238 of "dap4.y"  */
    {yyval=((Object)(yystack.valueAt (1-(1))));};
  break;
    

  case 36:
  if (yyn == 36)
    
/* Line 354 of lalr1.java  */
/* Line 244 of "dap4.y"  */
    {yyval=d4simplevariable(parser,((YaxToken)(yystack.valueAt (4-(1)))),((YaxToken)(yystack.valueAt (4-(2)))),((Object)(yystack.valueAt (4-(3)))),((YaxToken)(yystack.valueAt (4-(4))))); CHECK(yyval);};
  break;
    

  case 37:
  if (yyn == 37)
    
/* Line 354 of lalr1.java  */
/* Line 249 of "dap4.y"  */
    {yyval=((YaxToken)(yystack.valueAt (1-(1))));};
  break;
    

  case 38:
  if (yyn == 38)
    
/* Line 354 of lalr1.java  */
/* Line 250 of "dap4.y"  */
    {yyval=((YaxToken)(yystack.valueAt (1-(1))));};
  break;
    

  case 39:
  if (yyn == 39)
    
/* Line 354 of lalr1.java  */
/* Line 251 of "dap4.y"  */
    {yyval=((YaxToken)(yystack.valueAt (1-(1))));};
  break;
    

  case 40:
  if (yyn == 40)
    
/* Line 354 of lalr1.java  */
/* Line 252 of "dap4.y"  */
    {yyval=((YaxToken)(yystack.valueAt (1-(1))));};
  break;
    

  case 41:
  if (yyn == 41)
    
/* Line 354 of lalr1.java  */
/* Line 253 of "dap4.y"  */
    {yyval=((YaxToken)(yystack.valueAt (1-(1))));};
  break;
    

  case 42:
  if (yyn == 42)
    
/* Line 354 of lalr1.java  */
/* Line 254 of "dap4.y"  */
    {yyval=((YaxToken)(yystack.valueAt (1-(1))));};
  break;
    

  case 43:
  if (yyn == 43)
    
/* Line 354 of lalr1.java  */
/* Line 255 of "dap4.y"  */
    {yyval=((YaxToken)(yystack.valueAt (1-(1))));};
  break;
    

  case 44:
  if (yyn == 44)
    
/* Line 354 of lalr1.java  */
/* Line 256 of "dap4.y"  */
    {yyval=((YaxToken)(yystack.valueAt (1-(1))));};
  break;
    

  case 45:
  if (yyn == 45)
    
/* Line 354 of lalr1.java  */
/* Line 257 of "dap4.y"  */
    {yyval=((YaxToken)(yystack.valueAt (1-(1))));};
  break;
    

  case 46:
  if (yyn == 46)
    
/* Line 354 of lalr1.java  */
/* Line 258 of "dap4.y"  */
    {yyval=((YaxToken)(yystack.valueAt (1-(1))));};
  break;
    

  case 47:
  if (yyn == 47)
    
/* Line 354 of lalr1.java  */
/* Line 259 of "dap4.y"  */
    {yyval=((YaxToken)(yystack.valueAt (1-(1))));};
  break;
    

  case 48:
  if (yyn == 48)
    
/* Line 354 of lalr1.java  */
/* Line 260 of "dap4.y"  */
    {yyval=((YaxToken)(yystack.valueAt (1-(1))));};
  break;
    

  case 49:
  if (yyn == 49)
    
/* Line 354 of lalr1.java  */
/* Line 261 of "dap4.y"  */
    {yyval=((YaxToken)(yystack.valueAt (1-(1))));};
  break;
    

  case 50:
  if (yyn == 50)
    
/* Line 354 of lalr1.java  */
/* Line 262 of "dap4.y"  */
    {yyval=((YaxToken)(yystack.valueAt (1-(1))));};
  break;
    

  case 51:
  if (yyn == 51)
    
/* Line 354 of lalr1.java  */
/* Line 263 of "dap4.y"  */
    {yyval=((YaxToken)(yystack.valueAt (1-(1))));};
  break;
    

  case 52:
  if (yyn == 52)
    
/* Line 354 of lalr1.java  */
/* Line 264 of "dap4.y"  */
    {yyval=((YaxToken)(yystack.valueAt (2-(1))));};
  break;
    

  case 53:
  if (yyn == 53)
    
/* Line 354 of lalr1.java  */
/* Line 268 of "dap4.y"  */
    {yyval=((YaxToken)(yystack.valueAt (1-(1))));};
  break;
    

  case 54:
  if (yyn == 54)
    
/* Line 354 of lalr1.java  */
/* Line 269 of "dap4.y"  */
    {yyval=((YaxToken)(yystack.valueAt (1-(1))));};
  break;
    

  case 55:
  if (yyn == 55)
    
/* Line 354 of lalr1.java  */
/* Line 270 of "dap4.y"  */
    {yyval=((YaxToken)(yystack.valueAt (1-(1))));};
  break;
    

  case 56:
  if (yyn == 56)
    
/* Line 354 of lalr1.java  */
/* Line 271 of "dap4.y"  */
    {yyval=((YaxToken)(yystack.valueAt (1-(1))));};
  break;
    

  case 57:
  if (yyn == 57)
    
/* Line 354 of lalr1.java  */
/* Line 272 of "dap4.y"  */
    {yyval=((YaxToken)(yystack.valueAt (1-(1))));};
  break;
    

  case 58:
  if (yyn == 58)
    
/* Line 354 of lalr1.java  */
/* Line 273 of "dap4.y"  */
    {yyval=((YaxToken)(yystack.valueAt (1-(1))));};
  break;
    

  case 59:
  if (yyn == 59)
    
/* Line 354 of lalr1.java  */
/* Line 274 of "dap4.y"  */
    {yyval=((YaxToken)(yystack.valueAt (1-(1))));};
  break;
    

  case 60:
  if (yyn == 60)
    
/* Line 354 of lalr1.java  */
/* Line 275 of "dap4.y"  */
    {yyval=((YaxToken)(yystack.valueAt (1-(1))));};
  break;
    

  case 61:
  if (yyn == 61)
    
/* Line 354 of lalr1.java  */
/* Line 276 of "dap4.y"  */
    {yyval=((YaxToken)(yystack.valueAt (1-(1))));};
  break;
    

  case 62:
  if (yyn == 62)
    
/* Line 354 of lalr1.java  */
/* Line 277 of "dap4.y"  */
    {yyval=((YaxToken)(yystack.valueAt (1-(1))));};
  break;
    

  case 63:
  if (yyn == 63)
    
/* Line 354 of lalr1.java  */
/* Line 278 of "dap4.y"  */
    {yyval=((YaxToken)(yystack.valueAt (1-(1))));};
  break;
    

  case 64:
  if (yyn == 64)
    
/* Line 354 of lalr1.java  */
/* Line 279 of "dap4.y"  */
    {yyval=((YaxToken)(yystack.valueAt (1-(1))));};
  break;
    

  case 65:
  if (yyn == 65)
    
/* Line 354 of lalr1.java  */
/* Line 280 of "dap4.y"  */
    {yyval=((YaxToken)(yystack.valueAt (1-(1))));};
  break;
    

  case 66:
  if (yyn == 66)
    
/* Line 354 of lalr1.java  */
/* Line 281 of "dap4.y"  */
    {yyval=((YaxToken)(yystack.valueAt (1-(1))));};
  break;
    

  case 67:
  if (yyn == 67)
    
/* Line 354 of lalr1.java  */
/* Line 282 of "dap4.y"  */
    {yyval=((YaxToken)(yystack.valueAt (1-(1))));};
  break;
    

  case 68:
  if (yyn == 68)
    
/* Line 354 of lalr1.java  */
/* Line 283 of "dap4.y"  */
    {yyval=((YaxToken)(yystack.valueAt (1-(1))));};
  break;
    

  case 69:
  if (yyn == 69)
    
/* Line 354 of lalr1.java  */
/* Line 288 of "dap4.y"  */
    {yyval=d4list(parser,NULL,NULL);};
  break;
    

  case 70:
  if (yyn == 70)
    
/* Line 354 of lalr1.java  */
/* Line 290 of "dap4.y"  */
    {yyval=d4list(parser,((Object)(yystack.valueAt (2-(1)))),((Object)(yystack.valueAt (2-(2)))));};
  break;
    

  case 71:
  if (yyn == 71)
    
/* Line 354 of lalr1.java  */
/* Line 292 of "dap4.y"  */
    {yyval=d4list(parser,((Object)(yystack.valueAt (2-(1)))),((Object)(yystack.valueAt (2-(2)))));};
  break;
    

  case 72:
  if (yyn == 72)
    
/* Line 354 of lalr1.java  */
/* Line 294 of "dap4.y"  */
    {yyval=d4list(parser,((Object)(yystack.valueAt (2-(1)))),((Object)(yystack.valueAt (2-(2)))));};
  break;
    

  case 73:
  if (yyn == 73)
    
/* Line 354 of lalr1.java  */
/* Line 299 of "dap4.y"  */
    {yyval=d4mapref(parser,((YaxToken)(yystack.valueAt (3-(2))))); CHECK(yyval);};
  break;
    

  case 74:
  if (yyn == 74)
    
/* Line 354 of lalr1.java  */
/* Line 304 of "dap4.y"  */
    {yyval=d4structurevariable(parser,((YaxToken)(yystack.valueAt (4-(2)))),((Object)(yystack.valueAt (4-(3))))); CHECK(yyval);};
  break;
    

  case 75:
  if (yyn == 75)
    
/* Line 354 of lalr1.java  */
/* Line 309 of "dap4.y"  */
    {yyval=d4list(parser,NULL,NULL);};
  break;
    

  case 76:
  if (yyn == 76)
    
/* Line 354 of lalr1.java  */
/* Line 311 of "dap4.y"  */
    {yyval=d4list(parser,((Object)(yystack.valueAt (2-(1)))),((Object)(yystack.valueAt (2-(2)))));};
  break;
    

  case 77:
  if (yyn == 77)
    
/* Line 354 of lalr1.java  */
/* Line 313 of "dap4.y"  */
    {yyval=d4list(parser,((Object)(yystack.valueAt (2-(1)))),((Object)(yystack.valueAt (2-(2)))));};
  break;
    

  case 78:
  if (yyn == 78)
    
/* Line 354 of lalr1.java  */
/* Line 315 of "dap4.y"  */
    {yyval=d4list(parser,((Object)(yystack.valueAt (2-(1)))),((Object)(yystack.valueAt (2-(2)))));};
  break;
    

  case 79:
  if (yyn == 79)
    
/* Line 354 of lalr1.java  */
/* Line 320 of "dap4.y"  */
    {yyval=d4list(parser,NULL,NULL);};
  break;
    

  case 80:
  if (yyn == 80)
    
/* Line 354 of lalr1.java  */
/* Line 322 of "dap4.y"  */
    {yyval=d4list(parser,((List)(yystack.valueAt (2-(1)))),((Object)(yystack.valueAt (2-(2)))));};
  break;
    

  case 81:
  if (yyn == 81)
    
/* Line 354 of lalr1.java  */
/* Line 326 of "dap4.y"  */
    {yyval=((Object)(yystack.valueAt (1-(1))));};
  break;
    

  case 82:
  if (yyn == 82)
    
/* Line 354 of lalr1.java  */
/* Line 327 of "dap4.y"  */
    {yyval=((Object)(yystack.valueAt (1-(1))));};
  break;
    

  case 83:
  if (yyn == 83)
    
/* Line 354 of lalr1.java  */
/* Line 335 of "dap4.y"  */
    {yyval=d4attribute(parser,((List)(yystack.valueAt (5-(2)))),((List)(yystack.valueAt (5-(3)))),((List)(yystack.valueAt (5-(4))))); CHECK(yyval);};
  break;
    

  case 84:
  if (yyn == 84)
    
/* Line 354 of lalr1.java  */
/* Line 340 of "dap4.y"  */
    {yyval=d4attrlist(parser,NULL,emptytoken);};
  break;
    

  case 85:
  if (yyn == 85)
    
/* Line 354 of lalr1.java  */
/* Line 342 of "dap4.y"  */
    {yyval=d4attrlist(parser,((List)(yystack.valueAt (2-(1)))),((YaxToken)(yystack.valueAt (2-(2)))));};
  break;
    

  case 86:
  if (yyn == 86)
    
/* Line 354 of lalr1.java  */
/* Line 344 of "dap4.y"  */
    {yyval=d4attrlist(parser,((List)(yystack.valueAt (2-(1)))),((YaxToken)(yystack.valueAt (2-(2)))));};
  break;
    

  case 87:
  if (yyn == 87)
    
/* Line 354 of lalr1.java  */
/* Line 346 of "dap4.y"  */
    {yyval=d4attrlist(parser,((List)(yystack.valueAt (2-(1)))),((YaxToken)(yystack.valueAt (2-(2)))));};
  break;
    

  case 88:
  if (yyn == 88)
    
/* Line 354 of lalr1.java  */
/* Line 348 of "dap4.y"  */
    {yyval=d4attrlist(parser,((List)(yystack.valueAt (2-(1)))),((YaxToken)(yystack.valueAt (2-(2)))));};
  break;
    

  case 89:
  if (yyn == 89)
    
/* Line 354 of lalr1.java  */
/* Line 353 of "dap4.y"  */
    {yyval=d4attrlist(parser,NULL,emptytoken);};
  break;
    

  case 90:
  if (yyn == 90)
    
/* Line 354 of lalr1.java  */
/* Line 355 of "dap4.y"  */
    {yyval=d4attrlist(parser,((List)(yystack.valueAt (2-(1)))),((YaxToken)(yystack.valueAt (2-(2)))));};
  break;
    

  case 91:
  if (yyn == 91)
    
/* Line 354 of lalr1.java  */
/* Line 358 of "dap4.y"  */
    {yyval=((YaxToken)(yystack.valueAt (3-(2))));};
  break;
    

  case 92:
  if (yyn == 92)
    
/* Line 354 of lalr1.java  */
/* Line 362 of "dap4.y"  */
    {yyval=d4otherxml(parser,((List)(yystack.valueAt (1-(1)))));};
  break;
    



/* Line 354 of lalr1.java  */
/* Line 1279 of "DAP4Parser.java"  */
	default: break;
      }

    yy_symbol_print ("-> $$ =", yyr1_[yyn], yyval);

    yystack.pop (yylen);
    yylen = 0;

    /* Shift the result of the reduction.  */
    yyn = yyr1_[yyn];
    int yystate = yypgoto_[yyn - yyntokens_] + yystack.stateAt (0);
    if (0 <= yystate && yystate <= yylast_
	&& yycheck_[yystate] == yystack.stateAt (0))
      yystate = yytable_[yystate];
    else
      yystate = yydefgoto_[yyn - yyntokens_];

    yystack.push (yystate, yyval);
    return YYNEWSTATE;
  }

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  private final String yytnamerr_ (String yystr)
  {
    if (yystr.charAt (0) == '"')
      {
        StringBuffer yyr = new StringBuffer ();
        strip_quotes: for (int i = 1; i < yystr.length (); i++)
          switch (yystr.charAt (i))
            {
            case '\'':
            case ',':
              break strip_quotes;

            case '\\':
	      if (yystr.charAt(++i) != '\\')
                break strip_quotes;
              /* Fall through.  */
            default:
              yyr.append (yystr.charAt (i));
              break;

            case '"':
              return yyr.toString ();
            }
      }
    else if (yystr.equals ("$end"))
      return "end of input";

    return yystr;
  }

  /*--------------------------------.
  | Print this symbol on YYOUTPUT.  |
  `--------------------------------*/

  private void yy_symbol_print (String s, int yytype,
			         Object yyvaluep				 )
  {
    if (yydebug > 0)
    yycdebug (s + (yytype < yyntokens_ ? " token " : " nterm ")
	      + yytname_[yytype] + " ("
	      + (yyvaluep == null ? "(null)" : yyvaluep.toString ()) + ")");
  }

  /**
   * Parse input from the scanner that was specified at object construction
   * time.  Return whether the end of the input was reached successfully.
   *
   * @return <tt>true</tt> if the parsing succeeds.  Note that this does not
   *          imply that there were no syntax errors.
   */
  public boolean parse () throws Exception, Exception
  {
    /// Lookahead and lookahead in internal form.
    int yychar = yyempty_;
    int yytoken = 0;

    /* State.  */
    int yyn = 0;
    int yylen = 0;
    int yystate = 0;

    YYStack yystack = new YYStack ();

    /* Error handling.  */
    int yynerrs_ = 0;
    

    /// Semantic value of the lookahead.
    Object yylval = null;

    int yyresult;

    yycdebug ("Starting parse\n");
    yyerrstatus_ = 0;


    /* Initialize the stack.  */
    yystack.push (yystate, yylval);

    int label = YYNEWSTATE;
    for (;;)
      switch (label)
      {
        /* New state.  Unlike in the C/C++ skeletons, the state is already
	   pushed when we come here.  */
      case YYNEWSTATE:
        yycdebug ("Entering state " + yystate + "\n");
        if (yydebug > 0)
          yystack.print (yyDebugStream);

        /* Accept?  */
        if (yystate == yyfinal_)
          return true;

        /* Take a decision.  First try without lookahead.  */
        yyn = yypact_[yystate];
        if (yyn == yypact_ninf_)
          {
            label = YYDEFAULT;
	    break;
          }

        /* Read a lookahead token.  */
        if (yychar == yyempty_)
          {
	    yycdebug ("Reading a token: ");
	    yychar = yylex ();
            
            yylval = yylexer.getLVal ();
          }

        /* Convert token to internal form.  */
        if (yychar <= EOF)
          {
	    yychar = yytoken = EOF;
	    yycdebug ("Now at end of input.\n");
          }
        else
          {
	    yytoken = yytranslate_ (yychar);
	    yy_symbol_print ("Next token is", yytoken,
			     yylval);
          }

        /* If the proper action on seeing token YYTOKEN is to reduce or to
           detect an error, take that action.  */
        yyn += yytoken;
        if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yytoken)
          label = YYDEFAULT;

        /* <= 0 means reduce or error.  */
        else if ((yyn = yytable_[yyn]) <= 0)
          {
	    if (yyn == 0 || yyn == yytable_ninf_)
	      label = YYFAIL;
	    else
	      {
	        yyn = -yyn;
	        label = YYREDUCE;
	      }
          }

        else
          {
            /* Shift the lookahead token.  */
	    yy_symbol_print ("Shifting", yytoken,
			     yylval);

            /* Discard the token being shifted.  */
            yychar = yyempty_;

            /* Count tokens shifted since error; after three, turn off error
               status.  */
            if (yyerrstatus_ > 0)
              --yyerrstatus_;

            yystate = yyn;
            yystack.push (yystate, yylval);
            label = YYNEWSTATE;
          }
        break;

      /*-----------------------------------------------------------.
      | yydefault -- do the default action for the current state.  |
      `-----------------------------------------------------------*/
      case YYDEFAULT:
        yyn = yydefact_[yystate];
        if (yyn == 0)
          label = YYFAIL;
        else
          label = YYREDUCE;
        break;

      /*-----------------------------.
      | yyreduce -- Do a reduction.  |
      `-----------------------------*/
      case YYREDUCE:
        yylen = yyr2_[yyn];
        label = yyaction (yyn, yystack, yylen);
	yystate = yystack.stateAt (0);
        break;

      /*------------------------------------.
      | yyerrlab -- here on detecting error |
      `------------------------------------*/
      case YYFAIL:
        /* If not already recovering from an error, report this error.  */
        if (yyerrstatus_ == 0)
          {
	    ++yynerrs_;
	    yyerror (yysyntax_error (yystate, yytoken));
          }

        
        if (yyerrstatus_ == 3)
          {
	    /* If just tried and failed to reuse lookahead token after an
	     error, discard it.  */

	    if (yychar <= EOF)
	      {
	      /* Return failure if at end of input.  */
	      if (yychar == EOF)
	        return false;
	      }
	    else
	      yychar = yyempty_;
          }

        /* Else will try to reuse lookahead token after shifting the error
           token.  */
        label = YYERRLAB1;
        break;

      /*---------------------------------------------------.
      | errorlab -- error raised explicitly by YYERROR.  |
      `---------------------------------------------------*/
      case YYERROR:

        
        /* Do not reclaim the symbols of the rule which action triggered
           this YYERROR.  */
        yystack.pop (yylen);
        yylen = 0;
        yystate = yystack.stateAt (0);
        label = YYERRLAB1;
        break;

      /*-------------------------------------------------------------.
      | yyerrlab1 -- common code for both syntax error and YYERROR.  |
      `-------------------------------------------------------------*/
      case YYERRLAB1:
        yyerrstatus_ = 3;	/* Each real token shifted decrements this.  */

        for (;;)
          {
	    yyn = yypact_[yystate];
	    if (yyn != yypact_ninf_)
	      {
	        yyn += yyterror_;
	        if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
	          {
	            yyn = yytable_[yyn];
	            if (0 < yyn)
		      break;
	          }
	      }

	    /* Pop the current state because it cannot handle the error token.  */
	    if (yystack.height == 1)
	      return false;

	    
	    yystack.pop ();
	    yystate = yystack.stateAt (0);
	    if (yydebug > 0)
	      yystack.print (yyDebugStream);
          }

	

        /* Shift the error token.  */
        yy_symbol_print ("Shifting", yystos_[yyn],
			 yylval);

        yystate = yyn;
	yystack.push (yyn, yylval);
        label = YYNEWSTATE;
        break;

        /* Accept.  */
      case YYACCEPT:
        return true;

        /* Abort.  */
      case YYABORT:
        return false;
      }
  }

  // Generate an error message.
  private String yysyntax_error (int yystate, int tok)
  {
    if (errorVerbose)
      {
        int yyn = yypact_[yystate];
        if (yypact_ninf_ < yyn && yyn <= yylast_)
          {
	    StringBuffer res;

	    /* Start YYX at -YYN if negative to avoid negative indexes in
	       YYCHECK.  */
	    int yyxbegin = yyn < 0 ? -yyn : 0;

	    /* Stay within bounds of both yycheck and yytname.  */
	    int yychecklim = yylast_ - yyn + 1;
	    int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
	    int count = 0;
	    for (int x = yyxbegin; x < yyxend; ++x)
	      if (yycheck_[x + yyn] == x && x != yyterror_)
	        ++count;

	    // FIXME: This method of building the message is not compatible
	    // with internationalization.
	    res = new StringBuffer ("syntax error, unexpected ");
	    res.append (yytnamerr_ (yytname_[tok]));
	    if (count < 5)
	      {
	        count = 0;
	        for (int x = yyxbegin; x < yyxend; ++x)
	          if (yycheck_[x + yyn] == x && x != yyterror_)
		    {
		      res.append (count++ == 0 ? ", expecting " : " or ");
		      res.append (yytnamerr_ (yytname_[x]));
		    }
	      }
	    return res.toString ();
          }
      }

    return "syntax error";
  }


  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
  private static final byte yypact_ninf_ = -57;
  private static final byte yypact_[] =
  {
        12,   -57,    19,    -1,   -57,   -57,   -57,   -57,   -57,   -57,
     -57,   -57,    -3,   -57,   -52,   -56,    -4,     3,   -57,   -57,
     -57,   -57,   -57,   -57,   -57,   -57,   -57,   -57,   -57,   -57,
     -57,   -57,   -57,   -57,   -57,   -57,   -57,   -57,   -57,   -57,
      15,   -57,   -57,   -57,   -57,    17,    24,    75,    21,    25,
     -57,   -57,   -57,    39,   -57,   -57,   -57,   -55,   100,   -57,
     -57,   -57,    -9,    -2,   -57,   -57,   -57,   -57,    79,    45,
      27,    29,    86,   -57,   -57,   -57,   -57,    11,   -57,   -57,
     -57,   -57,    36,   -57,    81,   -57,    37,   -57,   -57,   -57,
     -57,   -57,   -57,   -57,   -57,   -57,   -57,   -57,   -57,   -57,
     -57,   -57,   -57,   -57,   -57,   -57,   -57,   -57,   -57,   -57,
     -57,    94,    99,    46,   -57,   -57,    92,   -57,   -57,    90,
     -57,   -57
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  private static final byte yydefact_[] =
  {
         0,     3,     0,    11,     1,     8,     5,     6,     4,     7,
       9,    10,     0,     2,     0,     0,     0,     0,    84,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    92,    16,    12,    13,    14,    34,
       0,    35,    15,    81,    82,     0,     0,     0,     0,     0,
      79,    52,    75,    25,    69,    19,    18,     0,     0,    20,
      29,    30,     0,     0,    85,    87,    86,    88,    89,     0,
       0,     0,     0,    17,    21,    28,    80,     0,    74,    76,
      77,    78,     0,    26,     0,    68,     0,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    70,    36,    71,    72,    23,    24,    22,    32,
      33,     0,     0,     0,    83,    90,     0,    31,    27,     0,
      73,    91
  };

  /* YYPGOTO[NTERM-NUM].  */
  private static final byte yypgoto_[] =
  {
       -57,   101,   -57,   -57,   -57,   -57,   -57,    56,   -57,   -57,
     -57,   -57,   -57,    47,   -57,    52,   -57,   -57,   -57,   -57,
     -57,   -57,   -57,   -57,   -10,   -57,   -57,   -57,   -57,   -57
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  private static final byte
  yydefgoto_[] =
  {
        -1,     2,     3,    12,    36,    47,    58,    59,    72,    68,
      83,    37,    50,    79,   111,    38,    39,    40,   103,    69,
     104,    41,    63,    62,    42,    43,    53,    84,   115,    44
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  private static final byte yytable_ninf_ = -1;
  private static final byte
  yytable_[] =
  {
         1,    13,    14,    75,    45,    48,    70,    49,    15,    46,
      71,    77,    16,    16,    18,     1,    17,    17,    78,     4,
      18,    18,    19,    19,    20,    20,    21,    21,    22,    22,
      23,    23,    24,    24,    25,    25,    26,    26,    27,    27,
      28,    28,    29,    29,    30,    30,    31,    31,    32,    32,
      33,    33,    76,    81,     5,    51,     6,     7,    77,   105,
       8,    85,    86,    34,    52,     9,    10,    11,    18,    34,
      34,    87,   109,    88,   110,    89,    54,    90,    55,    91,
      56,    92,    57,    93,    60,    94,    61,    95,    82,    96,
     107,    97,   106,    98,   108,    99,   112,   100,   116,   101,
      64,    65,   113,    66,    67,   114,    73,    57,   117,   118,
     120,   119,   121,    35,    74,    80,   102,    34
  };

  /* YYCHECK.  */
  private static final byte
  yycheck_[] =
  {
         3,     4,     5,    12,    56,    61,    61,    63,    11,    61,
      65,    13,    15,    15,    23,     3,    19,    19,    20,     0,
      23,    23,    25,    25,    27,    27,    29,    29,    31,    31,
      33,    33,    35,    35,    37,    37,    39,    39,    41,    41,
      43,    43,    45,    45,    47,    47,    49,    49,    51,    51,
      53,    53,    62,    63,    55,    59,    57,    58,    13,    69,
      61,    16,    17,    72,    61,    66,    67,    68,    23,    72,
      72,    26,    61,    28,    63,    30,    61,    32,    61,    34,
      56,    36,     7,    38,    63,    40,    61,    42,     9,    44,
      61,    46,    65,    48,     8,    50,    60,    52,    61,    54,
      61,    62,    21,    64,    65,    24,     6,     7,    14,    10,
      18,    65,    22,    12,    58,    63,    69,    72
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  private static final byte
  yystos_[] =
  {
         0,     3,    77,    78,     0,    55,    57,    58,    61,    66,
      67,    68,    79,     4,     5,    11,    15,    19,    23,    25,
      27,    29,    31,    33,    35,    37,    39,    41,    43,    45,
      47,    49,    51,    53,    72,    77,    80,    87,    91,    92,
      93,    97,   100,   101,   105,    56,    61,    81,    61,    63,
      88,    59,    61,   102,    61,    61,    56,     7,    82,    83,
      63,    61,    99,    98,    61,    62,    64,    65,    85,    95,
      61,    65,    84,     6,    83,    12,   100,    13,    20,    89,
      91,   100,     9,    86,   103,    16,    17,    26,    28,    30,
      32,    34,    36,    38,    40,    42,    44,    46,    48,    50,
      52,    54,    89,    94,    96,   100,    65,    61,     8,    61,
      63,    90,    60,    21,    24,   104,    61,    14,    10,    65,
      18,    22
  };

  /* TOKEN_NUMBER_[YYLEX-NUM] -- Internal symbol number corresponding
     to YYLEX-NUM.  */
  private static final short
  yytoken_number_[] =
  {
         0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330
  };

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  private static final byte
  yyr1_[] =
  {
         0,    76,    77,    78,    78,    78,    78,    78,    78,    78,
      78,    79,    79,    79,    79,    79,    79,    80,    81,    81,
      82,    82,    83,    84,    84,    85,    85,    86,    87,    88,
      88,    89,    90,    90,    91,    91,    92,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    95,
      95,    95,    95,    96,    97,    98,    98,    98,    98,    99,
      99,   100,   100,   101,   102,   102,   102,   102,   102,   103,
     103,   104,   105
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  private static final byte
  yyr2_[] =
  {
         0,     2,     4,     0,     2,     2,     2,     2,     2,     2,
       2,     0,     2,     2,     2,     2,     2,     4,     2,     2,
       1,     2,     3,     2,     2,     0,     2,     3,     4,     2,
       2,     3,     1,     1,     1,     1,     4,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       2,     2,     2,     3,     4,     0,     2,     2,     2,     0,
       2,     1,     1,     5,     0,     2,     2,     2,     2,     0,
       2,     3,     1
  };

  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  private static final String yytname_[] =
  {
    "$end", "error", "$undefined", "GROUP_", "_GROUP", "ENUMERATION_",
  "_ENUMERATION", "ENUMCONST_", "_ENUMCONST", "NAMESPACE_", "_NAMESPACE",
  "DIMENSION_", "_DIMENSION", "DIM_", "_DIM", "ENUM_", "_ENUM", "MAP_",
  "_MAP", "STRUCTURE_", "_STRUCTURE", "VALUE_", "_VALUE", "ATTRIBUTE_",
  "_ATTRIBUTE", "CHAR_", "_CHAR", "BYTE_", "_BYTE", "INT8_", "_INT8",
  "UINT8_", "_UINT8", "INT16_", "_INT16", "UINT16_", "_UINT16", "INT32_",
  "_INT32", "UINT32_", "_UINT32", "INT64_", "_INT64", "UINT64_", "_UINT64",
  "FLOAT32_", "_FLOAT32", "FLOAT64_", "_FLOAT64", "STRING_", "_STRING",
  "URL_", "_URL", "OPAQUE_", "_OPAQUE", "ATTR_BASE", "ATTR_BASETYPE",
  "ATTR_DAPVERSION", "ATTR_DDXVERSION", "ATTR_ENUM", "ATTR_HREF",
  "ATTR_NAME", "ATTR_NAMESPACE", "ATTR_SIZE", "ATTR_TYPE", "ATTR_VALUE",
  "ATTR_NS", "ATTR_XMLNS", "UNKNOWN_ATTR", "UNKNOWN_ELEMENT_",
  "_UNKNOWN_ELEMENT", "TEXT", "OTHERXML", "ERROR", "UNKNOWN", "UNEXPECTED",
  "$accept", "group", "group_attr_list", "group_body", "enumdef",
  "enum_attr_list", "enumconst_list", "enumconst", "enumconst_attr_list",
  "namespace_list", "namespace", "dimdef", "dimdef_attr_list", "dimref",
  "dimref_attr_list", "variable", "simplevariable", "atomictype_",
  "_atomictype", "variabledef", "mapref", "structurevariable",
  "structuredef", "metadatalist", "metadata", "attribute",
  "attribute_attr_list", "attribute_value_list", "attribute_value",
  "otherxml", null
  };

  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  private static final byte yyrhs_[] =
  {
        77,     0,    -1,     3,    78,    79,     4,    -1,    -1,    78,
      61,    -1,    78,    57,    -1,    78,    58,    -1,    78,    66,
      -1,    78,    55,    -1,    78,    67,    -1,    78,    68,    -1,
      -1,    79,    80,    -1,    79,    87,    -1,    79,    91,    -1,
      79,   100,    -1,    79,    77,    -1,     5,    81,    82,     6,
      -1,    61,    56,    -1,    56,    61,    -1,    83,    -1,    82,
      83,    -1,     7,    84,     8,    -1,    61,    65,    -1,    65,
      61,    -1,    -1,    85,    86,    -1,     9,    60,    10,    -1,
      11,    88,    99,    12,    -1,    61,    63,    -1,    63,    61,
      -1,    13,    90,    14,    -1,    61,    -1,    63,    -1,    92,
      -1,    97,    -1,    93,    61,    95,    94,    -1,    25,    -1,
      27,    -1,    29,    -1,    31,    -1,    33,    -1,    35,    -1,
      37,    -1,    39,    -1,    41,    -1,    43,    -1,    45,    -1,
      47,    -1,    49,    -1,    51,    -1,    53,    -1,    15,    59,
      -1,    26,    -1,    28,    -1,    30,    -1,    32,    -1,    34,
      -1,    36,    -1,    38,    -1,    40,    -1,    42,    -1,    44,
      -1,    46,    -1,    48,    -1,    50,    -1,    52,    -1,    54,
      -1,    16,    -1,    -1,    95,    89,    -1,    95,    96,    -1,
      95,   100,    -1,    17,    61,    18,    -1,    19,    61,    98,
      20,    -1,    -1,    98,    89,    -1,    98,    91,    -1,    98,
     100,    -1,    -1,    99,   100,    -1,   101,    -1,   105,    -1,
      23,   102,    85,   103,    24,    -1,    -1,   102,    61,    -1,
     102,    64,    -1,   102,    62,    -1,   102,    65,    -1,    -1,
     103,   104,    -1,    21,    65,    22,    -1,    72,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  private static final short yyprhs_[] =
  {
         0,     0,     3,     8,     9,    12,    15,    18,    21,    24,
      27,    30,    31,    34,    37,    40,    43,    46,    51,    54,
      57,    59,    62,    66,    69,    72,    73,    76,    80,    85,
      88,    91,    95,    97,    99,   101,   103,   108,   110,   112,
     114,   116,   118,   120,   122,   124,   126,   128,   130,   132,
     134,   136,   138,   141,   143,   145,   147,   149,   151,   153,
     155,   157,   159,   161,   163,   165,   167,   169,   171,   173,
     174,   177,   180,   183,   187,   192,   193,   196,   199,   202,
     203,   206,   208,   210,   216,   217,   220,   223,   226,   229,
     230,   233,   237
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  private static final short yyrline_[] =
  {
         0,   109,   109,   114,   115,   117,   119,   121,   123,   125,
     127,   133,   134,   136,   138,   140,   142,   147,   152,   157,
     165,   167,   173,   178,   183,   192,   193,   198,   203,   208,
     213,   221,   226,   230,   237,   238,   243,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   288,
     289,   291,   293,   298,   303,   309,   310,   312,   314,   320,
     321,   326,   327,   331,   340,   341,   343,   345,   347,   353,
     354,   358,   362
  };

  // Report on the debug stream that the rule yyrule is going to be reduced.
  private void yy_reduce_print (int yyrule, YYStack yystack)
  {
    if (yydebug == 0)
      return;

    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    /* Print the symbols being reduced, and their result.  */
    yycdebug ("Reducing stack by rule " + (yyrule - 1)
	      + " (line " + yylno + "), ");

    /* The symbols being reduced.  */
    for (int yyi = 0; yyi < yynrhs; yyi++)
      yy_symbol_print ("   $" + (yyi + 1) + " =",
		       yyrhs_[yyprhs_[yyrule] + yyi],
		       ((yystack.valueAt (yynrhs-(yyi + 1)))));
  }

  /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
  private static final byte yytranslate_table_[] =
  {
         0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75
  };

  private static final byte yytranslate_ (int t)
  {
    if (t >= 0 && t <= yyuser_token_number_max_)
      return yytranslate_table_[t];
    else
      return yyundef_token_;
  }

  private static final int yylast_ = 117;
  private static final int yynnts_ = 30;
  private static final int yyempty_ = -2;
  private static final int yyfinal_ = 4;
  private static final int yyterror_ = 1;
  private static final int yyerrcode_ = 256;
  private static final int yyntokens_ = 76;

  private static final int yyuser_token_number_max_ = 330;
  private static final int yyundef_token_ = 2;

/* User implementation code.  */
/* Unqualified %code blocks.  */

/* Line 876 of lalr1.java  */
/* Line 17 of "dap4.y"  */

 
    /**
     * Instantiates the Bison-generated parser.
     * @param yylexer The scanner that will supply tokens to the parser.
     */

    public DAP4Parser(String document)
    {
	super();
	setLexer(new DAP4Lexer(document));
    }

    /* the parse function allows the specification of a
       new stream in case one is reusing the parser
    */

    public boolean parse() throws Exception
    {
	return parse();
    }




/* Line 876 of lalr1.java  */
/* Line 1988 of "DAP4Parser.java"  */

}


/* Line 880 of lalr1.java  */
/* Line 364 of "dap4.y"  */


