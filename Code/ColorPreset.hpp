#pragma once

#include "Utils/Buffer.hpp"

#include <string>
#include <vector>

struct ColorPreset
{
	ColorPreset() = default;
	ColorPreset(const ColorPreset&) = default;
	ColorPreset& operator=(const ColorPreset&) = default;

	ColorPreset(
		const std::string& presetName,
		std::uint32_t presetColors[40]);

	ColorPreset(
		const std::string& presetName);

	ColorPreset(
		ColorPreset&& other) noexcept;

	constexpr std::size_t getColorCount() const noexcept
	{
		return sizeof(this->colors) / sizeof(this->colors[0]);
	}

	std::string name;
	std::uint32_t colors[40];
};

#define ColorPresetStorage_FilePath "./bpt_color_presets"

class ColorPresetStorage
{
public:
	static ColorPreset& GetCurrentPreset() noexcept;

	static void SaveToFile();

	static bool LoadFromFileInternal(
		ReadBuffer& readBuffer,
		std::vector<ColorPreset>& outColorPresets);
	static void LoadFromFile();

private:
	static bool PresetLoadedFromFile;

public:
	static std::uint32_t DefaultPaintToolColors[40];

	static std::size_t CurrentColorPreset;
	static std::vector<ColorPreset> ColorPresets;
};