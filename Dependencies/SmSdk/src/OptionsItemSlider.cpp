#include "SmSdk/Gui/OptionsItemSlider.hpp"

#if defined(SMSDK_ENABLE_MYGUI)

OptionsItemSlider::OptionsItemSlider(
	MyGUI::Widget* widget,
	const std::string& caption,
	float min_value,
	float max_value,
	std::size_t scroll_range
) :
	OptionsItemBase(),
	m_pSlider(nullptr),
	m_pValueTextBox(nullptr),
	m_uSteps(scroll_range),
	m_fMinValue(min_value),
	m_fMaxValue(max_value)
{
	this->initializeSlider(widget, caption);
	m_pSlider->setScrollRange(m_uSteps + 1);
}

void OptionsItemSlider::initializeSlider(MyGUI::Widget* parent, const std::string& caption)
{
	MyGUI::LayoutManager::getInstance().loadLayout(
		"$GAME_DATA/Gui/Layouts/Options/OptionsItem_Slider.layout", "", parent);

	parent->findWidget("Name")->castType<MyGUI::TextBox>()->setCaptionWithReplacing(caption);

	m_pSlider = parent->findWidget("Slider")->castType<MyGUI::ScrollBar>();
	m_pValueTextBox = parent->findWidget("Value")->castType<MyGUI::TextBox>();
}

void OptionsItemSlider::updateValueText()
{
	m_pValueTextBox->setCaption(std::to_string(m_pSlider->getScrollPosition()));
}

inline static float lerp(float a, float b, float f)
{
	return a + f * (b - a);
}

float OptionsItemSlider::getFraction() const
{
	const float v_fraction = float(m_pSlider->getScrollPosition()) / float(m_uSteps);
	return lerp(m_fMinValue, m_fMaxValue, v_fraction);
}

#endif