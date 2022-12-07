#include "stdio.h"
#include "stdlib.h"
#include "math.h"

int main()
{
    int k = 1;
    double eps, sum = 0, t;
    scanf("%lf", &eps);
    for (int i = 1;; i++)
    {
        t = 1.0 / (3 * i - 2) * k;
        k = -k;
        sum += t;
        if (fabs(t) <= eps)
            break;
    }

    printf("sum = %f\n", sum);
    system("pause");
    return 0;
}
