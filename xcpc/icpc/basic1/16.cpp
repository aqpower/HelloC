#include "stdio.h"
#include "stdlib.h"
#include "math.h"

int nnn(int n);

int main()
{
    int n, sum = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        sum += nnn(i);
    }
    printf("%d\n", sum);
    system("pause");
    return 0;
}

int nnn(int n)
{
    int result = 1;
    for (int i = 1; i <= n; i++)
    {
        result *= i;
    }
    return result;
}