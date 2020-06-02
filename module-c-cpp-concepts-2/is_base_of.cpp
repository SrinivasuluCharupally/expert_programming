#include <iostream>
#includeoot/Desktop/DK/lnx/boost/1.59.0/gcc-5.4.0/include/boost/static_assert.hpp"

class A {};
class B: public A {};
class C {};

template<class Base, class Derived>
struct SubclassCheck
{
    typedef char Yes;
    class No { char dummy[2]; };

    static Yes Test(Base);
    static No Test(...);
    enum {
        Value = (sizeof(Test(*(Derived*)NULL)) == sizeof(Yes))
    };
};

#define CHECK_DERIVES(b,d)\
    BOOT_STATIC_ASSERT((SubclassCheck<b,d>::Value));

int
main()
{
    CHECK_DERIVES(A, B);
    // CHECK_DERIVES(A, C); // fails
}
