#include "BetterPaintToolGui.hpp"

#include "SmSdk/Gui/GuiSystemManager.hpp"
#include "SmSdk/Gui/InGameGuiManager.hpp"
#include "SmSdk/Util/Color.hpp"

#include "CustomPaintToolGui.hpp"
#include "BetterPaintTool.hpp"

#include "Utils/MathUtils.hpp"
#include "Utils/Console.hpp"

#include <json/json.h>

BetterPaintToolGui::t_init_func_sig BetterPaintToolGui::o_initialize = nullptr;

std::uint32_t BetterPaintToolGui::g_paintColors[] =
{
	0xFFEEEEEE, 0xFF71F0F5, 0xFF6FF6CB, 0xFF88FF68, 0xFFEDED7E, 0xFFE36F4C, 0xFFF079AE, 0xFFF07BEE,
	0xFF6767F0, 0xFF5CAFEE, 0xFF7F7F7F, 0xFF13DBE2, 0xFF00EAA0, 0xFF53E719, 0xFFE6E62C, 0xFFE23E0A,
	0xFFED1475, 0xFFD211CF, 0xFF2525D0, 0xFF007FDF, 0xFF4A4A4A, 0xFF007C81, 0xFF077D57, 0xFF31800E,
	0xFF878711, 0xFF912E0F, 0xFFA60A50, 0xFF740A72, 0xFF00007C, 0xFF003B67, 0xFF222222, 0xFF003032,
	0xFF005037, 0xFF234006, 0xFF44440A, 0xFF5A1D0A, 0xFF6C0835, 0xFF530652, 0xFF020256, 0xFF002847
};

void BetterPaintToolGui::requestCoordItem(MyGUI::ItemBox* _sender, MyGUI::IntCoord& _coord, bool _drag)
{
	_coord.left = 0;
	_coord.top = 0;

	const float v_gui_scale = (float)GuiSystemManager::GetInstance()->screen_height;
	const int v_final_val = (int)std::round(v_gui_scale * 0.046296295f);

	_coord.width = v_final_val;
	_coord.height = v_final_val;
}

void BetterPaintToolGui::requestCreateWidgetItem(MyGUI::ItemBox* _sender, MyGUI::Widget* _item)
{
	MyGUI::Singleton<MyGUI::LayoutManager>::getInstancePtr()->loadLayout(
		"$GAME_DATA/Gui/Layouts/Common/ColorItem.layout",
		"",
		_item);
}

void BetterPaintToolGui::requestDrawItem(MyGUI::ItemBox* _sender, MyGUI::Widget* _item, const MyGUI::IBDrawItemInfo& _info)
{
	const Json::Value& j_userdata = *m_pItemBox->getItemDataAt<Json::Value>(_info.index);

	Color v_color;
	v_color.data = std::uint32_t(j_userdata.get("color", Json::Value(0xFFFFFFFFu)).asUInt64());
	if (v_color.data > 0xFFFFFFFF)
		v_color.data = 0xFFFFFFFF;

	const float v_color_b = v_color.getFloat(2);
	const float v_color_g = v_color.getFloat(1);
	const float v_color_r = v_color.getFloat(0);

	MyGUI::Widget* v_pColorWidget = _item->findWidget("Color");
	v_pColorWidget->setColour(MyGUI::Colour(v_color_r, v_color_g, v_color_b));

	const bool v_selected = j_userdata.get("selected", Json::Value(false)).asBool();
	MyGUI::Button* v_pBgButton = _item->findWidget("Background")->castType<MyGUI::Button>();
	v_pBgButton->setStateSelected(v_selected);
}

void BetterPaintToolGui::eventMouseItemActivate(MyGUI::ItemBox* _sender, std::size_t idx)
{
	if (idx == std::size_t(-1) || !m_pGuiInterface)
		return;

	const Json::Value& j_userdata = *m_pItemBox->getItemDataAt<Json::Value>(idx);
	m_pGuiInterface->func10(m_pItemBox->getName(), "", idx, j_userdata);
}

