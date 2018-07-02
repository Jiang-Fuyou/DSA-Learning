#include <stdio.h>

int n = 4;

int &set_value() { return n; }

void swap1(int a, int b)
{
    int t;
    t = a;
    a = b;
    b = t;
}

void swap2(int *a, int *b)
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

void swap3(int &a, int &b)
{
    int t;
    t = a;
    a = b;
    b = t;
}

int main()
{
    int x = 3, y = 4;

    printf("Before swap1: x = %d, y = %d\n", x, y);
    swap1(x, y);
    printf("After swap1: x = %d, y = %d\n", x, y);

    printf("Before swap2: x = %d, y = %d\n", x, y);
    swap2(&x, &y);
    printf("After swap2: x = %d, y = %d\n", x, y);

    printf("Before swap3: x = %d, y = %d\n", x, y);
    swap3(x, y);
    printf("After swap3: x = %d, y = %d\n", x, y);

    printf("n = %d\n", n);
    set_value() = 40;
    printf("n = %d\n", n);

    return 0;
}