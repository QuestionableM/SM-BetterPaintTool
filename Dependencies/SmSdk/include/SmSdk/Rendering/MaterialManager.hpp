#pragma once

#include "SmSdk/jsoncpp_include.hpp"
#include "SmSdk/config.hpp"

#include "SmSdk/Rendering/Material.hpp"

#include <unordered_map>
#include <vector>

SMSDK_BEGIN_NAMESPACE

struct MaterialEntry
{
	/* 0x0000 */ SDK_PUB std::uint32_t m_uId;
	/* 0x0004 */ SDK_PRI char pad_0x4[0x4];
	/* 0x0008 */ SDK_PUB std::string m_name;
	/* 0x0028 */ SDK_PUB std::uint8_t m_uMaterialType;
	/* 0x0029 */ SDK_PRI char pad_0x29[0x3];
	/* 0x002C */ SDK_PUB std::uint32_t m_uPipelineFlags;
	/* 0x0030 */ SDK_PUB std::uint64_t m_uRendQueueMask;
	/* 0x0038 */ SDK_PUB std::uint64_t m_uSemantic;
	/* 0x0040 */ SDK_PUB std::uint32_t m_uPosAnimCount;
	/* 0x0044 */ SDK_PUB std::uint32_t m_uVertexStride;
	/* 0x0048 */ SDK_PUB std::uint32_t m_uInstanceStride;
	/* 0x004C */ SDK_PRI char pad_0x4C[0x4];
	/* 0x0050 */ SDK_PUB Json::Value m_jCustomData;
	/* 0x0068 */ SDK_PUB Material* m_arrMaterials[132];
}; // Size: 0x488

static_assert(offsetof(MaterialEntry, MaterialEntry::m_uId) == 0x0, "MaterialEntry::m_uId: Incorrect offset");
static_assert(offsetof(MaterialEntry, MaterialEntry::m_name) == 0x8, "MaterialEntry::m_name: Incorrect offset");
static_assert(offsetof(MaterialEntry, MaterialEntry::m_uMaterialType) == 0x28, "MaterialEntry::m_uMaterialType: Incorrect offset");
static_assert(offsetof(MaterialEntry, MaterialEntry::m_uPipelineFlags) == 0x2C, "MaterialEntry::m_uPipelineFlags: Incorrect offset");
static_assert(offsetof(MaterialEntry, MaterialEntry::m_uRendQueueMask) == 0x30, "MaterialEntry::m_uRendQueueMask: Incorrect offset");
static_assert(offsetof(MaterialEntry, MaterialEntry::m_uSemantic) == 0x38, "MaterialEntry::m_uSemantic: Incorrect offset");
static_assert(offsetof(MaterialEntry, MaterialEntry::m_uPosAnimCount) == 0x40, "MaterialEntry::m_uPosAnimCount: Incorrect offset");
static_assert(offsetof(MaterialEntry, MaterialEntry::m_uVertexStride) == 0x44, "MaterialEntry::m_uVertexStride: Incorrect offset");
static_assert(offsetof(MaterialEntry, MaterialEntry::m_uInstanceStride) == 0x48, "MaterialEntry::m_uInstanceStride: Incorrect offset");
static_assert(offsetof(MaterialEntry, MaterialEntry::m_jCustomData) == 0x50, "MaterialEntry::m_jCustomData: Incorrect offset");
static_assert(offsetof(MaterialEntry, MaterialEntry::m_arrMaterials) == 0x68, "MaterialEntry::m_arrMaterials: Incorrect offset");
static_assert(sizeof(MaterialEntry) == 0x488, "MaterialEntry: Incorrect Size");

struct MaterialManager
{
	/* 0x0000 */ SDK_PUB Material* m_pForwardParticles;
	/* 0x0008 */ SDK_PUB Material* m_pPostFxaa;
	/* 0x0010 */ SDK_PUB Material* m_pPostGodrays;
	/* 0x0018 */ SDK_PUB Material* m_pMainClutterImpostorGBuffer;
	/* 0x0020 */ SDK_PUB Material* m_pMainClutterGBuffer;
	/* 0x0028 */ SDK_PUB Material* m_pMainDebugDrawer;
	/* 0x0030 */ SDK_PUB Material* m_pGuiBlurryBackground;
	/* 0x0038 */ SDK_PUB Material* m_pGuiTextureBoxArray;
	/* 0x0040 */ SDK_PUB Material* m_pCubeMapComposition;
	/* 0x0048 */ SDK_PUB Material* m_pPostBloom;
	/* 0x0050 */ SDK_PUB Material* m_pPostAddBloom;
	/* 0x0058 */ SDK_PUB Material* m_pPostAddBloomNoise;
	/* 0x0060 */ SDK_PUB Material* m_pPostBlur;
	/* 0x0068 */ SDK_PUB Material* m_pPostSmartBlur;
	/* 0x0070 */ SDK_PUB Material* m_pPostDof;
	/* 0x0078 */ SDK_PUB Material* m_pPostCopy;
	/* 0x0080 */ SDK_PUB Material* m_pPostCopyDepth;
	/* 0x0088 */ SDK_PUB Material* m_pPostCopyBrightness;
	/* 0x0090 */ SDK_PUB Material* m_pMainTerrainSurfaceGBuffer;
	/* 0x0098 */ SDK_PUB Material* m_pMainTerrainSurfaceDepth;
	/* 0x00A0 */ SDK_PUB Material* m_pMainEditorTerrainSurfaceGBuffer;
	/* 0x00A8 */ SDK_PUB Material* m_pMainEditorTerrainSurfaceDepth;
	/* 0x00B0 */ SDK_PUB Material* m_pMainSky;
	/* 0x00B8 */ SDK_PUB Material* m_pMainImpostorGBuffer;
	/* 0x00C0 */ SDK_PUB Material* m_pMainImpostorDepth;
	/* 0x00C8 */ SDK_PUB std::unordered_map<size_t, MaterialEntry*, PassthroughHash> m_arrMaterialMap[10];
	/* 0x0348 */ SDK_PUB std::vector<MaterialEntry*> m_vecMaterials;
}; // Size: 0x360

