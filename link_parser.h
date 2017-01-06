#include "olsr_classes.h"
#include <string>
#include "rapidjson/document.h"

using namespace rapidjson;

bool parseLink( string json, O_Link &toPopulate );