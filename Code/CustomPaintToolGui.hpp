#pragma once

#include <string>

class CustomPaintToolGui
{
public:
	static std::string CustomLayoutPath;
	static std::string CustomLayoutSliderPath;

	static std::string getCustomPaintToolGuiString();
	static std::string getCustomPaintToolSliderGuiString();

	static void writeIfNotExists();
};