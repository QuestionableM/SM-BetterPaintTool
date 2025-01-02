#pragma once

#include "win_include.hpp"
#include <string>

class CustomPaintToolGui
{
public:
	static HMODULE SelfDll;
	static std::string CustomLayoutPath;
	static std::string CustomLayoutSliderPath;

	static void writeIfNotExists();
};