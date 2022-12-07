#include "stdio.h"
#include "math.h"

#define Find(x, y) x + y == 0 ?: x + y
double a1, b1, a2, b2;
int flag = 1;

int main()
{
    scanf("%lf%lf%lf%lf", &a1, &b1, &a2, &b2);

    printf("(%.1f+%.1fi) + (%.1f+%.1fi) = ", a1, b1, a2, b2);
    if (fabs(a1 + a2) > 0.05)
    {
        printf("%.1f", a1 + a2);
        flag = 0;
    }
    if (fabs(b1 + b2) > 0.05)
    {
        if (flag)
            printf("%.1fi", b1 + b2);
        else
            printf("%+.1fi", b1 + b2);
        flag = 0;
    }
    if (flag)
        printf("0.0");
    printf("\n");
    flag = 1;

    printf("(%.1f+%.1fi) - (%.1f+%.1fi) = ", a1, b1, a2, b2);
    if (fabs(a1 - a2) > 0.05)
    {
        printf("%.1f", a1 - a2);
        flag = 0;
    }
    if (fabs(b1 - b2) > 0.05)
    {
        if (flag)
            printf("%.1fi", b1 - b2);
        else
            printf("%+.1fi", b1 - b2);
        flag = 0;
    }
    if (flag)
        printf("0.0");
    printf("\n");
    flag = 1;

    printf("(%.1f+%.1fi) * (%.1f+%.1fi) = ", a1, b1, a2, b2);
    if (fabs(a1 * a2 - b1 * b2) > 0.05)
    {
        printf("%.1f", a1 * a2 - b1 * b2);
        flag = 0;
    }
    if (fabs(b1 * a2 + a1 * b2) > 0.05)
    {
        if (flag)
            printf("%.1fi", b1 * a2 + a1 * b2);
        else
            printf("%+.1fi", b1 * a2 + a1 * b2);
        flag = 0;
    }
    if (flag)
        printf("0.0");
    printf("\n");
    flag = 1;

    printf("(%.1f+%.1fi) / (%.1f+%.1fi) = ", a1, b1, a2, b2);
    if (fabs((a1 * a2 + b1 * b2) / (a2 * a2 + b2 * b2)) > 0.05)
    {
        printf("%.1f", (a1 * a2 + b1 * b2) / (a2 * a2 + b2 * b2));
        flag = 0;
    }
    if (fabs((b1 * a2 - a1 * b2) / (a2 * a2 + b2 * b2)) > 0.05)
    {
        if (flag)
            printf("%.1fi", (b1 * a2 - a1 * b2) / (a2 * a2 + b2 * b2));
        else
            printf("%+.1fi", (b1 * a2 - a1 * b2) / (a2 * a2 + b2 * b2));
        flag = 0;
    }
    if (flag)
        printf("0.0");
    printf("\n");

    return 0;
}