static_assert(offsetof(MaterialManager, MaterialManager::m_pForwardParticles) == 0x0, "MaterialManager::m_pForwardParticles: Incorrect offset");
static_assert(offsetof(MaterialManager, MaterialManager::m_pPostFxaa) == 0x8, "MaterialManager::m_pPostFxaa: Incorrect offset");
static_assert(offsetof(MaterialManager, MaterialManager::m_pPostGodrays) == 0x10, "MaterialManager::m_pPostGodrays: Incorrect offset");
static_assert(offsetof(MaterialManager, MaterialManager::m_pMainClutterImpostorGBuffer) == 0x18, "MaterialManager::m_pMainClutterImpostorGBuffer: Incorrect offset");
static_assert(offsetof(MaterialManager, MaterialManager::m_pMainClutterGBuffer) == 0x20, "MaterialManager::m_pMainClutterGBuffer: Incorrect offset");
static_assert(offsetof(MaterialManager, MaterialManager::m_pMainDebugDrawer) == 0x28, "MaterialManager::m_pMainDebugDrawer: Incorrect offset");
static_assert(offsetof(MaterialManager, MaterialManager::m_pGuiBlurryBackground) == 0x30, "MaterialManager::m_pGuiBlurryBackground: Incorrect offset");
static_assert(offsetof(MaterialManager, MaterialManager::m_pGuiTextureBoxArray) == 0x38, "MaterialManager::m_pGuiTextureBoxArray: Incorrect offset");
static_assert(offsetof(MaterialManager, MaterialManager::m_pCubeMapComposition) == 0x40, "MaterialManager::m_pCubeMapComposition: Incorrect offset");
static_assert(offsetof(MaterialManager, MaterialManager::m_pPostBloom) == 0x48, "MaterialManager::m_pPostBloom: Incorrect offset");
static_assert(offsetof(MaterialManager, MaterialManager::m_pPostAddBloom) == 0x50, "MaterialManager::m_pPostAddBloom: Incorrect offset");
static_assert(offsetof(MaterialManager, MaterialManager::m_pPostAddBloomNoise) == 0x58, "MaterialManager::m_pPostAddBloomNoise: Incorrect offset");
static_assert(offsetof(MaterialManager, MaterialManager::m_pPostBlur) == 0x60, "MaterialManager::m_pPostBlur: Incorrect offset");
static_assert(offsetof(MaterialManager, MaterialManager::m_pPostSmartBlur) == 0x68, "MaterialManager::m_pPostSmartBlur: Incorrect offset");
static_assert(offsetof(MaterialManager, MaterialManager::m_pPostDof) == 0x70, "MaterialManager::m_pPostDof: Incorrect offset");
static_assert(offsetof(MaterialManager, MaterialManager::m_pPostCopy) == 0x78, "MaterialManager::m_pPostCopy: Incorrect offset");
static_assert(offsetof(MaterialManager, MaterialManager::m_pPostCopyDepth) == 0x80, "MaterialManager::m_pPostCopyDepth: Incorrect offset");
static_assert(offsetof(MaterialManager, MaterialManager::m_pPostCopyBrightness) == 0x88, "MaterialManager::m_pPostCopyBrightness: Incorrect offset");
static_assert(offsetof(MaterialManager, MaterialManager::m_pMainTerrainSurfaceGBuffer) == 0x90, "MaterialManager::m_pMainTerrainSurfaceGBuffer: Incorrect offset");
static_assert(offsetof(MaterialManager, MaterialManager::m_pMainTerrainSurfaceDepth) == 0x98, "MaterialManager::m_pMainTerrainSurfaceDepth: Incorrect offset");
static_assert(offsetof(MaterialManager, MaterialManager::m_pMainEditorTerrainSurfaceGBuffer) == 0xA0, "MaterialManager::m_pMainEditorTerrainSurfaceGBuffer: Incorrect offset");
static_assert(offsetof(MaterialManager, MaterialManager::m_pMainEditorTerrainSurfaceDepth) == 0xA8, "MaterialManager::m_pMainEditorTerrainSurfaceDepth: Incorrect offset");
static_assert(offsetof(MaterialManager, MaterialManager::m_pMainSky) == 0xB0, "MaterialManager::m_pMainSky: Incorrect offset");
static_assert(offsetof(MaterialManager, MaterialManager::m_pMainImpostorGBuffer) == 0xB8, "MaterialManager::m_pMainImpostorGBuffer: Incorrect offset");
static_assert(offsetof(MaterialManager, MaterialManager::m_pMainImpostorDepth) == 0xC0, "MaterialManager::m_pMainImpostorDepth: Incorrect offset");
static_assert(offsetof(MaterialManager, MaterialManager::m_arrMaterialMap) == 0xC8, "MaterialManager::m_arrMaterialMap: Incorrect offset");
static_assert(offsetof(MaterialManager, MaterialManager::m_vecMaterials) == 0x348, "MaterialManager::m_vecMaterials: Incorrect offset");

static_assert(sizeof(MaterialManager) == 0x360, "MaterialManager: Incorrect Size");

SMSDK_END_NAMESPACE