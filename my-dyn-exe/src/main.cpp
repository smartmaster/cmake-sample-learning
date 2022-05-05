#include "lib-loader-api.h"
#include "func.cpp.h"

int main(int argc, char **argv)
{
    IFoo * p = nullptr;
    for (int ii = 0; ii < 3; ++ii)
    {
        ILibLoader *loader = CrerateILibLoader();

        loader->load(MY_LIB_NAME("my-lib"));
        using func_t = IFoo* (*)();;
        auto func = (func_t)loader->resolve("cpp_singlton_api");
        p = func();
        p->f3();
        loader->release();
    }

    p->f3();

    return 0;
}