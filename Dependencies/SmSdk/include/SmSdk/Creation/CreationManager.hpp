#pragma once

#include "SmSdk/Creation/JointPhysicsProxy.hpp"
#include "SmSdk/Creation/RigidBody.hpp"
#include "SmSdk/Creation/Joint.hpp"
#include "SmSdk/config.hpp"

#include <unordered_map>
#include <memory>
#include <string>

SMSDK_BEGIN_NAMESPACE

struct BodyState
{
	std::shared_ptr<RigidBody> m_pBody;
	std::shared_ptr<struct BodyPhysicsProxy> m_pPhysicsProxy;
};

struct JointState
{
	std::shared_ptr<Joint> m_pJoint;
	std::shared_ptr<JointPhysicsProxy> m_pPhysicsProxy;
};

class CreationManager
{
	REMOVE_COPY_CONSTRUCTORS(CreationManager);

	SDK_PUB virtual ~CreationManager() = default;

	SDK_PUB static CreationManager* GetInstance();

	SDK_PUB BodyState* _getBodyState(const std::uint32_t uId);
	SDK_PUB JointState* _getJointState(const std::uint32_t uId);

	SDK_PUB static BodyState* GetBodyState(const std::uint32_t uId);
	SDK_PUB static JointState* GetJointState(const std::uint32_t uId);

	/* 0x0008 */ SDK_PUB std::unordered_map<std::uint32_t, BodyState> m_mapBodyStates;
	/* 0x0048 */ SDK_PUB std::unordered_map<std::uint32_t, std::shared_ptr<ChildShape>> m_mapChildShapes;
	/* 0x0088 */ SDK_PUB std::unordered_map<std::uint32_t, JointState> m_mapJointStates;
	/* 0x00C8 */ SDK_PUB std::unordered_map<std::uint32_t, std::shared_ptr<struct ControllerEntry>> m_mapControllerStates;
	/* 0x0108 */ SDK_PUB std::unordered_map<std::uint32_t, struct CreationEntry> m_mapCreations;
	/* 0x0148 */ SDK_PRI char pad_0x148[0x118];
}; // Size: 0x260

static_assert(offsetof(CreationManager, CreationManager::m_mapBodyStates) == 0x8, "CreationManager::m_mapBodyState: Incorrect offset");
static_assert(offsetof(CreationManager, CreationManager::m_mapChildShapes) == 0x48, "CreationManager::child_shape_map: Incorrect offset");
static_assert(offsetof(CreationManager, CreationManager::m_mapJointStates) == 0x88, "CreationManager::joint_map: Incorrect offset");
static_assert(offsetof(CreationManager, CreationManager::m_mapControllerStates) == 0xC8, "CreationManager::interactive_part_map: Incorrect offset");
static_assert(offsetof(CreationManager, CreationManager::m_mapCreations) == 0x108, "CreationManager::creation_map: Incorrect offset");

static_assert(sizeof(CreationManager) == 0x260, "CreationManager: Incorrect Size");

SMSDK_END_NAMESPACE