

#if defined(MY_LINUX_SOURCES)
#include <iostream>
#include "lib-loader-api.h"
#include <dlfcn.h>

using namespace ::std;

class CLibLoader : public ILibLoader
{
private:
    void *_module{nullptr};

public:
    virtual bool load(const char *libName) override
    {
        _module = dlopen(libName, RTLD_LAZY);
        if (nullptr == _module)
        {
            const char *error = dlerror();
            cout << "faile to open " << libName << ", the error is " << error << endl;
        }
        return !_module;
    }
    virtual void *resolve(const char *symbolName) override
    {
        return dlsym(_module, symbolName);
    }
    virtual void unload() override
    {
        if(_module)
        {
            dlclose(_module);
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