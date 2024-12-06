#pragma once

#include "SmSdk/config.hpp"

#if defined(SMSDK_ENABLE_STEAMAPI)
#include <steam/steam_api.h>
#else
using HSteamNetConnection = unsigned int;
#endif