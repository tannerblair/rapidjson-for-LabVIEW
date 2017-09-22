#pragma once

const char* kTypeNames[] =
{ 
   "Null", 
   "False", 
   "True", 
   "Object", 
   "Array", 
   "String", 
   "Number" 
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
   "Invalid percent encoding in URI fragment"
   "A character must percent encoded in URI fragment"
   "Path does not exist"
};