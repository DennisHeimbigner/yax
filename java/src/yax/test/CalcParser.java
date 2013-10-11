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

/* "src/yax/test/CalcParser.java":37  */ /* lalr1.java:91  */

/* "src/yax/test/CalcParser.java":39  */ /* lalr1.java:92  */
/* "%code imports" blocks.  */
/* "src/yax/test/calc.y":15  */ /* lalr1.java:93  */

import yax.*;

/* "src/yax/test/CalcParser.java":45  */ /* lalr1.java:93  */

/**
 * A Bison parser, automatically generated from <tt>src/yax/test/calc.y</tt>.
 *
 * @author LALR (1) parser skeleton written by Paolo Bonzini.
 */
public class CalcParser extends CalcTest
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
   * parser <tt>CalcParser</tt>.
   */
  public interface Lexer {
    /** Token returned by the scanner to signal the end of its input.  */
    public static final int EOF = 0;

/* Tokens.  */
    /** Token number,to be returned by the scanner.  */
    static final int CALC_ = 258;
    /** Token number,to be returned by the scanner.  */
    static final int _CALC = 259;
    /** Token number,to be returned by the scanner.  */
    static final int EQ_ = 260;
    /** Token number,to be returned by the scanner.  */
    static final int _EQ = 261;
    /** Token number,to be returned by the scanner.  */
    static final int ADD_ = 262;
    /** Token number,to be returned by the scanner.  */
    static final int _ADD = 263;
    /** Token number,to be returned by the scanner.  */
    static final int SUB_ = 264;
    /** Token number,to be returned by the scanner.  */
    static final int _SUB = 265;
    /** Token number,to be returned by the scanner.  */
    static final int MUL_ = 266;
    /** Token number,to be returned by the scanner.  */
    static final int _MUL = 267;
    /** Token number,to be returned by the scanner.  */
    static final int DIV_ = 268;
    /** Token number,to be returned by the scanner.  */
    static final int _DIV = 269;
    /** Token number,to be returned by the scanner.  */
    static final int EXP_ = 270;
    /** Token number,to be returned by the scanner.  */
    static final int _EXP = 271;
    /** Token number,to be returned by the scanner.  */
    static final int NEG_ = 272;
    /** Token number,to be returned by the scanner.  */
    static final int _NEG = 273;
    /** Token number,to be returned by the scanner.  */
    static final int INT_ = 274;
    /** Token number,to be returned by the scanner.  */
    static final int _INT = 275;
    /** Token number,to be returned by the scanner.  */
    static final int ATTR_N = 276;
    /** Token number,to be returned by the scanner.  */
    static final int TEXT = 277;
    /** Token number,to be returned by the scanner.  */
    static final int UNKNOWN_ATTR = 278;
    /** Token number,to be returned by the scanner.  */
    static final int UNKNOWN_ELEMENT_ = 279;
    /** Token number,to be returned by the scanner.  */
    static final int _UNKNOWN_ELEMENT = 280;


    

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
    int yylex () throws java.io.IOException;

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
/* "src/yax/test/calc.y":19  */ /* lalr1.java:236  */

public Object getLVal() {return null;}
public int yylex() {return 0;}
public void yyerror(String s) {System.err.println(s);}

/* "src/yax/test/CalcParser.java":174  */ /* lalr1.java:236  */

  }

  /**
   * The object doing lexical analysis for us.
   */
  private Lexer yylexer;
  
  


  /**
   * Instantiates the Bison-generated parser.
   */
  public CalcParser () 
  {
    
    this.yylexer = new YYLexer();
    
  }


  /**
   * Instantiates the Bison-generated parser.
   * @param yylexer The scanner that will supply tokens to the parser.
   */
  protected CalcParser (Lexer yylexer) 
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

  private int yyaction (int yyn, YYStack yystack, int yylen) 
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
          case 2:
  if (yyn == 2)
    /* "src/yax/test/calc.y":83  */ /* lalr1.java:476  */
    {yyval=null;};
  break;
    

  case 3:
  if (yyn == 3)
    /* "src/yax/test/calc.y":87  */ /* lalr1.java:476  */
    {yyval=null;};
  break;
    

  case 4:
  if (yyn == 4)
    /* "src/yax/test/calc.y":89  */ /* lalr1.java:476  */
    {calc(((Integer)(yystack.valueAt (2-(2))))); yyval=null;};
  break;
    

  case 5:
  if (yyn == 5)
    /* "src/yax/test/calc.y":94  */ /* lalr1.java:476  */
    {yyval = (((Integer)(yystack.valueAt (4-(2)))) == ((Integer)(yystack.valueAt (4-(3)))) ? new Integer(1) : new Integer(0));};
  break;
    

  case 6:
  if (yyn == 6)
    /* "src/yax/test/calc.y":96  */ /* lalr1.java:476  */
    {yyval=bin_add(((Integer)(yystack.valueAt (4-(2)))),((Integer)(yystack.valueAt (4-(3)))));};
  break;
    

  case 7:
  if (yyn == 7)
    /* "src/yax/test/calc.y":98  */ /* lalr1.java:476  */
    {yyval=bin_sub(((Integer)(yystack.valueAt (4-(2)))),((Integer)(yystack.valueAt (4-(3)))));};
  break;
    

  case 8:
  if (yyn == 8)
    /* "src/yax/test/calc.y":100  */ /* lalr1.java:476  */
    {yyval=bin_mul(((Integer)(yystack.valueAt (4-(2)))),((Integer)(yystack.valueAt (4-(3)))));};
  break;
    

  case 9:
  if (yyn == 9)
    /* "src/yax/test/calc.y":102  */ /* lalr1.java:476  */
    {yyval=bin_div(((Integer)(yystack.valueAt (4-(2)))),((Integer)(yystack.valueAt (4-(3)))));};
  break;
    

  case 10:
  if (yyn == 10)
    /* "src/yax/test/calc.y":104  */ /* lalr1.java:476  */
    {yyval=bin_exp(((Integer)(yystack.valueAt (4-(2)))),((Integer)(yystack.valueAt (4-(3)))));};
  break;
    

  case 11:
  if (yyn == 11)
    /* "src/yax/test/calc.y":106  */ /* lalr1.java:476  */
    {yyval=un_neg(((Integer)(yystack.valueAt (3-(2)))));};
  break;
    

  case 12:
  if (yyn == 12)
    /* "src/yax/test/calc.y":108  */ /* lalr1.java:476  */
    {yyval=((Integer)(yystack.valueAt (1-(1))));};
  break;
    

  case 13:
  if (yyn == 13)
    /* "src/yax/test/calc.y":110  */ /* lalr1.java:476  */
    {yyval=new Integer(0);};
  break;
    

  case 14:
  if (yyn == 14)
    /* "src/yax/test/calc.y":115  */ /* lalr1.java:476  */
    {yyval=number(((SaxEvent)(yystack.valueAt (3-(2)))));};
  break;
    

  case 15:
  if (yyn == 15)
    /* "src/yax/test/calc.y":117  */ /* lalr1.java:476  */
    {yyval=number(((SaxEvent)(yystack.valueAt (3-(2)))));};
  break;
    


