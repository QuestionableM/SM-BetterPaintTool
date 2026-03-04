#include "SmSdk/Gui/OptionsSubMenuBase.hpp"
#include "SmSdk/Gui/GuiSystemManager.hpp"

#include "SmSdk/unreferenced_params.hpp"
#include "SmSdk/config.hpp"

SMSDK_USE_NAMESPACE

#if defined(SMSDK_ENABLE_MYGUI)

OptionsSubMenuBase::OptionsSubMenuBase() : m_pSubMenuWidget(nullptr),
                                           m_pContainerHostPanel(nullptr),
                                           m_pContainer(nullptr),
                                           m_pScrollBar(nullptr),
                                           m_itemSize(456, 40),
                                           m_leftStackBox(m_itemSize),
                                           m_rightStackBox(m_itemSize),
                                           m_vecOptionItems(),
                                           m_iScrollValue(0),
                                           m_containerPos(0, 0) {}

void OptionsSubMenuBase::onScrollChangePos(MyGUI::ScrollBar* pCaller, size_t iPos)
{
	SMSDK_UNREF(pCaller);

	m_containerPos.top = -int(iPos);
	m_pContainer->setPosition(m_containerPos);
	this->someFunc4();
}

void OptionsSubMenuBase::onScroll(MyGUI::Widget* pCaller, int iScrollVal)
{
	SMSDK_UNREF(pCaller);

	m_containerPos.top = GuiSystemManager::ProcessScroll(
	    m_iScrollValue, m_itemSize.height, m_containerPos.top, iScrollVal,
	    GuiSystemManager::GetInstance()->getOptionItemSize());

	m_pContainer->setPosition(m_containerPos);
	if (m_pScrollBar)
		m_pScrollBar->setScrollPosition(-m_containerPos.top);
	this->someFunc4();
}

void OptionsSubMenuBase::updateScrollArea()
{
	const MyGUI::IntSize leftSize = m_leftStackBox.m_pEmptyPanel->getSize();
	const MyGUI::IntSize rightSize = m_rightStackBox.m_pEmptyPanel->getSize();
	const int iHeight = std::max(leftSize.height, rightSize.height);

	m_pSubMenuWidget->findWidget("LeftStack")->setSize(leftSize);
	m_pSubMenuWidget->findWidget("RightStack")->setSize(rightSize);

	m_pContainer->setSize(m_pContainer->getWidth(), iHeight);
	m_iScrollValue = (iHeight <= m_pContainerHostPanel->getHeight())
	    ? 0
	    : iHeight - m_pContainerHostPanel->getHeight();

	if (m_pContainerHostPanel->getVisible())
	{
		const float v_ratio = GuiSystemManager::GetInstance()->getOptionItemSize();
		m_pScrollBar->setScrollRange(size_t(m_iScrollValue) + 1);

		const size_t v_page_val = size_t(float(m_itemSize.height) * v_ratio);
		m_pScrollBar->setScrollPage(v_page_val);
		m_pScrollBar->setScrollWheelPage(v_page_val);
		m_pScrollBar->setScrollViewPage(size_t(m_pContainerHostPanel->getWidth()));

		const int v_track_sz = int(float(m_pContainerHostPanel->getHeight()) * float(m_pScrollBar->getLineSize()) / float(iHeight));
		m_pScrollBar->setTrackSize(v_track_sz);
		m_pScrollBar->setScrollPosition(-m_pContainer->getTop());
	}

	if (-m_containerPos.top > m_iScrollValue)
	{
		m_containerPos.top = -m_iScrollValue;
		m_pContainer->setPosition(m_containerPos);
		this->someFunc4();
	}
}

void OptionsSubMenuBase::updateScrollAreaAndScrollBar()
{
	this->updateScrollArea();
	m_pScrollBar->setVisible(m_iScrollValue > 0);
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

void OptionsSubMenuBase::initialize(MyGUI::Widget* pParent)
{
	m_pSubMenuWidget = MyGUI::LayoutManager::getInstance().loadLayout(
	    "$GAME_DATA/Gui/Layouts/Options/Options_SubMenu.layout",
	    "",
	    pParent)[0];

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
	m_vecOptionItems.clear();
}

void OptionsSubMenuBase::openMenu()
{
	for (auto& v_cur_item : m_vecOptionItems)
		v_cur_item->update();

	m_pScrollBar->setVisible(m_iScrollValue > 0);
	m_pSubMenuWidget->setVisible(true);
}

void OptionsSubMenuBase::closeMenu()
{
	m_pSubMenuWidget->setVisible(false);
}

#endif