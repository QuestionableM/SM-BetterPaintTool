#include "SmSdk/Creation/CreationManager.hpp"
#include "SmSdk/config.hpp"

SMSDK_USE_NAMESPACE

BodyState* CreationManager::_getBodyState(const std::uint32_t uId)
{
	auto iter = m_mapBodyStates.find(uId);
	if (iter == m_mapBodyStates.end())
		return nullptr;

	return &iter->second;
}

JointState* CreationManager::_getJointState(const std::uint32_t uId)
{
	auto iter = m_mapJointStates.find(uId);
	if (iter == m_mapJointStates.end())
		return nullptr;

	return &iter->second;
}

BodyState* CreationManager::GetBodyState(const std::uint32_t uId)
{
	CreationManager* pCreationManager = CreationManager::GetInstance();
	if (!pCreationManager)
		return nullptr;

	return pCreationManager->_getBodyState(uId);
}

JointState* CreationManager::GetJointState(const std::uint32_t uId)
{
	CreationManager* pCreationManager = CreationManager::GetInstance();
	if (!pCreationManager)
		return nullptr;

	return pCreationManager->_getJointState(uId);
}