#pragma once
#include "extern-c-def.h"

struct ILibLoader
{
    virtual bool load(const char* libName) = 0;
    virtual void* resolve(const char* symbolName) = 0;
    virtual void unload() = 0;
    virtual void release() = 0;
};

#if defined(MY_WINDOWS_SOURCES)
#define MY_LIB_NAME(x) x ".dll"
#elif defined(MY_LINUX_SOURCES)
#define MY_LIB_NAME(x) "lib"  x ".so"
#endif

ILibLoader* CrerateILibLoader();

