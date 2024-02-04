#pragma once

#include "SmSdk/Creation/JointPhysicsProxy.hpp"
#include "SmSdk/Creation/RigidBody.hpp"
#include "SmSdk/Creation/Joint.hpp"
#include "SmSdk/config.hpp"

#include <unordered_map>
#include <memory>
#include <string>

struct BodyStructure
{
	std::shared_ptr<RigidBody> body;
	std::shared_ptr<struct BodyPhysicsProxy> physics_proxy;
};

struct JointStructure
{
	std::shared_ptr<Joint> joint;
	std::shared_ptr<JointPhysicsProxy> physics_proxy;
};

class CreationManager
{
	REMOVE_COPY_CONSTRUCTORS(CreationManager);

public:
	virtual ~CreationManager() = default;

	static CreationManager* GetInstance();

	BodyStructure* _getBodyData(int id);
	JointStructure* _getJointData(int id);

	static BodyStructure* GetBodyData(int id);
	static JointStructure* GetJointData(int id);

	std::unordered_map<int, BodyStructure> body_map;
	std::unordered_map<int, std::shared_ptr<ChildShape>> child_shape_map;
	std::unordered_map<int, JointStructure> joint_map;
	std::unordered_map<int, std::shared_ptr<struct ControllerEntry>> interactive_part_map;
	std::unordered_map<int, struct CreationEntry> creation_map;
};