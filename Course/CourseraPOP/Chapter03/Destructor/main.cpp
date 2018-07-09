/*
    先被构造的对象后被析构掉
*/

#include "demo.h"

Demo d1(1);

void Func()
{
    static Demo d2(2);
    Demo d3(3);
    cout << "Func" << endl;
}

int main()
{
    Demo d4(4);
    d4 = 6;
    cout << "main" << endl;

    {
        Demo d5(5);
    }

    Func();
    cout << "main ends." << endl;

    return 0;
}