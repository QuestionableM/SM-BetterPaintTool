#pragma once

#include <string>

class CustomPaintToolGui
{
public:
	static std::string CustomLayoutPath;

	static std::string getCustomPaintToolGuiString();

	static void writeIfNotExists();
};