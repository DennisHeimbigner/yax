/* Copyright 2009, UCAR/Unidata and OPeNDAP, Inc.
   See the COPYRIGHT file for more information. */

package yax.lex;

public class Lexeme
{
    public String name; // element or attribute name
    public int open; // Bison token for element open
    public int close; // Bison token for element close
    public int atoken; // Bison token if this is an attribute
    public String[] attributesInOrder;

    public Lexeme(String name, int atoken) {this(name,0,0,atoken,null);}
    public Lexeme(String name, int open, int close)
	{this(name,open,close,0,null);}
    public Lexeme(String name, int open, int close, String[] alist)
	{this(name,open,close,0,alist);}

    public Lexeme(String name, int open, int close, int atoken, String[] alist)
    {
	this.name = name;
	this.open = open;
	this.close = close;
	this.atoken = atoken;
	attributesInOrder = alist;
    }

    public void attribute(String[] inorder)
    {
	attributesInOrder = inorder;
	// check for duplicates
	for(int i=0;i<inorder.length;i++) {
	    for(int j=i+1;j<inorder.length;j++)
	        assert (!inorder[i].equals(inorder[j]));
	}
    }

    public String toString()
    {
         String text = String.format("%s open=%d close=%d a=%d",name,open,close,atoken);
         if(attributesInOrder != null && attributesInOrder.length > 0) {
             text += " attributes=";
             for(String s: attributesInOrder) {
                 text += " " + s;
             }
         }
         return text;
    }
} // class Lexeme

