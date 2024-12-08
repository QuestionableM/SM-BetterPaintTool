#pragma once

#include "SmSdk/Util/StaticVariable.hpp"
#include "SmSdk/offsets.hpp"

class StaticValues
{
public:
	using PaintToolPaintLimiterType = StaticVariable<std::int32_t, SM_VAR_PAINT_DRAG_LIMITER>;
	using PaintToolEraseLimiterType = StaticVariable<std::int32_t, SM_VAR_PAINT_ERASE_LIMITER>;

	//A limiter for paint tool paint function
	static PaintToolPaintLimiterType sm_paintToolPaintLimiter;
	//A limiter for paint tool erase function
	static PaintToolEraseLimiterType sm_paintToolEraseLimiter;
};