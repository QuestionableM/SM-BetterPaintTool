#pragma once

#include "SmSdk/unreferenced_params.hpp"
#include "SmSdk/config.hpp"

#if defined(SMSDK_ENABLE_MYGUI)
#include "MyGUI.h"
#define DEFAULT_IMPL(...)
#define DEFAULT_IMPL_UNREF(...)
#else

#define DEFAULT_IMPL(...) {__VA_ARGS__}
#define DEFAULT_IMPL_UNREF(arg) \
	{ \
		SMSDK_UNREF(arg); \
	}

#include <cstddef>
#include <vector>
#include <string>

namespace MyGUI
{
struct IntSize
{
	int width, height;
};

struct IntPoint
{
	int left, top;
};

struct IntCoord
{
	int left, top, width, height;
};

struct Colour
{
	float red, green, blue, alpha;
};

// This is a stub, please define `SMSDK_ENABLE_MYGUI` to use MyGUI
class Gui
{
};
// This is a stub, please define `SMSDK_ENABLE_MYGUI` to use MyGUI
class Widget
{
};
// This is a stub, please define `SMSDK_ENABLE_MYGUI` to use MyGUI
class ScrollBar
{
};
// This is a stub, please define `SMSDK_ENABLE_MYGUI` to use MyGUI
class TextBox
{
};
// This is a stub, please define `SMSDK_ENABLE_MYGUI` to use MyGUI
class LayoutManager
{
};
// This is a stub, please define `SMSDK_ENABLE_MYGUI` to use MyGUI
class Button
{
};
// This is a stub, please define `SMSDK_ENABLE_MYGUI` to use MyGUI
class ItemBox
{
};
}

#endif

namespace MyGUI
{
class DirectX11Platform
{
};
}