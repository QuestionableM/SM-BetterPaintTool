#pragma once

#include "SmSdk/unreferenced_params.hpp"

class InputTarget
{
public:
	virtual void onKeyPress(int key) { SMSDK_UNREF(key); /* implemented by the game */ }
	virtual void onKeyRelease(int key) { SMSDK_UNREF(key); /* implemented by the game */ }
	virtual void onMouseKeyPress(int mouse_key) { SMSDK_UNREF(mouse_key); /* implemented by the game */ }
	virtual void onMouseKeyRelease(int mouse_key) { SMSDK_UNREF(mouse_key); /* implemented by the game */ }
	virtual void func5() { /* implemented by the game */ }
	virtual void func6() { /* implemented by the game */ }

}; // Size: 0x8

static_assert(sizeof(InputTarget) == 0x8, "InputTarget: Incorrect Size");