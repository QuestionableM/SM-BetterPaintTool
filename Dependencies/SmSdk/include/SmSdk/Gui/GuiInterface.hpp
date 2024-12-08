#pragma once

#include "SmSdk/unreferenced_params.hpp"
#include "SmSdk/jsoncpp_include.hpp"

#include <unordered_map>
#include <functional>
#include <memory>

class GuiBase;

class GuiInterface
{
public:
	virtual ~GuiInterface() = default;
	virtual void func2() {}
	virtual void func3() {}
	virtual void func4() {}
	virtual void func5(const std::string& str) { SMSDK_UNREF(str); }
	virtual void func6(const std::string& str, __int64 a3) { SMSDK_UNREF2(str, a3); }
	virtual void func7(const std::string& str, const std::string& str2) { SMSDK_UNREF2(str, str2); }
	virtual void func8(const std::string& str, const std::string& str2) { SMSDK_UNREF2(str, str2); }
	virtual void func9(const std::string& str, const std::string& str2, const Json::Value& json_val) { SMSDK_UNREF3(str, str2, json_val); }
	virtual void func10(const std::string& str, const std::string& str2, std::size_t idx, const Json::Value& json_val) { SMSDK_UNREF4(str, str2, idx, json_val); }

	/* 0x0008 */ std::shared_ptr<GuiBase> m_pGuiBase;
private:
	/* 0x0018 */ char pad_0x18[0xC8];
public:
	/* 0x00E0 */ std::unordered_map<std::string, std::function<void(const std::string&)>> m_mapStringToFunction;
private:
	/* 0x0120 */ char pad_0x120[0x80];
public:
	/* 0x01A0 */ std::unordered_map<std::string, std::unordered_map<std::string, std::function<void(std::size_t, const Json::Value&)>>> m_mapMapCallbackStorage;
private:
	/* 0x01E0 */ char pad_0x1E0[0xC0];

}; // Size: 0x2A0

static_assert(sizeof(GuiInterface) == 0x2A0, "GuiInterface: Incorrect Size");