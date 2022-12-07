#include "stdio.h"
#include "stdlib.h"

int main()
{
    double x;
    scanf("%lf", &x);
    printf("f(%.1f) = %.1f\n", x, x == 10 ? 1 / x : x);
    system("pause");
    return 0;
}