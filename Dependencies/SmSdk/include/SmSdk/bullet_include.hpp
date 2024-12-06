#pragma once

#include "SmSdk/config.hpp"

#if defined(SMSDK_ENABLE_PHYSICS)
#include <BulletCollision/BroadphaseCollision/btOverlappingPairCache.h>
#include <BulletDynamics/ConstraintSolver/btHingeConstraint.h>
#include <BulletCollision/CollisionShapes/btCompoundShape.h>
#include <BulletCollision/CollisionDispatch/btGhostObject.h>
#include <BulletCollision/CollisionShapes/btBoxShape.h>
#include <BulletDynamics/Dynamics/btRigidBody.h>
#else
struct btRigidBody {};
struct btBoxShape {};
struct btPairCachingGhostObject {};
struct btCollisionObject {};
struct btHingeConstraint {};
struct btCompoundShape {
private:
	char pad_data[120];
};
struct btNullPairCache {};
struct btCollisionDispatcher {};
struct btCollisionWorld {};
struct btGhostPairCallback {};

#endif