#include "stdio.h"

int main()
{
    int a = 8, b = 9, c = 10;

    int t = a / 3;
    a = a / 3;
    b += t;
    c += t;
    t = b / 3;
    b = b / 3;
    a += t;
    c += t;
    t = c / 3;
    c = c / 3;
    a += t;
    b += t;

    printf("%d %d %d\n", a, b, c);

    return 0;
}