void BetterPaintToolGui::eventEditTextChange(MyGUI::EditBox* _sender)
{
	const std::string& v_color_str = _sender->getCaption().asUTF8();

	m_pGuiInterface->func7("HexInput", v_color_str);

	const Color v_col(v_color_str);
	this->updateSlidersFromColor(v_col);
	this->updateHsvAndColorPickersFromColor(v_col);
}

void BetterPaintToolGui::eventColorMatrixSelectColor(MyGUI::Widget* _sender, int _left, int _top, MyGUI::MouseButton _id)
{
	MyGUI::IntCoord v_sender_sz = _sender->getAbsoluteCoord();

	const float v_uv_x = std::min(std::max(float(_left - v_sender_sz.left) / float(v_sender_sz.width), 0.0f), 1.0f);
	const float v_uv_y = std::min(std::max(float(_top - v_sender_sz.top) / float(v_sender_sz.height), 0.0f), 1.0f);

	const Color v_hsv_col = this->getColorPickerColorTransformed(
		v_uv_x, v_uv_y, this->getColorFromHsvPicker());

	this->updateSlidersFromColor(v_hsv_col);
	this->updateHexValueFromColor(v_hsv_col);

	MyGUI::Widget* v_pPtr = this->getColorPickerPointer();
	
	const int v_x_clamped = std::min(std::max(_left - v_sender_sz.left, 0), v_sender_sz.width);
	const int v_y_clamped = std::min(std::max(_top - v_sender_sz.top, 0), v_sender_sz.height);
	v_pPtr->setPosition(MyGUI::IntPoint(v_x_clamped - 2, v_y_clamped - 2));
}

void BetterPaintToolGui::eventColorHsvSelectColor(MyGUI::Widget* _sender, int _left, int _top, MyGUI::MouseButton _id)
{
	MyGUI::IntCoord v_sender_sz = _sender->getAbsoluteCoord();

	const double v_uv_x = std::min(std::max(double(_left - v_sender_sz.left) / double(v_sender_sz.width), 0.0), 1.0);
	Color v_color(RatioToRGB(v_uv_x));
	v_color.a = 0xFF;

	//Get the position of color picker and convert it to uv space
	const MyGUI::IntPoint v_ptr_pos = this->getColorPickerPointer()->getPosition();
	const MyGUI::IntSize v_picker_sz = this->getColorPicker()->getSize();
	const Color v_trans_color = this->getColorPickerColorTransformed(
		float(v_ptr_pos.left + 2) / float(v_picker_sz.width),
		float(v_ptr_pos.top + 2) / float(v_picker_sz.height),
		v_color);

	this->updateTextureGradient(v_color);
	this->updateSlidersFromColor(v_trans_color);
	this->updateHexValueFromColor(v_trans_color);

	const int v_x_clamped = std::min(std::max(_left - v_sender_sz.left, 0), v_sender_sz.width);
	this->getHsvPickerPointer()->setPosition(MyGUI::IntPoint(v_x_clamped - 2, 0));
}

void BetterPaintToolGui::colorRScrollChangePosition(MyGUI::ScrollBar* _sender, size_t _position)
{
	this->updateColorSlider("ScrollR");
}

void BetterPaintToolGui::colorGScrollChangePosition(MyGUI::ScrollBar* _sender, size_t _position)
{
	this->updateColorSlider("ScrollG");
}

void BetterPaintToolGui::colorBScrollChangePosition(MyGUI::ScrollBar* _sender, size_t _position)
{
	this->updateColorSlider("ScrollB");
}

void BetterPaintToolGui::colorREditTextChanged(MyGUI::EditBox* _sender)
{
	this->updateColorSliderFromTextInput("ScrollR");
}

void BetterPaintToolGui::colorGEditTextChanged(MyGUI::EditBox* _sender)
{
	this->updateColorSliderFromTextInput("ScrollG");
}

void BetterPaintToolGui::colorBEditTextChanged(MyGUI::EditBox* _sender)
{
	this->updateColorSliderFromTextInput("ScrollB");
}

