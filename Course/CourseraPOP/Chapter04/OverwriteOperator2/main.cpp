#include "mystring.h"

#include <iostream>
using namespace std;

int main()
{
    String s;
    s = "Hello!";
    cout << s.c_str() << endl;

    // String s2 = "Hello2!"; // Error!初始化调用构造函数，构造函数并没有重载=
    s = "World!";
    cout << s.c_str() << endl;

    String s1, s2;
    s1 = "This";
    s2 = "That";
    s1 = s2; // 浅拷贝问题，直接“=”容易出现浅拷贝问题
             // 需要重载对象之间的=运算符

    return 0;
}