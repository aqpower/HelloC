#include "stdio.h"
#include "stdlib.h"

int main()
{
    double a, b;
    scanf("%lf%lf", &a, &b);
    if (b == 0)
        printf("%.0f/%.0f=Error\n", a, b);
    else
    {
        if (b > 0)
            printf("%.0f/%.0f=%.2f\n", a, b, a / b);
        else
            printf("%.0f/(%.0f)=%.2f\n", a, b, a / b);
    }
    system("pause");
    return 0;
}
