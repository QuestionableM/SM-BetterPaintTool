#pragma once

#include "SmSdk/config.hpp"

#if defined(SMSDK_ENABLE_STEAMAPI)
#include <steam/steam_api.h>
#else
// This is a stub, please define `SMSDK_ENABLE_STEAMAPI` to use Steam API
using HSteamNetConnection = unsigned int;
#endif