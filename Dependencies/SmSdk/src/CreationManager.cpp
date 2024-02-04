#include "SmSdk/Creation/CreationManager.hpp"

BodyStructure* CreationManager::_getBodyData(int id)
{
	auto v_iter = this->body_map.find(id);
	if (v_iter == this->body_map.end())
		return nullptr;

	return &v_iter->second;
}

JointStructure* CreationManager::_getJointData(int id)
{
	auto v_iter = this->joint_map.find(id);
	if (v_iter == this->joint_map.end())
		return nullptr;

	return &v_iter->second;
}

BodyStructure* CreationManager::GetBodyData(int id)
{
	CreationManager* v_mgr = CreationManager::GetInstance();
	if (!v_mgr) return nullptr;

	return v_mgr->_getBodyData(id);
}

JointStructure* CreationManager::GetJointData(int id)
{
	CreationManager* v_mgr = CreationManager::GetInstance();
	if (!v_mgr) return nullptr;

	return v_mgr->_getJointData(id);
}