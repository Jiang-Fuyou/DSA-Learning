#include "sample.h"

#include <iostream>
using namespace std;

int main()
{
    const Sample o;
    Sample p;
    /*
    o.value = 100;
    o.func();
*/
    cout << o.GetValue() << endl;
    cout << p.GetValue() << endl;


    return 0;
}