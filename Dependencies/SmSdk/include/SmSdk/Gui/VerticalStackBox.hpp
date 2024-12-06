#pragma once

#include "SmSdk/mygui_include.hpp"

class VerticalStackBox
{
public:
#if defined(SMSDK_ENABLE_MYGUI)
	VerticalStackBox(MyGUI::IntSize item_sz);

	void onParentChangeCoord(MyGUI::Widget* caller);
	void onPanelScroll(MyGUI::Widget* caller, int scroll_val);
	void onScrollbarChangePosition(MyGUI::ScrollBar* caller, size_t pos);
	void initialize(MyGUI::Widget* parent, MyGUI::ScrollBar* scroll_bar);

	void onItemChangeCoord(MyGUI::Widget* caller);
	void onItemScroll(MyGUI::Widget* caller, int scroll_val);
	void updateScrollBar();
	MyGUI::Widget* createNewOption();
	void clearItems();
#endif

public:
	/* 0x0000 */ MyGUI::IntSize m_itemSize;
	/* 0x0008 */ std::string m_skin;
	/* 0x0028 */ MyGUI::Widget* m_pParent;
	/* 0x0030 */ MyGUI::Widget* m_pEmptyPanel;
	/* 0x0038 */ MyGUI::ScrollBar* m_pScrollBar;
	/* 0x0040 */ bool m_bEnableSeparators;
private:
	/* 0x0041 */ char pad_0x41[0x3];
public:
	/* 0x0044 */ __int32 some_val3;
	/* 0x0048 */ __int32 some_val4;
	/* 0x004C */ __int32 m_scrollDistance;
	/* 0x0050 */ __int32 m_scrollValue;
	/* 0x0054 */ __int32 some_val7;
	/* 0x0058 */ MyGUI::IntPoint m_panelPos;
	/* 0x0060 */ std::vector<MyGUI::Widget*> m_vecWidgets;
	/* 0x0078 */ MyGUI::Colour m_separatorColor;
}; // Size: 0x88

static_assert(offsetof(VerticalStackBox, VerticalStackBox::m_itemSize) == 0x0, "VerticalStackBox::m_itemSize: Incorrect offset");
static_assert(offsetof(VerticalStackBox, VerticalStackBox::m_skin) == 0x8, "VerticalStackBox::m_skin: Incorrect offset");
static_assert(offsetof(VerticalStackBox, VerticalStackBox::m_pParent) == 0x28, "VerticalStackBox::m_pParent: Incorrect offset");
static_assert(offsetof(VerticalStackBox, VerticalStackBox::m_pEmptyPanel) == 0x30, "VerticalStackBox::m_pEmptyPanel: Incorrect offset");
static_assert(offsetof(VerticalStackBox, VerticalStackBox::m_pScrollBar) == 0x38, "VerticalStackBox::m_pScrollBar: Incorrect offset");
static_assert(offsetof(VerticalStackBox, VerticalStackBox::m_bEnableSeparators) == 0x40, "VerticalStackBox::m_bEnableSeparators: Incorrect offset");
static_assert(offsetof(VerticalStackBox, VerticalStackBox::some_val3) == 0x44, "VerticalStackBox::some_val3: Incorrect offset");
static_assert(offsetof(VerticalStackBox, VerticalStackBox::some_val4) == 0x48, "VerticalStackBox::some_val4: Incorrect offset");
static_assert(offsetof(VerticalStackBox, VerticalStackBox::m_scrollDistance) == 0x4C, "VerticalStackBox::m_scrollDistance: Incorrect offset");
static_assert(offsetof(VerticalStackBox, VerticalStackBox::m_scrollValue) == 0x50, "VerticalStackBox::m_scrollValue: Incorrect offset");
static_assert(offsetof(VerticalStackBox, VerticalStackBox::some_val7) == 0x54, "VerticalStackBox::some_val7: Incorrect offset");
static_assert(offsetof(VerticalStackBox, VerticalStackBox::m_panelPos) == 0x58, "VerticalStackBox::m_panelPos: Incorrect offset");
static_assert(offsetof(VerticalStackBox, VerticalStackBox::m_vecWidgets) == 0x60, "VerticalStackBox::m_vecWidgets: Incorrect offset");
static_assert(offsetof(VerticalStackBox, VerticalStackBox::m_separatorColor) == 0x78, "VerticalStackBox::m_separatorColor: Incorrect offset");

static_assert(sizeof(VerticalStackBox) == 0x88, "VerticalStackBox: Incorrect Size");