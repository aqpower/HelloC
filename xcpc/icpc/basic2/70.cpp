#include "stdio.h"
#include "math.h"

int main()
{
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    printf("%.0f\n", fabs(c - a) + fabs(d - b));

    return 0;
}