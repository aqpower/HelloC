#include "stdio.h"
#include "stdlib.h"

int main()
{
    int i;
    double t, sum = 0, a = 2, b = 1;
    for (i = 1; i <= 10; i++)
    {
        sum += a / b;
        t = a;
        a = a + b;
        b = t;
    }
    printf("%lf\n", sum);
    system("pause");
    return 0;
}
