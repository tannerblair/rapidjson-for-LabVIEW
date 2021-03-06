#pragma once
#include "jsonIncludes.h"
struct jsonErrorCluster {
   bool status = false;
   int code = 0;
   char * info[256];
};

const char* kParseErrorStrings[] =
{
   "No error",
   "The document is empty.",
   "The document root must not follow by other values.",
   "Invalid value.", "Missing a name for object member.",
   "Missing a colon after a name of object member.",
   "Missing a comma or '}' after an object member.",
   "Missing a comma or ']' after an array element.",
   "Incorrect hex digit after \\u escape in string." ,
   "The surrogate pair in string is invalid.",
   "Invalid escape character in string.",
   "Missing a closing quotation mark in string.",
   "Invalid encoding in string.",
   "Number too big to be stored in double.",
   "Miss fraction part in number.",
   "Miss exponent in number.",
   "Parsing was terminated.",
   "Unspecific syntax error."
};

const char * kPointerParseErrorStrings[]{
   "none",
   "A path must begin with a '/'",
   "Invalid escape",
   "Invalid percent encoding in URI fragment",
   "A character must percent encoded in URI fragment",
   "Path does not exist",
   "Path does not reference an object",
   "Path does not reference an array",
   "Path does not reference an object or array",
   "Type requested does not match type at path",
};

enum kPointerParseErrorType {
   NONE,
   NO_SLASH,
   BAD_ESCAPE,
   BAD_PERCENT,
   BAD_URI,
   NOT_A_PATH,
   NOT_AN_OBJECT,
   NOT_AN_ARRAY,
   NOT_A_STRUCTURE,
   BAD_TYPE
};

