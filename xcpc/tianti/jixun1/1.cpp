#include "stdio.h"

int nnn(int n);

int main()
{
    int sum,n;
    scanf("%d", &n);
    for (int i = 1; i <= n;i++)
        sum += nnn(i);
    printf("%d", sum);

    return 0;
}

int nnn(int n)
{
    int sum = 1;
    for (int i = 1; i <= n;i++)
        sum *= i;
    return sum;
}