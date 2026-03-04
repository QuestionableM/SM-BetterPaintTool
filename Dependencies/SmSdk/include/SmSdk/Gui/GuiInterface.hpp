#pragma once

#include "SmSdk/unreferenced_params.hpp"
#include "SmSdk/jsoncpp_include.hpp"

#include <unordered_map>
#include <functional>
#include <memory>
#include <string>
#include <deque>

SMSDK_BEGIN_NAMESPACE

class GuiBase;

struct GuiDeferredCallback
{
	/* 0x0000 */ SDK_PUB std::string m_identifier;
	/* 0x0020 */ SDK_PUB std::function<void(void)> m_callback;
}; // Size: 0x60

static_assert(offsetof(GuiDeferredCallback, GuiDeferredCallback::m_identifier) == 0x0, "GuiDeferredCallback::m_identifier: Incorrect offset");
static_assert(offsetof(GuiDeferredCallback, GuiDeferredCallback::m_callback) == 0x20, "GuiDeferredCallback::m_callback: Incorrect offset");

static_assert(sizeof(GuiDeferredCallback) == 0x60, "GuiDeferredCallback: Incorrect Size");

class GuiInterface
{
	SDK_PUB virtual ~GuiInterface() = default;
	SDK_PUB virtual void open() {}
	SDK_PUB virtual void close() {}
	SDK_PRI virtual void func4() {}
	SDK_PUB virtual void func5(const std::string& str) { SMSDK_UNREF(str); }
	SDK_PUB virtual void func6(const std::string& str, std::int64_t a3) { SMSDK_UNREF2(str, a3); }
	SDK_PUB virtual void func7(const std::string& str, const std::string& str2) { SMSDK_UNREF2(str, str2); }
	SDK_PUB virtual void func8(const std::string& str, const std::string& str2) { SMSDK_UNREF2(str, str2); }
	SDK_PUB virtual void func9(const std::string& str, const std::string& str2, const Json::Value& json_val) { SMSDK_UNREF3(str, str2, json_val); }
	SDK_PUB virtual void func10(const std::string& str, const std::string& str2, size_t idx, const Json::Value& json_val) { SMSDK_UNREF4(str, str2, idx, json_val); }
	SDK_PRI virtual void func11() {}
	SDK_PRI virtual void func12() {}
	SDK_PUB virtual void processDeferredCallbacks() {}

	/* 0x0008 */ SDK_PUB std::shared_ptr<GuiBase> m_pGuiBase;
	/* 0x0018 */ SDK_PRI bool m_bSomeBool;
	/* 0x0019 */ SDK_PRI char pad_0x19[0x7];
	/* 0x0020 */ SDK_PUB std::function<void(void)> m_closeCallback;
	/* 0x0060 */ SDK_PUB std::unordered_map<std::string, std::function<void(void)>> m_mapEmptyFunctionCallbacks;
	/* 0x00A0 */ SDK_PUB std::unordered_map<std::string, std::function<void(std::int64_t)>> m_mapOneArgFunctionCallbacks;
	/* 0x00E0 */ SDK_PUB std::unordered_map<std::string, std::function<void(const std::string&)>> m_mapStringToFunction;
	/* 0x0120 */ SDK_PRI char pad_0x120[0x80];
	/* 0x01A0 */ SDK_PUB std::unordered_map<std::string, std::unordered_map<std::string, std::function<void(size_t, const Json::Value&)>>> m_mapMapCallbackStorage;
	/* 0x01E0 */ SDK_PRI char pad_0x1E0[0x80];
	/* 0x0260 */ SDK_PUB std::deque<std::function<void(void)>> m_deferredCallbackDeque;
	/* 0x0288 */ SDK_PUB std::vector<GuiDeferredCallback> m_vecDeferredCallbacks;
}; // Size: 0x2A0

static_assert(offsetof(GuiInterface, GuiInterface::m_pGuiBase) == 0x8, "GuiInterface::m_pGuiBase: Incorrect offset");
static_assert(offsetof(GuiInterface, GuiInterface::m_closeCallback) == 0x20, "GuiInterface::m_closeCallback: Incorrect offset");
static_assert(offsetof(GuiInterface, GuiInterface::m_mapEmptyFunctionCallbacks) == 0x60, "GuiInterface::m_mapEmptyFunctionCallbacks: Incorrect offset");
static_assert(offsetof(GuiInterface, GuiInterface::m_mapOneArgFunctionCallbacks) == 0xA0, "GuiInterface::m_mapOneArgFunctionCallbacks: Incorrect offset");
static_assert(offsetof(GuiInterface, GuiInterface::m_mapStringToFunction) == 0xE0, "GuiInterface::m_mapStringToFunction: Incorrect offset");
static_assert(offsetof(GuiInterface, GuiInterface::m_mapMapCallbackStorage) == 0x1A0, "GuiInterface::m_mapMapCallbackStorage: Incorrect offset");
static_assert(offsetof(GuiInterface, GuiInterface::m_deferredCallbackDeque) == 0x260, "GuiInterface::m_deferredCallbackDeque: Incorrect offset");
static_assert(offsetof(GuiInterface, GuiInterface::m_vecDeferredCallbacks) == 0x288, "GuiInterface::m_vecDeferredCallbacks: Incorrect offset");

static_assert(sizeof(GuiInterface) == 0x2A0, "GuiInterface: Incorrect Size");

SMSDK_END_NAMESPACE