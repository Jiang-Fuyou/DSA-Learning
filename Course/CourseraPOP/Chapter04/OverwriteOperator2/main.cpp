#include "mystring.h"

#include <iostream>
using namespace std;

int main()
{
    String s;
    s = "Hello!";
    cout << s.c_str() << endl;

    // String s2 = "Hello2!"; // Error!��ʼ�����ù��캯�������캯����û������=
    s = "World!";
    cout << s.c_str() << endl;

    String s1, s2;
    s1 = "This";
    s2 = "That";
    s1 = s2; // ǳ�������⣬ֱ�ӡ�=�����׳���ǳ��������
             // ��Ҫ���ض���֮���=�����

    return 0;
}