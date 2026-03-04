#include "SmSdk/Gui/VerticalStackBox.hpp"
#include "SmSdk/Gui/GuiSystemManager.hpp"

#include "SmSdk/unreferenced_params.hpp"
#include "SmSdk/Util/Memory.hpp"
#include "SmSdk/offsets.hpp"

SMSDK_USE_NAMESPACE

#if defined(SMSDK_ENABLE_MYGUI)

VerticalStackBox::VerticalStackBox(MyGUI::IntSize item_sz) : m_itemSize(item_sz),
                                                             m_skin("PanelEmpty"),
                                                             m_pParent(nullptr),
                                                             m_pEmptyPanel(nullptr),
                                                             m_pScrollBar(nullptr),
                                                             m_bEnableSeparators(true),
                                                             m_iSomeVal3(0),
                                                             m_iSomeVal4(4),
                                                             m_iScrollDistance(item_sz.height),
                                                             m_iScrollValue(0),
                                                             m_iSomeVal7(0),
                                                             m_panelPos(0, 0),
                                                             m_vecWidgets(),
                                                             m_separatorColor(0.25490198f, 0.25490198f, 0.25490198f) {}

void VerticalStackBox::onParentChangeCoord(MyGUI::Widget* pCaller)
{
	SMSDK_UNREF(pCaller);
	this->updateScrollBar();
}

void VerticalStackBox::onPanelScroll(MyGUI::Widget* pCaller, int iScrollVal)
{
	SMSDK_UNREF(pCaller);

	m_panelPos.top = GuiSystemManager::ProcessScroll(
	    m_iScrollValue, m_iScrollDistance, m_panelPos.top, iScrollVal,
	    GuiSystemManager::GetInstance()->getOptionItemSize2());

	m_pEmptyPanel->setPosition(m_panelPos);
	if (m_pScrollBar)
		m_pScrollBar->setScrollPosition(-m_panelPos.top);
}

void VerticalStackBox::onScrollbarChangePosition(MyGUI::ScrollBar* pCaller, size_t uPos)
{
	SMSDK_UNREF(pCaller);

	if (!m_pParent->getVisible())
		return;

	m_panelPos.top = -int(uPos);
	m_pEmptyPanel->setPosition(m_panelPos);
}

void VerticalStackBox::initialize(MyGUI::Widget* pParent, MyGUI::ScrollBar* pScrollBar)
{
	m_pParent = pParent;
	m_pScrollBar = pScrollBar;

	m_pParent->eventChangeCoord += MyGUI::newDelegate(this, &VerticalStackBox::onParentChangeCoord);

	m_pEmptyPanel = m_pParent->createWidget<MyGUI::Widget>(
	    "PanelEmpty", MyGUI::IntCoord(0, 0, m_pParent->getWidth(), 0), MyGUI::Align::Default);

	m_pEmptyPanel->eventMouseWheel += MyGUI::newDelegate(this, &VerticalStackBox::onPanelScroll);
	if (m_pScrollBar)
		m_pScrollBar->eventScrollChangePosition += MyGUI::newDelegate(this, &VerticalStackBox::onScrollbarChangePosition);
}

void VerticalStackBox::onItemChangeCoord(MyGUI::Widget* pCaller)
{
	const size_t* pIdx = pCaller->getUserData<size_t>();
	if (!pIdx)
		return;

	const size_t uItemIdx = (*pIdx) + 1;

	if (uItemIdx >= m_vecWidgets.size())
	{
		if (pCaller == m_vecWidgets[m_vecWidgets.size() - 1])
		{
			const MyGUI::IntSize size = m_pEmptyPanel->getSize();
			m_pEmptyPanel->setSize(MyGUI::IntSize(size.width, pCaller->getBottom()));
			this->updateScrollBar();
		}
	}
	else
	{
		MyGUI::Widget* pCurrentWidget = m_vecWidgets[uItemIdx];
		const MyGUI::IntPoint currentWidgetPos = pCurrentWidget->getPosition();

		pCurrentWidget->setPosition(MyGUI::IntPoint(currentWidgetPos.left, pCaller->getBottom()));
	}
}

