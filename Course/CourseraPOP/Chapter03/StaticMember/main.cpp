#include "rectangle.h"

int Rectangle::nTotalArea = 0;
int Rectangle::nTotalNumber = 0;

int main()
{
    Rectangle r1(3, 3), r2(2, 2);
    Rectangle::PrintTotal();
    //r1.PrintTotal(); // 尽量用上面的调用方式

    return 0;
}