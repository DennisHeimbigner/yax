/**
This software is released under the terms of the Apache License version 2.
For details of the license, see http://www.apache.org/licenses/LICENSE-2.0.
*/

package yax;

public class Lexeme
{
    public String name; // element or attribute name
    public int open; // Bison token for element open
    public int close; // Bison token for element close
    public int atoken; // Bison token if this is an attribute
    public String[] legalAttributes;
    public boolean textok; // Can this lexeme (if element) have text?

    public Lexeme(String name, int atoken) {this(name,0,0,atoken,null,false);}
    public Lexeme(String name, int open, int close)
	{this(name,open,close,0,null,false);}
    public Lexeme(String name, int open, int close, String[] alist)
	{this(name,open,close,0,alist,false);}

    public Lexeme(String name, int open, int close, int atoken, String[] alist, boolean textok)
    {
	this.name = name;
	this.open = open;
	this.close = close;
	this.atoken = atoken;
	legalAttributes = alist;
	this.textok = textok;
    }

    public void attribute(String[] alist)
    {
	legalAttributes = alist;
	// check for duplicates
	for(int i=0;i<legalAttributes.length;i++) {
	    for(int j=i+1;j<legalAttributes.length;j++)
	        assert (!legalAttributes[i].equals(legalAttributes[j]));
	}
    }

    public String toString()
    {
         String text = String.format("%s open=%d close=%d a=%d",name,open,close,atoken);
         if(legalAttributes != null && legalAttributes.length > 0) {
             text += " attributes=";
             for(String s: legalAttributes) {
                 text += " " + s;
             }
         }
         return text;
    }
} // class Lexeme
