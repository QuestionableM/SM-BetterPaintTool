#pragma once

struct IToolImpl
{
	virtual ~IToolImpl() = default;
}; // Size: 0x8

static_assert(sizeof(IToolImpl) == 0x8, "IToolImpl: Incorrect Size");