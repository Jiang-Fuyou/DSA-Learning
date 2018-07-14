#include "complex.h"

#include <iostream>
using namespace std;

int main()
{
    Complex a(1, 2);
    Complex b(2, 3);
    // Complex c = a + b;
    // cout << c.r << " + " << c.i << "i" << endl;

    Complex d = a + b;
    Complex e = a - b;
    
    d.Print();
    e.Print();

    return 0;
}