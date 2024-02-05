#pragma once

#include "SmSdk/Physics/PhysicsProxy.hpp"
#include "SmSdk/Tool/PaintTool.hpp"

#include <functional>
#include <memory>

class btCollisionObject;

class BetterPaintTool : public PaintTool
{
public:
	using t_init_sig = bool(*)(BetterPaintTool*);
	using t_update_sig = void(*)(BetterPaintTool*, float);

	static t_init_sig o_initialize;
	static t_update_sig o_update;


	static bool h_initialize(BetterPaintTool* self);
	static void h_update(BetterPaintTool* self, float dt);

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