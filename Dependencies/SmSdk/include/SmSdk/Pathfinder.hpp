#pragma once

struct PathNode : public NetObj
{
private:
	/* 0x0028 */ char pad_0x28[0x8];
public:
	/* 0x0030 */ __int16 m_worldId;
private:
	/* 0x0032 */ char pad_0x32[0x1E];
public:
	/* 0x0050 */ DirectX::XMFLOAT3 m_position;
private:
	/* 0x005C */ char pad_0x5C[0x4];
}; // Size: 0x60

static_assert(offsetof(PathNode, PathNode::m_worldId) == 0x30, "PathNode::m_worldId: Incorrect offset");
static_assert(offsetof(PathNode, PathNode::m_position) == 0x50, "PathNode::m_position: Incorrect offset");

static_assert(sizeof(PathNode) == 0x60, "PathNode: Incorrect Size");



struct Pathfinder
{
    static Pathfinder* GetInstance();

	/* 0x0000 */ std::unordered_map<int, std::shared_ptr<PathNode>> m_mapPathNodes;
	/* 0x0040 */ std::vector<std::shared_ptr<PathNode>> m_vecPathNodes;
private:
	/* 0x0058 */ char pad_0x58[0x48];

}; // Size: 0xA0

static_assert(offsetof(Pathfinder, Pathfinder::m_mapPathNodes) == 0x0, "Pathfinder::m_mapPathNodes: Incorrect offset");
static_assert(offsetof(Pathfinder, Pathfinder::m_vecPathNodes) == 0x40, "Pathfinder::m_vecPathNodes: Incorrect offset");

static_assert(sizeof(Pathfinder) == 0xA0, "Pathfinder: Incorrect Size");