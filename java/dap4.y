%debug
%error-verbose

%define public
%define package "yax"
%define extends "DAP4parse"
%define throws "Exception"
%define lex_throws "Exception"

%code imports {
import opendap.dap.*;
import opendap.dap.BaseTypeFactory;
import opendap.dap.parsers.ParseException;
import java.io.*;
}

%code {
 
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

}
%token <YaxToken> GROUP_ _GROUP
%token <YaxToken> ENUMERATION_ _ENUMERATION
%token <YaxToken> ENUMCONST_ _ENUMCONST
%token <YaxToken> NAMESPACE_ _NAMESPACE
%token <YaxToken> DIMENSION_ _DIMENSION
%token <YaxToken> DIM_ _DIM
%token <YaxToken> ENUM_ _ENUM
%token <YaxToken> MAP_ _MAP
%token <YaxToken> STRUCTURE_ _STRUCTURE
%token <YaxToken> VALUE_ _VALUE
%token <YaxToken> ATTRIBUTE_ _ATTRIBUTE

/* atomictype lexemes */
%token <YaxToken> CHAR_ _CHAR
%token <YaxToken> BYTE_ _BYTE
%token <YaxToken> INT8_ _INT8
%token <YaxToken> UINT8_ _UINT8
%token <YaxToken> INT16_ _INT16
%token <YaxToken> UINT16_ _UINT16
%token <YaxToken> INT32_ _INT32
%token <YaxToken> UINT32_ _UINT32
%token <YaxToken> INT64_ _INT64
%token <YaxToken> UINT64_ _UINT64
%token <YaxToken> FLOAT32_ _FLOAT32
%token <YaxToken> FLOAT64_ _FLOAT64
%token <YaxToken> STRING_ _STRING
%token <YaxToken> URL_ _URL
%token <YaxToken> OPAQUE_ _OPAQUE

/* Standard attributes */
%token <YaxToken> ATTR_BASE ATTR_BASETYPE ATTR_DAPVERSION ATTR_DDXVERSION
%token <YaxToken> ATTR_ENUM ATTR_HREF ATTR_NAME ATTR_NAMESPACE
%token <YaxToken> ATTR_SIZE ATTR_TYPE ATTR_VALUE 
%token <YaxToken> ATTR_NS ATTR_XMLNS
%token <YaxToken> UNKNOWN_ATTR UNKNOWN_ELEMENT_ _UNKNOWN_ELEMENT

/* Currently unused */
%token <YaxToken> TEXT

/* Special case */
%token <List> OTHERXML

/* Error cases */
%token <YaxToken> ERROR UNKNOWN UNEXPECTED

%type <Object> group
%type <Object> enumdef enumconst
%type <Object> namespace
%type <Object> dimdef dimref 
%type <Object> variable simplevariable structurevariable
%type <Object> variabledef
%type <Object> structuredef
%type <Object> mapref
%type <Object> metadata attribute otherxml

%type <List>   group_body group_attr_list
%type <List>   enum_attr_list enumconst_list enumconst_attr_list
%type <List>   namespace_list 
%type <List>   dimdef_attr_list dimref_attr_list
%type <List>   attribute_attr_list attribute_value_list metadatalist

%type <YaxToken>  attribute_value

%type <YaxToken> atomictype_ _atomictype

%start group

%%
group:
	GROUP_ group_attr_list group_body _GROUP
	    {$$=d4group(parser,$2,$3); CHECK($$); } 
	;

group_attr_list:
	  /*empty*/ {$$=d4attrlist(parser,NULL,emptytoken);}
	| group_attr_list ATTR_NAME
	    {$$=d4attrlist(parser,$1,$2);}
	| group_attr_list ATTR_DAPVERSION
	    {$$=d4attrlist(parser,$1,$2);}
	| group_attr_list ATTR_DDXVERSION
	    {$$=d4attrlist(parser,$1,$2);}
	| group_attr_list ATTR_NS
	    {$$=d4attrlist(parser,$1,$2);}
	| group_attr_list ATTR_BASE
	    {$$=d4attrlist(parser,$1,$2);}
	| group_attr_list ATTR_XMLNS
	    {$$=d4attrlist(parser,$1,$2);}
	| group_attr_list UNKNOWN_ATTR
	    {$$=d4attrlist(parser,$1,$2);}
	;