/* "src/yax/test/CalcParser.java":503  */ /* lalr1.java:476  */
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
      throws java.io.IOException
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

  private static final byte yypact_ninf_ = -2;
  private static final byte yytable_ninf_ = -1;

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
  private static final byte yypact_[] = yypact_init();
  private static final byte[] yypact_init()
  {
    return new byte[]
    {
      26,    -2,     2,    -1,    -2,    33,    -2,     0,     0,     0,
       0,     0,     0,     0,     6,    -2,    -2,    -2,     0,     0,
       0,     0,     0,     0,    12,    18,    19,    34,    35,    31,
      30,    32,    28,    -2,    -2,    -2,    -2,    -2,    -2,    -2,
      -2,    -2
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
       0,     3,     0,     0,     1,     0,     2,     0,     0,     0,
       0,     0,     0,     0,     0,     4,    12,    13,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    11,    14,    15,     5,     6,     7,     8,
       9,    10
    };
  }

/* YYPGOTO[NTERM-NUM].  */
  private static final byte yypgoto_[] = yypgoto_init();
  private static final byte[] yypgoto_init()
  {
    return new byte[]
    {
      -2,    -2,    -2,    13,    -2
    };
  }

/* YYDEFGOTO[NTERM-NUM].  */
  private static final byte yydefgoto_[] = yydefgoto_init();
  private static final byte[] yydefgoto_init()
  {
    return new byte[]
    {
      -1,     2,     3,    15,    16
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
       5,     5,     4,     6,     7,     7,     8,     8,     9,     9,
      10,    10,    11,    11,    12,    12,    13,    13,    14,    14,
      18,    19,    20,    21,    22,    23,    24,    25,    26,     1,
      33,    27,    28,    29,    30,    31,    32,    17,    34,    35,
      36,    38,    39,    37,    41,     0,    40
    };
  }

