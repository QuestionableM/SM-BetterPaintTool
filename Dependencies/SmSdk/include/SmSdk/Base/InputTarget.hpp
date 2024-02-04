#pragma once

class InputTarget
{
public:
	virtual ~InputTarget() = default;

}; // Size: 0x8

static_assert(sizeof(InputTarget) == 0x8, "InputTarget: Incorrect Size");