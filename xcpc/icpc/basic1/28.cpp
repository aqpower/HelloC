#include "stdio.h"
#include "stdlib.h"

double myNnn(int n);

int main()
{
    int n, i;
    double sum = 1;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        sum += 1.0 / myNnn(i);
    printf("%.8f\n", sum);
    system("pause");
    return 0;
}

double myNnn(int n)
{
    double sum = 1;
    for (int i = 2; i <= n; i++)
        sum *= i;
    return sum;
}
