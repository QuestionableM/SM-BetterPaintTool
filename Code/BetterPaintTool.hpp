#pragma once

#include "SmSdk/Physics/PhysicsProxy.hpp"
#include "SmSdk/Tool/PaintTool.hpp"

#include <functional>
#include <memory>

class btCollisionObject;

namespace SM {
	class InputManager;
}

class BetterPaintTool : public SM::PaintTool
{
public:
	using t_init_sig = bool(*)(BetterPaintTool*);
	using t_update_sig = void(*)(BetterPaintTool*, float);
	using t_process_inputs = void (*)(SM::InputManager*);

	static t_process_inputs o_processInputs;
	static t_init_sig o_initialize;
	static t_update_sig o_update;

	static void h_processInputs(SM::InputManager* self);
	static bool h_initialize(BetterPaintTool* self);
	static void h_update(BetterPaintTool* self, float dt);

	static std::uint32_t getLimiterAxisIndex(const DirectX::XMINT3& limiter);
	void updateSelectionData(SM::PaintToolSelectionData& sel_data);
	static bool isObjectSelected(const SM::PaintToolSelectionData& sel_data);
	bool isErasingOrPainting() const;

	//Color that depends on time_since_last_change
	SM::Color getInterpolatedColor();
	void setColor(SM::Color color);

	static bool getColorFromShape(int obj_idx, int tri_idx, SM::Color& out_color);
	static bool getColorFromJoint(SM::PhysicsProxy* proxy, int tri_idx, SM::Color& out_color);
	static bool getColorFromCharacter(int char_idx, SM::Color& out_color);
	static bool getColorFromHarvestable(int hvs_idx, SM::Color& out_color);
	static bool getColorFromCollisionObject(const btCollisionObject* obj, int tri_idx, SM::Color& out_color);

}; // Size: 0x6F0

static_assert(sizeof(BetterPaintTool) == 0x6F0, "PaintTool: Incorrect Size");