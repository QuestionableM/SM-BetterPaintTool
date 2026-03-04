#pragma once

#include "SmSdk/config.hpp"

#if defined(SMSDK_ENABLE_PHYSICS)
#include <BulletCollision/BroadphaseCollision/btOverlappingPairCache.h>
#include <BulletDynamics/ConstraintSolver/btHingeConstraint.h>
#include <BulletCollision/CollisionShapes/btCompoundShape.h>
#include <BulletCollision/CollisionDispatch/btGhostObject.h>
#include <BulletCollision/CollisionShapes/btBoxShape.h>
#include <BulletDynamics/Dynamics/btRigidBody.h>
#include <BulletDynamics/Dynamics/btActionInterface.h>
#else
// This is a stub, please define `SMSDK_ENABLE_PHYSICS` to use Bullet Physics
struct btRigidBody
{
};
// This is a stub, please define `SMSDK_ENABLE_PHYSICS` to use Bullet Physics
struct btBoxShape
{
};
// This is a stub, please define `SMSDK_ENABLE_PHYSICS` to use Bullet Physics
struct btPairCachingGhostObject
{
};
// This is a stub, please define `SMSDK_ENABLE_PHYSICS` to use Bullet Physics
struct btCollisionObject
{
};
// This is a stub, please define `SMSDK_ENABLE_PHYSICS` to use Bullet Physics
struct btHingeConstraint
{
};
// This is a stub, please define `SMSDK_ENABLE_PHYSICS` to use Bullet Physics
struct btCompoundShape
{
private:
	char pad_data[120];
};
// This is a stub, please define `SMSDK_ENABLE_PHYSICS` to use Bullet Physics
struct btNullPairCache
{
};
// This is a stub, please define `SMSDK_ENABLE_PHYSICS` to use Bullet Physics
struct btCollisionDispatcher
{
};
// This is a stub, please define `SMSDK_ENABLE_PHYSICS` to use Bullet Physics
struct btCollisionWorld
{
};
// This is a stub, please define `SMSDK_ENABLE_PHYSICS` to use Bullet Physics
struct btGhostPairCallback
{
};
// This is a stub, please define `SMSDK_ENABLE_PHYSICS` to use Bullet Physics
struct btActionInterface
{
private:
	void* data;
};
// This is a stub, please define `SMSDK_ENABLE_PHYSICS` to use Bullet Physics
struct btVector3
{
private:
	float data[4];
};
#endif