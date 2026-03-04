#pragma once

#include "SmSdk/Base/NetObj.hpp"
#include "SmSdk/Creation/ChildShape.hpp"

#include <memory>
#include <list>
#include <string>
#include <map>

SMSDK_BEGIN_NAMESPACE

enum ControllerType : uint32_t
{
	ControllerType_Null = 0x0,
	ControllerType_ElectricMotor = 0x1,
	ControllerType_MotorController = 0x2,
	ControllerType_SteeringController = 0x3,
	ControllerType_SeatController = 0x4,
	ControllerType_SequenceController = 0x5,
	ControllerType_ButtonController = 0x6,
	ControllerType_LeverController = 0x7,
	ControllerType_SensorController = 0x8,
	ControllerType_ThrusterController = 0x9,
	ControllerType_RadioController = 0xA,
	ControllerType_HornController = 0xB,
	ControllerType_ToneController = 0xC,
	ControllerType_LogicController = 0xD,
	ControllerType_TimerController = 0xE,
	ControllerType_ParticlePreviewController = 0xF,
	ControllerType_SpringController = 0x10,
	ControllerType_SpotLightController = 0x11,
	ControllerType_ChestController = 0x13,
	ControllerType_ItemStackController = 0x14,
	ControllerType_ScriptController = 0x15,
	ControllerType_COUNT = 0x1F,
};

class ControllerBase : public NetObj
{
	/* 0x0028 */ SDK_PRI char pad_0x28[0x10];
	/* 0x0038 */ SDK_PUB ControllerType m_controllerType;
	/* 0x003C */ SDK_PRI char pad_0x3C[0xC];
	/* 0x0048 */ SDK_PUB std::shared_ptr<ChildShape> m_pParentShape;
	/* 0x0058 */ SDK_PRI char pad_0x58[0x10];
	/* 0x0068 */ SDK_PUB std::int32_t m_iMaxParentCount;
	/* 0x006C */ SDK_PRI char pad_0x6C[0x14];
	/* 0x0080 */ SDK_PUB std::shared_ptr<class GuiInterface> m_pGuiInterface;
	/* 0x0090 */ SDK_PUB std::list<std::shared_ptr<ControllerBase>> m_listParents;
	/* 0x00A0 */ SDK_PUB std::list<std::shared_ptr<class Controller>> m_listChildControllers;
	/* 0x00B0 */ SDK_PUB std::list<std::shared_ptr<class Joint>> m_listChildJoints;
	/* 0x00C0 */ SDK_PUB std::map<std::string, class ControllerBoneData> m_mapAnimatedBones;
	/* 0x00D0 */ SDK_PUB bool m_bUpdateFlag;
	/* 0x00D1 */ SDK_PRI char pad_0xD1[0xF];
}; // Size: 0xE0

static_assert(sizeof(ControllerBase) == 0xE0, "ControllerBase: Incorrect Size");

SMSDK_END_NAMESPACE