void VerticalStackBox::onItemScroll(MyGUI::Widget* pCaller, int iScrollVal)
{
	this->m_pEmptyPanel->_riseMouseWheel(iScrollVal);
}

void VerticalStackBox::updateScrollBar()
{
	const int parentHeight = m_pParent->getHeight();
	const int panelHeight = m_pEmptyPanel->getHeight();

	int heightDiff, heightDiffDiv;

	if (panelHeight <= parentHeight)
	{
		heightDiff = 0;
		heightDiffDiv = 0;
	}
	else
	{
		heightDiff = panelHeight - parentHeight;
		heightDiffDiv = int(float(heightDiff) / float(m_iScrollDistance));
	}

	m_iScrollValue = heightDiff;
	this->m_iSomeVal7 = heightDiffDiv;

	if (m_pParent->getVisible() && m_pScrollBar)
	{
		m_pScrollBar->setScrollRange(size_t(m_iScrollValue) + 1);
		m_pScrollBar->setScrollPage(size_t(m_iScrollDistance));
		m_pScrollBar->setScrollViewPage(m_pParent->getWidth());

		m_pScrollBar->setTrackSize((parentHeight * m_pScrollBar->getLineSize()) / panelHeight);
		m_pScrollBar->setScrollPosition(-m_pEmptyPanel->getTop());
	}

	if (-m_panelPos.top > m_iScrollValue)
	{
		m_panelPos.top = -m_iScrollValue;
		m_pEmptyPanel->setPosition(m_panelPos);
	}
}

MyGUI::Widget* VerticalStackBox::createNewOption()
{
	const float fOptItemSz = GuiSystemManager::GetInstance()->getOptionItemSize();
	const int iOffset = m_vecWidgets.empty()
	    ? 0
	    : m_vecWidgets[m_vecWidgets.size() - 1]->getBottom();

	const MyGUI::IntCoord newItemCoords(
	    0,
	    iOffset,
	    int(float(m_itemSize.width) * fOptItemSz),
	    int(float(m_itemSize.height) * fOptItemSz));

	MyGUI::Widget* newWidget = m_pEmptyPanel->createWidget<MyGUI::Widget>(
	    m_skin, newItemCoords, MyGUI::Align::Default);

	if (!m_vecWidgets.empty() && m_bEnableSeparators)
	{
		const int someOffset = std::max(m_itemSize.width - m_iSomeVal4 - m_iSomeVal3, 0);

		const MyGUI::IntCoord sepCoords(
		    int(float(this->m_iSomeVal3) * fOptItemSz), 0,
		    int(float(someOffset) * fOptItemSz), 1);

		MyGUI::Widget* separator = newWidget->createWidget<MyGUI::Widget>(
		    "WhiteSkin", sepCoords, MyGUI::Align::HStretch);

		separator->setNeedMouseFocus(false);
		separator->setColour(m_separatorColor);
	}

	newWidget->setUserData(m_vecWidgets.size());
	newWidget->eventChangeCoord += MyGUI::newDelegate(this, &VerticalStackBox::onItemChangeCoord);
	newWidget->eventMouseWheel += MyGUI::newDelegate(this, &VerticalStackBox::onItemScroll);

	m_pEmptyPanel->setSize(m_pEmptyPanel->getWidth(), newWidget->getBottom());
	m_vecWidgets.push_back(newWidget);

	this->updateScrollBar();
	return newWidget;
}

void VerticalStackBox::clearItems()
{
	for (MyGUI::Widget* pCurrentWidget : m_vecWidgets)
		m_pEmptyPanel->_destroyChildWidget(pCurrentWidget);

	m_vecWidgets.clear();
	m_pEmptyPanel->setSize(m_pEmptyPanel->getWidth(), 0);
}

#endif