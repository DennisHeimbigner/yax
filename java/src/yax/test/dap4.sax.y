%language "Java"
%debug
%error-verbose
%pure-parser

%define parser_class_name "Dap4SaxParser"
%define extends "Dap4SaxTest"
%define api.push-pull push
%define public
%define package "yax.test"
%define throws "Exception"
%define lex_throws "Exception"

%code imports {
}

%code lexer {
public Object getLVal() {return null;}
public int yylex() {return 0;}
public void yyerror(String s) {System.err.println(s);}
}

/* This version exploits the
   ability of the sax parser to
   order attributes
*/

%token  GROUP_ _GROUP
%token  ENUMERATION_ _ENUMERATION
%token  ENUMCONST_ _ENUMCONST
%token  NAMESPACE_ _NAMESPACE
%token  DIMENSION_ _DIMENSION
%token  DIM_ _DIM
%token  ENUM_ _ENUM
%token  MAP_ _MAP
%token  STRUCTURE_ _STRUCTURE
%token  VALUE_ _VALUE
%token  ATTRIBUTE_ _ATTRIBUTE

/* atomictype lexemes */
%token  CHAR_ _CHAR
%token  BYTE_ _BYTE
%token  INT8_ _INT8
%token  UINT8_ _UINT8
%token  INT16_ _INT16
%token  UINT16_ _UINT16
%token  INT32_ _INT32
%token  UINT32_ _UINT32
%token  INT64_ _INT64
%token  UINT64_ _UINT64
%token  FLOAT32_ _FLOAT32
%token  FLOAT64_ _FLOAT64
%token  STRING_ _STRING
%token  URL_ _URL
%token  OPAQUE_ _OPAQUE

/* Standard attributes */
%token  ATTR_BASE ATTR_BASETYPE ATTR_DAPVERSION ATTR_DDXVERSION
%token  ATTR_ENUM ATTR_HREF ATTR_NAME ATTR_NAMESPACE
%token  ATTR_SIZE ATTR_TYPE ATTR_VALUE 
%token  ATTR_NS ATTR_XMLNS
%token  UNKNOWN_ATTR UNKNOWN_ELEMENT_ _UNKNOWN_ELEMENT

%token  TEXT

/* Error cases */
%token  ERROR UNKNOWN UNEXPECTED

%start group

%%
group:
	GROUP_ ATTR_NAME group_opt_attr group_body _GROUP
	;

group_opt_attr:
	  /*empty*/
	| ATTR_DAPVERSION
	| ATTR_DAPVERSION ATTR_DDXVERSION
	| ATTR_DAPVERSION ATTR_DDXVERSION ATTR_NS
	| ATTR_DAPVERSION ATTR_DDXVERSION ATTR_NS ATTR_BASE
	| ATTR_DAPVERSION ATTR_DDXVERSION ATTR_NS ATTR_BASE ATTR_XMLNS
	| ATTR_DAPVERSION ATTR_DDXVERSION ATTR_NS ATTR_BASE unknown_attrs
	;

/* These will always be pushed to the end of the list of attributes */
unknown_attrs:
	  UNKNOWN_ATTR
	| unknown_attrs UNKNOWN_ATTR
	;

group_body:
	  /*empty*/
	| group_body enumdef
	| group_body dimdef
	| group_body variable
	| group_body metadata
	| group_body group
	;

enumdef:
	ENUMERATION_ ATTR_NAME enum_opt_attr enumconst_list _ENUMERATION
	;

enum_opt_attr:
	  /*empty*/
	| ATTR_BASETYPE
	;

enumconst_list:
	  enumconst
	| enumconst_list enumconst
	;

enumconst:
	ENUMCONST_ ATTR_NAME ATTR_VALUE _ENUMCONST
	;

namespace_list: 
	  /*empty*/
	| namespace_list namespace
	;

namespace:
	NAMESPACE_ ATTR_HREF _NAMESPACE
	;

dimdef:
	DIMENSION_ ATTR_NAME ATTR_SIZE metadatalist _DIMENSION
	;

dimref:
	  DIM_ ATTR_NAME _DIM
	| DIM_ ATTR_SIZE _DIM
	;

variable:
	  simplevariable
	| structurevariable
	;

/* Use atomic type to avoid rule explosion */
simplevariable:
	  atomictype_ ATTR_NAME variabledef _atomictype
	| ENUM_ ATTR_ENUM ATTR_NAME variabledef _ENUM
	;

atomictype_:
	  CHAR_
	| BYTE_
	| INT8_
	| UINT8_
	| INT16_
	| UINT16_
	| INT32_
	| UINT32_
	| INT64_
	| UINT64_
	| FLOAT32_
	| FLOAT64_
	| STRING_
	| URL_
	| OPAQUE_
	;

_atomictype:
	  _CHAR
	| _BYTE
	| _INT8
	| _UINT8
	| _INT16
	| _UINT16
	| _INT32
	| _UINT32
	| _INT64
	| _UINT64
	| _FLOAT32
	| _FLOAT64
	| _STRING
	| _URL
	| _OPAQUE
	;

variabledef:
	  /*empty*/
	| variabledef dimref
	| variabledef mapref
	| variabledef metadata
	;

mapref:
	MAP_ ATTR_NAME _MAP
	;

structurevariable:
	STRUCTURE_ ATTR_NAME structuredef _STRUCTURE
	;

structuredef:
	  /*empty*/
	| structuredef dimref
	| structuredef variable
	| structuredef metadata
	;

metadatalist:
	  /*empty*/
	| metadatalist metadata
	;

metadata:
	  attribute
	;

attribute:
	ATTRIBUTE_ ATTR_NAME attribute_opt_attr
                   namespace_list
                   value_list
		   _ATTRIBUTE
	;

attribute_opt_attr:
	  /*empty*/
	| ATTR_TYPE
	| ATTR_TYPE ATTR_NAMESPACE
	;

value_list:
	  /*empty*/
	| value_list value
	;

value:
	  VALUE_ ATTR_VALUE _VALUE
	| VALUE_ text_list _VALUE
	;

text_list:
	  /*empty*/
	| text_list TEXT
	;

%%
