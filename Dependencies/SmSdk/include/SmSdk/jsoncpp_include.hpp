#pragma once

#include "SmSdk/config.hpp"

#if defined(SMSDK_ENABLE_JSONCPP)
#include <json/json.h>
#else
namespace Json
{
// This is a stub, please define `SMSDK_ENABLE_JSONCPP` to use JSONCPP
class Value
{
private:
	char data[0x18];
};
}
#endif