#pragma once

#include "SmSdk/config.hpp"
#include "SmSdk/unreferenced_params.hpp"

SMSDK_BEGIN_NAMESPACE

class Task
{
	SDK_PUB virtual ~Task() {}
	SDK_PUB virtual std::int64_t update(float fDeltaTime)
	{
		SMSDK_UNREF(fDeltaTime);
		return 0;
	}
}; // Size: 0x8

static_assert(sizeof(Task) == 0x8, "Task: Incorrect Size");

SMSDK_END_NAMESPACE