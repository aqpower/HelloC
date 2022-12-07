#include "stdio.h"
#include "stdlib.h"

int main()
{
    int n, j, i;
    scanf("%d", &n);
    for (i = 1; i <= n / 2 + 1; i++)
    {
        for (j = 0; j < n - 1 - 2 * (i - 1); j++)
            printf(" ");
        for (j = 0; j < 2 * i - 1; j++)
            printf("* ");
        printf("\n");
    }
    for (i = n / 2; i >= 1; i--)
    {
        for (j = 0; j < n - 1 - 2 * (i - 1); j++)
            printf(" ");
        for (j = 0; j < 2 * i - 1; j++)
            printf("* ");
        printf("\n");
    }

    system("pause");
    return 0;
}
