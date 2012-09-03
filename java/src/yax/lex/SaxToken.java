/* Copyright 2009, UCAR/Unidata and OPeNDAP, Inc.
   See the COPYRIGHT file for more information. */

package yax.lex;

public class SaxToken
{
    public Type type = Type.UNDEFINED; // Sax token type
    public String name = null;
    public String fullname = null;
    public String namespace = null;

    public String value = null; // for attributes
    public String text = null;  // for text

    public SaxToken(Type type) {this.type = type;}
    public SaxToken(Type type,String name) {this.type = type; this.name=name;}

    public SaxToken(Type type, String name,
                    String fullname, String uri)
    {
	this(type,name);
	this.fullname = fullname;
	this.namespace = uri;
    }


    public String toString()
    {
	String text = Util.trace(this);
	return text;
    }

} // class SaxToken

