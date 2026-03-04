#pragma once

#include "SmSdk/config.hpp"

SMSDK_BEGIN_NAMESPACE

#pragma warning(push)
#pragma warning(disable : 4324)

__declspec(align(16)) class Aligned16Base
{
};

#pragma warning(pop)

SMSDK_END_NAMESPACE