private static final byte yycheck_[] = yycheck_init();
  private static final byte[] yycheck_init()
  {
    return new byte[]
    {
       1,     1,     0,     4,     5,     5,     7,     7,     9,     9,
      11,    11,    13,    13,    15,    15,    17,    17,    19,    19,
       7,     8,     9,    10,    11,    12,    13,    21,    22,     3,
      18,    18,    19,    20,    21,    22,    23,     4,    20,    20,
       6,    10,    12,     8,    16,    -1,    14
    };
  }

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
  private static final byte yystos_[] = yystos_init();
  private static final byte[] yystos_init()
  {
    return new byte[]
    {
       0,     3,    27,    28,     0,     1,     4,     5,     7,     9,
      11,    13,    15,    17,    19,    29,    30,     4,    29,    29,
      29,    29,    29,    29,    29,    21,    22,    29,    29,    29,
      29,    29,    29,    18,    20,    20,     6,     8,    10,    12,
      14,    16
    };
  }

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  private static final byte yyr1_[] = yyr1_init();
  private static final byte[] yyr1_init()
  {
    return new byte[]
    {
       0,    26,    27,    28,    28,    29,    29,    29,    29,    29,
      29,    29,    29,    29,    30,    30
    };
  }

/* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
  private static final byte yyr2_[] = yyr2_init();
  private static final byte[] yyr2_init()
  {
    return new byte[]
    {
       0,     2,     3,     0,     2,     4,     4,     4,     4,     4,
       4,     3,     1,     2,     3,     3
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
     275,   276,   277,   278,   279,   280
    };
  }

  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  private static final String yytname_[] = yytname_init();
  private static final String[] yytname_init()
  {
    return new String[]
    {
  "$end", "error", "$undefined", "CALC_", "_CALC", "EQ_", "_EQ", "ADD_",
  "_ADD", "SUB_", "_SUB", "MUL_", "_MUL", "DIV_", "_DIV", "EXP_", "_EXP",
  "NEG_", "_NEG", "INT_", "_INT", "ATTR_N", "TEXT", "UNKNOWN_ATTR",
  "UNKNOWN_ELEMENT_", "_UNKNOWN_ELEMENT", "$accept", "calc", "exprlist",
  "expr", "integer", null
    };
  }

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  private static final byte yyrline_[] = yyrline_init();
  private static final byte[] yyrline_init()
  {
    return new byte[]
    {
       0,    83,    83,    87,    88,    93,    95,    97,    99,   101,
     103,   105,   107,   109,   114,   116
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
      25
    };
  }

  private static final byte yytranslate_ (int t)
  {
    if (t >= 0 && t <= yyuser_token_number_max_)
      return yytranslate_table_[t];
    else
      return yyundef_token_;
  }

  private static final int yylast_ = 46;
  private static final int yynnts_ = 5;
  private static final int yyempty_ = -2;
  private static final int yyfinal_ = 4;
  private static final int yyterror_ = 1;
  private static final int yyerrcode_ = 256;
  private static final int yyntokens_ = 26;

  private static final int yyuser_token_number_max_ = 280;
  private static final int yyundef_token_ = 2;

/* User implementation code.  */
/* Unqualified %code blocks.  */
/* "src/yax/test/calc.y":25  */ /* lalr1.java:1060  */


void
calc(Object n)
{
    System.out.printf("result=%s\n",n.toString());
}

Integer bin_add(Integer n1, Integer n2) {return n1 + n2;}

Integer bin_sub(Integer n1, Integer n2) {return n1 - n2;}

Integer bin_mul(Integer n1, Integer n2) {return n1 * n2;}

Integer bin_div(Integer n1, Integer n2) {return n1 / n2;}

Integer bin_exp(Integer n1, Integer n2) {return n1 ^ n2;}

Integer un_neg(Integer n1) {return - n1;}

Integer
number(SaxEvent event)
{
    int n = 0;
    try {
      if(event.event == SaxEventType.CHARACTERS)
	n = Integer.parseInt(event.text);
      else if(event.event == SaxEventType.ATTRIBUTE)
	n = Integer.parseInt(event.value);
      else
	yyerror("Unexpected event: "+ event.toString());
    } catch (NumberFormatException nfe) {
	yyerror("Illegal number: "+ event.toString());
    }
    return n;
}


/* "src/yax/test/CalcParser.java":1219  */ /* lalr1.java:1060  */

}

/* "src/yax/test/calc.y":119  */ /* lalr1.java:1064  */