group_body:
	  /*empty*/
	    {$$=d4list(parser,NULL,NULL);}
	| group_body enumdef
	    {$$=d4list(parser,$1,$2);}
	| group_body dimdef
	    {$$=d4list(parser,$1,$2);}
	| group_body variable
	    {$$=d4list(parser,$1,$2);}
	| group_body metadata
	    {$$=d4list(parser,$1,$2);}
	| group_body group
	    {$$=d4list(parser,$1,$2);}
	;

enumdef:
	ENUMERATION_ enum_attr_list enumconst_list _ENUMERATION
	    {$$=d4enumdef(parser,$2,$3); CHECK($$);}
	;

enum_attr_list:
	ATTR_NAME ATTR_BASETYPE
	    {$$=d4attrlist(parser,NULL,emptytoken);
		d4attrlist(parser,$$,$1);
		d4attrlist(parser,$$,$2);
	    }
	| ATTR_BASETYPE ATTR_NAME 
	    {$$=d4attrlist(parser,NULL,emptytoken);
		d4attrlist(parser,$$,$1);
		d4attrlist(parser,$$,$2);
	    }
	;

enumconst_list:
	  enumconst
	    {$$=d4list(parser,NULL,NULL);}
	| enumconst_list enumconst
	    {$$=d4list(parser,$1,$2);}
	;


enumconst:
	ENUMCONST_ enumconst_attr_list _ENUMCONST
	    {$$=d4enumconst(parser,$2); CHECK($$);}
	;
	
enumconst_attr_list:
	  ATTR_NAME ATTR_VALUE
	    {$$=d4attrlist(parser,NULL,emptytoken);
		d4attrlist(parser,$$,$1);
		d4attrlist(parser,$$,$2);
	    }
	| ATTR_VALUE ATTR_NAME
	    {$$=d4attrlist(parser,NULL,emptytoken);
		d4attrlist(parser,$$,$1);
		d4attrlist(parser,$$,$2);
	    }
	;

namespace_list: 
	  /*empty*/
	    {$$=d4list(parser,NULL,NULL);}
	| namespace_list namespace
	    {$$=d4list(parser,$1,$2);}
	;

namespace:
	NAMESPACE_ ATTR_HREF _NAMESPACE
	    {$$=d4namespace(parser,$2); CHECK($$);}
	;

dimdef:
	DIMENSION_ dimdef_attr_list metadatalist _DIMENSION
	    {$$=d4dimdef(parser,$2,$3); CHECK($$);}
	;

dimdef_attr_list:
	  ATTR_NAME ATTR_SIZE
	    {$$=d4attrlist(parser,NULL,emptytoken);
		d4attrlist(parser,$$,$1);
		d4attrlist(parser,$$,$2);
	    }
	| ATTR_SIZE ATTR_NAME
	    {$$=d4attrlist(parser,NULL,emptytoken);
		d4attrlist(parser,$$,$1);
		d4attrlist(parser,$$,$2);
	    }
	;

dimref:
	DIM_ dimref_attr_list _DIM
	    {$$=d4dimref(parser,$2); CHECK($$);}
	;

dimref_attr_list:
	  ATTR_NAME
	    {$$=d4attrlist(parser,NULL,emptytoken);
		d4attrlist(parser,$$,$1);
	    }
	| ATTR_SIZE
	    {$$=d4attrlist(parser,NULL,emptytoken);
		d4attrlist(parser,$$,$1);
	    }
	;

variable:
	  simplevariable    {$$=$1;}
	| structurevariable {$$=$1;}
	;

/* Use atomic type to avoid rule explosion */
simplevariable:
	atomictype_ ATTR_NAME variabledef _atomictype
	    {$$=d4simplevariable(parser,$1,$2,$3,$4); CHECK($$);}
	;


