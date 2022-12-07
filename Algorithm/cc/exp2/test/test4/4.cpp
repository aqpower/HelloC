#include "stdio.h"

int main()
{
    int sum = 0, a[9][9], i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < i; j++)
        {
            sum += a[i][j];
        }
    }
    printf("%d", sum);

    return 0;
}
