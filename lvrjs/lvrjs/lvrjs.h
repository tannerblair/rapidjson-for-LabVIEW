#pragma once
#define DLLEXPORT __declspec(dllexport)
#define RAPIDJSON_HAS_STDSTRING 1
#include "jsonConstants.h"
#include "rapidjson\document.h"
#include "rapidjson\stringbuffer.h"
#include "rapidjson\writer.h"
#include "rapidjson\prettywriter.h"
#include "rapidjson\pointer.h"

using namespace rapidjson;
using namespace std;

const enum kErrorType : uint32_t { noError, parse, invalidPath };

// This node creates a JSON reference.If a JSON string is supplied this 
//JSON structure goes into the reference.If it's an empty string an empty 
//JSON structure is created. 
DLLEXPORT Document * jsonCreate(char * json, Document * error);

//This node allows for identifying if a JSON property or array element exists 
//and the type of the value at that location. 
DLLEXPORT int jsonQuery(Document * d, char * path, Document * error);

//This node will insert a JSON substructure as specified by path.If this path 
//matches an existing property in the JSON it we be replaced.If no path is 
//specified the substructure is appended to the end of the JSON.
//The control label of the parent control wired to anything(such as a cluster label) 
//is ignored when a path is specified.Instead the last property name in path is 
//used as the key for the inserted property.Children of the parent controls wired to 
//anything will utilize their control label for their property names.
DLLEXPORT void  jsonInsertBool(Document * d, char * path, bool value, bool & replaced, Document * error);
DLLEXPORT void  jsonInsertI32(Document * d, char * path, int32_t value, bool & replaced, Document * error);
DLLEXPORT void  jsonInsertU32(Document * d, char * path, uint32_t value, bool & replaced, Document * error);
DLLEXPORT void  jsonInsertI64(Document * d, char * path, int64_t value, bool & replaced, Document * error);
DLLEXPORT void  jsonInsertU64(Document * d, char * path, uint64_t value, bool & replaced, Document * error);
DLLEXPORT void  jsonInsertDbl(Document * d, char * path, double value, bool & replaced, Document * error);
DLLEXPORT void  jsonInsertFloat(Document * d, char * path, float value, bool & replaced, Document * error);
DLLEXPORT void  jsonInsertString(Document * d, char * path, char * value, bool & replaced, Document * error);
DLLEXPORT void  jsonInsertValue(Document * d, char * path, Value * value, bool & replaced, Document * error);

DLLEXPORT void  jsonParseBool(Document * d, char * path, bool & value, bool & found, Document * error);
DLLEXPORT void  jsonParseI32(Document * d, char * path, int32_t & value, bool & found, Document * error);
DLLEXPORT void  jsonParseU32(Document * d, char * path, uint32_t & value, bool & found, Document * error);
DLLEXPORT void  jsonParseI64(Document * d, char * path, int64_t & value, bool & found, Document * error);
DLLEXPORT void  jsonParseU64(Document * d, char * path, uint64_t & value, bool & found, Document * error);
DLLEXPORT void  jsonParseDbl(Document * d, char * path, double & value, bool & found, Document * error);
DLLEXPORT void  jsonParseFloat(Document * d, char * path, float & value, bool & found, Document * error);
DLLEXPORT char * jsonParseString(Document * d, char * path, char * value, bool & found, Document * error);

//Produces a JSON string from a JSON Reference
DLLEXPORT char * jsonToString(Document * d, char * path, bool prettyPrint, Document * error);
   
//Provided a JSON ref and a path this returns an array of keys.The keys returned are the 
//first level of the hierarchy at the give path; e.g this does not recursively navigate 
//through the tree and return the entire hierarchy of keys at a given path.
//This does not recurse and send all the children of the entire structure.
DLLEXPORT char * jsonKey(Document * d, char * path, int index, Document * error);
 
DLLEXPORT Value * jsonStructureInfo(Document *d, char * path, int & count, Document * error);
//Creates a new copy of a given reference.If no path is provided the entire reference is 
//copied.If a path is provided the copy contains the JSON at that path only.
DLLEXPORT Document * jsonClone(Document * d, char * path, Document * error);

//Deletes a property as specified at a particular path/index. 
//Remove index input for all these VIs.We can remove length if we have array syntax for ranges in the path.
DLLEXPORT int jsonDeleteKey(Document * d, char * path, Document * error);

//Destroys the JSON structure in memory. 
DLLEXPORT void jsonClose(Document * d, Document * error);

DLLEXPORT void jsonSetErrorInfo(Document * error, bool status, int32_t code, const char * source);

DLLEXPORT void jsonFormatPtrError(Pointer ptr, Document * error);
DLLEXPORT void jsonFormatPtrError(int code, Document * error);

DLLEXPORT void jsonFormatParseError(ParseResult p, Document * error);