atomictype_:
	  CHAR_		  {$$=$1;}
	| BYTE_		  {$$=$1;}
	| INT8_		  {$$=$1;}
	| UINT8_	  {$$=$1;}
	| INT16_	  {$$=$1;}
	| UINT16_	  {$$=$1;}
	| INT32_	  {$$=$1;}
	| UINT32_	  {$$=$1;}
	| INT64_	  {$$=$1;}
	| UINT64_	  {$$=$1;}
	| FLOAT32_	  {$$=$1;}
	| FLOAT64_	  {$$=$1;}
	| STRING_	  {$$=$1;}
	| URL_		  {$$=$1;}
	| OPAQUE_	  {$$=$1;}
	| ENUM_ ATTR_ENUM {$$=$1;}
	;

_atomictype:
	  _CHAR	   {$$=$1;}
	| _BYTE	   {$$=$1;}
	| _INT8	   {$$=$1;}
	| _UINT8   {$$=$1;}
	| _INT16   {$$=$1;}
	| _UINT16  {$$=$1;}
	| _INT32   {$$=$1;}
	| _UINT32  {$$=$1;}
	| _INT64   {$$=$1;}
	| _UINT64  {$$=$1;}
	| _FLOAT32 {$$=$1;}
	| _FLOAT64 {$$=$1;}
	| _STRING  {$$=$1;}
	| _URL	   {$$=$1;}
	| _OPAQUE  {$$=$1;}
	| _ENUM	   {$$=$1;}
	;

variabledef:
	  /*empty*/
	    {$$=d4list(parser,NULL,NULL);}
	| variabledef dimref
	    {$$=d4list(parser,$1,$2);}
	| variabledef mapref
	    {$$=d4list(parser,$1,$2);}
	| variabledef metadata
	    {$$=d4list(parser,$1,$2);}
	;

mapref:
	MAP_ ATTR_NAME _MAP
	    {$$=d4mapref(parser,$2); CHECK($$);}
	;

structurevariable:
	STRUCTURE_ ATTR_NAME structuredef _STRUCTURE
	    {$$=d4structurevariable(parser,$2,$3); CHECK($$);}
	;

structuredef:
	  /*empty*/
	    {$$=d4list(parser,NULL,NULL);}
	| structuredef dimref
	    {$$=d4list(parser,$1,$2);}
	| structuredef variable
	    {$$=d4list(parser,$1,$2);}
	| structuredef metadata
	    {$$=d4list(parser,$1,$2);}
	;

metadatalist:
	  /*empty*/
	    {$$=d4list(parser,NULL,NULL);}
	| metadatalist metadata
	    {$$=d4list(parser,$1,$2);}
	;

metadata:
	  attribute {$$=$1;}
	| otherxml  {$$=$1;}
	;

attribute:
	ATTRIBUTE_ attribute_attr_list
                   namespace_list
                   attribute_value_list
		   _ATTRIBUTE
	    {$$=d4attribute(parser,$2,$3,$4); CHECK($$);}
	;

attribute_attr_list:
	  /*empty*/
	    {$$=d4attrlist(parser,NULL,emptytoken);}
	| attribute_attr_list ATTR_NAME
	    {$$=d4attrlist(parser,$1,$2);}
	| attribute_attr_list ATTR_TYPE
	    {$$=d4attrlist(parser,$1,$2);}
	| attribute_attr_list ATTR_NAMESPACE
	    {$$=d4attrlist(parser,$1,$2);}
	| attribute_attr_list ATTR_VALUE
	    {$$=d4attrlist(parser,$1,$2);}
	;	

attribute_value_list:
	  /*empty*/
	    {$$=d4attrlist(parser,NULL,emptytoken);}
	| attribute_value_list attribute_value
	    {$$=d4attrlist(parser,$1,$2);}
	;
attribute_value:
	VALUE_ ATTR_VALUE _VALUE {$$=$2;}
	;

otherxml:
	OTHERXML  {$$=d4otherxml(parser,$1);}

%%
