

#if defined(MY_WINDOWS_SOURCES)

#include "lib-loader-api.h"
#include <iostream>
#include <windows.h>
#include <tchar.h>

using namespace ::std;

class CLibLoader : public ILibLoader
{
private:
    HMODULE _module{nullptr};

public:
    virtual bool load(const char *libName) override
    {
        DWORD lastError = 0;
        _module = LoadLibraryA(libName);
        if (nullptr == _module)
        {
            lastError = ::GetLastError();
            cout << "faile to open " << libName << ", the error is " << lastError << endl;
        }
        return !_module;
    }
    virtual void *resolve(const char *symbolName) override
    {
        return GetProcAddress(_module, symbolName);
    }
    virtual void unload() override
    {
        if(_module)
        {
            FreeLibrary(_module);
            _module = nullptr;
        }
    }
    virtual void release() override
    {
            unload();
            delete this;
    }
};

ILibLoader* CrerateILibLoader()
{
    return new CLibLoader();
}

#endif