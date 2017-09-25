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
void jsonInsertI32(Document * d, char * path, int32_t value, bool & replaced, Document * error)
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
void jsonInsertU32(Document * d, char * path, uint32_t value, bool & replaced, Document * error)
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
void jsonInsertI64(Document * d, char * path, int64_t value, bool & replaced, Document * error)
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
void jsonInsertU64(Document * d, char * path, uint64_t value, bool & replaced, Document * error)
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
void jsonInsertDbl(Document * d, char * path, double value, bool & replaced, Document * error)
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

void jsonParseBool(Document * d, char * path, bool & value, bool & found, Document * error)
{
   Pointer p = Pointer(path);
   if (p.IsValid()) {
      if (p.Get(*d) != nullptr)
      {
         //exists, check that type is boolean
         found = true;
         if (p.Get(*d)->IsBool()) {
            value = p.GetWithDefault(*d, value).GetBool();
         }
         else {
            jsonFormatPtrError(BAD_TYPE, error);
            return void();
         }
      }
      else {
         found = false;
         return void();
      }
   }
   else {
      jsonFormatPtrError(p, error);
   }
}
void jsonParseI32(Document * d, char * path, int32_t & value, bool & found, Document * error)
{
   Pointer p = Pointer(path);
   if (p.IsValid()) {
      if (p.Get(*d) != nullptr)
      {
         //exists, check that type is boolean
         found = true;
         if (p.Get(*d)->IsInt()) {
            value = p.GetWithDefault(*d, value).GetInt();
         }
         else {
            jsonFormatPtrError(BAD_TYPE, error);
            return void();
         }
      }
      else {
         found = false;
         return void();
      }
   }
   else {
      jsonFormatPtrError(p, error);
   }
}
void jsonParseU32(Document * d, char * path, uint32_t & value, bool & found, Document * error)
{
   Pointer p = Pointer(path);
   if (p.IsValid()) {
      if (p.Get(*d) != nullptr)
      {
         //exists, check that type is boolean
         found = true;
         if (p.Get(*d)->IsUint()) {
            value = p.GetWithDefault(*d, value).GetUint();
         }
         else {
            jsonFormatPtrError(BAD_TYPE, error);
            return void();
         }
      }
      else {
         found = false;
         return void();
      }
   }
   else {
      jsonFormatPtrError(p, error);
   }
}
void jsonParseI64(Document * d, char * path, int64_t & value, bool & found, Document * error)
{
   Pointer p = Pointer(path);
   if (p.IsValid()) {
      if (p.Get(*d) != nullptr)
      {
         //exists, check that type is boolean
         found = true;
         if (p.Get(*d)->IsInt64()) {
            value = p.GetWithDefault(*d, value).GetInt64();
         }
         else {
            jsonFormatPtrError(BAD_TYPE, error);
            return void();
         }
      }
      else {
         found = false;
         return void();
      }
   }
   else {
      jsonFormatPtrError(p, error);
   }
}
void jsonParseU64(Document * d, char * path, uint64_t & value, bool & found, Document * error)
{
   Pointer p = Pointer(path);
   if (p.IsValid()) {
      if (p.Get(*d) != nullptr)
      {
         //exists, check that type is boolean
         found = true;
         if (p.Get(*d)->IsUint64()) {
            value = p.GetWithDefault(*d, value).GetUint64();
         }
         else {
            jsonFormatPtrError(BAD_TYPE, error);
            return void();
         }
      }
      else {
         found = false;
         return void();
      }
   }
   else {
      jsonFormatPtrError(p, error);
   }
}
void jsonParseDbl(Document * d, char * path, double & value, bool & found, Document * error)
{
   Pointer p = Pointer(path);
   if (p.IsValid()) {
      if (p.Get(*d) != nullptr)
      {
         //exists, check that type is boolean
         found = true;
         if (p.Get(*d)->IsDouble()) {
            value = p.GetWithDefault(*d, value).GetDouble();
         }
         else {
            jsonFormatPtrError(BAD_TYPE, error);
            return void();
         }
      }
      else {
         found = false;
         return void();
      }
   }
   else {
      jsonFormatPtrError(p, error);
   }
}
void jsonParseFloat(Document * d, char * path, float & value, bool & found, Document * error)
{
   Pointer p = Pointer(path);
   if (p.IsValid()) {
      if (p.Get(*d) != nullptr)
      {
         //exists, check that type is boolean
         found = true;
         if (p.Get(*d)->IsFloat()) {
            value = p.GetWithDefault(*d, value).GetFloat();
         }
         else {
            jsonFormatPtrError(BAD_TYPE, error);
            return void();
         }
      }
      else {
         found = false;
         return void();
      }
   }
   else {
      jsonFormatPtrError(p, error);
   }
}
char * jsonParseString(Document * d, char * path, char * value, bool & found, Document * error)
{
   Pointer p = Pointer(path);
   if (p.IsValid()) {
      if (p.Get(*d) != nullptr)
      {
         //exists, check that type is boolean
         found = true;
         if (p.Get(*d)->IsString()) {
            value = _strdup(p.GetWithDefault(*d, value).GetString());
            return value;
         }
         else {
            jsonFormatPtrError(BAD_TYPE, error);
            return "";
         }
      }
      else {
         found = false;
         return "";
      }
   }
   else {
      jsonFormatPtrError(p, error);
   }
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

DLLEXPORT Value * jsonStructureInfo(Document *d, char * path, int & count, Document * error)
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
