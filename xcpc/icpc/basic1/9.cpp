#include "stdio.h"
#include "stdlib.h"

int main()
{
    int n, i;
    double sum = 0;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        sum += 1.0 / (2 * i - 1);
    printf("sum = %f\n", sum);

    system("pause");
    return 0;
}
