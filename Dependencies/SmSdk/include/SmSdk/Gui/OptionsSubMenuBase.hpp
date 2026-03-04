#pragma once

#include "SmSdk/unreferenced_params.hpp"
#include "SmSdk/mygui_include.hpp"
#include "SmSdk/Util/Memory.hpp"
#include "SmSdk/offsets.hpp"

#include "SmSdk/Gui/VerticalStackBox.hpp"
#include "SmSdk/Gui/OptionsItemBase.hpp"

#include <vector>

SMSDK_BEGIN_NAMESPACE

class OptionsSubMenuBase
{
	SDK_PUB static void GameConstructor(OptionsSubMenuBase* self)
	{
		using fSubMenuBaseConstructor = void (*)(OptionsSubMenuBase*);
		Memory::Read<fSubMenuBaseConstructor>(SM_CONSTRUCTOR_OPTIONS_SUB_MENU_BASE_OFFSET)(self);
	}

#if defined(SMSDK_ENABLE_MYGUI)
	SDK_PUB OptionsSubMenuBase();
#endif
	SDK_PUB virtual ~OptionsSubMenuBase() = default;

#if defined(SMSDK_ENABLE_MYGUI)
	SDK_PUB void onScrollChangePos(MyGUI::ScrollBar* pCaller, size_t iPos);
	SDK_PUB void onScroll(MyGUI::Widget* pCaller, int iScrollVal);
	SDK_PUB void updateScrollArea();
	SDK_PUB void updateScrollAreaAndScrollBar();
	//Does not update the scroll bar
	SDK_PUB void clearSilent();
	SDK_PUB void clear();
#endif

	SDK_PUB virtual void initialize(MyGUI::Widget* pParent) DEFAULT_IMPL_UNREF(pParent);

	SDK_PUB virtual void cleanOptionItems() DEFAULT_IMPL();
	SDK_PUB virtual void openMenu() DEFAULT_IMPL();
	SDK_PUB virtual void closeMenu() DEFAULT_IMPL();

	SDK_PUB virtual void onUpdate() {}

	SDK_PRI virtual bool someFunc2() { return 0; }
	SDK_PRI virtual bool someFunc3() { return 0; }
	SDK_PUB virtual void restoreDefaults() = 0;

#if _SM_VERSION_NUM >= 070771
	SDK_PRI virtual void someFunc5() {}
#endif
	SDK_PRI virtual void someFunc4() {}

	/* 0x0008 */ SDK_PUB MyGUI::Widget* m_pSubMenuWidget;
	/* 0x0010 */ SDK_PUB MyGUI::Widget* m_pContainerHostPanel;
	/* 0x0018 */ SDK_PUB MyGUI::Widget* m_pContainer;
	/* 0x0020 */ SDK_PUB MyGUI::ScrollBar* m_pScrollBar;
	/* 0x0028 */ SDK_PUB MyGUI::IntSize m_itemSize;
	/* 0x0030 */ SDK_PUB VerticalStackBox m_leftStackBox;
	/* 0x00B8 */ SDK_PUB VerticalStackBox m_rightStackBox;
	/* 0x0140 */ SDK_PUB std::vector<std::shared_ptr<OptionsItemBase>> m_vecOptionItems;
	/* 0x0158 */ SDK_PUB std::int32_t m_iScrollValue;
	/* 0x015C */ SDK_PUB MyGUI::IntPoint m_containerPos;
	/* 0x0164 */ SDK_PRI char pad_0x164[0x4];
}; // Size: 0x168

static_assert(offsetof(OptionsSubMenuBase, OptionsSubMenuBase::m_pSubMenuWidget) == 0x8, "OptionsSubMenuBase::m_pSubMenuWidget: Incorrect offset");
static_assert(offsetof(OptionsSubMenuBase, OptionsSubMenuBase::m_pContainerHostPanel) == 0x10, "OptionsSubMenuBase::m_pContainerHostPanel: Incorrect offset");
static_assert(offsetof(OptionsSubMenuBase, OptionsSubMenuBase::m_pContainer) == 0x18, "OptionsSubMenuBase::m_pContainer: Incorrect offset");
static_assert(offsetof(OptionsSubMenuBase, OptionsSubMenuBase::m_pScrollBar) == 0x20, "OptionsSubMenuBase::m_pScrollBar: Incorrect offset");
static_assert(offsetof(OptionsSubMenuBase, OptionsSubMenuBase::m_itemSize) == 0x28, "OptionsSubMenuBase::m_itemSize: Incorrect offset");
static_assert(offsetof(OptionsSubMenuBase, OptionsSubMenuBase::m_leftStackBox) == 0x30, "OptionsSubMenuBase::m_leftStackBox: Incorrect offset");
static_assert(offsetof(OptionsSubMenuBase, OptionsSubMenuBase::m_rightStackBox) == 0xB8, "OptionsSubMenuBase::m_rightStackBox: Incorrect offset");
static_assert(offsetof(OptionsSubMenuBase, OptionsSubMenuBase::m_vecOptionItems) == 0x140, "OptionsSubMenuBase::m_vecOptionItems: Incorrect offset");
static_assert(offsetof(OptionsSubMenuBase, OptionsSubMenuBase::m_iScrollValue) == 0x158, "OptionsSubMenuBase::m_iScrollValue: Incorrect offset");
static_assert(offsetof(OptionsSubMenuBase, OptionsSubMenuBase::m_containerPos) == 0x15C, "OptionsSubMenuBase::m_containerPos: Incorrect offset");

static_assert(sizeof(OptionsSubMenuBase) == 0x168, "OptionsSubMenuBase: Incorrect Size");

SMSDK_END_NAMESPACE