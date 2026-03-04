#pragma once

#include "SmSdk/config.hpp"

SMSDK_BEGIN_NAMESPACE

class InGameGuiManagerInterface
{
	SDK_PUB virtual ~InGameGuiManagerInterface() = default;
}; // Size: 0x8

static_assert(sizeof(InGameGuiManagerInterface) == 0x8, "InGameGuiManagerInterface: Incorrect Size");

SMSDK_END_NAMESPACE