void BetterPaintToolGui::eventPresetColorsTabPressed(MyGUI::Widget* _sender, int _left, int _top, MyGUI::MouseButton _id)
{
	if (_sender->castType<MyGUI::Button>()->getStateSelected())
		return;

	this->switchTabsAndButtons(true);
}

void BetterPaintToolGui::eventCustomColorTabPressed(MyGUI::Widget* _sender, int _left, int _top, MyGUI::MouseButton _id)
{
	if (_sender->castType<MyGUI::Button>()->getStateSelected())
		return;

	this->switchTabsAndButtons(false);
}



void BetterPaintToolGui::switchTabsAndButtons(bool state)
{
	this->getPresetColorsWnd()->setVisible(state);
	this->getCustomColorWnd()->setVisible(!state);

	this->getPresetColorsTab()->castType<MyGUI::Button>()->setStateSelected(state);
	this->getCustomColorTab()->castType<MyGUI::Button>()->setStateSelected(!state);
}

void BetterPaintToolGui::getSliderData(MyGUI::Widget* slider_parent, SliderData* p_sliderData)
{
	p_sliderData->slider = slider_parent->findWidget("Slider")->castType<MyGUI::ScrollBar>();
	p_sliderData->name = slider_parent->findWidget("Name")->castType<MyGUI::TextBox>();
	p_sliderData->value = slider_parent->findWidget("Value")->castType<MyGUI::EditBox>();
}

Color BetterPaintToolGui::getColorFromSliders()
{
	Color v_color;
	v_color.r = std::uint8_t(m_pMainPanel->findWidget("ScrollR")->findWidget("Slider")->castType<MyGUI::ScrollBar>()->getScrollPosition());
	v_color.g = std::uint8_t(m_pMainPanel->findWidget("ScrollG")->findWidget("Slider")->castType<MyGUI::ScrollBar>()->getScrollPosition());
	v_color.b = std::uint8_t(m_pMainPanel->findWidget("ScrollB")->findWidget("Slider")->castType<MyGUI::ScrollBar>()->getScrollPosition());
	v_color.a = 0xff;

	return v_color;
}

Color BetterPaintToolGui::getColorFromHsvPicker()
{
	MyGUI::Widget* v_pParent = this->getHsvPicker();
	MyGUI::Widget* v_pPtr = this->getHsvPickerPointer();

	const double v_coeff = double(v_pPtr->getPosition().left + 2) / double(v_pParent->getWidth());
	Color v_final_color(RatioToRGB(v_coeff));
	v_final_color.a = 0xFF;

	return v_final_color;
}

Color BetterPaintToolGui::getColorPickerColorTransformed(float uv_x, float uv_y, Color col)
{
	col.r = std::uint8_t(MathUtil::lerp(MathUtil::lerp(1.0f, col.getFloat(0), uv_x), 0.0f, uv_y) * 255.0f);
	col.g = std::uint8_t(MathUtil::lerp(MathUtil::lerp(1.0f, col.getFloat(1), uv_x), 0.0f, uv_y) * 255.0f);
	col.b = std::uint8_t(MathUtil::lerp(MathUtil::lerp(1.0f, col.getFloat(2), uv_x), 0.0f, uv_y) * 255.0f);

	return col;
}

MyGUI::Widget* BetterPaintToolGui::getPresetColorsWnd()
{
	return m_pMainPanel->findWidget("PresetColorsWnd");
}

MyGUI::Widget* BetterPaintToolGui::getPresetColorsTab()
{
	return m_pMainPanel->findWidget("PresetColorsTab");
}

MyGUI::Widget* BetterPaintToolGui::getCustomColorWnd()
{
	return m_pMainPanel->findWidget("CustomColorWnd");
}

MyGUI::Widget* BetterPaintToolGui::getCustomColorTab()
{
	return m_pMainPanel->findWidget("CustomColorTab");
}

MyGUI::Widget* BetterPaintToolGui::getColorPicker()
{
	return m_pMainPanel->findWidget("ColorPicker");
}

