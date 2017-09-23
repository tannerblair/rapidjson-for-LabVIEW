// lvrjs.cpp : Defines the exported functions for the DLL application.
//

//#include "stdafx.h"
#include "lvrjs.h"
#include <sstream>


Document * jsonCreate(string json, Document * error) 
{
   Document * d = new Document();
   ParseResult ok = d->Parse(json);
   if (!ok)
      jsonFormatParseError(ok, error);

   return d;
}

int jsonQuery(Document * d, string path, Document * error)
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
void jsonInsertBool(Document * d, string path, bool value, Document * error)
{
   Pointer p = Pointer(path);
   if (p.IsValid()) {
      p.Set(*d, value);
   }
   else {
      jsonFormatPtrError(p, error);
   }

}
void jsonInsertI32(Document * d, string path, int32_t value, Document * error)
{
   Pointer p = Pointer(path);
   if (p.IsValid())
      p.Set(*d, value);
   else
      jsonFormatPtrError(p, error);
}
void jsonInsertU32(Document * d, string path, uint32_t value, Document * error)
{
   Pointer p = Pointer(path);
   if (p.IsValid())
      p.Set(*d, value);
   else
      jsonFormatPtrError(p, error);
}
void jsonInsertI64(Document * d, string path, int64_t value, Document * error)
{
   Pointer p = Pointer(path);
   if (p.IsValid())
      p.Set(*d, value);
   else
      jsonFormatPtrError(p, error);
}
void jsonInsertU64(Document * d, string path, uint64_t value, Document * error)
{
   Pointer p = Pointer(path);
   if (p.IsValid())
      p.Set(*d, value);
   else
      jsonFormatPtrError(p, error);
}
void jsonInsertDbl(Document * d, string path, double value, Document * error)
{
   Pointer p = Pointer(path);
   if (p.IsValid())
      p.Set(*d, value);
   else
      jsonFormatPtrError(p, error);
}
void jsonInsertFloat(Document * d, string path, float value, Document * error)
{
   Pointer p = Pointer(path);
   if (p.IsValid())
      p.Set(*d, value);
   else
      jsonFormatPtrError(p, error);
}
void jsonInsertString(Document * d, string path, string value, Document * error)
{
   Pointer p = Pointer(path);
   if (p.IsValid())
      p.Set(*d, value);
   else
      jsonFormatPtrError(p, error);
}

void jsonInsertValue(Document * d, string path, Value * value, Document * error)
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

bool jsonParseBool(Document * d, string path, bool value, Document * error)
{
   Pointer p = Pointer(path);
   if (p.IsValid())
      return p.GetWithDefault(*d, value).GetBool();
   jsonFormatPtrError(p, error);
   return value;
}

int32_t jsonParseI32(Document * d, string path, int32_t value, Document * error)
{
   Pointer p = Pointer(path);
   if (p.IsValid())
      return p.GetWithDefault(*d, value).GetInt();
   jsonFormatPtrError(p, error);
   return value;
}

uint32_t jsonParseU32(Document * d, string path, uint32_t value, Document * error)
{
   Pointer p = Pointer(path);
   if (p.IsValid())
      return p.GetWithDefault(*d, value).GetUint();
   jsonFormatPtrError(p, error);
   return value;
}

int64_t jsonParseI64(Document * d, string path, int64_t value, Document * error)
{
   Pointer p = Pointer(path);
   if (p.IsValid())
      return p.GetWithDefault(*d, value).GetInt64();
   jsonFormatPtrError(p, error);
   return value;
}

uint64_t jsonParseU64(Document * d, string path, uint64_t value, Document * error)
{
   Pointer p = Pointer(path);
   if (p.IsValid())
      return p.GetWithDefault(*d, value).GetUint64();
   jsonFormatPtrError(p, error);
   return value;
}

double jsonParseDbl(Document * d, string path, double value, Document * error)
{
   Pointer p = Pointer(path);
   if (p.IsValid())
      return p.GetWithDefault(*d, value).GetDouble();
   jsonFormatPtrError(p, error);
   return value;
}

float jsonParseFloat(Document * d, string path, float value, Document * error)
{
   Pointer p = Pointer(path);
   if (p.IsValid())
      return p.GetWithDefault(*d, value).GetFloat();
   jsonFormatPtrError(p, error);
   return value;
}

const string jsonParseString(Document * d, string path, string value, Document * error)
{
   Pointer p = Pointer(path);
   if (p.IsValid())
      return p.GetWithDefault(*d, value).GetString();
   jsonFormatPtrError(p, error);
   return value;
}

const string jsonToString(Document * d, string path, bool prettyPrint, Document * error)
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
      return buffer.GetString();
   }
   return "null";
}
//!!!This is the devil. I can't get it working.
string jsonKeys(Document * d, string path, Document * error) 
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

Document * jsonClone(Document * d, string path, Document * error)
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

int jsonDeleteKey(Document * d, string path, Document * error)
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

void jsonSetErrorInfo(Document * error, bool status, int32_t code, string source)
{
   Pointer("/status").Set(*error, status, error->GetAllocator());
   Pointer("/code").Set(*error, code, error->GetAllocator());
   Pointer("/source").Set(*error, source, error->GetAllocator());


}

void jsonFormatPtrError(Pointer ptr, Document * error)
{
   string err;

   err += "Invalid Path Error\n";
   err += kPointerParseErrorStrings[ptr.GetParseErrorCode()];
   err += "\n";
   err += "Offset: ";
   err += ptr.GetParseErrorOffset();

   jsonSetErrorInfo(error, true, 1000 + ptr.GetParseErrorCode(), err);
}

void jsonFormatPtrError(int code, Document * error)
{
   string err;
   err += "Invalid Path Error\n";
   err += kPointerParseErrorStrings[code];

   jsonSetErrorInfo(error, true, 1000 + code, err);
}

void jsonFormatParseError(ParseResult p, Document * error) {
  
   string err = new char[256];

   err += "Parse Error\n";
   err += kParseErrorStrings[p.Code()];
   err += "\n";
   err += "Offset: ";
   err += p.Offset();

   jsonSetErrorInfo(error, true, p.Code(), err);
}
