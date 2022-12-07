#include "stdio.h"

int main()
{
    int n, i, nnn = 1;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        nnn *= i;
    }
    printf("%d\n", nnn);

    return 0;
}