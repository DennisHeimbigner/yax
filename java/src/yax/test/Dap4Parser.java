/* A Bison parser, made by GNU Bison 3.0.  */

/* Skeleton implementation for Bison LALR(1) parsers in Java

   Copyright (C) 2007-2013 Free Software Foundation, Inc.

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

package yax.test;
/* First part of user declarations.  */

/* "src/yax/test/Dap4Parser.java":37  */ /* lalr1.java:91  */

/* "src/yax/test/Dap4Parser.java":39  */ /* lalr1.java:92  */

/**
 * A Bison parser, automatically generated from <tt>src/yax/test/dap4.y</tt>.
 *
 * @author LALR (1) parser skeleton written by Paolo Bonzini.
 */
public class Dap4Parser extends Dap4Test
{
    /** Version number for the Bison executable that generated this parser.  */
  public static final String bisonVersion = "3.0";

  /** Name of the skeleton that generated this parser.  */
  public static final String bisonSkeleton = "lalr1.java";


  /**
   * True if verbose error messages are enabled.
   */
  private boolean yyErrorVerbose = true;

  /**
   * Return whether verbose error messages are enabled.
   */
  public final boolean getErrorVerbose() { return yyErrorVerbose; }

  /**
   * Set the verbosity of error messages.
   * @param verbose True to request verbose error messages.
   */
  public final void setErrorVerbose(boolean verbose)
  { yyErrorVerbose = verbose; }




  

