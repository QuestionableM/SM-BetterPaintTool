#pragma once

#include "SmSdk/Base/NetObj.hpp"
#include "ChildShape.hpp"
#include "Joint.hpp"

#include <BulletCollision/CollisionShapes/btCompoundShape.h>

#include <unordered_set>
#include <vector>

class RigidBody : public NetObj
{
public:
	inline ChildShape* getChildShape(int id)
	{
		if (id < 0 || id >= m_vecChildShapes.size())
			return nullptr;

		return m_vecChildShapes[id].get();
	}

	inline Joint* getJoint(int id)
	{
		int v_jnt_counter = 0;
		for (const auto& v_cur_jnt : m_setJointStorage)
		{
			if (id == v_jnt_counter)
				return v_cur_jnt.get();

			v_jnt_counter++;
		}

		return nullptr;
	}

private:
	/* 0x0028 */ char pad_0x28[0xC];
public:
	/* 0x0034 */ __int16 world_id;
private:
	/* 0x0036 */ char pad_0x36[0xA];
public:
	/* 0x0040 */ DirectX::XMMATRIX transform;
private:
	/* 0x0080 */ char pad_0x80[0x8];
public:
	/* 0x0088 */ std::shared_ptr<struct ShapeGridData> shape_grid_data;
	/* 0x0098 */ DirectX::XMFLOAT3 m_localAabbMin;
	/* 0x00A4 */ DirectX::XMFLOAT3 m_localAabbMax;
private:
	/* 0x00B0 */ char pad_0xB0[0x20];
public:
	/* 0x00D0 */ btCompoundShape compound_shape;
	/* 0x0150 */ std::vector<std::shared_ptr<ChildShape>> m_vecChildShapes;
private:
	/* 0x0168 */ char pad_0x168[0x18];
public:
	/* 0x0180 */ std::unordered_set<std::shared_ptr<Joint>> m_setJointStorage;
private:
	/* 0x01C0 */ char pad_0x1C0[0x10];

}; //Size=0x01C8

static_assert(sizeof(RigidBody) == 0x1D0, "RigidBody: Incorrect Size");