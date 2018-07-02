#include <stdio.h>

void PrintMin(const int a, const int b)
{
    if (a < b)
        printf("Min is %d.\n", a);
    else
        printf("Min is %d.\n", b);
}

void PrintMax(const int a, const int b)
{
    if (a < b)
        printf("Max is %d.\n", b);
    else
        printf("Max is %d.\n", a);
}

int main()
{
    void(*pf)(int, int);
    int x = 3, y = 4;

    printf("Test min:\n");
    pf = PrintMin;
    pf(x, y);

    printf("Test max:\n");
    pf = PrintMax;
    pf(x, y);
    
    return 0;
}