#include "SmSdk/Util/Color.hpp"

ColorBGRA::ColorBGRA(Color color)
	: b(color.b), g(color.g), r(color.r), a(color.a) {}

Color::Color(const std::string& col)
{
	if (col.empty() || col.size() > 6)
	{
		this->data = 0xFF000000;
		return;
	}

	if (col.size() == 6)
	{
		this->r = std::uint8_t(std::strtol(col.substr(0, 2).c_str(), nullptr, 16));
		this->g = std::uint8_t(std::strtol(col.substr(2, 2).c_str(), nullptr, 16));
		this->b = std::uint8_t(std::strtol(col.substr(4, 2).c_str(), nullptr, 16));
	}
	else
	{
		this->data = (std::uint32_t)std::strtoul(col.c_str(), nullptr, 16);
	}

	this->a = 0xff;
}

Color::Color(std::uint32_t col)
    : data(col) {}

Color::Color(std::uint64_t col)
    : data(std::uint32_t(col)) {}

Color::Color(ColorBGRA col)
	: r(col.r), g(col.g), b(col.b), a(col.a) {}

float Color::getFloat(std::size_t idx)
{
	return float(this->col_array[idx]) * (1.0f / 255.0f);
}

void Color::setFloat(std::size_t idx, float val)
{
    this->col_array[idx] = std::uint8_t(val * 255.0f);
}


void RGBtoHSV(Color col, float& fH, float& fS, float& fV) {
    const float fR = col.getFloat(0);
    const float fG = col.getFloat(1);
    const float fB = col.getFloat(2);

    const float fCMax = std::max(std::max(fR, fG), fB);
    const float fCMin = std::min(std::min(fR, fG), fB);
    const float fDelta = fCMax - fCMin;

    if (fDelta > 0) {
        if (fCMax == fR) {
            fH = 60.0f * std::fmod((fG - fB) / fDelta, 6.0f);
        }
        else if (fCMax == fG) {
            fH = 60.0f * (((fB - fR) / fDelta) + 2.0f);
        }
        else if (fCMax == fB) {
            fH = 60.0f * (((fR - fG) / fDelta) + 4.0f);
        }

        if (fCMax > 0) {
            fS = fDelta / fCMax;
        }
        else {
            fS = 0.0f;
        }

        fV = fCMax;
    }
    else {
        fH = 0.0f;
        fS = 0.0f;
        fV = fCMax;
    }

    if (fH < 0) {
        fH = 360.0f + fH;
    }
}

std::uint32_t RatioToRGB(double ratio)
{
    //we want to normalize ratio so that it fits in to 6 regions
    //where each region is 256 units long
    const int normalized = int(ratio * 256 * 6);

    //find the region for this position
    const int region = normalized / 256;

    //find the distance to the start of the closest region
    const std::uint8_t x = std::uint8_t(normalized % 256);

    std::uint8_t r = 0, g = 0, b = 0;
    switch (region)
    {
    case 6:
    case 0: r = 255; g = 0;   b = 0;   g += x; break;
    case 1: r = 255; g = 255; b = 0;   r -= x; break;
    case 2: r = 0;   g = 255; b = 0;   b += x; break;
    case 3: r = 0;   g = 255; b = 255; g -= x; break;
    case 4: r = 0;   g = 0;   b = 255; r += x; break;
    case 5: r = 255; g = 0;   b = 255; b -= x; break;
    }

    return r + (g << 8) + (b << 16);
}