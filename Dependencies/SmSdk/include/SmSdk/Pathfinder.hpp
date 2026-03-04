#pragma once

#include "SmSdk/config.hpp"

#include "SmSdk/Base/NetObj.hpp"
#include <unordered_map>
#include <vector>
#include <memory>

SMSDK_BEGIN_NAMESPACE

struct PathNode : public NetObj
{
	/* 0x0028 */ SDK_PRI char pad_0x28[0x8];
	/* 0x0030 */ SDK_PUB std::int16_t m_iWorldId;
	/* 0x0032 */ SDK_PRI char pad_0x32[0x1E];
	/* 0x0050 */ SDK_PUB DirectX::XMFLOAT3 m_position;
	/* 0x005C */ SDK_PRI char pad_0x5C[0x4];
}; // Size: 0x60

static_assert(offsetof(PathNode, PathNode::m_iWorldId) == 0x30, "PathNode::m_iWorldId: Incorrect offset");
static_assert(offsetof(PathNode, PathNode::m_position) == 0x50, "PathNode::m_position: Incorrect offset");

static_assert(sizeof(PathNode) == 0x60, "PathNode: Incorrect Size");


struct Pathfinder
{
	SDK_PUB static Pathfinder* GetInstance();

	/* 0x0000 */ SDK_PUB std::unordered_map<int, std::shared_ptr<PathNode>> m_mapPathNodes;
	/* 0x0040 */ SDK_PUB std::vector<std::shared_ptr<PathNode>> m_vecPathNodes;
	/* 0x0058 */ SDK_PRI char pad_0x58[0x48];
}; // Size: 0xA0

static_assert(offsetof(Pathfinder, Pathfinder::m_mapPathNodes) == 0x0, "Pathfinder::m_mapPathNodes: Incorrect offset");
static_assert(offsetof(Pathfinder, Pathfinder::m_vecPathNodes) == 0x40, "Pathfinder::m_vecPathNodes: Incorrect offset");

static_assert(sizeof(Pathfinder) == 0xA0, "Pathfinder: Incorrect Size");

SMSDK_END_NAMESPACE