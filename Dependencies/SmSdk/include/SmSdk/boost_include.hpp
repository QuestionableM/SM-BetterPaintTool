#pragma once

#include "SmSdk/config.hpp"

#if defined(SMSDK_ENABLE_BOOST)
#include <boost/uuid/uuid.hpp>
#else
namespace boost
{
	namespace uuids
	{
		class uuid
		{
		private:
			char data[16];
		};
	}
}
#endif