#pragma once

// Additional libraries that can be added to expand the functionality of SMSDK

#define SMSDK_ENABLE_PHYSICS
#define SMSDK_ENABLE_JSONCPP
//#define SMSDK_ENABLE_FMOD
//#define SMSDK_ENABLE_STEAMAPI
#define SMSDK_ENABLE_MYGUI
//#define SMSDK_ENABLE_D3D11

// WARNING: All the map getters will be wrong without the Boost uuid library
// TODO: This could be fixed by implementing the hash function that Boost uses internally for our stub
//#define SMSDK_ENABLE_BOOST

// You can optionally wrap everything into a namespace
#define SMSDK_NAMESPACE SM

#include <cstdint>
#include <cstddef>

#define SINGLETON_CLASS(class_name) \
	class_name() = delete; \
	class_name(const class_name&) = delete; \
	class_name(class_name&&) = delete; \
	~class_name() = delete

#define REMOVE_COPY_CONSTRUCTORS(class_name) \
	class_name() = delete; \
	class_name(const class_name&) = delete; \
	class_name(class_name&&) = delete;

// Means that the size_t is an output of an XXH function
using XXHStringHash = size_t;

// A simple number used as a hash
struct PassthroughHash
{
	inline size_t operator()(const size_t val) const noexcept
	{
		return val;
	}
};

#define SDK_PUB public:
#define SDK_PRI private:
#define SDK_PRO protected:

#ifdef SMSDK_NAMESPACE
#define SMSDK_BEGIN_NAMESPACE namespace SMSDK_NAMESPACE {
#define SMSDK_END_NAMESPACE }
#define SMSDK_USE_NAMESPACE using namespace SMSDK_NAMESPACE;
#else
#define SMSDK_BEGIN_NAMESPACE
#define SMSDK_END_NAMESPACE
#define SMSDK_USE_NAMESPACE
#endif