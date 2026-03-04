#pragma once

#include "SmSdk/config.hpp"

#if defined(SMSDK_ENABLE_BOOST)
#include <boost/uuid/uuid.hpp>
#else
// Stub
namespace boost
{
namespace uuids
{
// This is a stub, please define `SMSDK_ENABLE_BOOST` to use Boost UUIDs
class uuid
{
private:
	char data[16];
};
}
}
#endif