// lvrjstester.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "lvrjs.h"
#include <string>



using namespace std;
int main()
{
   char * jsonString = "{\"TestingTesting\": {\"World\": [0, 2, 4, 6, 8]}}";
   char * jsonString2 = "{\"Barry\": {\"Blair\": [1, 3, 5, 7, 9]}}";
   Document * error = jsonCreate("{}", nullptr);
   Document * d = jsonCreate(jsonString, error);
   Document *d1 = jsonCreate(jsonString2, error);
   const char * test = jsonKeys(d, "", error);
   
   cout << test;
   Value str = Value("test");
   jsonInsertValue(d, "/Hello/World", d1, error);
   cout << jsonToString(d, "",false, error) << "\n";
   cout << jsonToString(d1, "",false,  error);

   jsonClose(d, nullptr);
   std::cin.ignore();
   return 0;

}