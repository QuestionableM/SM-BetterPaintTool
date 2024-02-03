#pragma once

#include "win_include.hpp"

class EngineConColor
{
	WORD color_data = 0;

	constexpr EngineConColor() noexcept = default;

	friend constexpr EngineConColor operator"" _bg(unsigned long long val) noexcept;
	friend constexpr EngineConColor operator"" _fg(unsigned long long val) noexcept;

public:
	inline constexpr operator WORD() const noexcept
	{
		return color_data;
	}

	inline constexpr EngineConColor operator|(EngineConColor rhs) noexcept
	{
		EngineConColor lOutput;
		lOutput.color_data = this->color_data | rhs.color_data;

		return lOutput;
	}
};

inline constexpr EngineConColor operator"" _bg(unsigned long long val) noexcept
{
	EngineConColor lOutput;

	if ((val & 0b1000) == 0b1000) lOutput.color_data |= BACKGROUND_RED;
	if ((val & 0b0100) == 0b0100) lOutput.color_data |= BACKGROUND_GREEN;
	if ((val & 0b0010) == 0b0010) lOutput.color_data |= BACKGROUND_BLUE;
	if ((val & 0b0001) == 0b0001) lOutput.color_data |= BACKGROUND_INTENSITY;

	return lOutput;
}

inline constexpr EngineConColor operator"" _fg(unsigned long long val) noexcept
{
	EngineConColor lOutput;

	if ((val & 0b1000) == 0b1000) lOutput.color_data |= FOREGROUND_RED;
	if ((val & 0b0100) == 0b0100) lOutput.color_data |= FOREGROUND_GREEN;
	if ((val & 0b0010) == 0b0010) lOutput.color_data |= FOREGROUND_BLUE;
	if ((val & 0b0001) == 0b0001) lOutput.color_data |= FOREGROUND_INTENSITY;

	return lOutput;
}