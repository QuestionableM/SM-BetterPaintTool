#pragma once

#include <string>
#include <cmath>
#include "SmSdk/config.hpp"

SMSDK_BEGIN_NAMESPACE

union Color;

#pragma warning(push)
#pragma warning(disable : 4201)

union ColorBGRA
{
	uint32_t data;
	struct
	{
		uint8_t b, g, r, a;
	};

	ColorBGRA() = default;
	ColorBGRA(Color color);
};

union Color
{
	uint32_t data;
	struct
	{
		uint8_t r, g, b, a;
	};
	uint8_t colArr[4];

	Color() = default;
	Color(const std::string& col);
	Color(uint32_t col);
	Color(uint64_t col);
	Color(ColorBGRA col);

	float getFloat(size_t iIdx);
	void setFloat(size_t iIdx, float fVal);

	inline std::string toHexStringRGB() const
	{
		char buffer[10];
		sprintf_s(buffer, "%02X%02X%02X", uint32_t(this->r), uint32_t(this->g), uint32_t(this->b));

		return std::string(buffer, 6);
	}

	inline bool operator==(Color other) const noexcept
	{
		return this->data == other.data;
	}
};

#pragma warning(pop)

void RGBtoHSV(Color col, float& fH, float& fS, float& fV);
uint32_t RatioToRGB(double dRatio);

SMSDK_END_NAMESPACE