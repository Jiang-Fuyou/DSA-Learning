#include "complex.h"

int main()
{
    Complex c1;
    Complex c2(2);
    Complex c3(2, 3);
    Complex *pc = new Complex;

    delete pc;
    
    return 0;
}