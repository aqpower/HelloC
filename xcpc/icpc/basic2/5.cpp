#include "stdio.h"

int main()
{
    int n, i;
    double sum, k = 1;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        sum += k * i / (2 * i - 1);
        k = -k;
    }
    printf("%.3f", sum);
    return 0;
}