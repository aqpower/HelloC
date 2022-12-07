#include "stdio.h"

int myMin(int a, int b);

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d %d", myMin(a, b), a * b / myMin(a, b));
    return 0;
}

int myMin(int a, int b)
{
    if (a % b == 0)
        return b;
    return myMin(b, a % b);
}