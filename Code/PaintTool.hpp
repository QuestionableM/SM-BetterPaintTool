#pragma once

#include "IToolNetworkData.hpp"
#include "GuiInterface.hpp"
#include "ClientTool.hpp"
#include "Color.hpp"

#include <functional>
#include <memory>

struct PaintToolNetworkData : public IToolNetworkData
{
	/* 0x0010 */ Color paint_color;
private:
	/* 0x0014 */ char pad_0x14[0x4];
public:
	/* 0x0018 */ std::function<void(void)> function;
}; // Size: 0x58

static_assert(sizeof(PaintToolNetworkData) == 0x58, "PaintToolNetworkData: Incorrect Size");

class PaintTool : public ClientTool
{
public:
	using t_init_sig = bool(*)(PaintTool*);

	static t_init_sig o_initialize;
	static bool h_initialize(PaintTool* self);

private:
	/* 0x0548 */ char pad_0x548[0x8];
public:
	/* 0x0550 */ Color paint_color;
private:
	/* 0x0554 */ char pad_0x554[0x16C];
public:
	/* 0x06C0 */ float time_since_last_change;
	/* 0x06C4 */ Color prev_paint_color;
	/* 0x06C8 */ Color visualization_color;
private:
	/* 0x06CC */ char pad_0x6CC[0x4];
public:
	/* 0x06D0 */ PaintToolNetworkData* network_data;
private:
	/* 0x06D8 */ char pad_0x6D8[0x8];
public:
	/* 0x06E0 */ std::shared_ptr<GuiInterface> m_pGuiInterface;

}; // Size: 0x6F0

static_assert(sizeof(PaintTool) == 0x6F0, "PaintTool: Incorrect Size");