#include "stdio.h"
#include "stdlib.h"
#include "math.h"

int main()
{
    double a, b, c, d, x, y;
    scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
    x = a + c;
    y = b + d;
    if (fabs(a + c) < 0.5)
        x = 0;
    if (fabs(b + d) < 0.5)
        y = 0;
    printf("(%.1f, %.1f)", x, y);
    system("pause");
    return 0;
}