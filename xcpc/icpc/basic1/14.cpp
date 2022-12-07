#include "stdio.h"
#include "stdlib.h"

int main()
{
    int m, n, i;
    double result = 0;
    scanf("%d%d", &m, &n);
    for (i = m; i <= n; i++)
    {
        result += i * i + 1.0 / i;
    }
    printf("sum = %f\n", result);
    system("pause");
    return 0;
}
