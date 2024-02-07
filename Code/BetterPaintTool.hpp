#pragma once

#include "SmSdk/Physics/PhysicsProxy.hpp"
#include "SmSdk/Tool/PaintTool.hpp"

#include <functional>
#include <memory>

class btCollisionObject;
class InputManager;

class BetterPaintTool : public PaintTool
{
public:
	using t_init_sig = bool(*)(BetterPaintTool*);
	using t_update_sig = void(*)(BetterPaintTool*, float);
	using t_process_inputs = void (*)(InputManager*);

	static t_process_inputs o_processInputs;
	static t_init_sig o_initialize;
	static t_update_sig o_update;

	static void h_processInputs(InputManager* self);
	static bool h_initialize(BetterPaintTool* self);
	static void h_update(BetterPaintTool* self, float dt);

	void updateSelectionData(PaintToolSelectionData& sel_data);
	bool isObjectSelected(const PaintToolSelectionData& sel_data) const;

	//Color that depends on time_since_last_change
	Color getInterpolatedColor();
	void setColor(Color color);

	static bool getColorFromShape(int obj_idx, int tri_idx, Color& out_color);
	static bool getColorFromJoint(PhysicsProxy* proxy, int tri_idx, Color& out_color);
	static bool getColorFromCharacter(int char_idx, Color& out_color);
	static bool getColorFromHarvestable(int hvs_idx, Color& out_color);
	static bool getColorFromCollisionObject(const btCollisionObject* obj, int tri_idx, Color& out_color);

}; // Size: 0x6F0

static_assert(sizeof(BetterPaintTool) == 0x6F0, "PaintTool: Incorrect Size");