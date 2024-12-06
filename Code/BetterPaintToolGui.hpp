#pragma once

#include "SmSdk/Gui/PaintToolGui.hpp"
#include "SmSdk/Util/Color.hpp"

struct SliderData
{
	MyGUI::ScrollBar* slider;
	MyGUI::TextBox* name;
	MyGUI::TextBox* value;
};

class BetterPaintTool;

class BetterPaintToolGui : public PaintToolGui
{
public:
	using t_init_func_sig = void(*)(BetterPaintToolGui*);
	using t_scroll_callback_sig = void(BetterPaintToolGui::*)(MyGUI::ScrollBar*, size_t);

	//MYGUI callbacks
	void requestCoordItem(MyGUI::ItemBox* _sender, MyGUI::IntCoord& _coord, bool _drag);
	void requestCreateWidgetItem(MyGUI::ItemBox* _sender, MyGUI::Widget* _item);
	void requestDrawItem(MyGUI::ItemBox* _sender, MyGUI::Widget* _item, const MyGUI::IBDrawItemInfo& _info);
	void eventMouseItemActivate(MyGUI::ItemBox* _sender, std::size_t idx);
	void eventEditTextChange(MyGUI::EditBox* _sender);
	void eventColorMatrixSelectColor(MyGUI::Widget* _sender, int _left, int _top, MyGUI::MouseButton _id);
	void eventColorHsvSelectColor(MyGUI::Widget* _sender, int _left, int _top, MyGUI::MouseButton _id);
	void colorRScrollChangePosition(MyGUI::ScrollBar* _sender, size_t _position);
	void colorGScrollChangePosition(MyGUI::ScrollBar* _sender, size_t _position);
	void colorBScrollChangePosition(MyGUI::ScrollBar* _sender, size_t _position);
	void eventPresetColorsTabPressed(MyGUI::Widget* _sender, int _left, int _top, MyGUI::MouseButton _id);
	void eventCustomColorTabPressed(MyGUI::Widget* _sender, int _left, int _top, MyGUI::MouseButton _id);

	///Tab switching functions
	void switchTabsAndButtons(bool state);

	//Data getters
	void getSliderData(MyGUI::Widget* slider_parent, SliderData* p_sliderData);
	Color getColorFromSliders();
	Color getColorFromHsvPicker();
	static Color getColorPickerColorTransformed(float uv_x, float uv_y, Color col);
	MyGUI::Widget* getPresetColorsWnd();
	MyGUI::Widget* getPresetColorsTab();
	MyGUI::Widget* getCustomColorWnd();
	MyGUI::Widget* getCustomColorTab();
	MyGUI::Widget* getColorPicker();
	MyGUI::Widget* getColorPickerPointer();
	MyGUI::Widget* getHsvPicker();
	MyGUI::Widget* getHsvPickerPointer();
	MyGUI::Widget* getHexInputBox();

	//Color slider functions
	void setupColorSlider(const std::string& widget_name, const std::string& visual_name, t_scroll_callback_sig callback);
	void updateColorSlider(const std::string& widget_name);
	void setColorSliderPos(const std::string& widget_name, std::size_t value);
	
	//Update functions
	void updateHexValueFromColor(Color col);
	void updateSlidersFromColor(Color col);
	void updateHsvAndColorPickersFromColor(Color col);
	void updateTextureGradient(Color color);

	//Create functions
	void createTextureGradient();
	void createHueGradient();
	void initializeHooked();
	void initParams(BetterPaintTool* paint_tool);

	static t_init_func_sig o_initialize;
	static void h_initialize(BetterPaintToolGui* self);

	static bool isColorPreset(Color col);

	static std::uint32_t g_paintColors[];

}; // Size: 0x20