  /**
   * Communication interface between the scanner and the Bison-generated
   * parser <tt>Dap4Parser</tt>.
   */
  public interface Lexer {
    /** Token returned by the scanner to signal the end of its input.  */
    public static final int EOF = 0;

/* Tokens.  */
    /** Token number,to be returned by the scanner.  */
    static final int DATASET_ = 258;
    /** Token number,to be returned by the scanner.  */
    static final int _DATASET = 259;
    /** Token number,to be returned by the scanner.  */
    static final int GROUP_ = 260;
    /** Token number,to be returned by the scanner.  */
    static final int _GROUP = 261;
    /** Token number,to be returned by the scanner.  */
    static final int ENUMERATION_ = 262;
    /** Token number,to be returned by the scanner.  */
    static final int _ENUMERATION = 263;
    /** Token number,to be returned by the scanner.  */
    static final int ENUMCONST_ = 264;
    /** Token number,to be returned by the scanner.  */
    static final int _ENUMCONST = 265;
    /** Token number,to be returned by the scanner.  */
    static final int NAMESPACE_ = 266;
    /** Token number,to be returned by the scanner.  */
    static final int _NAMESPACE = 267;
    /** Token number,to be returned by the scanner.  */
    static final int DIMENSION_ = 268;
    /** Token number,to be returned by the scanner.  */
    static final int _DIMENSION = 269;
    /** Token number,to be returned by the scanner.  */
    static final int DIM_ = 270;
    /** Token number,to be returned by the scanner.  */
    static final int _DIM = 271;
    /** Token number,to be returned by the scanner.  */
    static final int ENUM_ = 272;
    /** Token number,to be returned by the scanner.  */
    static final int _ENUM = 273;
    /** Token number,to be returned by the scanner.  */
    static final int MAP_ = 274;
    /** Token number,to be returned by the scanner.  */
    static final int _MAP = 275;
    /** Token number,to be returned by the scanner.  */
    static final int STRUCTURE_ = 276;
    /** Token number,to be returned by the scanner.  */
    static final int _STRUCTURE = 277;
    /** Token number,to be returned by the scanner.  */
    static final int VALUE_ = 278;
    /** Token number,to be returned by the scanner.  */
    static final int _VALUE = 279;
    /** Token number,to be returned by the scanner.  */
    static final int ATTRIBUTE_ = 280;
    /** Token number,to be returned by the scanner.  */
    static final int _ATTRIBUTE = 281;
    /** Token number,to be returned by the scanner.  */
    static final int CHAR_ = 282;
    /** Token number,to be returned by the scanner.  */
    static final int _CHAR = 283;
    /** Token number,to be returned by the scanner.  */
    static final int BYTE_ = 284;
    /** Token number,to be returned by the scanner.  */
    static final int _BYTE = 285;
    /** Token number,to be returned by the scanner.  */
    static final int INT8_ = 286;
    /** Token number,to be returned by the scanner.  */
    static final int _INT8 = 287;
    /** Token number,to be returned by the scanner.  */
    static final int UINT8_ = 288;
    /** Token number,to be returned by the scanner.  */
    static final int _UINT8 = 289;
    /** Token number,to be returned by the scanner.  */
    static final int INT16_ = 290;
    /** Token number,to be returned by the scanner.  */
    static final int _INT16 = 291;
    /** Token number,to be returned by the scanner.  */
    static final int UINT16_ = 292;
    /** Token number,to be returned by the scanner.  */
    static final int _UINT16 = 293;
    /** Token number,to be returned by the scanner.  */
    static final int INT32_ = 294;
    /** Token number,to be returned by the scanner.  */
    static final int _INT32 = 295;
    /** Token number,to be returned by the scanner.  */
    static final int UINT32_ = 296;
    /** Token number,to be returned by the scanner.  */
    static final int _UINT32 = 297;
    /** Token number,to be returned by the scanner.  */
    static final int INT64_ = 298;
    /** Token number,to be returned by the scanner.  */
    static final int _INT64 = 299;
    /** Token number,to be returned by the scanner.  */
    static final int UINT64_ = 300;
    /** Token number,to be returned by the scanner.  */
    static final int _UINT64 = 301;
    /** Token number,to be returned by the scanner.  */
    static final int FLOAT32_ = 302;
    /** Token number,to be returned by the scanner.  */
    static final int _FLOAT32 = 303;
    /** Token number,to be returned by the scanner.  */
    static final int FLOAT64_ = 304;
    /** Token number,to be returned by the scanner.  */
    static final int _FLOAT64 = 305;
    /** Token number,to be returned by the scanner.  */
    static final int STRING_ = 306;
    /** Token number,to be returned by the scanner.  */
    static final int _STRING = 307;
    /** Token number,to be returned by the scanner.  */
    static final int URL_ = 308;
    /** Token number,to be returned by the scanner.  */
    static final int _URL = 309;
    /** Token number,to be returned by the scanner.  */
    static final int OPAQUE_ = 310;
    /** Token number,to be returned by the scanner.  */
    static final int _OPAQUE = 311;
    /** Token number,to be returned by the scanner.  */
    static final int ATTR_BASE = 312;
    /** Token number,to be returned by the scanner.  */
    static final int ATTR_BASETYPE = 313;
    /** Token number,to be returned by the scanner.  */
    static final int ATTR_DAPVERSION = 314;
    /** Token number,to be returned by the scanner.  */
    static final int ATTR_DDXVERSION = 315;
    /** Token number,to be returned by the scanner.  */
    static final int ATTR_ENUM = 316;
    /** Token number,to be returned by the scanner.  */
    static final int ATTR_HREF = 317;
    /** Token number,to be returned by the scanner.  */
    static final int ATTR_NAME = 318;
    /** Token number,to be returned by the scanner.  */
    static final int ATTR_NAMESPACE = 319;
    /** Token number,to be returned by the scanner.  */
    static final int ATTR_SIZE = 320;
    /** Token number,to be returned by the scanner.  */
    static final int ATTR_TYPE = 321;
    /** Token number,to be returned by the scanner.  */
    static final int ATTR_VALUE = 322;
    /** Token number,to be returned by the scanner.  */
    static final int ATTR_NS = 323;
    /** Token number,to be returned by the scanner.  */
    static final int ATTR_XMLNS = 324;
    /** Token number,to be returned by the scanner.  */
    static final int UNKNOWN_ATTR = 325;
    /** Token number,to be returned by the scanner.  */
    static final int UNKNOWN_ELEMENT_ = 326;
    /** Token number,to be returned by the scanner.  */
    static final int _UNKNOWN_ELEMENT = 327;
    /** Token number,to be returned by the scanner.  */
    static final int TEXT = 328;
    /** Token number,to be returned by the scanner.  */
    static final int ERROR = 329;
    /** Token number,to be returned by the scanner.  */
    static final int UNKNOWN = 330;
    /** Token number,to be returned by the scanner.  */
    static final int UNEXPECTED = 331;


    

