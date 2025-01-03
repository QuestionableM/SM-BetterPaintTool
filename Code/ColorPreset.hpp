#pragma once

#include <string>
#include <vector>

struct ColorPreset
{
	ColorPreset(
		const std::string& presetName,
		std::uint32_t presetColors[40]);

	ColorPreset(
		const std::string& presetName);

	std::string name;
	std::uint32_t colors[40];
};

class ColorPresetStorage
{
public:
	static ColorPreset& GetCurrentPreset() noexcept;

public:
	static std::uint32_t DefaultPaintToolColors[40];

	static std::size_t CurrentColorPreset;
	static std::vector<ColorPreset> ColorPresets;
};