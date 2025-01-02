#include "CustomPaintToolGui.hpp"

#include "SmSdk/DirectoryManager.hpp"
#include "win_include.hpp"
#include "../resource.h"

#include <fstream>

HMODULE CustomPaintToolGui::SelfDll = nullptr;
std::string CustomPaintToolGui::CustomLayoutPath = "$GAME_DATA/Gui/Layouts/Tool/Tool_PaintTool_DLL_Injected.layout";
std::string CustomPaintToolGui::CustomLayoutSliderPath = "$GAME_DATA/Gui/Layouts/Tool/Tool_PaintTool_Slider_DLL_Injected.layout";

static bool GetTextResource(
	HMODULE mod,
	const char* resourceName,
	std::string& outText)
{
	HRSRC v_resource = FindResourceA(mod, resourceName, "TXT");
	if (!v_resource) return false;

	HGLOBAL v_loadedResource = LoadResource(mod, v_resource);
	if (!v_loadedResource) return false;

	void* v_rawResource = LockResource(v_loadedResource);
	if (!v_rawResource) return false;

	const DWORD v_rawResourceSize = SizeofResource(mod, v_resource);

	outText.assign((const char*)v_rawResource, (std::size_t)v_rawResourceSize);
	return true;
}

bool file_exists(const std::string& path)
{
	std::string v_replaced_path = path;
	DirectoryManager::ReplacePathR(v_replaced_path);

	//Can't use filesystem in C++14, so i'ma use std::ifstream
	std::ifstream v_file(v_replaced_path);
	return v_file.is_open() && v_file.good();
}

void writeStringToFile(const std::string& path, const std::string& data)
{
	std::string v_replaced_path = path;
	DirectoryManager::ReplacePathR(v_replaced_path);

	std::ofstream v_output(v_replaced_path, std::ios::binary);
	if (v_output.is_open())
	{
		v_output << data;
		v_output.close();
	}
}

void writeResourceIfNotExists(
	const std::string& path,
	const char* resourceName)
{
	if (file_exists(path)) return;

	std::string v_resData;
	if (GetTextResource(CustomPaintToolGui::SelfDll, resourceName, v_resData))
		writeStringToFile(path, v_resData);
}

void CustomPaintToolGui::writeIfNotExists()
{
	writeResourceIfNotExists(CustomPaintToolGui::CustomLayoutPath, MAKEINTRESOURCEA(IDR_TXT1));
	writeResourceIfNotExists(CustomPaintToolGui::CustomLayoutSliderPath, MAKEINTRESOURCEA(IDR_TXT2));
}