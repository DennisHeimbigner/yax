%error-verbose
%pure-parser

%lex-param {DAP4parser* parser}
%parse-param {DAP4parser* parser}

%{
#include "yxlist.h"
#include "yax.h"
#include "dap4parse.h"

#define YYDEBUG 1
#define TRACE
#define TEST

#ifdef TEST
#define CHECK(x)
#else
#define CHECK(x) {if((x)==NULL) YYABORT;}
#endif

/* Forward */

union YYSTYPE;

int dap4lex(YYSTYPE* lvalp, DAP4parser* parser);
int dap4error(DAP4parser* state, const char* msg);

%}

%union {
   void* object;
   YXlist* list;
   yax_token token;
}


%token <token> GROUP_ _GROUP
%token <token> ENUMERATION_ _ENUMERATION
%token <token> ENUMCONST_ _ENUMCONST
%token <token> NAMESPACE_ _NAMESPACE
%token <token> DIMENSION_ _DIMENSION
%token <token> DIM_ _DIM
%token <token> ENUM_ _ENUM
%token <token> MAP_ _MAP
%token <token> STRUCTURE_ _STRUCTURE
%token <token> VALUE_ _VALUE
%token <token> ATTRIBUTE_ _ATTRIBUTE

/* atomictype lexemes */
%token <token> CHAR_ _CHAR
%token <token> BYTE_ _BYTE
%token <token> INT8_ _INT8
%token <token> UINT8_ _UINT8
%token <token> INT16_ _INT16
%token <token> UINT16_ _UINT16
%token <token> INT32_ _INT32
%token <token> UINT32_ _UINT32
%token <token> INT64_ _INT64
%token <token> UINT64_ _UINT64
%token <token> FLOAT32_ _FLOAT32
%token <token> FLOAT64_ _FLOAT64
%token <token> STRING_ _STRING
%token <token> URL_ _URL
%token <token> OPAQUE_ _OPAQUE

/* Standard attributes */
%token <token> ATTR_BASE ATTR_BASETYPE ATTR_DAPVERSION ATTR_DDXVERSION
%token <token> ATTR_ENUM ATTR_HREF ATTR_NAME ATTR_NAMESPACE
%token <token> ATTR_SIZE ATTR_TYPE ATTR_VALUE 
%token <token> ATTR_NS ATTR_XMLNS
%token <token> UNKNOWN_ATTR UNKNOWN_ELEMENT_ _UNKNOWN_ELEMENT

/* Currently unused */
%token <token> TEXT

/* Special case */
%token <list> OTHERXML

/* Error cases */
%token <token> ERROR UNKNOWN UNEXPECTED


%type <object> group
%type <object> enumdef enumconst
%type <object> namespace
%type <object> dimdef dimref 
%type <object> variable simplevariable structurevariable
%type <object> variabledef
%type <object> structuredef
%type <object> mapref
%type <object> metadata attribute otherxml

%type <list>   group_body group_attr_list
%type <list>   enum_attr_list enumconst_list enumconst_attr_list
%type <list>   namespace_list 
%type <list>   dimdef_attr_list dimref_attr_list
%type <list>   attribute_attr_list attribute_value_list metadatalist

%type <token>  attribute_value

%type <token> atomictype_ _atomictype

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
