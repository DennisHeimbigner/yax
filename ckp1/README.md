The yax system uses YACC (Bison really)
to contruct parsers for specific
XML document formats.

In order to use yax, it is necessary to manually produce the
three pieces of code.
# A Bison .y grammar file. This file can be produced in a
straightforward way starting with a RELAXNG [] grammar for the XML document.
# A perfect hash function for the element names and attribute names
defined in #1. The examples use the GNU gperf program
to generate the perfect hash code.
<li> A lexer for the YAXX/Bison parser.
This lexer in turn uses the yax provided basic xml lexer
to provide lexemes for the Bison generated parser.

Yax has some limitations with respect
to the kinds of XML document it can handle.
# Mixed content is not supported.
# % is not supported.
# The xml prolog and DOCTYPE constructs are parsed
     but not used.
# Name space prefixs (e.g. "xxx:yyy") are just treated as part
     of the name of an element.
# The input document is an in-memory string.
     A duplicate will be created and used inside the yax library.
# Comments are scanned but ignored.
# Entities (e.g. &amp;amp;) are not converted, but
an API function is provided to do that.

