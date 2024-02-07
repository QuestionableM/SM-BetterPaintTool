#pragma once

#include "SmSdk/Util/StaticVariable.hpp"

class StaticValues
{
public:
	using PaintToolPaintLimiterType = StaticVariable<std::int32_t, 0x3F060D>;
	using PaintToolEraseLimiterType = StaticVariable<std::int32_t, 0x3F0D9B>;

	//A limiter for paint tool paint function
	static PaintToolPaintLimiterType sm_paintToolPaintLimiter;
	//A limiter for paint tool erase function
	static PaintToolEraseLimiterType sm_paintToolEraseLimiter;
};