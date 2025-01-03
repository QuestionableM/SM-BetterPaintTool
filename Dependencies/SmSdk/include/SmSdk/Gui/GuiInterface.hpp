#pragma once

#include "SmSdk/unreferenced_params.hpp"
#include "SmSdk/jsoncpp_include.hpp"

#include <unordered_map>
#include <functional>
#include <memory>

class GuiBase;

struct GuiDeferredCallback
{
	/* 0x0000 */ std::string m_identifier;
	/* 0x0020 */ std::function<void(void)> m_callback;
}; // Size: 0x60

static_assert(offsetof(GuiDeferredCallback, GuiDeferredCallback::m_identifier) == 0x0, "GuiDeferredCallback::m_identifier: Incorrect offset");
static_assert(offsetof(GuiDeferredCallback, GuiDeferredCallback::m_callback) == 0x20, "GuiDeferredCallback::m_callback: Incorrect offset");

static_assert(sizeof(GuiDeferredCallback) == 0x60, "GuiDeferredCallback: Incorrect Size");

class GuiInterface
{
public:
	virtual ~GuiInterface() = default;
	virtual void open() {}
	virtual void close() {}
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
	/* 0x01E0 */ char pad_0x1E0[0x80];
public:
	/* 0x0260 */ std::deque<std::function<void(void)>> m_deferredCallbackDeque;
	/* 0x0288 */ std::vector<GuiDeferredCallback> m_vecDeferredCallbacks;

}; // Size: 0x2A0

static_assert(offsetof(GuiInterface, GuiInterface::m_pGuiBase) == 0x8, "GuiInterface::m_pGuiBase: Incorrect offset");
static_assert(offsetof(GuiInterface, GuiInterface::m_mapStringToFunction) == 0xE0, "GuiInterface::m_mapStringToFunction: Incorrect offset");
static_assert(offsetof(GuiInterface, GuiInterface::m_mapMapCallbackStorage) == 0x1A0, "GuiInterface::m_mapMapCallbackStorage: Incorrect offset");
static_assert(offsetof(GuiInterface, GuiInterface::m_deferredCallbackDeque) == 0x260, "GuiInterface::m_deferredCallbackDeque: Incorrect offset");
static_assert(offsetof(GuiInterface, GuiInterface::m_vecDeferredCallbacks) == 0x288, "GuiInterface::m_vecDeferredCallbacks: Incorrect offset");

static_assert(sizeof(GuiInterface) == 0x2A0, "GuiInterface: Incorrect Size");