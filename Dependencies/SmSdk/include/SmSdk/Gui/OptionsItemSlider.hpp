#pragma once

#include "SmSdk/Gui/OptionsItemBase.hpp"

#include "SmSdk/Util/Memory.hpp"
#include "SmSdk/offsets.hpp"

#include <functional>
#include <string>

SMSDK_BEGIN_NAMESPACE

class OptionsItemSlider : public OptionsItemBase
{
	SDK_PUB virtual ~OptionsItemSlider() = default;

#if defined(SMSDK_ENABLE_MYGUI)
	SDK_PUB OptionsItemSlider(
	    MyGUI::Widget* pWidget,
	    const std::string& caption,
	    float fMinValue,
	    float fMaxValue,
	    size_t iScrollRange);

	SDK_PUB void initializeSlider(MyGUI::Widget* pParent, const std::string& caption);
	SDK_PUB void updateValueText();
	SDK_PUB float getFraction() const;
#endif

	SDK_PUB void update() override {}
	
	SDK_PUB MyGUI::ScrollBar* m_pSlider;
	SDK_PUB MyGUI::TextBox* m_pValueTextBox;
	SDK_PUB size_t m_uSteps;
	SDK_PUB float m_fMinValue;
	SDK_PUB float m_fMaxValue;
};

static_assert(offsetof(OptionsItemSlider, OptionsItemSlider::m_pSlider) == 0x10, "OptionsItemSlider::m_pSlider: Incorrect offset");

SMSDK_END_NAMESPACE