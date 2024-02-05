#pragma once

#include "SmSdk/Gui/GuiInterface.hpp"
#include "SmSdk/Util/Color.hpp"

#include "IToolNetworkData.hpp"
#include "ClientTool.hpp"

#include <DirectXMath.h>
#include <functional>

class PaintToolNetworkData : public IToolNetworkData
{
public:
	/* 0x0010 */ Color paint_color;
	/* 0x0014 */ bool m_bColorUpdated;
private:
	/* 0x0015 */ char pad_0x15[0x3];
public:
	/* 0x0018 */ std::function<void(void)> function;

}; // Size: 0x58

static_assert(sizeof(PaintToolNetworkData) == 0x58, "PaintToolNetworkData: Incorrect Size");

struct PaintToolSelectionData
{
	/* 0x0000 */ __int32 m_objectId;
	/* 0x0004 */ __int32 m_objectType;
	/* 0x0008 */ DirectX::XMFLOAT3 some_vector;
	/* 0x0014 */ DirectX::XMINT3 m_selectionBoxLimiter;
	/* 0x0020 */ DirectX::XMINT3 m_selectionBoxMin;
	/* 0x002C */ DirectX::XMINT3 m_selectionBoxMax;
private:
	/* 0x0038 */ char pad_0x38[0x8];

}; // Size: 0x40

static_assert(sizeof(PaintToolSelectionData) == 0x40, "PaintToolSelectionData: Incorrect Size");

class PaintTool : public ClientTool
{
private:
	/* 0x0548 */ char pad_0x548[0x8];
public:
	/* 0x0550 */ Color paint_color;
	/* 0x0554 */ __int32 m_lmb_state;
	/* 0x0558 */ __int32 m_rmb_state;
private:
	/* 0x055C */ char pad_0x55C[0x4];
public:
	/* 0x0560 */ PaintToolSelectionData m_paintSelection;
	/* 0x05A0 */ PaintToolSelectionData m_eraseSelection;
	/* 0x05E0 */ DirectX::XMMATRIX m_paintSelectionObjectMatrix;
	/* 0x0620 */ DirectX::XMMATRIX m_eraseSelectionObjectMatrix;
	/* 0x0660 */ bool m_selectorEnabled;
private:
	/* 0x0661 */ char pad_0x661[0x3];
public:
	/* 0x0664 */ __int32 m_selectedObjectId;
	/* 0x0668 */ DirectX::XMINT3 m_selectorPosition;
private:
	/* 0x0674 */ char pad_0x674[0xC];
public:
	/* 0x0680 */ DirectX::XMMATRIX m_selectorObjectMatrix;
	/* 0x06C0 */ float time_since_last_change;
	/* 0x06C4 */ Color prev_paint_color;
	/* 0x06C8 */ Color visualization_color;
private:
	/* 0x06CC */ char pad_0x6CC[0x4];
public:
	/* 0x06D0 */ PaintToolNetworkData* m_pNetworkData;
private:
	/* 0x06D8 */ char pad_0x6D8[0x8];
public:
	/* 0x06E0 */ std::shared_ptr<GuiInterface> m_pGuiInterface;

}; // Size: 0x6F0

static_assert(sizeof(PaintTool) == 0x6F0, "PaintTool: Incorrect Size");