#pragma once

#define SINGLETON_CLASS(class_name) \
	class_name() = delete; \
	class_name(const class_name&) = delete; \
	class_name(class_name&&) = delete; \
	~class_name() = delete

#define REMOVE_COPY_CONSTRUCTORS(class_name) \
	class_name() = delete; \
	class_name(const class_name&) = delete; \
	class_name(class_name&&) = delete;

//Additional libraries that can be added to expand the functionality of SMSDK

#define SMSDK_ENABLE_PHYSICS
#define SMSDK_ENABLE_JSONCPP
//#define SMSDK_ENABLE_FMOD
//#define SMSDK_ENABLE_STEAMAPI
#define SMSDK_ENABLE_MYGUI

// WARNING: All the map getters will be wrong without the Boost uuid library
//#define SMSDK_ENABLE_BOOST