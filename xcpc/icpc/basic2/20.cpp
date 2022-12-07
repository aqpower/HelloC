#include "stdio.h"

int main()
{
    int n, k = 0, sum = 0;
    scanf("%d", &n);
    while (n)
    {
        sum += n % 10;
        k++;
        n /= 10;
    }
    printf("%d %d", k, sum);
    
    return 0;
}