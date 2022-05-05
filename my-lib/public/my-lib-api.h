#pragma once

#if defined(MY_WINDOWS_SOURCES)

#if defined(MY_LIB_12289358_CC47_11EC_8243_47E9D2D6E4D5)
#define MY_LIB_API __declspec(dllexport)
#else
#define MY_LIB_API __declspec(dllimport)
#endif

#elif defined(MY_LINUX_SOURCES)
#define MY_LIB_API __attribute__ ((visibility ("default")))
#endif