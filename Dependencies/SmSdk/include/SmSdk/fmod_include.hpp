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
// This is a stub, please define `SMSDK_ENABLE_FMOD` to use FMOD
class System
{
};
}

// This is a stub, please define `SMSDK_ENABLE_FMOD` to use FMOD
class System
{
};
}

// This is a stub, please define `SMSDK_ENABLE_FMOD` to use FMOD
struct FMOD_ADVANCEDSETTINGS
{
private:
	char pad_data[104];
};
#endif