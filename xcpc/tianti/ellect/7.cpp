#include "stdio.h"

int judge(int n);

int main()
{
    int n, count = 0;
    scanf("%d", &n);
    for (int i = 2; i <= n - 2; i++)
    {
        if (judge(i))
        {
            if (judge(i + 2))
            {
                count++;
            }
        }
    }
    printf("%d", count);
    return 0;
}

int judge(int n)
{
    for (int i = 2; i < n; i++)
    {
        if (!(n % i))
        {
            return 0;
        }
    }
    return 1;
}