MyGUI::Widget* BetterPaintToolGui::getColorPickerPointer()
{
	return m_pMainPanel->findWidget("ColorPickerPointer");
}

MyGUI::Widget* BetterPaintToolGui::getHsvPicker()
{
	return m_pMainPanel->findWidget("HsvPicker");
}

MyGUI::Widget* BetterPaintToolGui::getHsvPickerPointer()
{
	return m_pMainPanel->findWidget("HsvPickerPointer");
}

MyGUI::Widget* BetterPaintToolGui::getHexInputBox()
{
	return m_pMainPanel->findWidget("HexInput");
}

void BetterPaintToolGui::setupColorSlider(
	const std::string& widget_name,
	const std::string& visual_name,
	t_scroll_callback_sig callback,
	t_edit_text_callback_sig edit_text_callback)
{
	MyGUI::Widget* v_pSliderHolder = m_pMainPanel->findWidget(widget_name);
	MyGUI::Singleton<MyGUI::LayoutManager>::getInstancePtr()->loadLayout(
		"$GAME_DATA/Gui/Layouts/Tool/Tool_PaintTool_Slider_DLL_Injected.layout", "", v_pSliderHolder);

	SliderData v_slider;
	this->getSliderData(v_pSliderHolder, &v_slider);

	v_slider.slider->setScrollRange(256);
	v_slider.slider->setScrollPosition(0);
	v_slider.slider->setNeedKeyFocus(false);

	v_slider.name->setCaption(visual_name);
	v_slider.value->setCaption("0");
	v_slider.value->setNeedKeyFocus(true);
	v_slider.value->setNeedMouseFocus(true);
	v_slider.value->setMaxTextLength(3);

	v_slider.slider->eventScrollChangePosition += MyGUI::newDelegate(this, callback);
	v_slider.value->eventEditTextChange += MyGUI::newDelegate(this, edit_text_callback);
}

void BetterPaintToolGui::updateHexInputAndColorPickersFromSliders()
{
	const Color v_sliderColor = this->getColorFromSliders();
	this->updateHexValueFromColor(v_sliderColor);
	this->updateHsvAndColorPickersFromColor(v_sliderColor);
}

void BetterPaintToolGui::updateColorSliderFromTextInput(const std::string& widget_name)
{
	SliderData v_slider;
	this->getSliderData(m_pMainPanel->findWidget(widget_name), &v_slider);

	const std::string& v_textValue = v_slider.value->getCaption().asUTF8();
	const std::size_t v_scrollPos = std::min<std::size_t>(std::strtoull(v_textValue.c_str(), nullptr, 10), 255);
	v_slider.slider->setScrollPosition(v_scrollPos);

	this->updateHexInputAndColorPickersFromSliders();
}

void BetterPaintToolGui::updateColorSlider(const std::string& widget_name)
{
	SliderData v_slider;
	this->getSliderData(m_pMainPanel->findWidget(widget_name), &v_slider);

	const std::size_t v_pos = v_slider.slider->getScrollPosition();
	v_slider.value->setCaption(std::to_string(v_pos));

	this->updateHexInputAndColorPickersFromSliders();
}

void BetterPaintToolGui::setColorSliderPos(const std::string& widget_name, std::size_t value)
{
	MyGUI::Widget* v_pHolder = m_pMainPanel->findWidget(widget_name);

	v_pHolder->findWidget("Slider")->castType<MyGUI::ScrollBar>()->setScrollPosition(value);
	v_pHolder->findWidget("Value")->castType<MyGUI::TextBox>()->setCaption(std::to_string(value));
}

void BetterPaintToolGui::updateHexValueFromColor(Color col)
{
	char v_buffer[10];
	sprintf_s(v_buffer, "%02X%02X%02X", std::uint32_t(col.r), std::uint32_t(col.g), std::uint32_t(col.b));

	const std::string v_hex_str(v_buffer, 6);

	this->getHexInputBox()->castType<MyGUI::EditBox>()->setOnlyText(v_hex_str);
	m_pGuiInterface->func7("HexInput", v_hex_str);
}

