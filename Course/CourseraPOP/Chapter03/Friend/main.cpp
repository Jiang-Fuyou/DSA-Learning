#include "main.h"

int main()
{
    CCar c1(22), c2(33), c3(44);
    CDriver d1;
    d1.ModifyCar(&c1);

    c1.PrintPrice();
    c2.PrintPrice();
    c3.PrintPrice();

    return 0;
}