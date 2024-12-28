#include "CustomPaintToolGui.hpp"

#include "SmSdk/DirectoryManager.hpp"

#include <fstream>

std::string CustomPaintToolGui::CustomLayoutPath = "$GAME_DATA/Gui/Layouts/Tool/Tool_PaintTool_DLL_Injected.layout";
std::string CustomPaintToolGui::CustomLayoutSliderPath = "$GAME_DATA/Gui/Layouts/Tool/Tool_PaintTool_Slider_DLL_Injected.layout";

std::string CustomPaintToolGui::getCustomPaintToolGuiString()
{
	static const char file_data[] =
		"<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
		"<MyGUI type=\"Layout\" version=\"3.2.0\">"
		"\t<Widget type=\"Widget\" skin=\"PanelEmpty\" name=\"MainPanel\" position_real=\"0 0 0.3125 0.36944444444444446\">"
		"\t\t<Property key=\"NeedMouse\" value=\"true\" />"
		"\t\t<Property key=\"NeedKey\" value=\"false\" />"
		"\t\t<Widget type=\"Button\" skin=\"InventoryTab\" align=\"Left Top\" name=\"PresetColorsTab\" position_real=\"0.03333333333333333 0 0.3333333333333333 0.12531328320802004\">"
		"\t\t\t<Property key=\"Caption\" value=\"Preset Colors\" />"
		"\t\t\t<Property key=\"TextAlign\" value=\"Center\" />"
		"\t\t\t<Property key=\"FontName\" value=\"SM_ItemTitle\" />"
		"\t\t\t<Property key=\"TextShadow\" value=\"true\" />"
		"\t\t\t<Property key=\"NeedKey\" value=\"false\" />"
		"\t\t\t<Property key=\"NeedMouse\" value=\"true\" />"
		"\t\t\t<Property key=\"Alpha\" value=\"1\" />"
		"\t\t\t<Property key=\"InheritsAlpha\" value=\"false\" />"
		"\t\t</Widget>"
		"\t\t<Widget type=\"Button\" skin=\"InventoryTab\" align=\"Left Top\" name=\"CustomColorTab\" position_real=\"0.4 0 0.3333333333333333 0.12531328320802004\">"
		"\t\t\t<Property key=\"Caption\" value=\"Custom\" />"
		"\t\t\t<Property key=\"FontName\" value=\"SM_ItemTitle\" />"
		"\t\t\t<Property key=\"TextAlign\" value=\"Center\" />"
		"\t\t\t<Property key=\"TextShadow\" value=\"true\" />"
		"\t\t\t<Property key=\"NeedKey\" value=\"false\" />"
		"\t\t\t<Property key=\"NeedMouse\" value=\"true\" />"
		"\t\t\t<Property key=\"InheritsAlpha\" value=\"false\" />"
		"\t\t</Widget>"
		"\t\t<Widget type=\"Widget\" skin=\"BackgroundPopup\" align=\"Default\" name=\"PresetColorsWnd\" position_real=\"0 0.12531328320802004 1 0.87468671679198\">"
		"\t\t\t<Property key=\"NeedKey\" value=\"false\" />"
		"\t\t\t<Property key=\"NeedMouse\" value=\"true\" />"
		"\t\t\t<Property key=\"InheritsAlpha\" value=\"false\" />"
		"\t\t\t<Widget type=\"TextBox\" skin=\"TextBox\" position_real=\"0.08166666666666667 0.14040114613180515 0.8316666666666667 0.14040114613180515\">"
		"\t\t\t\t<Property key=\"Caption\" value=\"#{PAINT_TOOL_TITLE}\" />"
		"\t\t\t\t<Property key=\"FontName\" value=\"SM_HeaderLarge_Wide\" />"
		"\t\t\t\t<Property key=\"TextAlign\" value=\"Center\" />"
		"\t\t\t\t<Property key=\"NeedKey\" value=\"false\" />"
		"\t\t\t\t<Property key=\"NeedMouse\" value=\"false\" />"
		"\t\t\t</Widget>"
		"\t\t\t<Widget type=\"ItemBox\" skin=\"InventoryItemBox2\" name=\"ColorGrid\" position_real=\"0.08166666666666667 0.2808022922636103 0.85 0.5759312320916905\">"
		"\t\t\t\t<Property key=\"NeedKey\" value=\"false\" />"
		"\t\t\t\t<Property key=\"NeedDragDrop\" value=\"false\" />"
		"\t\t\t</Widget>"
		"\t\t</Widget>"
		"\t\t<Widget type=\"Widget\" skin=\"BackgroundPopup\" align=\"Default\" name=\"CustomColorWnd\" position_real=\"0 0.12531328320802004 1 0.87468671679198\">"
		"\t\t\t<Property key=\"NeedKey\" value=\"false\" />"
		"\t\t\t<Property key=\"NeedMouse\" value=\"true\" />"
		"\t\t\t<Property key=\"InheritsAlpha\" value=\"false\" />"
		"\t\t\t<Widget type=\"Widget\" skin=\"PanelEmpty\" align=\"Left Top\" name=\"ListBoxBG3\" position_real=\"0.05 0.7707736389684814 0.535 0.14326647564469913\">"
		"\t\t\t\t<Property key=\"NeedMouse\" value=\"true\" />"
		"\t\t\t\t<Property key=\"NeedKey\" value=\"true\" />"
		"\t\t\t\t<Widget type=\"TextBox\" skin=\"TextBox\" align=\"HStretch Top\" position_real=\"0.5233644859813084 0 0.4766355140186916 1\">"
		"\t\t\t\t\t<Property key=\"FontName\" value=\"SM_Button\" />"
		"\t\t\t\t\t<Property key=\"TextAlign\" value=\"Center\" />"
		"\t\t\t\t\t<Property key=\"TextShadow\" value=\"true\" />"
		"\t\t\t\t\t<Property key=\"Caption\" value=\"Hex Color Input\" />"
		"\t\t\t\t\t<Property key=\"NeedKey\" value=\"false\" />"
		"\t\t\t\t\t<Property key=\"NeedMouse\" value=\"false\" />"
		"\t\t\t\t</Widget>"
		"\t\t\t\t<Widget type=\"Widget\" skin=\"SearchBarBackground\" align=\"HStretch Top\" position_real=\"0 0 0.4766355140186916 1\">"
		"\t\t\t\t\t<Property key=\"NeedMouse\" value=\"true\" />"
		"\t\t\t\t\t<Property key=\"NeedKey\" value=\"true\" />"
		"\t\t\t\t\t<Widget type=\"EditBox\" skin=\"EditBoxEmpty\" align=\"HStretch VStretch\" name=\"HexInput\" position_real=\"0.013071895424836602 0.04 0.9673202614379085 0.92\">"
		"\t\t\t\t\t\t<Property key=\"FontName\" value=\"SM_Button\" />"
		"\t\t\t\t\t\t<Property key=\"TextAlign\" value=\"Center\" />"
		"\t\t\t\t\t\t<Property key=\"TextShadow\" value=\"true\" />"
		"\t\t\t\t\t\t<Property key=\"NeedMouse\" value=\"true\" />"
		"\t\t\t\t\t\t<Property key=\"NeedKey\" value=\"true\" />"
		"\t\t\t\t\t</Widget>"
		"\t\t\t\t</Widget>"
		"\t\t\t</Widget>"
		"\t\t\t<Widget type=\"Widget\" skin=\"PanelEmpty\" name=\"ScrollR\" position_real=\"0.05 0.08595988538681948 0.5 0.14326647564469913\" />"
		"\t\t\t<Widget type=\"Widget\" skin=\"PanelEmpty\" name=\"ScrollG\" position_real=\"0.05 0.3008595988538682 0.5 0.14326647564469913\" />"
		"\t\t\t<Widget type=\"Widget\" skin=\"PanelEmpty\" name=\"ScrollB\" position_real=\"0.05 0.5157593123209169 0.5 0.14326647564469913\" />"
		"\t\t\t<Widget type=\"ImageBox\" skin=\"ImageBox\" name=\"ColorPicker\" position_real=\"0.7 0.08595988538681948 0.25 0.4297994269340974\">"
		"\t\t\t\t<Property key=\"NeedKey\" value=\"false\" />"
		"\t\t\t</Widget>"
		"\t\t\t<Widget type=\"ImageBox\" skin=\"ImageBox\" name=\"HsvPicker\" position_real=\"0.7 0.5730659025787965 0.25 0.08595988538681948\">"
		"\t\t\t\t<Property key=\"NeedKey\" value=\"false\" />"
		"\t\t\t</Widget>"
		"\t\t</Widget>"
		"\t</Widget>"
		"\t<CodeGeneratorSettings />"
		"</MyGUI>";

	return std::string(file_data, sizeof(file_data) - 1);
}

