// lvrjs.cpp : Defines the exported functions for the DLL application.
//

//#include "stdafx.h"
#include "lvrjs.h"


Document * jsonCreate(char * json, Document * error) 
{
   string buffer = json;
   Document * d = new Document();
   ParseResult ok = d->Parse(buffer);
   if (!ok)
      jsonFormatParseError(ok, error);

   return d;
}

int jsonQuery(Document * d, char * path, Document * error)
{
   Pointer p = Pointer(path);
   if (p.IsValid()) {
      if (p.Get(*d) != nullptr)
      {
         Value * v = Pointer(path).Get(*d);
         return v->GetType();
      }
      else {
         return -1;
      }
   }
   else {
      jsonFormatPtrError(p, error);
      return -1;
   }
}

void jsonInsertBool(Document * d, char * path, bool value, bool & replaced, Document * error)
{
   Pointer p = Pointer(path);
   if (p.IsValid()) {
      //Good path
      replaced = p.Get(*d) != nullptr;
      p.Set(*d, value);
   }
   else {
      jsonFormatPtrError(p, error);
   }
}
void jsonInsertInt(Document * d, char * path, int32_t value, bool & replaced, Document * error)
{
   Pointer p = Pointer(path);
   if (p.IsValid()) {
      replaced = p.Get(*d) != nullptr;
      p.Set(*d, value);
   }
   else {
      jsonFormatPtrError(p, error);
   }
}
void jsonInsertUint(Document * d, char * path, uint32_t value, bool & replaced, Document * error)
{
   Pointer p = Pointer(path);
   if (p.IsValid()) {
      replaced = p.Get(*d) != nullptr;
      p.Set(*d, value);
   }
   else {
      jsonFormatPtrError(p, error);
   }
}
void jsonInsertInt64(Document * d, char * path, int64_t value, bool & replaced, Document * error)
{
   Pointer p = Pointer(path);
   if (p.IsValid()) {
      replaced = p.Get(*d) != nullptr;
      p.Set(*d, value);
   }
   else {
      jsonFormatPtrError(p, error);
   }
}
void jsonInsertUint64(Document * d, char * path, uint64_t value, bool & replaced, Document * error)
{
   Pointer p = Pointer(path);
   if (p.IsValid()) {
      replaced = p.Get(*d) != nullptr;
      p.Set(*d, value);
   }
   else {
      jsonFormatPtrError(p, error);
   }
}
void jsonInsertDouble(Document * d, char * path, double value, bool & replaced, Document * error)
{
   Pointer p = Pointer(path);
   if (p.IsValid()) {
      replaced = p.Get(*d) != nullptr;
      p.Set(*d, value);
   }
   else {
      jsonFormatPtrError(p, error);
   }
}
void jsonInsertFloat(Document * d, char * path, float value, bool & replaced, Document * error)
{
   Pointer p = Pointer(path);
   if (p.IsValid()) {
      replaced = p.Get(*d) != nullptr;
      p.Set(*d, value);
   }
   else {
      jsonFormatPtrError(p, error);
   }
}
void jsonInsertString(Document * d, char * path, char * value, bool & replaced, Document * error)
{
   Pointer p = Pointer(path);
   if (p.IsValid()) {
      replaced = p.Get(*d) != nullptr;
      p.Set(*d, value);
   }
   else {
      jsonFormatPtrError(p, error);
   }
}
void jsonInsertValue(Document * d, char * path, Value * value, bool & replaced, Document * error)
{

   Pointer p = Pointer(path);
   if (p.IsValid()) {
      replaced = p.Get(*d) != nullptr;
      Document newdoc;
      newdoc.CopyFrom(*value, d->GetAllocator());
      p.Set(*d, newdoc);
   }
   else
      jsonFormatPtrError(p, error);
}

