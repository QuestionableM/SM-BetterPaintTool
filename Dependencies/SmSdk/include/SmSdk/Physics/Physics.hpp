#pragma once

#include "SmSdk/bullet_include.hpp"
#include "SmSdk/Base/Task.hpp"

SMSDK_BEGIN_NAMESPACE

struct PhysicsBase : public Task
{
	/* 0x0008 */ SDK_PRI char pad_0x8[0x8];
	/* 0x0010 */ SDK_PUB struct World* m_pWorld;
	/* 0x0018 */ SDK_PRI char pad_0x18[0x48];
	/* 0x0060 */ SDK_PUB btNullPairCache* m_pNullPairCache;
	/* 0x0068 */ SDK_PRI char pad_0x68[0x8];
	/* 0x0070 */ SDK_PUB struct ParallelDispatcher* m_pParallelDispatcher;
	/* 0x0078 */ SDK_PRI char pad_0x78[0x8];
	/* 0x0080 */ SDK_PUB struct SolverPool* m_pSolverPool;
	/* 0x0088 */ SDK_PUB struct TickDynamicsWorld* m_pTickDynamicsWorld;
	/* 0x0090 */ SDK_PUB btGhostPairCallback* m_pGhostPairCallback;
	/* 0x0098 */ SDK_PRI char pad_0x98[0xD8];
	/* 0x0170 */ SDK_PUB btCollisionWorld* m_pCollisionWorld2;
	/* 0x0178 */ SDK_PRI char pad_0x178[0x18];
	/* 0x0190 */ SDK_PUB btCollisionWorld* m_pCollisionWorld;
	/* 0x0198 */ SDK_PRI char pad_0x198[0x1A8];
}; // Size: 0x340

static_assert(sizeof(PhysicsBase) == 0x340, "PhysicsBase: Incorrect Size");

enum PhysicsFilterMask
{
	PhysicsFilterMask_DynamicBody = 1,
	PhysicsFilterMask_StaticBody = 2,
	PhysicsFilterMask_Character = 4,
	PhysicsFilterMask_AreaTrigger = 8,
	PhysicsFilterMask_TerrainSurface = 128,
	PhysicsFilterMask_TerrainAsset = 256,
	PhysicsFilterMask_Harvestable = 512,
	PhysicsFilterMask_Lifts = 1024,
	PhysicsFilterMask_Joints = 4096,
	PhysicsFilterMask_VoxelTerrain = 32768
};

class Physics
{
	SDK_PUB static Physics* GetInstance();

	/* 0x0000 */ SDK_PUB PhysicsBase* m_pPhysicsBase;
	/* 0x0008 */ SDK_PUB btNullPairCache* m_pNullPairCache;
	/* 0x0010 */ SDK_PRI char pad_0x10[0x10];
	/* 0x0020 */ SDK_PUB btCollisionDispatcher* m_pDispatcher;
	/* 0x0028 */ SDK_PUB btCollisionWorld* m_pCollisionWorld;
}; // Size: 0x30

static_assert(sizeof(Physics) == 0x30, "Physics: Incorrect Size");

SMSDK_END_NAMESPACE