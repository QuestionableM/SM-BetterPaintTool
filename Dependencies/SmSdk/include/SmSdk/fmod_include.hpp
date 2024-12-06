#pragma once

#include "SmSdk/config.hpp"

#if defined(SMSDK_ENABLE_FMOD)
#include <fmod/fmod_studio.hpp>
#include <fmod/fmod.hpp>
#else
namespace FMOD
{
	namespace Studio
	{
		class System {};
	}

	class System {};
}

struct FMOD_ADVANCEDSETTINGS
{
private:
	char pad_data[104];
};
#endif