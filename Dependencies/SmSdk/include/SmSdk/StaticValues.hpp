#pragma once

#include "SmSdk/Util/StaticVariable.hpp"
#include "SmSdk/offsets.hpp"

class StaticValues
{
public:
#if defined(_SM_VERSION_070_771)
	using PaintToolPaintLimiterType = StaticVariable<std::int32_t, 0x3E0E1B>;
	using PaintToolEraseLimiterType = StaticVariable<std::int32_t, 0x2AD53D>;
#else
	using PaintToolPaintLimiterType = StaticVariable<std::int32_t, 0x3F060D>;
	using PaintToolEraseLimiterType = StaticVariable<std::int32_t, 0x3F0D9B>;
#endif

	// A limiter for paint tool paint function
	static PaintToolPaintLimiterType sm_paintToolPaintLimiter;
	// A limiter for paint tool erase function
	static PaintToolEraseLimiterType sm_paintToolEraseLimiter;
};