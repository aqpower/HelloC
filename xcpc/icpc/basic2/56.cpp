#include "stdio.h"

int main()
{
    int sum = 0, j, i, n, date[15];
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &date[i]);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            sum += date[i] * 10 + date[j];
        }
    }

    printf("%d\n", sum);

    return 0;
}