#include <iostream>
#include <string>
#include <vector>
#include "func.cpp.h"

using namespace ::std;

void cpp_internal()
{
    cout << __FUNCTION__ << endl;
}

void cpp_api()
{
    cpp_internal();
    cout << __FUNCTION__ << endl;
}

namespace
{
    struct CFoo : public IFoo
    {
    private:
        string _str;
        vector<char> _shadow;

    public:
        CFoo() : 
        _str{__FUNCTION__}
         
        {
            _shadow.assign(_str.begin(), _str.end());
            _shadow.push_back('\0');
        }
        virtual void f1() override
        {
            cout << __FUNCTION__ << " " << _str << " " << _shadow.data() << endl;
        }
        virtual void f2() override
        {
            cout << __FUNCTION__ << " " << _str << " " << _shadow.data() << endl;
        }
        virtual void f3() override
        {
            cout << __FUNCTION__ << " " << _str << " " << _shadow.data() << endl;
        }
        virtual void f4() override
        {
            cout << __FUNCTION__ << " " << _str << " " << _shadow.data() << endl;
        }
    };
}

IFoo *cpp_singlton_api()
{
    static CFoo foo;
    return &foo;
}