bool jsonParseBool(Document * d, char * path, bool & value, Document * error)
{
   Pointer p = Pointer(path);
   if (p.IsValid()) {
      if (p.Get(*d) != nullptr)
      {
         return jsonConvert(p.Get(*d), value);
      }
   }
   else {
      jsonFormatPtrError(p, error);
   }
   return false;
}
bool jsonParseInt(Document * d, char * path, int32_t & value, Document * error)
{
   Pointer p = Pointer(path);
   if (p.IsValid()) {
      if (p.Get(*d) != nullptr)
      {
         return jsonConvert(p.Get(*d), value);
      }
   }
   else {
      jsonFormatPtrError(p, error);
   }
   return false;
}
bool jsonParseUint(Document * d, char * path, uint32_t & value, Document * error)
{
   Pointer p = Pointer(path);
   if (p.IsValid()) {
      if (p.Get(*d) != nullptr)
      {
         return jsonConvert(p.Get(*d), value);
      }
   }
   else {
      jsonFormatPtrError(p, error);
   }
   return false;
}
bool jsonParseInt64(Document * d, char * path, int64_t & value, Document * error)
{
   Pointer p = Pointer(path);
   if (p.IsValid()) {
      if (p.Get(*d) != nullptr)
      {
         return jsonConvert(p.Get(*d), value);
      }
   }
   else {
      jsonFormatPtrError(p, error);
   }
   return false;
}
bool jsonParseUint64(Document * d, char * path, uint64_t & value, Document * error)
{
   Pointer p = Pointer(path);
   if (p.IsValid()) {
      if (p.Get(*d) != nullptr)
      {
         return jsonConvert(p.Get(*d), value);
      }
   }
   else {
      jsonFormatPtrError(p, error);
   }
   return false;
}
bool jsonParseDouble(Document * d, char * path, double & value, Document * error)
{
   Pointer p = Pointer(path);
   if (p.IsValid()) {
      if (p.Get(*d) != nullptr)
      {
         return jsonConvert(p.Get(*d), value);
      }
   }
   else {
      jsonFormatPtrError(p, error);
   }
   return false;
}
bool jsonParseFloat(Document * d, char * path, float & value, Document * error)
{
   Pointer p = Pointer(path);
   if (p.IsValid()) {
      if (p.Get(*d) != nullptr)
      {
         return jsonConvert(p.Get(*d), value);
      }
   }
   else {
      jsonFormatPtrError(p, error);
   }
   return false;
}
char * jsonParseString(Document * d, char * path, bool & success, Document * error)
{
   Pointer p = Pointer(path);
   if (p.IsValid()) {
      if (p.Get(*d) != nullptr)
      {
         StringBuffer temp;
         success = jsonConvert(p.Get(*d), temp);
         return _strdup(temp.GetString());
      }
   }
   else {
      jsonFormatPtrError(p, error);
   }
   return false;
}

char * jsonToString(Document * d, char * path, bool prettyPrint, Document * error)
{
   if (jsonQuery(d, path, error))
   {
      Value * v = Pointer(path).Get(*d);
      StringBuffer buffer;
      buffer.Clear();
      if (!prettyPrint) {
         Writer<rapidjson::StringBuffer> writer(buffer);
         v->Accept(writer);
      }
      else {
         PrettyWriter<StringBuffer> writer(buffer);
         v->Accept(writer);
      }
      char * result = _strdup(buffer.GetString());
      result[buffer.GetLength()] = '\0';
      return result;
   }
   return "null";
}

char * jsonKey(Document * d, char * path, int index, Document * error) 
{
   Pointer p = Pointer(path);
   if (p.IsValid()) {
      if (p.Get(*d) != nullptr)
      {
         if (p.Get(*d)->IsObject())
         {
            string result;
            return _strdup((p.Get(*d)->MemberBegin() + index)->name.GetString());
         }
         else {
            jsonFormatPtrError(6, error);
            return "";
         }
      }
      else {
         jsonFormatPtrError(5, error);
         return "";
      }
   }
   else {
      jsonFormatPtrError(p, error);
      return "";
   }
}

Value * jsonStructureInfo(Document *d, char * path, int & count, Document * error)
{
   Pointer p = Pointer(path);
   if (p.IsValid()) {
      if (p.Get(*d) != nullptr)
      {
         if (p.Get(*d)->IsObject())
         {
            count = p.Get(*d)->MemberCount();
            return p.Get(*d);
         }
         else if (p.Get(*d)->IsArray()) {
            count = p.Get(*d)->Size();
            return p.Get(*d);
         }
         else {
            jsonFormatPtrError(NOT_A_STRUCTURE, error);
         }
      }
      else {
         jsonFormatPtrError(NOT_A_PATH, error);
      }
      jsonFormatPtrError(p, error);
   }
   count = -1;
   return nullptr;
}
Document * jsonClone(Document * d, char * path, Document * error)
{
   Pointer p = Pointer(path);
   if (p.IsValid()) {
      if (p.Get(*d) != nullptr)
      {
         Document * newdoc = new Document();
         newdoc->CopyFrom(*p.Get(*d), newdoc->GetAllocator());
         return newdoc;
      }
      else {
         jsonFormatPtrError(5, error);
         return nullptr;
      }
   }
   else {
      jsonFormatPtrError(p, error);
      return nullptr;
   }
}

int jsonDeleteKey(Document * d, char * path, Document * error)
{
   Pointer p = Pointer(path);
   if (p.IsValid())
      return p.Erase(*d);
   jsonFormatPtrError(p, error);
   return 0;
}

void jsonClose(Document * d, Document * error)
{
   delete d;
}

