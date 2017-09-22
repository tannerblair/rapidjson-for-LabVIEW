// lvrjs.cpp : Defines the exported functions for the DLL application.
//

//#include "stdafx.h"
#include "lvrjs.h"
#include <sstream>


Document * jsonCreate(const char * json, Document * error) 
{
   Document * d = new Document();
   char * jsonBuffer = _strdup(json);
   ParseResult ok = d->Parse(jsonBuffer);
   if (!ok)
      jsonFormatParseError(ok, error);

   return d;
}

int jsonQuery(Document * d, char * path, Document * error)
{
   Pointer p = Pointer(path);
   if (p.IsValid()) {
      Value * v = Pointer(path).Get(*d);
      if (v != nullptr) {
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
void jsonInsertBool(Document * d, char * path, bool value, Document * error)
{
   Pointer p = Pointer(path);
   if (p.IsValid()) {
      p.Set(*d, value);
   }
   else {
      jsonFormatPtrError(p, error);
   }

}
void jsonInsertI32(Document * d, char * path, int32_t value, Document * error)
{
   Pointer p = Pointer(path);
   if (p.IsValid())
      p.Set(*d, value);
   else
      jsonFormatPtrError(p, error);
}
void jsonInsertU32(Document * d, char * path, uint32_t value, Document * error)
{
   Pointer p = Pointer(path);
   if (p.IsValid())
      p.Set(*d, value);
   else
      jsonFormatPtrError(p, error);
}
void jsonInsertI64(Document * d, char * path, int64_t value, Document * error)
{
   Pointer p = Pointer(path);
   if (p.IsValid())
      p.Set(*d, value);
   else
      jsonFormatPtrError(p, error);
}
void jsonInsertU64(Document * d, char * path, uint64_t value, Document * error)
{
   Pointer p = Pointer(path);
   if (p.IsValid())
      p.Set(*d, value);
   else
      jsonFormatPtrError(p, error);
}
void jsonInsertDbl(Document * d, char * path, double value, Document * error)
{
   Pointer p = Pointer(path);
   if (p.IsValid())
      p.Set(*d, value);
   else
      jsonFormatPtrError(p, error);
}
void jsonInsertFloat(Document * d, char * path, float value, Document * error)
{
   Pointer p = Pointer(path);
   if (p.IsValid())
      p.Set(*d, value);
   else
      jsonFormatPtrError(p, error);
}
void jsonInsertString(Document * d, char * path, char * value, Document * error)
{
   Pointer p = Pointer(path);
   if (p.IsValid())
      p.Set(*d, value);
   else
      jsonFormatPtrError(p, error);
}

void jsonInsertValue(Document * d, char * path, Value * value, Document * error)
{

   Pointer p = Pointer(path);
   if (p.IsValid()) {
      Document newdoc;
      newdoc.CopyFrom(*value, d->GetAllocator());
      p.Set(*d, newdoc);
   }
   else
      jsonFormatPtrError(p, error);
}

bool jsonParseBool(Document * d, char * path, bool value, Document * error)
{
   Pointer p = Pointer(path);
   if (p.IsValid())
      return p.GetWithDefault(*d, value).GetBool();
   jsonFormatPtrError(p, error);
   return value;
}

int32_t jsonParseI32(Document * d, char * path, int32_t value, Document * error)
{
   Pointer p = Pointer(path);
   if (p.IsValid())
      return p.GetWithDefault(*d, value).GetInt();
   jsonFormatPtrError(p, error);
   return value;
}

uint32_t jsonParseU32(Document * d, char * path, uint32_t value, Document * error)
{
   Pointer p = Pointer(path);
   if (p.IsValid())
      return p.GetWithDefault(*d, value).GetUint();
   jsonFormatPtrError(p, error);
   return value;
}

int64_t jsonParseI64(Document * d, char * path, int64_t value, Document * error)
{
   Pointer p = Pointer(path);
   if (p.IsValid())
      return p.GetWithDefault(*d, value).GetInt64();
   jsonFormatPtrError(p, error);
   return value;
}

uint64_t jsonParseU64(Document * d, char * path, uint64_t value, Document * error)
{
   Pointer p = Pointer(path);
   if (p.IsValid())
      return p.GetWithDefault(*d, value).GetUint64();
   jsonFormatPtrError(p, error);
   return value;
}

double jsonParseDbl(Document * d, char * path, double value, Document * error)
{
   Pointer p = Pointer(path);
   if (p.IsValid())
      return p.GetWithDefault(*d, value).GetDouble();
   jsonFormatPtrError(p, error);
   return value;
}

float jsonParseFloat(Document * d, char * path, float value, Document * error)
{
   Pointer p = Pointer(path);
   if (p.IsValid())
      return p.GetWithDefault(*d, value).GetFloat();
   jsonFormatPtrError(p, error);
   return value;
}

const char * jsonParseString(Document * d, char * path, char * value, Document * error)
{
   Pointer p = Pointer(path);
   if (p.IsValid())
      return p.GetWithDefault(*d, value).GetString();
   jsonFormatPtrError(p, error);
   return value;
}

const char * jsonToString(Document * d, char * path, bool prettyPrint, Document * error)
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
      char * output = _strdup(buffer.GetString());
      *(output + buffer.GetLength()) = '\0';

      return output;
   }
   return "null";
}
//!!!This is the devil. I can't get it working.
char * jsonKeys(Document * d, char * path, Document * error) 
{
   Pointer p = Pointer(path);
   if (p.IsValid()) {
      char result[1024] = "";
      int i = 0;
      strcat_s(result, 1024, p.Get(*d)->MemberBegin()->name.GetString());
      for (Value::ConstMemberIterator itr = p.Get(*d)->MemberBegin() + 1;
         itr != p.Get(*d)->MemberEnd(); itr++)
      {
         strcat_s(result, 1024, ",");
         strcat_s(result, 1024, p.Get(*d)->MemberBegin()->name.GetString());
      }
      return result;
   }
   else {
      jsonFormatPtrError(p, error);
   }
   return "";
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

void jsonSetErrorInfo(Document * error, bool status, int32_t code, char * source)
{
   Pointer("/status").Set(*error, status, error->GetAllocator());
   Pointer("/code").Set(*error, code, error->GetAllocator());
   Pointer("/source").Set(*error, source, error->GetAllocator());


}

void jsonFormatPtrError(Pointer ptr, Document * error)
{
   char * err = new char[256];

   sprintf_s(
      err, 256,
      "Invalid Path Error\n%s\noffset: %d ",
      kPointerParseErrorStrings[ptr.GetParseErrorCode()],
      ptr.GetParseErrorOffset()
   );

   jsonSetErrorInfo(error, true, 1000 + ptr.GetParseErrorCode(), err);
}

void jsonFormatPtrError(int code, Document * error)
{
   char * err = new char[256];

   sprintf_s(
      err, 256,
      "Invalid Path Error\n%s",
      kPointerParseErrorStrings[code]
   );

   jsonSetErrorInfo(error, true, 1000 + code, err);
}

void jsonFormatParseError(ParseResult p, Document * error) {
  
   char * err = new char[256];
   sprintf_s(
      err,
      256,
      "\nParse Error\n%s\noffset: %d ",
      kParseErrorStrings[p.Code()],
      p.Offset()
   );

   jsonSetErrorInfo(error, true, p.Code(), err);
}
