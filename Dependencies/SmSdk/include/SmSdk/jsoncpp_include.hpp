#pragma once

#include "SmSdk/config.hpp"

#if defined(SMSDK_ENABLE_JSONCPP)
#include <json/json.h>
#else
namespace Json
{
	class Value {};
}
#endif