void BetterPaintToolGui::updateSlidersFromColor(Color col)
{
	this->setColorSliderPos("ScrollR", std::size_t(col.r));
	this->setColorSliderPos("ScrollG", std::size_t(col.g));
	this->setColorSliderPos("ScrollB", std::size_t(col.b));
}

void BetterPaintToolGui::updateHsvAndColorPickersFromColor(Color col)
{
	float h, s, v;
	RGBtoHSV(col, h, s, v);

	const int v_width = this->getHsvPicker()->getSize().width;
	this->getHsvPickerPointer()->setPosition(MyGUI::IntPoint(
		int(MathUtil::lerp(0.0f, float(v_width), h / 360.0f)) - 2,
		0
	));
	
	const MyGUI::IntSize v_pMatSz = this->getColorPicker()->getSize();
	this->getColorPickerPointer()->setPosition(MyGUI::IntPoint(
		int(MathUtil::lerp(0.0f, float(v_pMatSz.width), s)) - 2,
		int(MathUtil::lerp(float(v_pMatSz.height), 0.0f, v)) - 2
	));

	this->updateTextureGradient(RatioToRGB(double(h / 360.0f)));
}

void BetterPaintToolGui::updateTextureGradient(Color color)
{
	MyGUI::ITexture* v_tex = MyGUI::Singleton<MyGUI::RenderManager>::getInstancePtr()->getTexture("ColorPickerMatrix");

	const int v_tex_width = v_tex->getWidth();
	const int v_tex_height = v_tex->getHeight();
	void* v_tex_data = v_tex->lock(MyGUI::TextureUsage::Write);

	const float v_color_r = color.getFloat(0);
	const float v_color_g = color.getFloat(1);
	const float v_color_b = color.getFloat(2);

	ColorBGRA* v_tex_pixels = reinterpret_cast<ColorBGRA*>(v_tex_data);
	for (int y = 0; y < v_tex_height; y++)
	{
		const int v_cur_stride = y * v_tex_width;
		const float uv_y = float(y) / float(v_tex_height - 1);
		const float uv_y_inv = 1.0f - uv_y;

		for (int x = 0; x < v_tex_width; x++)
		{
			const float uv_x = float(x) / float(v_tex_width - 1);
			auto v_cur_pixel = &v_tex_pixels[x + v_cur_stride];

			const float v_white_mod = (1.0f - uv_x) * uv_y_inv;
			const float v_color_mod = uv_x * uv_y_inv;

			v_cur_pixel->r = std::uint8_t((v_white_mod + v_color_mod * v_color_r) * 255.0f);
			v_cur_pixel->g = std::uint8_t((v_white_mod + v_color_mod * v_color_g) * 255.0f);
			v_cur_pixel->b = std::uint8_t((v_white_mod + v_color_mod * v_color_b) * 255.0f);
			v_cur_pixel->a = 0xFF;
		}
	}

	v_tex->unlock();
}



void BetterPaintToolGui::createTextureGradient()
{
	MyGUI::RenderManager* v_pRendMgr = MyGUI::Singleton<MyGUI::RenderManager>::getInstancePtr();
	if (v_pRendMgr->getTexture("ColorPickerMatrix"))
		return;

	MyGUI::ITexture* v_pTex = v_pRendMgr->createTexture("ColorPickerMatrix");
	v_pTex->createManual(32, 32, MyGUI::TextureUsage::Write | MyGUI::TextureUsage::Static, MyGUI::PixelFormat::R8G8B8A8);
}

