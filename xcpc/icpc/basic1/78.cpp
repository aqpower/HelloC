#include "stdio.h"
#include "stdlib.h"

int myall(int n);

int main()
{
    int n, t, m, i;
    scanf("%d", &n);
    for (i = 1;; i++)
    {
        t = myall(n) * 3 + 1;
        printf("%d:%d\n", i, t);
        if (n == t)
            break;
        n = t;
    }
    system("pause");
    return 0;
}

int myall(int n)
{
    int t, sum = 0;
    while (n)
    {
        t = n % 10;
        sum += t;
        n = n / 10;
    }
    return sum;
}