#include "stdio.h"

int main()
{
    int i, n, sum = 1;
    scanf("%d", &n);
    n -= 1;
    while (n--)
    {
        sum = (sum + 1) * 2;
    }
    printf("%d", sum);
    
    return 0;
}