    /**
     * Method to retrieve the semantic value of the last scanned token.
     * @return the semantic value of the last scanned token.
     */
    Object getLVal ();

    /**
     * Entry point for the scanner.  Returns the token identifier corresponding
     * to the next token and prepares to return the semantic value
     * of the token.
     * @return the token identifier corresponding to the next token.
     */
    int yylex () throws Exception;

    /**
     * Entry point for error reporting.  Emits an error
     * in a user-defined way.
     *
     * 
     * @param msg The string for the error message.
     */
     void yyerror (String msg);
  }

  private class YYLexer implements Lexer {
/* "%code lexer" blocks.  */
/* "src/yax/test/dap4.y":17  */ /* lalr1.java:236  */

public Object getLVal() {return null;}
public int yylex() {return 0;}
public void yyerror(String s) {System.err.println(s);}

/* "src/yax/test/Dap4Parser.java":270  */ /* lalr1.java:236  */

  }

  /**
   * The object doing lexical analysis for us.
   */
  private Lexer yylexer;
  
  


  /**
   * Instantiates the Bison-generated parser.
   */
  public Dap4Parser () 
  {
    
    this.yylexer = new YYLexer();
    
  }


  /**
   * Instantiates the Bison-generated parser.
   * @param yylexer The scanner that will supply tokens to the parser.
   */
  protected Dap4Parser (Lexer yylexer) 
  {
    
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

  /**
   * Print an error message via the lexer.
   *
   * @param msg The error message.
   */
  public final void yyerror (String msg)
  {
    yylexer.yyerror (msg);
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

    public final void push (int state, Object value                            ) {
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
      pop (1);
    }

    public final void pop (int num) {
      // Avoid memory leaks... garbage collection is a white lie!
      if (num > 0) {
        java.util.Arrays.fill (valueStack, height - num + 1, height + 1, null);
        
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

      for (int i = 0; i <= height; i++)
        {
          out.print (' ');
          out.print (stateStack[i]);
        }
      out.println ();
    }
  }

  /**
   * Returned by a Bison action in order to stop the parsing process and
   * return success (<tt>true</tt>).
   */
  public static final int YYACCEPT = 0;

  /**
   * Returned by a Bison action in order to stop the parsing process and
   * return failure (<tt>false</tt>).
   */
  public static final int YYABORT = 1;


  /**
   * Returned by a Bison action in order to request a new token.
   */
  public static final int YYPUSH_MORE = 4;

  /**
   * Returned by a Bison action in order to start error recovery without
   * printing an error message.
   */
  public static final int YYERROR = 2;

  /**
   * Internal return codes that are not supported for user semantic
   * actions.
   */
  private static final int YYERRLAB = 3;
  private static final int YYNEWSTATE = 4;
  private static final int YYDEFAULT = 5;
  private static final int YYREDUCE = 6;
  private static final int YYERRLAB1 = 7;
  private static final int YYRETURN = 8;
  private static final int YYGETTOKEN = 9; /* Signify that a new token is expected when doing push-parsing.  */

  private int yyerrstatus_ = 0;


    /* Lookahead and lookahead in internal form.  */
    int yychar = yyempty_;
    int yytoken = 0;

    /* State.  */
    int yyn = 0;
    int yylen = 0;
    int yystate = 0;
    YYStack yystack = new YYStack ();
    int label = YYNEWSTATE;

    /* Error handling.  */
    int yynerrs_ = 0;
    

    /* Semantic value of the lookahead.  */
    Object yylval = null;

  /**
   * Return whether error recovery is being done.  In this state, the parser
   * reads token until it reaches a known state, and then restarts normal
   * operation.
   */
  public final boolean recovering ()
  {
    return yyerrstatus_ == 0;
  }

  private int yyaction (int yyn, YYStack yystack, int yylen) throws Exception
  {
    Object yyval;
    

    /* If YYLEN is nonzero, implement the default value of the action:
       '$$ = $1'.  Otherwise, use the top of the stack.

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
        
/* "src/yax/test/Dap4Parser.java":501  */ /* lalr1.java:476  */
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
                                 Object yyvaluep                                 )
  {
    if (yydebug > 0)
    yycdebug (s + (yytype < yyntokens_ ? " token " : " nterm ")
              + yytname_[yytype] + " ("
              + (yyvaluep == null ? "(null)" : yyvaluep.toString ()) + ")");
  }



  /**
   * Push Parse input from external lexer
   *
   * @param yylextoken current token
   * @param yylexval current lval

   *
   * @return <tt>YYACCEPT, YYABORT, YYPUSH_MORE</tt>
   */
  public int push_parse (int yylextoken, Object yylexval)
      throws Exception, Exception
  {
    


    if (!this.push_parse_initialized)
      {
        push_parse_initialize ();

        yycdebug ("Starting parse\n");
        yyerrstatus_ = 0;
      } else
        label = YYGETTOKEN;

    boolean push_token_consumed = true;

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
          {label = YYACCEPT; break;}

        /* Take a decision.  First try without lookahead.  */
        yyn = yypact_[yystate];
        if (yy_pact_value_is_default_ (yyn))
          {
            label = YYDEFAULT;
            break;
          }
        /* Fall Through */

      case YYGETTOKEN:
        /* Read a lookahead token.  */
        if (yychar == yyempty_)
          {

            if (!push_token_consumed)
              return YYPUSH_MORE;
            yycdebug ("Reading a token: ");
            yychar = yylextoken;
            yylval = yylexval;
            push_token_consumed = false;

          }

        /* Convert token to internal form.  */
        if (yychar <= Lexer.EOF)
          {
            yychar = yytoken = Lexer.EOF;
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
            if (yy_table_value_is_error_ (yyn))
              label = YYERRLAB;
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
          label = YYERRLAB;
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
      case YYERRLAB:
        /* If not already recovering from an error, report this error.  */
        if (yyerrstatus_ == 0)
          {
            ++yynerrs_;
            if (yychar == yyempty_)
              yytoken = yyempty_;
            yyerror (yysyntax_error (yystate, yytoken));
          }

        
        if (yyerrstatus_ == 3)
          {
        /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

        if (yychar <= Lexer.EOF)
          {
          /* Return failure if at end of input.  */
          if (yychar == Lexer.EOF)
            {label = YYABORT; break;}
          }
        else
            yychar = yyempty_;
          }

        /* Else will try to reuse lookahead token after shifting the error
           token.  */
        label = YYERRLAB1;
        break;

      /*-------------------------------------------------.
      | errorlab -- error raised explicitly by YYERROR.  |
      `-------------------------------------------------*/
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
        yyerrstatus_ = 3;       /* Each real token shifted decrements this.  */

        for (;;)
          {
            yyn = yypact_[yystate];
            if (!yy_pact_value_is_default_ (yyn))
              {
                yyn += yyterror_;
                if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                  {
                    yyn = yytable_[yyn];
                    if (0 < yyn)
                      break;
                  }
              }

            /* Pop the current state because it cannot handle the
             * error token.  */
            if (yystack.height == 0)
              {label = YYABORT; break;}

            
            yystack.pop ();
            yystate = yystack.stateAt (0);
            if (yydebug > 0)
              yystack.print (yyDebugStream);
          }

        if (label == YYABORT)
            /* Leave the switch.  */
            break;



        /* Shift the error token.  */
        yy_symbol_print ("Shifting", yystos_[yyn],
                         yylval);

        yystate = yyn;
        yystack.push (yyn, yylval);
        label = YYNEWSTATE;
        break;

        /* Accept.  */
      case YYACCEPT:
        this.push_parse_initialized = false; return YYACCEPT;

        /* Abort.  */
      case YYABORT:
        this.push_parse_initialized = false; return YYABORT;
      }
}

  boolean push_parse_initialized = false;

    /**
     * (Re-)Initialize the state of the push parser.
     */
  public void push_parse_initialize()
  {
    /* Lookahead and lookahead in internal form.  */
    this.yychar = yyempty_;
    this.yytoken = 0;

    /* State.  */
    this.yyn = 0;
    this.yylen = 0;
    this.yystate = 0;
    this.yystack = new YYStack ();
    this.label = YYNEWSTATE;

    /* Error handling.  */
    this.yynerrs_ = 0;
    

    /* Semantic value of the lookahead.  */
    this.yylval = null;

    yystack.push (this.yystate, this.yylval);

    this.push_parse_initialized = true;

  }




  // Generate an error message.
  private String yysyntax_error (int yystate, int tok)
  {
    if (yyErrorVerbose)
      {
        /* There are many possibilities here to consider:
           - If this state is a consistent state with a default action,
             then the only way this function was invoked is if the
             default action is an error action.  In that case, don't
             check for expected tokens because there are none.
           - The only way there can be no lookahead present (in tok) is
             if this state is a consistent state with a default action.
             Thus, detecting the absence of a lookahead is sufficient to
             determine that there is no unexpected or expected token to
             report.  In that case, just report a simple "syntax error".
           - Don't assume there isn't a lookahead just because this
             state is a consistent state with a default action.  There
             might have been a previous inconsistent state, consistent
             state with a non-default action, or user semantic action
             that manipulated yychar.  (However, yychar is currently out
             of scope during semantic actions.)
           - Of course, the expected token list depends on states to
             have correct lookahead information, and it depends on the
             parser not to perform extra reductions after fetching a
             lookahead from the scanner and before detecting a syntax
             error.  Thus, state merging (from LALR or IELR) and default
             reductions corrupt the expected token list.  However, the
             list is correct for canonical LR with one exception: it
             will still contain any token that will not be accepted due
             to an error action in a later state.
        */
        if (tok != yyempty_)
          {
            /* FIXME: This method of building the message is not compatible
               with internationalization.  */
            StringBuffer res =
              new StringBuffer ("syntax error, unexpected ");
            res.append (yytnamerr_ (yytname_[tok]));
            int yyn = yypact_[yystate];
            if (!yy_pact_value_is_default_ (yyn))
              {
                /* Start YYX at -YYN if negative to avoid negative
                   indexes in YYCHECK.  In other words, skip the first
                   -YYN actions for this state because they are default
                   actions.  */
                int yyxbegin = yyn < 0 ? -yyn : 0;
                /* Stay within bounds of both yycheck and yytname.  */
                int yychecklim = yylast_ - yyn + 1;
                int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
                int count = 0;
                for (int x = yyxbegin; x < yyxend; ++x)
                  if (yycheck_[x + yyn] == x && x != yyterror_
                      && !yy_table_value_is_error_ (yytable_[x + yyn]))
                    ++count;
                if (count < 5)
                  {
                    count = 0;
                    for (int x = yyxbegin; x < yyxend; ++x)
                      if (yycheck_[x + yyn] == x && x != yyterror_
                          && !yy_table_value_is_error_ (yytable_[x + yyn]))
                        {
                          res.append (count++ == 0 ? ", expecting " : " or ");
                          res.append (yytnamerr_ (yytname_[x]));
                        }
                  }
              }
            return res.toString ();
          }
      }

    return "syntax error";
  }

  /**
   * Whether the given <code>yypact_</code> value indicates a defaulted state.
   * @param yyvalue   the value to check
   */
  private static boolean yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  /**
   * Whether the given <code>yytable_</code>
   * value indicates a syntax error.
   * @param yyvalue the value to check
   */
  private static boolean yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  private static final byte yypact_ninf_ = -50;
  private static final byte yytable_ninf_ = -1;

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
  private static final byte yypact_[] = yypact_init();
  private static final byte[] yypact_init()
  {
    return new byte[]
    {
       8,   -50,     2,    73,   -50,   -50,   -50,   -50,   -50,   -50,
     -50,   -50,    -4,   -50,   -50,   -48,     6,   -39,   -10,   -50,
     -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,
     -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,
      14,   -50,   -50,   -50,    73,    16,    23,    48,    18,    22,
     -50,   -50,   -50,    36,   -50,    -1,   -50,   -50,   -49,    54,
     -50,   -50,   -50,    -6,    76,   -50,   -50,   -50,    78,    40,
     -50,    20,    32,    94,   -50,   -50,   -50,   -50,    10,   -50,
     -50,   -50,   -50,    44,   -50,    41,   -50,    45,   -50,   -50,
     -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,
     -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,
     -50,   -50,    96,    98,    47,   -50,   -50,   100,   -50,   -50,
      92,   -17,   -50,   -50,   -50,   -50
    };
  }

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
  private static final byte yydefact_[] = yydefact_init();
  private static final byte[] yydefact_init()
  {
    return new byte[]
    {
       0,     4,     0,    12,     1,     9,     6,     7,     5,     8,
      10,    11,     0,     2,     4,     0,     0,     0,     0,    84,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    17,    13,    14,    15,    35,
       0,    36,    16,    82,    12,     0,     0,     0,     0,     0,
      80,    53,    76,    26,    70,     0,    20,    19,     0,     0,
      21,    30,    31,     0,     0,    85,    87,    86,    88,     0,
       3,     0,     0,     0,    18,    22,    29,    81,     0,    75,
      77,    78,    79,     0,    27,     0,    69,     0,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    71,    37,    72,    73,    24,    25,    23,
      33,    34,     0,     0,    92,    83,    89,     0,    32,    28,
       0,     0,    74,    90,    91,    93
    };
  }

/* YYPGOTO[NTERM-NUM].  */
  private static final byte yypgoto_[] = yypgoto_init();
  private static final byte[] yypgoto_init()
  {
    return new byte[]
    {
     -50,   -50,   -50,   104,    80,   -50,   -50,   -50,    63,   -50,
     -50,   -50,   -50,   -50,    57,   -50,    64,   -50,   -50,   -50,
     -50,   -50,   -50,   -50,   -50,    -3,   -50,   -50,   -50,   -50,
     -50
    };
  }

/* YYDEFGOTO[NTERM-NUM].  */
  private static final byte yydefgoto_[] = yydefgoto_init();
  private static final byte[] yydefgoto_init()
  {
    return new byte[]
    {
      -1,     2,    35,     3,    12,    36,    47,    59,    60,    73,
      68,    84,    37,    50,    80,   112,    38,    39,    40,   104,
      69,   105,    41,    64,    63,    42,    43,    53,    85,   116,
     121
    };
  }

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
  private static final byte yytable_[] = yytable_init();
  private static final byte[] yytable_init()
  {
    return new byte[]
    {
      13,    14,     4,    15,    14,    70,    15,   124,    76,    16,
      45,     1,    16,    17,    71,    46,    17,    18,    72,    19,
      18,    19,    51,    20,    19,    21,    20,    22,    21,    23,
      22,    24,    23,    25,    24,    26,    25,    27,    26,    28,
      27,    29,    28,    30,    29,    31,    30,    32,    31,    33,
      32,    34,    33,    52,    34,    78,   125,    58,    86,    87,
      77,    82,    74,    58,   114,    19,   106,   115,    88,    48,
      89,    49,    90,   110,    91,   111,    92,    54,    93,    56,
      94,    57,    95,    61,    96,    62,    97,   107,    98,    83,
      99,    78,   100,    17,   101,   108,   102,    18,    79,    65,
      66,    19,    67,    20,   109,    21,   113,    22,   117,    23,
     119,    24,   118,    25,   120,    26,   123,    27,    44,    28,
     122,    29,    75,    30,    55,    31,   103,    32,    81,    33,
       5,    34,     6,     7,     0,     0,     8,     0,     0,     0,
       0,     9,    10,    11
    };
  }

private static final byte yycheck_[] = yycheck_init();
  private static final byte[] yycheck_init()
  {
    return new byte[]
    {
       4,     5,     0,     7,     5,     6,     7,    24,    14,    13,
      58,     3,    13,    17,    63,    63,    17,    21,    67,    25,
      21,    25,    61,    27,    25,    29,    27,    31,    29,    33,
      31,    35,    33,    37,    35,    39,    37,    41,    39,    43,
      41,    45,    43,    47,    45,    49,    47,    51,    49,    53,
      51,    55,    53,    63,    55,    15,    73,     9,    18,    19,
      63,    64,     8,     9,    23,    25,    69,    26,    28,    63,
      30,    65,    32,    63,    34,    65,    36,    63,    38,    63,
      40,    58,    42,    65,    44,    63,    46,    67,    48,    11,
      50,    15,    52,    17,    54,    63,    56,    21,    22,    63,
      64,    25,    66,    27,    10,    29,    62,    31,    63,    33,
      12,    35,    16,    37,    67,    39,    24,    41,    14,    43,
      20,    45,    59,    47,    44,    49,    69,    51,    64,    53,
      57,    55,    59,    60,    -1,    -1,    63,    -1,    -1,    -1,
      -1,    68,    69,    70
    };
  }

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
  private static final byte yystos_[] = yystos_init();
  private static final byte[] yystos_init()
  {
    return new byte[]
    {
       0,     3,    78,    80,     0,    57,    59,    60,    63,    68,
      69,    70,    81,     4,     5,     7,    13,    17,    21,    25,
      27,    29,    31,    33,    35,    37,    39,    41,    43,    45,
      47,    49,    51,    53,    55,    79,    82,    89,    93,    94,
      95,    99,   102,   103,    80,    58,    63,    83,    63,    65,
      90,    61,    63,   104,    63,    81,    63,    58,     9,    84,
      85,    65,    63,   101,   100,    63,    64,    66,    87,    97,
       6,    63,    67,    86,     8,    85,    14,   102,    15,    22,
      91,    93,   102,    11,    88,   105,    18,    19,    28,    30,
      32,    34,    36,    38,    40,    42,    44,    46,    48,    50,
      52,    54,    56,    91,    96,    98,   102,    67,    63,    10,
      63,    65,    92,    62,    23,    26,   106,    63,    16,    12,
      67,   107,    20,    24,    24,    73
    };
  }

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  private static final byte yyr1_[] = yyr1_init();
  private static final byte[] yyr1_init()
  {
    return new byte[]
    {
       0,    77,    78,    79,    80,    80,    80,    80,    80,    80,
      80,    80,    81,    81,    81,    81,    81,    81,    82,    83,
      83,    84,    84,    85,    86,    86,    87,    87,    88,    89,
      90,    90,    91,    92,    92,    93,    93,    94,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      97,    97,    97,    97,    98,    99,   100,   100,   100,   100,
     101,   101,   102,   103,   104,   104,   104,   104,   105,   105,
     106,   106,   107,   107
    };
  }

/* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
  private static final byte yyr2_[] = yyr2_init();
  private static final byte[] yyr2_init()
  {
    return new byte[]
    {
       0,     2,     4,     4,     0,     2,     2,     2,     2,     2,
       2,     2,     0,     2,     2,     2,     2,     2,     4,     2,
       2,     1,     2,     3,     2,     2,     0,     2,     3,     4,
       2,     2,     3,     1,     1,     1,     1,     4,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     2,     2,     2,     3,     4,     0,     2,     2,     2,
       0,     2,     1,     5,     0,     2,     2,     2,     0,     2,
       3,     3,     0,     2
    };
  }

  /* YYTOKEN_NUMBER[YYLEX-NUM] -- Internal symbol number corresponding
      to YYLEX-NUM.  */
  private static final short yytoken_number_[] = yytoken_number_init();
  private static final short[] yytoken_number_init()
  {
    return new short[]
    {
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331
    };
  }

  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  private static final String yytname_[] = yytname_init();
  private static final String[] yytname_init()
  {
    return new String[]
    {
  "$end", "error", "$undefined", "DATASET_", "_DATASET", "GROUP_",
  "_GROUP", "ENUMERATION_", "_ENUMERATION", "ENUMCONST_", "_ENUMCONST",
  "NAMESPACE_", "_NAMESPACE", "DIMENSION_", "_DIMENSION", "DIM_", "_DIM",
  "ENUM_", "_ENUM", "MAP_", "_MAP", "STRUCTURE_", "_STRUCTURE", "VALUE_",
  "_VALUE", "ATTRIBUTE_", "_ATTRIBUTE", "CHAR_", "_CHAR", "BYTE_", "_BYTE",
  "INT8_", "_INT8", "UINT8_", "_UINT8", "INT16_", "_INT16", "UINT16_",
  "_UINT16", "INT32_", "_INT32", "UINT32_", "_UINT32", "INT64_", "_INT64",
  "UINT64_", "_UINT64", "FLOAT32_", "_FLOAT32", "FLOAT64_", "_FLOAT64",
  "STRING_", "_STRING", "URL_", "_URL", "OPAQUE_", "_OPAQUE", "ATTR_BASE",
  "ATTR_BASETYPE", "ATTR_DAPVERSION", "ATTR_DDXVERSION", "ATTR_ENUM",
  "ATTR_HREF", "ATTR_NAME", "ATTR_NAMESPACE", "ATTR_SIZE", "ATTR_TYPE",
  "ATTR_VALUE", "ATTR_NS", "ATTR_XMLNS", "UNKNOWN_ATTR",
  "UNKNOWN_ELEMENT_", "_UNKNOWN_ELEMENT", "TEXT", "ERROR", "UNKNOWN",
  "UNEXPECTED", "$accept", "dataset", "group", "group_attr_list",
  "group_body", "enumdef", "enum_attr_list", "enumconst_list", "enumconst",
  "enumconst_attr_list", "namespace_list", "namespace", "dimdef",
  "dimdef_attr_list", "dimref", "dimref_attr_list", "variable",
  "simplevariable", "atomictype_", "_atomictype", "variabledef", "mapref",
  "structurevariable", "structuredef", "metadatalist", "metadata",
  "attribute", "attribute_attr_list", "value_list", "value", "text_list", null
    };
  }

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  private static final short yyrline_[] = yyrline_init();
  private static final short[] yyrline_init()
  {
    return new short[]
    {
       0,    69,    69,    73,    76,    78,    79,    80,    81,    82,
      83,    84,    87,    89,    90,    91,    92,    93,    97,   101,
     102,   106,   107,   112,   116,   117,   120,   122,   126,   130,
     134,   135,   139,   143,   144,   148,   149,   154,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     196,   198,   199,   200,   204,   208,   211,   213,   214,   215,
     218,   220,   224,   228,   234,   236,   237,   238,   241,   243,
     247,   248,   251,   253
    };
  }


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
                       yystos_[yystack.stateAt(yynrhs - (yyi + 1))],
                       ((yystack.valueAt (yynrhs-(yyi + 1)))));
  }

  /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
  private static final byte yytranslate_table_[] = yytranslate_table_init();
  private static final byte[] yytranslate_table_init()
  {
    return new byte[]
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
      75,    76
    };
  }

  private static final byte yytranslate_ (int t)
  {
    if (t >= 0 && t <= yyuser_token_number_max_)
      return yytranslate_table_[t];
    else
      return yyundef_token_;
  }

  private static final int yylast_ = 143;
  private static final int yynnts_ = 31;
  private static final int yyempty_ = -2;
  private static final int yyfinal_ = 4;
  private static final int yyterror_ = 1;
  private static final int yyerrcode_ = 256;
  private static final int yyntokens_ = 77;

  private static final int yyuser_token_number_max_ = 331;
  private static final int yyundef_token_ = 2;

/* User implementation code.  */

}

/* "src/yax/test/dap4.y":256  */ /* lalr1.java:1064  */

