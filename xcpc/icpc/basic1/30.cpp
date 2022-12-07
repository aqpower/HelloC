#include "stdio.h"
#include "stdlib.h"

int main()
{
    int n;
    double t, sum = 0, a = 2, b = 1;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        sum += a / b;
        t = a;
        a = a + b;
        b = t;
    }
    printf("%.2f\n", sum);
    system("pause");
    return 0;
}
