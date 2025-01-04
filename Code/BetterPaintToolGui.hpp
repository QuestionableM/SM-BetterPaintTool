#pragma once

#include "SmSdk/Gui/PaintToolGui.hpp"
#include "SmSdk/Util/Color.hpp"

struct SliderData
{
	MyGUI::ScrollBar* slider;
	MyGUI::TextBox* name;
	MyGUI::EditBox* value;
};

class BetterPaintTool;

class BetterPaintToolGui : public PaintToolGui
{
public:
	using t_init_func_sig = void(*)(BetterPaintToolGui*);
	using t_scroll_callback_sig = void(BetterPaintToolGui::*)(MyGUI::ScrollBar*, size_t);
	using t_edit_text_callback_sig = void(BetterPaintToolGui::*)(MyGUI::EditBox*);

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
	void colorREditTextChanged(MyGUI::EditBox* _sender);
	void colorGEditTextChanged(MyGUI::EditBox* _sender);
	void colorBEditTextChanged(MyGUI::EditBox* _sender);

	// Color presets callbacks
	void eventAddNewColorPresetPressed(MyGUI::Widget* _sender, int _left, int _top, MyGUI::MouseButton _id);
	void eventRemoveCurrentPresetPressed(MyGUI::Widget* _sender, int _left, int _top, MyGUI::MouseButton _id);
	void eventSwitchColorPresetRightPreseed(MyGUI::Widget* _sender, int _left, int _top, MyGUI::MouseButton _id);
	void eventSwitchColorPresetLeftPressed(MyGUI::Widget* _sender, int _left, int _top, MyGUI::MouseButton _id);
	void eventCloseColorEditorPressed(MyGUI::Widget* _sender, int _left, int _top, MyGUI::MouseButton _id);
	void eventPresetNameChanged(MyGUI::EditBox* _sender);

	///Tab switching functions
	void switchEditorMode(bool editorMode);

	//Data getters
	void getSliderData(MyGUI::Widget* slider_parent, SliderData* p_sliderData);
	MyGUI::ScrollBar* getScrollBar(const std::string& name);
	Color getColorFromSliders();
	Color getColorFromHsvPicker();
	static Color getColorPickerColorTransformed(float uv_x, float uv_y, Color col);
	MyGUI::Widget* getPresetColorsWnd();
	MyGUI::Widget* getCustomColorWnd();
	MyGUI::Widget* getColorPicker();
	MyGUI::Widget* getColorPickerPointer();
	MyGUI::Widget* getHsvPicker();
	MyGUI::Widget* getHsvPickerPointer();
	MyGUI::Widget* getHexInputBox();
	MyGUI::Widget* getColorPresetsPanel();
	MyGUI::Button* getLeftPresetSwitch();
	MyGUI::Button* getRightPresetSwitch();
	MyGUI::Button* getAddNewPresetButton();
	MyGUI::Button* getRemoveCurrentPresetButton();
	MyGUI::EditBox* getPresetNameEditBox();

	//Color slider functions
	void setupColorSlider(
		const std::string& widget_name,
		const std::string& visual_name,
		t_scroll_callback_sig callback,
		t_edit_text_callback_sig edit_text_callback);
	void updateColorSliderFromTextInput(const std::string& widget_name);
	void updateHexInputAndColorPickersFromSliders();
	void updateColorSlider(const std::string& widget_name);
	void setColorSliderPos(const std::string& widget_name, std::size_t value);
	
	//Update functions
	void updateHexInputParameter(const std::string& newVal);
	void updateHexValueFromColor(Color col);
	void updateSlidersFromColor(Color col);
	void updateHsvAndColorPickersFromColor(Color col);
	void updateTextureGradient(Color color);
	void updateCurrentPresetFromIndex();
	void updateColorPaletteFromIndex();
	void updateHelperTextState(bool showCannotEditMsg);

	void openColorEditor(std::size_t colIdx);
	void applyEditedColor();

	//Create functions
	void createTextureGradient();
	void createHueGradient();
	void initializeHooked();
	void initializeColorGrid(BetterPaintTool* pPaintTool);
	void initParams(BetterPaintTool* pPaintTool);

	static t_init_func_sig o_initialize;
	static void h_initialize(BetterPaintToolGui* self);

}; // Size: 0x20