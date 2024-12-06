#include "SmSdk/Gui/VerticalStackBox.hpp"
#include "SmSdk/Gui/GuiSystemManager.hpp"

#include "SmSdk/unreferenced_params.hpp"
#include "SmSdk/Util/Memory.hpp"
#include "SmSdk/offsets.hpp"

#if defined(SMSDK_ENABLE_MYGUI)

VerticalStackBox::VerticalStackBox(MyGUI::IntSize item_sz) :
	m_itemSize(item_sz),
	m_skin("PanelEmpty"),
	m_pParent(nullptr),
	m_pEmptyPanel(nullptr),
	m_pScrollBar(nullptr),
	m_bEnableSeparators(true),
	some_val3(0),
	some_val4(4),
	m_scrollDistance(item_sz.height),
	m_scrollValue(0),
	some_val7(0),
	m_panelPos(0, 0),
	m_vecWidgets(),
	m_separatorColor(0.25490198f, 0.25490198f, 0.25490198f)
{}

void VerticalStackBox::onParentChangeCoord(MyGUI::Widget* caller)
{
	SMSDK_UNREF(caller);
	this->updateScrollBar();
}

void VerticalStackBox::onPanelScroll(MyGUI::Widget* caller, int scroll_val)
{
	SMSDK_UNREF(caller);

	m_panelPos.top = GuiSystemManager::ProcessScroll(
		m_scrollValue, m_scrollDistance, m_panelPos.top, scroll_val,
		GuiSystemManager::GetInstance()->getOptionItemSize2());

	m_pEmptyPanel->setPosition(m_panelPos);
	if (m_pScrollBar)
		m_pScrollBar->setScrollPosition(-m_panelPos.top);
}

void VerticalStackBox::onScrollbarChangePosition(MyGUI::ScrollBar* caller, size_t pos)
{
	SMSDK_UNREF(caller);

	if (!m_pParent->getVisible())
		return;

	m_panelPos.top = -int(pos);
	m_pEmptyPanel->setPosition(m_panelPos);
}

void VerticalStackBox::initialize(MyGUI::Widget* parent, MyGUI::ScrollBar* scroll_bar)
{
	m_pParent = parent;
	m_pScrollBar = scroll_bar;

	m_pParent->eventChangeCoord += MyGUI::newDelegate(this, &VerticalStackBox::onParentChangeCoord);

	m_pEmptyPanel = m_pParent->createWidget<MyGUI::Widget>(
		"PanelEmpty", MyGUI::IntCoord(0, 0, m_pParent->getWidth(), 0), MyGUI::Align::Default);
	
	m_pEmptyPanel->eventMouseWheel += MyGUI::newDelegate(this, &VerticalStackBox::onPanelScroll);
	if (m_pScrollBar)
		m_pScrollBar->eventScrollChangePosition += MyGUI::newDelegate(this, &VerticalStackBox::onScrollbarChangePosition);
}

void VerticalStackBox::onItemChangeCoord(MyGUI::Widget* caller)
{
	const std::size_t* v_idx = caller->getUserData<std::size_t>();
	if (!v_idx) return;

	const std::size_t v_item_idx = (*v_idx) + 1;

	if (v_item_idx >= m_vecWidgets.size())
	{
		if (caller == m_vecWidgets[m_vecWidgets.size() - 1])
		{
			const MyGUI::IntSize v_sz = m_pEmptyPanel->getSize();
			m_pEmptyPanel->setSize(MyGUI::IntSize(v_sz.width, caller->getBottom()));
			this->updateScrollBar();
		}
	}
	else
	{
		MyGUI::Widget* v_cur_widget = m_vecWidgets[v_item_idx];
		const MyGUI::IntPoint v_cur_pos = v_cur_widget->getPosition();

		v_cur_widget->setPosition(MyGUI::IntPoint(v_cur_pos.left, caller->getBottom()));
	}
}

void VerticalStackBox::onItemScroll(MyGUI::Widget* caller, int scroll_val)
{
	this->m_pEmptyPanel->_riseMouseWheel(scroll_val);
}

void VerticalStackBox::updateScrollBar()
{
	const int v_parent_height = m_pParent->getHeight();
	const int v_panel_height = m_pEmptyPanel->getHeight();

	int v_height_diff, v_height_diff_div;

	if (v_panel_height <= v_parent_height)
	{
		v_height_diff = 0;
		v_height_diff_div = 0;
	}
	else
	{
		v_height_diff = v_panel_height - v_parent_height;
		v_height_diff_div = int(float(v_height_diff) / float(m_scrollDistance));
	}

	m_scrollValue = v_height_diff;
	this->some_val7 = v_height_diff_div;

	if (m_pParent->getVisible() && m_pScrollBar)
	{
		m_pScrollBar->setScrollRange(std::size_t(m_scrollValue) + 1);
		m_pScrollBar->setScrollPage(std::size_t(m_scrollDistance));
		m_pScrollBar->setScrollViewPage(m_pParent->getWidth());

		m_pScrollBar->setTrackSize((v_parent_height * m_pScrollBar->getLineSize()) / v_panel_height);
		m_pScrollBar->setScrollPosition(-m_pEmptyPanel->getTop());
	}

	if (-m_panelPos.top > m_scrollValue)
	{
		m_panelPos.top = -m_scrollValue;
		m_pEmptyPanel->setPosition(m_panelPos);
	}
}

MyGUI::Widget* VerticalStackBox::createNewOption()
{
	const float v_optItemSz = GuiSystemManager::GetInstance()->getOptionItemSize();
	const int v_offset = m_vecWidgets.empty()
		? 0 : m_vecWidgets[m_vecWidgets.size() - 1]->getBottom();

	const MyGUI::IntCoord v_new_item_coords(
		0,
		v_offset,
		int(float(m_itemSize.width) * v_optItemSz),
		int(float(m_itemSize.height) * v_optItemSz));

	MyGUI::Widget* v_new_widget = m_pEmptyPanel->createWidget<MyGUI::Widget>(
		m_skin, v_new_item_coords, MyGUI::Align::Default);

	if (!m_vecWidgets.empty() && m_bEnableSeparators)
	{
		const int v_some_offset = std::max(m_itemSize.width - this->some_val4 - this->some_val3, 0);

		const MyGUI::IntCoord v_sep_coords(
			int(float(this->some_val3) * v_optItemSz), 0,
			int(float(v_some_offset) * v_optItemSz), 1);

		MyGUI::Widget* v_separator = v_new_widget->createWidget<MyGUI::Widget>(
			"WhiteSkin", v_sep_coords, MyGUI::Align::HStretch);

		v_separator->setNeedMouseFocus(false);
		v_separator->setColour(m_separatorColor);
	}

	v_new_widget->setUserData(m_vecWidgets.size());
	v_new_widget->eventChangeCoord += MyGUI::newDelegate(this, &VerticalStackBox::onItemChangeCoord);
	v_new_widget->eventMouseWheel += MyGUI::newDelegate(this, &VerticalStackBox::onItemScroll);

	m_pEmptyPanel->setSize(m_pEmptyPanel->getWidth(), v_new_widget->getBottom());
	m_vecWidgets.push_back(v_new_widget);
	
	this->updateScrollBar();
	return v_new_widget;
}

void VerticalStackBox::clearItems()
{
	for (MyGUI::Widget* v_cur_widget : m_vecWidgets)
		m_pEmptyPanel->_destroyChildWidget(v_cur_widget);

	m_vecWidgets.clear();
	m_pEmptyPanel->setSize(m_pEmptyPanel->getWidth(), 0);
}

#endif