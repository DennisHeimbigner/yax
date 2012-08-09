/* C code produced by gperf version 3.0.3 */
/* Command-line: gperf dap4.gperf  */
/* Computed positions: -k'1-2,$' */

#if !((' ' == 32) && ('!' == 33) && ('"' == 34) && ('#' == 35) \
      && ('%' == 37) && ('&' == 38) && ('\'' == 39) && ('(' == 40) \
      && (')' == 41) && ('*' == 42) && ('+' == 43) && (',' == 44) \
      && ('-' == 45) && ('.' == 46) && ('/' == 47) && ('0' == 48) \
      && ('1' == 49) && ('2' == 50) && ('3' == 51) && ('4' == 52) \
      && ('5' == 53) && ('6' == 54) && ('7' == 55) && ('8' == 56) \
      && ('9' == 57) && (':' == 58) && (';' == 59) && ('<' == 60) \
      && ('=' == 61) && ('>' == 62) && ('?' == 63) && ('A' == 65) \
      && ('B' == 66) && ('C' == 67) && ('D' == 68) && ('E' == 69) \
      && ('F' == 70) && ('G' == 71) && ('H' == 72) && ('I' == 73) \
      && ('J' == 74) && ('K' == 75) && ('L' == 76) && ('M' == 77) \
      && ('N' == 78) && ('O' == 79) && ('P' == 80) && ('Q' == 81) \
      && ('R' == 82) && ('S' == 83) && ('T' == 84) && ('U' == 85) \
      && ('V' == 86) && ('W' == 87) && ('X' == 88) && ('Y' == 89) \
      && ('Z' == 90) && ('[' == 91) && ('\\' == 92) && (']' == 93) \
      && ('^' == 94) && ('_' == 95) && ('a' == 97) && ('b' == 98) \
      && ('c' == 99) && ('d' == 100) && ('e' == 101) && ('f' == 102) \
      && ('g' == 103) && ('h' == 104) && ('i' == 105) && ('j' == 106) \
      && ('k' == 107) && ('l' == 108) && ('m' == 109) && ('n' == 110) \
      && ('o' == 111) && ('p' == 112) && ('q' == 113) && ('r' == 114) \
      && ('s' == 115) && ('t' == 116) && ('u' == 117) && ('v' == 118) \
      && ('w' == 119) && ('x' == 120) && ('y' == 121) && ('z' == 122) \
      && ('{' == 123) && ('|' == 124) && ('}' == 125) && ('~' == 126))
/* The character set is not based on ISO-646.  */
error "gperf generated tables don't work with this execution character set. Please report a bug to <bug-gnu-gperf@gnu.org>."
#endif


#include <string.h>
#include "yxlist.h"
#include "yax.h"
#include "dap4parse.h"
#include "dap4.tab.h"
struct dap4_keyword { char *name; enum yytokentype opentag ; enum yytokentype closetag; };
#include <string.h>

#define TOTAL_KEYWORDS 39
#define MIN_WORD_LENGTH 2
#define MAX_WORD_LENGTH 11
#define MIN_HASH_VALUE 2
#define MAX_HASH_VALUE 74
/* maximum key range = 73, duplicates = 0 */

