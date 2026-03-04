#pragma once

#include "SmSdk/Tool/IToolImpl.hpp"
#include "SmSdk/Tool/Tool.hpp"

#include <unordered_map>
#include <string>
#include <memory>

SMSDK_BEGIN_NAMESPACE

class ClientTool;

enum AnimationFlag : uint32_t
{
	AnimationFlag_None = 0,
	AnimationFlag_Repeat = 1
};

struct ToolAnimationEntry
{
	/* 0x0000 */ SDK_PUB std::string m_animName;
	/* 0x0020 */ SDK_PUB std::string m_nextAnim;
	/* 0x0040 */ SDK_PUB float m_fAnimBegin;
	/* 0x0044 */ SDK_PUB float m_fAnimEnd;
	/* 0x0048 */ SDK_PUB float m_fAnimTime;
	/* 0x004C */ SDK_PUB float m_fWeight;
	/* 0x0050 */ SDK_PUB float m_fPlaybackSpeed;
	/* 0x0054 */ SDK_PUB std::uint32_t m_uFlags;
}; // Size: 0x58

static_assert(sizeof(ToolAnimationEntry) == 0x58, "ToolAnimationEntry: Incorrect Size");

struct ToolAnimationList
{
	/* 0x0000 */ SDK_PUB std::string m_toolIdle;
	/* 0x0020 */ SDK_PUB std::string m_toolIdleRelaxed;
	/* 0x0040 */ SDK_PUB std::string m_toolRunFwd;
	/* 0x0060 */ SDK_PUB std::string m_toolRunBwd;
	/* 0x0080 */ SDK_PUB std::string m_toolSprint;
	/* 0x00A0 */ SDK_PUB std::string m_toolJump;
	/* 0x00C0 */ SDK_PUB std::string m_toolJumpUp;
	/* 0x00E0 */ SDK_PUB std::string m_toolJumpDown;
	/* 0x0100 */ SDK_PUB std::string m_toolJumpLand;
	/* 0x0120 */ SDK_PUB std::string m_toolJumpLandFwd;
	/* 0x0140 */ SDK_PUB std::string m_toolJumpLandBwd;
	/* 0x0160 */ SDK_PUB std::string m_toolCrouchIdle;
	/* 0x0180 */ SDK_PUB std::string m_toolCrouchFwd;
	/* 0x01A0 */ SDK_PUB std::string m_toolCrouchBwd;
	/* 0x01C0 */ SDK_PRI std::string m_someString1;
	/* 0x01E0 */ SDK_PRI std::string m_someString2;
	/* 0x0200 */ SDK_PRI std::string m_someString3;
}; // Size: 0x220

static_assert(sizeof(ToolAnimationList) == 0x220, "ToolAnimationList: Incorrect Size");

struct ToolAnimationData
{
	SDK_PUB void setAnimation(const std::string& name)
	{
		auto iter = m_mapAnimationData.find(name);
		if (iter == m_mapAnimationData.end())
			return;

		m_currentAnim = name;
		iter->second.m_fAnimTime = 0.0f;
		m_fAnimBegin = 0.2f;
	}

	SDK_PUB bool hasAnimation(const std::string& name) const
	{
		return m_mapAnimationData.find(name) != m_mapAnimationData.end();
	}

	SDK_PUB void resetAnimation(const std::string& name)
	{
		auto iter = m_mapAnimationData.find(name);
		if (iter == m_mapAnimationData.end())
			return;

		iter->second.m_fAnimTime = 0.0f;
		iter->second.m_fWeight = 0.0f;
	}

	SDK_PUB void addNewAnimation(
	    const std::string& name,
	    const std::string& startAnim,
	    const std::string& nextAnim,
	    float animBegin = 0.0f,
	    float animEnd = 1.0f,
	    float playbackSpeed = 1.0f,
	    uint32_t flags = 256)
	{
		ToolAnimationEntry newEntry;
		newEntry.m_animName = startAnim;
		newEntry.m_nextAnim = nextAnim;
		newEntry.m_fAnimTime = 0.0f;
		newEntry.m_fAnimBegin = animBegin;
		newEntry.m_fAnimEnd = animEnd;
		newEntry.m_fWeight = 0.0f;
		newEntry.m_fPlaybackSpeed = playbackSpeed;
		newEntry.m_uFlags = flags;

		m_mapAnimationData.emplace(name, newEntry);
	}

	SDK_PUB void removeAnimation(const std::string& name)
	{
		auto iter = m_mapAnimationData.find(name);
		if (iter != m_mapAnimationData.end())
			m_mapAnimationData.erase(iter);
	}

	/* 0x0000 */ SDK_PUB ClientTool* m_pToolPtr;
	/* 0x0008 */ SDK_PUB std::unordered_map<std::string, ToolAnimationEntry> m_mapAnimationData;
	/* 0x0048 */ SDK_PUB std::string m_currentAnim;
	/* 0x0068 */ SDK_PUB ToolAnimationList m_toolAnimList;
	/* 0x0288 */ SDK_PUB float m_fAnimBegin;
	/* 0x028C */ SDK_PRI char pad_0x28C[0x4];
}; // Size: 0x290

static_assert(sizeof(ToolAnimationData) == 0x290, "ToolAnimationData: Incorrect Size");

class ClientTool : public IToolImpl
{
	SDK_PUB inline void setTpAnimation(const std::string& name)
	{
		m_tpAnims.setAnimation(name);
	}

	SDK_PUB inline void setFpAnimation(const std::string& name)
	{
		m_fpAnims.setAnimation(name);
	}

	SDK_PUB inline void setFpAndTpAnimation(const std::string& name)
	{
		this->setFpAnimation(name);
		this->setTpAnimation(name);
	}

	/* 0x0008 */ SDK_PUB ToolAnimationData m_tpAnims;
	/* 0x0298 */ SDK_PUB ToolAnimationData m_fpAnims;
	/* 0x0528 */ SDK_PUB std::shared_ptr<Tool> m_pTool;
	/* 0x0538 */ SDK_PUB bool m_blockSprint;
	/* 0x0539 */ SDK_PRI char pad_0x539[0x3];
	/* 0x053C */ SDK_PUB float m_fDispersionFraction;
	/* 0x0540 */ SDK_PUB float m_fCrosshairAlpha;
	/* 0x0544 */ SDK_PUB bool m_fInteractionTextSuppressed;
	/* 0x0545 */ SDK_PRI char pad_0x545[0x3];
}; // Size: 0x548

static_assert(sizeof(ClientTool) == 0x548, "ClientTool: Incorrect Size");

SMSDK_END_NAMESPACE