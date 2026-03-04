#pragma once

#include <windows.h>

#include <unordered_set>
#include <functional>
#include <fstream>
#include <sstream>
#include <string>
#include <mutex>

#include "SmSdk/config.hpp"

SMSDK_BEGIN_NAMESPACE

namespace UTILS
{
class Contraption;

enum ConsoleLogType : uint32_t
{
	ConsoleLogType_Default = 0x1,
	ConsoleLogType_Profile = 0x2,
	ConsoleLogType_Resource = 0x4,
	ConsoleLogType_Shader = 0x8,
	ConsoleLogType_Buffer = 0x10,
	ConsoleLogType_Render = 0x20,
	ConsoleLogType_Network = 0x40,
	ConsoleLogType_System = 0x80,
	ConsoleLogType_Terrain = 0x100,
	ConsoleLogType_World = 0x200,
	ConsoleLogType_Audio = 0x400,
	ConsoleLogType_Lua = 0x800,
	ConsoleLogType_Print = 0x1000,
	ConsoleLogType_UGC = 0x2000,
	ConsoleLogType_Steam = 0x4000,
	ConsoleLogType_Warning = 0x40000000,
	ConsoleLogType_Error = 0x80000000,
};

class Console
{
public:
	virtual ~Console();
	virtual void log(const std::string& msg, WORD wColor, ConsoleLogType eType);
	virtual bool logNoRepeat(const std::string& msg, WORD wColor, ConsoleLogType eType);

	static Console* GetInstance();
private:
	template <typename CurArg>
	inline void variadicInternal(std::stringstream& ss, const CurArg& curArg)
	{
		ss << curArg;
	}

	template <typename CurArg, typename... Args>
	inline void variadicInternal(std::stringstream& ss, const CurArg& curArg, const Args&... argList)
	{
		this->variadicInternal(ss, curArg);
		this->variadicInternal(ss, argList...);
	}
public:
	template <typename... Args>
	inline void logVariadic(WORD wColor, ConsoleLogType eType, const Args&... args)
	{
		std::stringstream ss;
		this->variadicInternal(ss, args...);

		this->log(ss.str(), wColor, eType);
	}

	template <typename... Args>
	inline void logVariadicNoRepeat(WORD wColor, ConsoleLogType eType, const Args&... args)
	{
		std::stringstream ss;
		this->variadicInternal(ss, args...);

		this->logNoRepeat(ss.rdbuf()->str(), wColor, eType);
	}

	//inline static std::function<void(const char*, const char*, unsigned int)> sm_assertHandler = nullptr;
public:
	//inline static std::mutex sm_logMutex = std::mutex();
	//inline static std::mutex sm_logNoRepeatMutex = std::mutex();
	//inline static std::unordered_set<uint64_t> sm_messageCache = {};
private:
	/* 0x0008 */ std::function<void(const char*, unsigned int)> m_unknownFunction;
public:
	/* 0x0048 */ uint32_t m_uConsoleOutMask;
	/* 0x004C */ uint32_t m_uFileOutputMask;
	/* 0x0050 */ uint32_t m_uCallbackOutputMask;
private:
	/* 0x0054 */ char pad_0x54[0x4];
public:
	/* 0x0058 */ HANDLE m_hConsole = NULL;
	/* 0x0060 */ std::ofstream m_outStream;
private:
	/* 0x0168 */ char pad_0x168[0x10];
public:
	/* 0x0178 */ bool m_bCodePageSet = false;
	/* 0x0179 */ bool m_bConsoleAllocated = false;
private:
	/* 0x017A */ char pad_0x17A[0x2];
public:
	/* 0x017C */ uint32_t m_uWarningCounter = 0;
	/* 0x0180 */ uint32_t m_uErrorCounter = 0;
private:
	/* 0x0184 */ char pad_0x184[0x4];
};
}

#define LOG_ERROR(...) UTILS::Console::GetInstance()->logVariadic(FOREGROUND_RED | FOREGROUND_INTENSITY, UTILS::ConsoleLogType_Error, __VA_ARGS__)
#define LOG_WARNING(...) UTILS::Console::GetInstance()->logVariadic(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY, UTILS::ConsoleLogType_Warning, __VA_ARGS__)

SMSDK_END_NAMESPACE