#ifdef __GNUC__
__inline
#else
#ifdef __cplusplus
inline
#endif
#endif
static unsigned int
hash (str, len)
     register const char *str;
     register unsigned int len;
{
  static const unsigned char asso_values[] =
    {
      75, 75, 75, 75, 75, 75, 75, 75, 75, 75,
      75, 75, 75, 75, 75, 75, 75, 75, 75, 75,
      75, 75, 75, 75, 75, 75, 75, 75, 75, 75,
      75, 75, 75, 75, 75, 75, 75, 75, 75, 75,
      75, 75, 75, 75, 75, 75, 75, 75, 75, 75,
       5, 75,  0, 75, 20, 75, 30, 75, 75, 75,
      75, 75, 75, 75, 75, 40, 50, 30,  0,  5,
       0, 25, 75,  0, 75, 75,  0,  0, 50, 10,
      75, 75,  0, 15, 75,  0, 40, 75, 75, 75,
      75, 75, 75, 75, 75, 75, 75,  0,  5, 75,
       5,  0, 20,  0, 15, 20, 75, 75,  0, 10,
       0, 75,  5, 75, 15,  0, 25, 75, 35, 75,
      15, 15, 75, 75, 75, 75, 75, 75, 75, 75,
      75, 75, 75, 75, 75, 75, 75, 75, 75, 75,
      75, 75, 75, 75, 75, 75, 75, 75, 75, 75,
      75, 75, 75, 75, 75, 75, 75, 75, 75, 75,
      75, 75, 75, 75, 75, 75, 75, 75, 75, 75,
      75, 75, 75, 75, 75, 75, 75, 75, 75, 75,
      75, 75, 75, 75, 75, 75, 75, 75, 75, 75,
      75, 75, 75, 75, 75, 75, 75, 75, 75, 75,
      75, 75, 75, 75, 75, 75, 75, 75, 75, 75,
      75, 75, 75, 75, 75, 75, 75, 75, 75, 75,
      75, 75, 75, 75, 75, 75, 75, 75, 75, 75,
      75, 75, 75, 75, 75, 75, 75, 75, 75, 75,
      75, 75, 75, 75, 75, 75, 75, 75, 75, 75,
      75, 75, 75, 75, 75, 75
    };
  return len + asso_values[(unsigned char)str[1]] + asso_values[(unsigned char)str[0]] + asso_values[(unsigned char)str[len - 1]];
}

static const struct dap4_keyword wordlist[] =
  {
    {""}, {""},
    {"ns", ATTR_NS, 0},
    {"URL", URL_, _URL},
    {"name", ATTR_NAME, 0},
    {"Int64", INT64_, _INT64},
    {"UInt64", UINT64_, _UINT64},
    {"Float64", FLOAT64_, _FLOAT64},
    {"Map", MAP_, _MAP},
    {"base", ATTR_BASE, 0},
    {"Int32", INT32_, _INT32},
    {"UInt32", UINT32_, _UINT32},
    {"Float32", FLOAT32_, _FLOAT32},
    {"basetype", ATTR_BASETYPE, 0},
    {"enum", ATTR_ENUM, 0},
    {"dapVersion", ATTR_DAPVERSION, 0},
    {"Enumeration", ENUMERATION_, _ENUMERATION},
    {""}, {""},
    {"Enum", ENUM_, _ENUM},
    {"ddxVersion", ATTR_DDXVERSION, 0},
    {"Opaque", OPAQUE_, _OPAQUE},
    {""}, {""},
    {"size", ATTR_SIZE, 0},
    {"Int16", INT16_, _INT16},
    {"UInt16", UINT16_, _UINT16},
    {""}, {""},
    {"Dimension", DIMENSION_, _DIMENSION},
    {"xmlns", ATTR_XMLNS, 0},
    {""}, {""},
    {"Dim", DIM_, _DIM},
    {"Int8", INT8_, _INT8},
    {"UInt8", UINT8_, _UINT8},
    {""}, {""}, {""},
    {"EnumConst", ENUMCONST_, _ENUMCONST},
    {"value", ATTR_VALUE, 0},
    {""}, {""},
    {"OtherXML", OTHERXML, OTHERXML},
    {"type", ATTR_TYPE, 0},
    {"Value", VALUE_, _VALUE},
    {"String", STRING_, _STRING},
    {""}, {""},
    {"Structure", STRUCTURE_, _STRUCTURE},
    {"Group", GROUP_, _GROUP},
    {""}, {""}, {""},
    {"href", ATTR_HREF, 0},
    {""}, {""}, {""}, {""},
    {"Namespace", NAMESPACE_, _NAMESPACE},
    {""}, {""}, {""}, {""},
    {"Char", CHAR_, _CHAR},
    {""}, {""}, {""}, {""},
    {"Byte", BYTE_, _BYTE},
    {""}, {""}, {""}, {""},
    {"Attribute", ATTRIBUTE_, _ATTRIBUTE}
  };

#ifdef __GNUC__
__inline
#ifdef __GNUC_STDC_INLINE__
__attribute__ ((__gnu_inline__))
#endif
#endif
const struct dap4_keyword *
dap4_keyword_lookup (str, len)
     register const char *str;
     register unsigned int len;
{
  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
      register int key = hash (str, len);

      if (key <= MAX_HASH_VALUE && key >= 0)
        {
          register const char *s = wordlist[key].name;

          if (*str == *s && !strcmp (str + 1, s + 1))
            return &wordlist[key];
        }
    }
  return 0;
}

