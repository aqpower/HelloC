#include "stdio.h"
#include "stdlib.h"
double fact(int n);

int main()
{
    int m, n;
    scanf("%d%d", &m, &n);
    printf("result = %.0f\n", fact(n) / fact(m) / fact(n - m));

    system("pause");
    return 0;
}

double fact(int n)
{
    int i;
    double result = 1;
    for (i = 1; i <= n; i++)
        result *= i;
    return result;
}
