#include "stdio.h"
#include "stdlib.h"

int main()
{
    double a, b;
    scanf("%lf%lf", &a, &b);
    printf("%.0f + %.0f = %.0f\n\
%.0f - %.0f = %.0f\n\
%.0f * %.0f = %.0f\n",
           a, b, a + b, a, b, a - b, a, b, a * b);
    if ((int)a % (int)b)
        printf("%.0f / %.0f = %.2f\n", a, b, a / b);
    else
        printf("%.0f / %.0f = %.0f\n", a, b, a / b);
    
    system("pause");
    return 0;
}