void BetterPaintToolGui::createHueGradient()
{
	MyGUI::RenderManager* v_pRendMgr = MyGUI::Singleton<MyGUI::RenderManager>::getInstancePtr();

	if (v_pRendMgr->getTexture("ColorPickerHue") != nullptr)
		return;

	MyGUI::ITexture* v_pTex = v_pRendMgr->createTexture("ColorPickerHue");
	v_pTex->createManual(32, 4, MyGUI::TextureUsage::Static | MyGUI::TextureUsage::Write, MyGUI::PixelFormat::R8G8B8A8);

	const int v_tex_width = v_pTex->getWidth();
	const int v_tex_height = v_pTex->getHeight();
	ColorBGRA* v_tex_pixels = reinterpret_cast<ColorBGRA*>(v_pTex->lock(MyGUI::TextureUsage::Write));

	for (int y = 0; y < v_tex_height; y++)
	{
		const int v_cur_stride = y * v_tex_width;

		for (int x = 0; x < v_tex_width; x++)
		{
			const double v_uv_x = double(x) / double(v_tex_width - 1);
			ColorBGRA* v_cur_pixel = &v_tex_pixels[x + v_cur_stride];
			Color v_pix_data(RatioToRGB(v_uv_x));

			v_cur_pixel->r = v_pix_data.r;
			v_cur_pixel->g = v_pix_data.g;
			v_cur_pixel->b = v_pix_data.b;
			v_cur_pixel->a = 0xff;
		}
	}

	v_pTex->unlock();
}

