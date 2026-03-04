#pragma once

#include "SmSdk/Gui/GuiInterface.hpp"
#include "SmSdk/Util/Color.hpp"

#include "SmSdk/Tool/IToolNetworkData.hpp"
#include "SmSdk/Tool/ClientTool.hpp"

#include <DirectXMath.h>
#include <functional>

SMSDK_BEGIN_NAMESPACE

class PaintToolNetworkData : public IToolNetworkData
{
	/* 0x0010 */ SDK_PUB Color m_paintColor;
	/* 0x0014 */ SDK_PUB bool m_bColorUpdated;
	/* 0x0015 */ SDK_PRI char pad_0x15[0x3];
	/* 0x0018 */ SDK_PUB std::function<void(void)> m_function;
}; // Size: 0x58

static_assert(sizeof(PaintToolNetworkData) == 0x58, "PaintToolNetworkData: Incorrect Size");

struct PaintToolSelectionData
{
	/* 0x0000 */ SDK_PUB std::int32_t m_iObjectId;
	/* 0x0004 */ SDK_PUB std::int32_t m_iObjectType;
	/* 0x0008 */ SDK_PRI DirectX::XMFLOAT3 m_someVector;
	/* 0x0014 */ SDK_PUB DirectX::XMINT3 m_selectionBoxLimiter;
	/* 0x0020 */ SDK_PUB DirectX::XMINT3 m_selectionBoxMin;
	/* 0x002C */ SDK_PUB DirectX::XMINT3 m_selectionBoxMax;
	/* 0x0038 */ SDK_PRI char pad_0x38[0x8];
}; // Size: 0x40

static_assert(sizeof(PaintToolSelectionData) == 0x40, "PaintToolSelectionData: Incorrect Size");

class PaintTool : public ClientTool
{
	/* 0x0548 */ SDK_PRI char pad_0x548[0x8];
	/* 0x0550 */ SDK_PUB Color m_paintColor;
	/* 0x0554 */ SDK_PUB std::int32_t m_iLmbState;
	/* 0x0558 */ SDK_PUB std::int32_t m_iRmbState;
	/* 0x055C */ SDK_PRI char pad_0x55C[0x4];
	/* 0x0560 */ SDK_PUB PaintToolSelectionData m_paintSelection;
	/* 0x05A0 */ SDK_PUB PaintToolSelectionData m_eraseSelection;
	/* 0x05E0 */ SDK_PUB DirectX::XMMATRIX m_paintSelectionObjectMatrix;
	/* 0x0620 */ SDK_PUB DirectX::XMMATRIX m_eraseSelectionObjectMatrix;
	/* 0x0660 */ SDK_PUB bool m_bSelectorEnabled;
	/* 0x0661 */ SDK_PRI char pad_0x661[0x3];
	/* 0x0664 */ SDK_PUB std::int32_t m_iSelectedObjectId;
	/* 0x0668 */ SDK_PUB DirectX::XMINT3 m_selectorPosition;
	/* 0x0674 */ SDK_PRI char pad_0x674[0xC];
	/* 0x0680 */ SDK_PUB DirectX::XMMATRIX m_selectorObjectMatrix;
	/* 0x06C0 */ SDK_PUB float m_fTimeSinceLastChange;
	/* 0x06C4 */ SDK_PUB Color m_prevPaintColor;
	/* 0x06C8 */ SDK_PUB Color m_visualizationColor;
	/* 0x06CC */ SDK_PRI char pad_0x6CC[0x4];
	/* 0x06D0 */ SDK_PUB PaintToolNetworkData* m_pNetworkData;
	/* 0x06D8 */ SDK_PRI char pad_0x6D8[0x8];
	/* 0x06E0 */ SDK_PUB std::shared_ptr<GuiInterface> m_pGuiInterface;
}; // Size: 0x6F0

static_assert(sizeof(PaintTool) == 0x6F0, "PaintTool: Incorrect Size");

SMSDK_END_NAMESPACE