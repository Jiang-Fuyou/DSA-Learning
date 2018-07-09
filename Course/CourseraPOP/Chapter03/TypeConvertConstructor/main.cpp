#include "complex.h"

int main()
{
    Complex c1;
    Complex c2(1, 2);
    Complex c3 = 12; // 初始化的时候直接调用类型转换构造函数
    c1 = 9; // 非初始化的情况下执行类型转换，先将右侧的9转换成一个临时Complex对象，
            // 此时执行类型转换构造函数，将此临时对象赋予c1之后，将临时对象析构，
            // 会再执行析构函数。
    c2 = 10;

    return 0;
}