/* Copyright 2009, UCAR/Unidata and OPeNDAP, Inc.
   See the COPYRIGHT file for more information. */

package yax.lex;

// The order here is such that the ordinal value matches that of the C code
public enum SaxEvent {
	UNDEFINED,
	EOF,
	OPEN,
	CLOSE,
	EMPTYCLOSE,
	ATTRIBUTE,
	TEXT,
	CDATA,
	PROLOG,
	DOCTYPE,
	COMMENT;
} // enum SaxEvent



