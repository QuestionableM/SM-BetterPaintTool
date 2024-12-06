#pragma once

#include "SmSdk/bullet_include.hpp"
#include "SmSdk/Base/Task.hpp"

struct PhysicsBase : public Task
{
private:
	/* 0x0008 */ char pad_0x8[0x8];
public:
	/* 0x0010 */ struct World* world;
private:
	/* 0x0018 */ char pad_0x18[0x48];
public:
	/* 0x0060 */ btNullPairCache* null_pair_cache;
private:
	/* 0x0068 */ char pad_0x68[0x8];
public:
	/* 0x0070 */ struct ParallelDispatcher* parallel_dispatcher;
private:
	/* 0x0078 */ char pad_0x78[0x8];
public:
	/* 0x0080 */ struct SolverPool* solver_pool;
	/* 0x0088 */ struct TickDynamicsWorld* tick_dynamics_world;
	/* 0x0090 */ btGhostPairCallback* ghost_pair_callback;
private:
	/* 0x0098 */ char pad_0x98[0xD8];
public:
	/* 0x0170 */ btCollisionWorld* collision_world2;
private:
	/* 0x0178 */ char pad_0x178[0x18];
public:
	/* 0x0190 */ btCollisionWorld* collision_world;
private:
	/* 0x0198 */ char pad_0x198[0x1A8];

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
public:
	static Physics* GetInstance();

	/* 0x0000 */ PhysicsBase* physics_base;
	/* 0x0008 */ btNullPairCache* null_pair_cache;
	/* 0x0010 */ char pad_0x10[0x10];
	/* 0x0020 */ btCollisionDispatcher* dispatcher;
	/* 0x0028 */ btCollisionWorld* collision_world;

}; // Size: 0x30

static_assert(sizeof(Physics) == 0x30, "Physics: Incorrect Size");