#pragma once

#include "SmSdk/unreferenced_params.hpp"
#include "SmSdk/config.hpp"

#if defined(SMSDK_ENABLE_MYGUI)
#include "MyGUI.h"
#define DEFAULT_IMPL(...)
#define DEFAULT_IMPL_UNREF(...)
#else

#define DEFAULT_IMPL(...) { __VA_ARGS__ }
#define DEFAULT_IMPL_UNREF(arg) { SMSDK_UNREF(arg); }

#include <cstddef>
#include <vector>
#include <string>

namespace MyGUI
{
	struct IntSize {
		int width, height;
	};

	struct IntPoint {
		int left, top;
	};

	struct IntCoord {
		int left, top, width, height;
	};

	struct Colour {
		float red, green, blue, alpha;
	};

	
	class Gui {};
	class Widget {};
	class ScrollBar {};
	class TextBox {};
	class LayoutManager {};
}

#endif

namespace MyGUI
{
	class DirectX11Platform {};
}