#include "SmSdk/Gui/OptionsSubMenuBase.hpp"
#include "SmSdk/Gui/GuiSystemManager.hpp"

#include "SmSdk/unreferenced_params.hpp"

#if defined(SMSDK_ENABLE_MYGUI)

OptionsSubMenuBase::OptionsSubMenuBase() :
	m_pSubMenuWidget(nullptr),
	m_pContainerHostPanel(nullptr),
	m_pContainer(nullptr),
	m_pScrollBar(nullptr),
	m_itemSize(456, 40),
	m_leftStackBox(m_itemSize),
	m_rightStackBox(m_itemSize),
	m_optionItems(),
	m_scrollValue(0),
	m_containerPos(0, 0)
{}

void OptionsSubMenuBase::onScrollChangePos(MyGUI::ScrollBar* caller, std::size_t pos)
{
	SMSDK_UNREF(caller);

	m_containerPos.top = -int(pos);
	m_pContainer->setPosition(m_containerPos);
	this->someFunc4();
}

void OptionsSubMenuBase::onScroll(MyGUI::Widget* caller, int scroll_val)
{
	SMSDK_UNREF(caller);

	m_containerPos.top = GuiSystemManager::ProcessScroll(
		m_scrollValue, m_itemSize.height, m_containerPos.top, scroll_val,
		GuiSystemManager::GetInstance()->getOptionItemSize());

	m_pContainer->setPosition(m_containerPos);
	if (m_pScrollBar)
		m_pScrollBar->setScrollPosition(-m_containerPos.top);
	this->someFunc4();
}

void OptionsSubMenuBase::updateScrollArea()
{
	const MyGUI::IntSize v_left_sz = m_leftStackBox.m_pEmptyPanel->getSize();
	const MyGUI::IntSize v_right_sz = m_rightStackBox.m_pEmptyPanel->getSize();
	const int v_height = std::max(v_left_sz.height, v_right_sz.height);

	m_pSubMenuWidget->findWidget("LeftStack")->setSize(v_left_sz);
	m_pSubMenuWidget->findWidget("RightStack")->setSize(v_right_sz);

	m_pContainer->setSize(m_pContainer->getWidth(), v_height);
	m_scrollValue = (v_height <= m_pContainerHostPanel->getHeight())
		? 0 : v_height - m_pContainerHostPanel->getHeight();

	if (m_pContainerHostPanel->getVisible())
	{
		const float v_ratio = GuiSystemManager::GetInstance()->getOptionItemSize();
		m_pScrollBar->setScrollRange(std::size_t(m_scrollValue) + 1);

		const std::size_t v_page_val = std::size_t(float(m_itemSize.height) * v_ratio);
		m_pScrollBar->setScrollPage(v_page_val);
		m_pScrollBar->setScrollWheelPage(v_page_val);
		m_pScrollBar->setScrollViewPage(std::size_t(m_pContainerHostPanel->getWidth()));

		const int v_track_sz = int(float(m_pContainerHostPanel->getHeight())
			* float(m_pScrollBar->getLineSize()) / float(v_height));
		m_pScrollBar->setTrackSize(v_track_sz);
		m_pScrollBar->setScrollPosition(-m_pContainer->getTop());
	}

	if (-m_containerPos.top > m_scrollValue)
	{
		m_containerPos.top = -m_scrollValue;
		m_pContainer->setPosition(m_containerPos);
		this->someFunc4();
	}
}

void OptionsSubMenuBase::updateScrollAreaAndScrollBar()
{
	this->updateScrollArea();
	m_pScrollBar->setVisible(m_scrollValue > 0);
}

void OptionsSubMenuBase::clearSilent()
{
	this->cleanOptionItems();

	m_leftStackBox.clearItems();
	m_rightStackBox.clearItems();
}

void OptionsSubMenuBase::clear()
{
	this->clearSilent();
	this->updateScrollAreaAndScrollBar();
}

void OptionsSubMenuBase::initialize(MyGUI::Widget* parent)
{
	m_pSubMenuWidget = MyGUI::LayoutManager::getInstance().loadLayout(
		"$GAME_DATA/Gui/Layouts/Options/Options_SubMenu.layout",
		"",
		parent)[0];

	m_pContainerHostPanel = m_pSubMenuWidget->findWidget("ContainerHostPanel");

	m_pContainer = m_pSubMenuWidget->findWidget("Container");
	m_pContainer->eventMouseWheel += MyGUI::newDelegate(this, &OptionsSubMenuBase::onScroll);

	m_leftStackBox.initialize(m_pSubMenuWidget->findWidget("LeftStack"), nullptr);
	m_leftStackBox.m_pEmptyPanel->eventMouseWheel += MyGUI::newDelegate(this, &OptionsSubMenuBase::onScroll);

	m_rightStackBox.initialize(m_pSubMenuWidget->findWidget("RightStack"), nullptr);
	m_rightStackBox.m_pEmptyPanel->eventMouseWheel += MyGUI::newDelegate(this, &OptionsSubMenuBase::onScroll);

	m_pScrollBar = m_pSubMenuWidget->findWidget("Scroll")->castType<MyGUI::ScrollBar>();
	m_pScrollBar->eventScrollChangePosition += MyGUI::newDelegate(this, &OptionsSubMenuBase::onScrollChangePos);

	m_pSubMenuWidget->setVisible(false);
}

void OptionsSubMenuBase::cleanOptionItems()
{
	m_optionItems.clear();
}

void OptionsSubMenuBase::openMenu()
{
	for (auto& v_cur_item : m_optionItems)
		v_cur_item->update();

	m_pScrollBar->setVisible(m_scrollValue > 0);
	m_pSubMenuWidget->setVisible(true);
}

void OptionsSubMenuBase::closeMenu()
{
	m_pSubMenuWidget->setVisible(false);
}

#endif