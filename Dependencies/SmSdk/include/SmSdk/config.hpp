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

//Requires bullet3 to be included in the project
#define SMSDK_ENABLE_PHYSICS