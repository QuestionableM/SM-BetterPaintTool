#include "ColorPreset.hpp"

ColorPreset::ColorPreset(
	const std::string& presetName,
	std::uint32_t presetColors[40]
) :
	name(presetName)
{
	std::memcpy(this->colors, presetColors, sizeof(this->colors));
}

ColorPreset::ColorPreset(
	const std::string& presetName
) :
	name(presetName)
{
	for (std::size_t a = 0; a < 40; a++)
		this->colors[a] = 0xFFEEEEEE;
}

////////////// COLOR PRESET STORAGE //////////////////

ColorPreset& ColorPresetStorage::GetCurrentPreset() noexcept
{
	return ColorPresetStorage::ColorPresets[ColorPresetStorage::CurrentColorPreset];
}

std::uint32_t ColorPresetStorage::DefaultPaintToolColors[40] =
{
	0xFFEEEEEE, 0xFF71F0F5, 0xFF6FF6CB, 0xFF88FF68, 0xFFEDED7E, 0xFFE36F4C, 0xFFF079AE, 0xFFF07BEE,
	0xFF6767F0, 0xFF5CAFEE, 0xFF7F7F7F, 0xFF13DBE2, 0xFF00EAA0, 0xFF53E719, 0xFFE6E62C, 0xFFE23E0A,
	0xFFED1475, 0xFFD211CF, 0xFF2525D0, 0xFF007FDF, 0xFF4A4A4A, 0xFF007C81, 0xFF077D57, 0xFF31800E,
	0xFF878711, 0xFF912E0F, 0xFFA60A50, 0xFF740A72, 0xFF00007C, 0xFF003B67, 0xFF222222, 0xFF003032,
	0xFF005037, 0xFF234006, 0xFF44440A, 0xFF5A1D0A, 0xFF6C0835, 0xFF530652, 0xFF020256, 0xFF002847
};

std::size_t ColorPresetStorage::CurrentColorPreset = 0;
std::vector<ColorPreset> ColorPresetStorage::ColorPresets =
{
	ColorPreset
	{
		"Default",
		ColorPresetStorage::DefaultPaintToolColors
	}
};