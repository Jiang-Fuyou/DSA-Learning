#include "this.h"

// 静态成员函数不可以使用this指针

int main()
{
    Complex c1(2, 3);
    c1.AddOne();

    A *p = NULL;
    p->Hello(); // 


    return 0;
}