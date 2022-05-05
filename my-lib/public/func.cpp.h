#pragma once 
#include "extern-c-def.h"
#include "my-lib-api.h"

MY_EXTERN_C
MY_LIB_API
void cpp_api();


struct IFoo
{
    virtual void f1() = 0;
    virtual void f2() = 0;
    virtual void f3() = 0;
    virtual void f4() = 0;
};

MY_EXTERN_C
MY_LIB_API
IFoo* cpp_singlton_api();
