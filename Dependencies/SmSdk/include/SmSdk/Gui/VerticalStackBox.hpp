#pragma once

#include "SmSdk/mygui_include.hpp"
#include "SmSdk/config.hpp"

SMSDK_BEGIN_NAMESPACE

class VerticalStackBox
{
#if defined(SMSDK_ENABLE_MYGUI)
	SDK_PUB VerticalStackBox(MyGUI::IntSize item_sz);

	SDK_PUB void onParentChangeCoord(MyGUI::Widget* pCaller);
	SDK_PUB void onPanelScroll(MyGUI::Widget* pCaller, int iScrollVal);
	SDK_PUB void onScrollbarChangePosition(MyGUI::ScrollBar* pCaller, size_t uPos);
	SDK_PUB void initialize(MyGUI::Widget* pParent, MyGUI::ScrollBar* pScrollBar);

	SDK_PUB void onItemChangeCoord(MyGUI::Widget* pCaller);
	SDK_PUB void onItemScroll(MyGUI::Widget* pCaller, int iScrollVal);
	SDK_PUB void updateScrollBar();
	SDK_PUB MyGUI::Widget* createNewOption();
	SDK_PUB void clearItems();
#endif

	/* 0x0000 */ SDK_PUB MyGUI::IntSize m_itemSize;
	/* 0x0008 */ SDK_PUB std::string m_skin;
	/* 0x0028 */ SDK_PUB MyGUI::Widget* m_pParent;
	/* 0x0030 */ SDK_PUB MyGUI::Widget* m_pEmptyPanel;
	/* 0x0038 */ SDK_PUB MyGUI::ScrollBar* m_pScrollBar;
	/* 0x0040 */ SDK_PUB bool m_bEnableSeparators;
	/* 0x0041 */ SDK_PRI char pad_0x41[0x3];
	/* 0x0044 */ SDK_PRI std::int32_t m_iSomeVal3;
	/* 0x0048 */ SDK_PRI std::int32_t m_iSomeVal4;
	/* 0x004C */ SDK_PUB std::int32_t m_iScrollDistance;
	/* 0x0050 */ SDK_PUB std::int32_t m_iScrollValue;
	/* 0x0054 */ SDK_PRI std::int32_t m_iSomeVal7;
	/* 0x0058 */ SDK_PUB MyGUI::IntPoint m_panelPos;
	/* 0x0060 */ SDK_PUB std::vector<MyGUI::Widget*> m_vecWidgets;
	/* 0x0078 */ SDK_PUB MyGUI::Colour m_separatorColor;
}; // Size: 0x88

static_assert(offsetof(VerticalStackBox, VerticalStackBox::m_itemSize) == 0x0, "VerticalStackBox::m_itemSize: Incorrect offset");
static_assert(offsetof(VerticalStackBox, VerticalStackBox::m_skin) == 0x8, "VerticalStackBox::m_skin: Incorrect offset");
static_assert(offsetof(VerticalStackBox, VerticalStackBox::m_pParent) == 0x28, "VerticalStackBox::m_pParent: Incorrect offset");
static_assert(offsetof(VerticalStackBox, VerticalStackBox::m_pEmptyPanel) == 0x30, "VerticalStackBox::m_pEmptyPanel: Incorrect offset");
static_assert(offsetof(VerticalStackBox, VerticalStackBox::m_pScrollBar) == 0x38, "VerticalStackBox::m_pScrollBar: Incorrect offset");
static_assert(offsetof(VerticalStackBox, VerticalStackBox::m_bEnableSeparators) == 0x40, "VerticalStackBox::m_bEnableSeparators: Incorrect offset");
static_assert(offsetof(VerticalStackBox, VerticalStackBox::m_iScrollDistance) == 0x4C, "VerticalStackBox::m_iScrollDistance: Incorrect offset");
static_assert(offsetof(VerticalStackBox, VerticalStackBox::m_iScrollValue) == 0x50, "VerticalStackBox::m_iScrollValue: Incorrect offset");
static_assert(offsetof(VerticalStackBox, VerticalStackBox::m_panelPos) == 0x58, "VerticalStackBox::m_panelPos: Incorrect offset");
static_assert(offsetof(VerticalStackBox, VerticalStackBox::m_vecWidgets) == 0x60, "VerticalStackBox::m_vecWidgets: Incorrect offset");
static_assert(offsetof(VerticalStackBox, VerticalStackBox::m_separatorColor) == 0x78, "VerticalStackBox::m_separatorColor: Incorrect offset");

static_assert(sizeof(VerticalStackBox) == 0x88, "VerticalStackBox: Incorrect Size");

SMSDK_END_NAMESPACE