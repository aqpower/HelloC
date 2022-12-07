#include "stdio.h"
#include "stdlib.h"

int main()
{
    int i, n, k = 1;
    double sum = 0;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        sum += k * 1.0 / (3 * i - 2);
        k=-k;
    }
    printf("sum = %.3f\n", sum);

    system("pause");
    return 0;
}