std::string CustomPaintToolGui::getCustomPaintToolSliderGuiString()
{
	static const char v_fileData[] =
		"<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
		"<MyGUI type=\"Layout\" version=\"3.2.0\">"
		"\t<Widget type=\"TextBox\" skin=\"TextBox\" name=\"Name\" position_real=\"0 0 0.350877 1\">"
		"\t\t<Property key=\"Caption\" value=\"LABEL\" />"
		"\t\t<Property key=\"FontName\" value=\"SM_TextLabel\" />"
		"\t\t<Property key=\"TextAlign\" value=\"Left VCenter\" />"
		"\t\t<Property key=\"NeedMouse\" value=\"false\" />"
		"\t</Widget>"
		"\t<Widget type=\"Widget\" skin=\"WhiteSkin\" name=\"Line\" position_real=\"0 1 0.991228 0.025\">"
		"\t\t<Property key=\"Alpha\" value=\"0.05\" />"
		"\t\t<Property key=\"NeedMouse\" value=\"false\" />"
		"\t\t<Property key=\"NeedKey\" value=\"false\" />"
		"\t</Widget>"
		"\t<Widget type=\"ScrollBar\" skin=\"InventoryHSlider\" name=\"Slider\" position_real=\"0.412281 0.25 0.587719 0.45\">"
		"\t\t<Property key=\"Range\" value=\"101\" />"
		"\t</Widget>"
		"\t<Widget type=\"EditBox\" skin=\"EditBoxEmpty\" name=\"Value\" position_real=\"0.223684 0.25 0.175439 0.5\">"
		"\t\t<Property key=\"FontName\" value=\"SM_ListItem\" />"
		"\t\t<Property key=\"Caption\" value=\"-1234567890\" />"
		"\t\t<Property key=\"TextAlign\" value=\"Right VCenter\" />"
		"\t\t<Property key=\"NeedKey\" value=\"true\" />"
		"\t\t<Property key=\"NeedMouse\" value=\"true\" />"
		"\t\t<Property key=\"TextColour\" value=\"1 0.831373 0.290196\" />"
		"\t</Widget>"
		"\t<CodeGeneratorSettings />"
		"</MyGUI>";

	return std::string(v_fileData, sizeof(v_fileData) - 1);
}

bool file_exists(const std::string& path)
{
	std::string v_replaced_path = path;
	DirectoryManager::ReplacePathR(v_replaced_path);

	//Can't use filesystem in C++14, so i'ma use std::ifstream
	std::ifstream v_file(v_replaced_path);
	return v_file.is_open() && v_file.good();
}

void write_string_to_file(const std::string& path, const std::string& data)
{
	std::string v_replaced_path = path;
	DirectoryManager::ReplacePathR(v_replaced_path);

	std::ofstream v_output(v_replaced_path);
	if (v_output.is_open())
	{
		v_output << data;
		v_output.close();
	}
}

void CustomPaintToolGui::writeIfNotExists()
{
	if (!file_exists(CustomPaintToolGui::CustomLayoutPath))
		write_string_to_file(CustomPaintToolGui::CustomLayoutPath, CustomPaintToolGui::getCustomPaintToolGuiString());

	if (!file_exists(CustomPaintToolGui::CustomLayoutSliderPath))
		write_string_to_file(CustomPaintToolGui::CustomLayoutSliderPath, CustomPaintToolGui::getCustomPaintToolSliderGuiString());
}