void jsonSetErrorInfo(Document * error, bool status, int32_t code, const char * source)
{
   Pointer("/status").Set(*error, status, error->GetAllocator());
   Pointer("/code").Set(*error, code, error->GetAllocator());
   Pointer("/source").Set(*error, source, error->GetAllocator());


}

void jsonFormatPtrError(Pointer ptr, Document * error)
{
   string err;
   char buffer[21];
   _itoa_s(ptr.GetParseErrorOffset(), buffer, 10);
   err += "Invalid Path Error\n";
   err += kPointerParseErrorStrings[ptr.GetParseErrorCode()];
   err += "\n";
   err += "Offset: ";
   err += buffer;

   jsonSetErrorInfo(error, true, 1000 + ptr.GetParseErrorCode(), err.c_str());
}

void jsonFormatPtrError(int code, Document * error)
{
   string err;
   err += "Invalid Path Error\n";
   err += kPointerParseErrorStrings[code];

   jsonSetErrorInfo(error, true, 1000 + code, err.c_str());
}

void jsonFormatParseError(ParseResult p, Document * error) {
  
   string err;
   char buffer[21];
   _itoa_s(p.Offset(), buffer, 10);
   err += "Parse Error\n";
   err += kParseErrorStrings[p.Code()];
   err += "\n";
   err += "Offset: ";
   err += buffer;
   jsonSetErrorInfo(error, true, p.Code(), err.c_str());
}


//------------------CONVERTERS-----------------//
//Returns true if conversion was successful, false, if failed.
//Defaulting will be handled in LabVIEW.
bool jsonConvert(Value * v, bool & value) {
   if (v->IsBool()) {
      value = v->GetBool();
      return true;
   }
   //Check if value is a string
   else if (v->IsString()) {
      if (strcmp(v->GetString(), "true") == 0) {
         value = true;
         return true;
      }
      else if (strcmp(v->GetString(), "false") == 0) {
         value = false;
         return true;
      }
      else {
         value = false;
         return false;
      }
   }
   else if (v->IsNumber()) {
      value = (v->GetDouble() != 0);
      return true;
   }
   else {
      return false;
   }
}
bool jsonConvert(Value * v, int32_t & value) 
{
   if (v->IsInt()) {
      value = v->GetInt();
      return true;
   }
   //Check if value is a string
   else if (v->IsString()) {
      return (sscanf_s(v->GetString(), "%d", & value) == 1);
   }
   else if (v->IsBool()) {
      value = v->GetBool();
      return true;
   }
   else {
      return false;
   }
}
bool jsonConvert(Value * v, int64_t & value) {
   if (v->IsInt64()) {
      value = v->GetInt64();
      return true;
   }
   //Check if value is a string
   else if (v->IsString()) {
      return (sscanf_s(v->GetString(), "%lld", & value) == 1);
   }
   else if (v->IsBool()) {
      value = v->GetBool();
      return true;
   }
   else {
      return false;
   }
}
bool jsonConvert(Value * v, uint32_t & value) {
   if (v->IsUint()) {
      value = v->GetUint();
      return true;
   }
   //Check if value is a string
   else if (v->IsString()) {
      return (sscanf_s(v->GetString(), "%u", & value) == 1);
   }
   else if (v->IsBool()) {
      value = v->GetBool();
      return true;
   }
   else {
      return false;
   }
}
bool jsonConvert(Value * v, uint64_t & value) {
   if (v->IsUint64()) {
      value = v->GetUint64();
      return true;
   }
   //Check if value is a string
   else if (v->IsString()) {
      return (sscanf_s(v->GetString(), "%llu", & value) == 1);
   }
   else if (v->IsBool()) {
      value = v->GetBool();
      return true;
   }
   else {
      return false;
   }
}
bool jsonConvert(Value * v, float & value) {
   if (v->IsFloat()) {
      value = v->GetFloat();
      return true;
   }
   //Check if value is a string
   else if (v->IsString()) {
      return (sscanf_s(v->GetString(), "%f", & value) == 1);
   }
   else if (v->IsBool()) {
      value = v->GetBool();
      return true;
   }
   else {
      return false;
   }
}
bool jsonConvert(Value * v, double & value) {
   if (v->IsDouble()) {
      value = v->GetDouble();
      return true;
   }
   //Check if value is a string
   else if (v->IsString()) {
      return (sscanf_s(v->GetString(), "%lf", & value) == 1);
   }
   else if (v->IsBool()) {
      value = v->GetBool();
      return true;
   }
   else {
      return false;
   }
}
bool jsonConvert(Value * v, StringBuffer & value) {
   if (v->IsArray() || v->IsObject() || v->IsNull()) {
      return false;
   }
   for (int i = 0; i < v->GetStringLength(); i++)
   {
      value.Put(v->GetString()[i]);
   }
}