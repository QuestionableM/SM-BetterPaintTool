#pragma once

#include <string>
#include <cmath>

union Color;

#pragma warning(push)
#pragma warning(disable : 4201)

union ColorBGRA
{
	std::uint32_t data;
	struct { std::uint8_t b, g, r, a; };

	ColorBGRA() = default;
	ColorBGRA(Color color);
};

union Color
{
	std::uint32_t data;
	struct { std::uint8_t r, g, b, a; };
	std::uint8_t col_array[4];

	Color() = default;
	Color(const std::string& col);
	Color(std::uint32_t col);
	Color(std::uint64_t col);
	Color(ColorBGRA col);

	float getFloat(std::size_t idx);
	void setFloat(std::size_t idx, float val);

	inline bool operator==(Color other) const noexcept
	{
		return this->data == other.data;
	}
};

#pragma warning(pop)

void RGBtoHSV(Color col, float& fH, float& fS, float& fV);
std::uint32_t RatioToRGB(double ratio);