void BetterPaintToolGui::initializeHooked()
{
	MyGUI::Gui* v_pGui = MyGUI::Singleton<MyGUI::Gui>::getInstancePtr();
	MyGUI::LayoutManager* v_pLayoutManager = MyGUI::Singleton<MyGUI::LayoutManager>::getInstancePtr();
	GuiSystemManager* v_pGuiSysMgr = GuiSystemManager::GetInstance();
	const MyGUI::IntCoord& v_inventory_pos = InGameGuiManager::GetInstance()->m_pInventory->pos;

	m_pMainPanel = v_pGui->createWidget<MyGUI::Widget>(
		"PanelEmpty",
		MyGUI::IntCoord(
			v_pGuiSysMgr->screen_left, v_pGuiSysMgr->screen_top,
			v_pGuiSysMgr->screen_width, v_pGuiSysMgr->screen_height),
		MyGUI::Align::Default,
		"Back",
		"PaintTool");

	m_pMainPanel->setNeedKeyFocus(false);

	CustomPaintToolGui::writeIfNotExists();
	v_pLayoutManager->loadLayout(CustomPaintToolGui::CustomLayoutPath, "", m_pMainPanel);

	MyGUI::Widget* v_pMainPanel = m_pMainPanel->findWidget("MainPanel");
	m_pMainPanel->setSize(v_pMainPanel->getSize());
	m_pMainPanel->setPosition(
		(v_inventory_pos.width - v_pMainPanel->getCoord().width) / 2,
		(v_inventory_pos.height - v_pMainPanel->getCoord().height) / 2);

	{
		//Setup the scroll bars
		this->setupColorSlider("ScrollR", "Red", &BetterPaintToolGui::colorRScrollChangePosition, &BetterPaintToolGui::colorREditTextChanged);
		this->setupColorSlider("ScrollG", "Green", &BetterPaintToolGui::colorGScrollChangePosition, &BetterPaintToolGui::colorGEditTextChanged);
		this->setupColorSlider("ScrollB", "Blue", &BetterPaintToolGui::colorBScrollChangePosition, &BetterPaintToolGui::colorBEditTextChanged);
	}

	{
		//Setup hex input
		MyGUI::EditBox* v_pEditBox = this->getHexInputBox()->castType<MyGUI::EditBox>();

		v_pEditBox->setMaxTextLength(6);
		v_pEditBox->eventEditTextChange += MyGUI::newDelegate(this, &BetterPaintToolGui::eventEditTextChange);
	}

	{
		//Setup PresetColorsTab button
		MyGUI::Button* v_pBtn = this->getPresetColorsTab()->castType<MyGUI::Button>();

		v_pBtn->setStateSelected(true);
		v_pBtn->eventMouseButtonPressed += MyGUI::newDelegate(this, &BetterPaintToolGui::eventPresetColorsTabPressed);
	}

	{
		//Setup CustomColorTab button
		MyGUI::Button* v_pBtn = this->getCustomColorTab()->castType<MyGUI::Button>();

		v_pBtn->setStateSelected(false);
		v_pBtn->eventMouseButtonPressed += MyGUI::newDelegate(this, &BetterPaintToolGui::eventCustomColorTabPressed);
	}

	{
		//Setup the color picker
		this->createTextureGradient();
		this->updateTextureGradient(0xFF00FFFF);

		MyGUI::ImageBox* v_pImgBox = this->getColorPicker()->castType<MyGUI::ImageBox>();
		v_pImgBox->setImageTexture("ColorPickerMatrix");
		v_pImgBox->setImageCoord(MyGUI::IntCoord(1, 1, 30, 30));
		v_pImgBox->eventMouseButtonPressed += MyGUI::newDelegate(this, &BetterPaintToolGui::eventColorMatrixSelectColor);
		v_pImgBox->eventMouseDrag += MyGUI::newDelegate(this, &BetterPaintToolGui::eventColorMatrixSelectColor);
		
		MyGUI::Widget* v_pPtr = v_pImgBox->createWidget<MyGUI::Widget>("WhiteSkin", MyGUI::IntCoord(0, 0, 4, 4), MyGUI::Align::Default, "ColorPickerPointer");
		v_pPtr->setNeedMouseFocus(false);
		v_pPtr->setNeedKeyFocus(false);
	}

	{
		//Setup the hue color picker
		this->createHueGradient();

		MyGUI::ImageBox* v_pImgBox = this->getHsvPicker()->castType<MyGUI::ImageBox>();
		v_pImgBox->setImageTexture("ColorPickerHue");
		v_pImgBox->setImageCoord(MyGUI::IntCoord(1, 1, 30, 30));
		v_pImgBox->eventMouseButtonPressed += MyGUI::newDelegate(this, &BetterPaintToolGui::eventColorHsvSelectColor);
		v_pImgBox->eventMouseDrag += MyGUI::newDelegate(this, &BetterPaintToolGui::eventColorHsvSelectColor);

		MyGUI::Widget* v_pPtr = v_pImgBox->createWidget<MyGUI::Widget>("WhiteSkin", MyGUI::IntCoord(0, 0, 4, v_pImgBox->getSize().height), MyGUI::Align::Default, "HsvPickerPointer");
		v_pPtr->setNeedMouseFocus(false);
		v_pPtr->setNeedKeyFocus(false);
	}

	m_pItemBox = this->getPresetColorsWnd()->findWidget("ColorGrid")->castType<MyGUI::ItemBox>();
	m_pItemBox->requestCoordItem = MyGUI::newDelegate(this, &BetterPaintToolGui::requestCoordItem);
	m_pItemBox->requestCreateWidgetItem = MyGUI::newDelegate(this, &BetterPaintToolGui::requestCreateWidgetItem);
	m_pItemBox->requestDrawItem = MyGUI::newDelegate(this, &BetterPaintToolGui::requestDrawItem);
	m_pItemBox->eventMouseItemActivate += MyGUI::newDelegate(this, &BetterPaintToolGui::eventMouseItemActivate);

	m_pMainPanel->setVisible(false);

	if (m_pGuiInterface)
		m_pGuiInterface->func7("InitFunc", "");
}

void BetterPaintToolGui::initParams(BetterPaintTool* paint_tool)
{
	const Color v_col = paint_tool->m_pNetworkData->paint_color;

	this->updateHsvAndColorPickersFromColor(v_col);
	this->updateHexValueFromColor(v_col);
	this->updateSlidersFromColor(v_col);

	this->switchTabsAndButtons(BetterPaintToolGui::isColorPreset(v_col));
}

void BetterPaintToolGui::h_initialize(BetterPaintToolGui* self)
{
	self->initializeHooked();
}

bool BetterPaintToolGui::isColorPreset(Color col)
{
	//Alpha should always be 255
	col.a = 0xFF;

	constexpr std::size_t v_num_colors = sizeof(g_paintColors) / sizeof(std::uint32_t);
	for (std::size_t a = 0; a < v_num_colors; a++)
		if (col.data == g_paintColors[a]) return true;

	return false;
}