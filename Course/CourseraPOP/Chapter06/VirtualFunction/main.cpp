#include "head.h"

int main()
{
    Base OBase;
    Derived ODerived;
    
    // �����ĸ��麯��ȡ����pָ���������͵Ķ���
    Base *p;
    p = &OBase;
    p->SomeVirtualFunction();
    p = &ODerived;
    p->SomeVirtualFunction();

    // ������ָ������
    Base &r1 = OBase;
    Base &r2 = ODerived;
    r1.SomeVirtualFunction();
    r2.SomeVirtualFunction();

    return 0;
}