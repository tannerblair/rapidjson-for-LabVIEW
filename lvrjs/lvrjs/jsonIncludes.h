#pragma once
#define DLLEXPORT __declspec(dllexport)
#define RAPIDJSON_HAS_STDSTRING 1

#include "jsonErrors.h"
#include "jsonConstants.h"
#include "rapidjson\document.h"
#include "rapidjson\stringbuffer.h"
#include "rapidjson\writer.h"
#include "rapidjson\prettywriter.h"
#include "rapidjson\pointer.h"
#include <inttypes.h>



using namespace rapidjson;
using namespace std;