#include "head.h"

int main()
{
    Base OBase;
    Derived ODerived;
    
    // 调用哪个虚函数取决于p指向哪种类型的对象
    Base *p;
    p = &OBase;
    p->SomeVirtualFunction();
    p = &ODerived;
    p->SomeVirtualFunction();

    // 引用与指针类似
    Base &r1 = OBase;
    Base &r2 = ODerived;
    r1.SomeVirtualFunction();
    r2.SomeVirtualFunction();

    return 0;
}