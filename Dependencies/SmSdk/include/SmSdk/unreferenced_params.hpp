#pragma once

#define SMSDK_UNREF(arg) ((void)(arg))
#define SMSDK_UNREF2(arg, arg2) SMSDK_UNREF(arg); SMSDK_UNREF(arg2)
#define SMSDK_UNREF3(arg, arg2, arg3) SMSDK_UNREF2(arg, arg2); SMSDK_UNREF(arg3)
#define SMSDK_UNREF4(arg, arg2, arg3, arg4) SMSDK_UNREF3(arg, arg2, arg3); SMSDK_UNREF(arg4)