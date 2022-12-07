#include "stdlib.h"
#include "stdio.h"

int main()
{
    int n, i, m, j, k;
    scanf("%d", &n);
    m = (n + 1) / 2;
    for (i = 1; i <= n; i++)
    {
        if (i <= m)
        {
            for (j = m - i; j > 0; j--)
                printf(" ");
            for (k = i; k > 0; k--)
                printf("* ");
        }
        else
        {
            for (j = i - m; j > 0; j--)
                printf(" ");
            for (k = 2 * m - i; k > 0; k--)
                printf("* ");
        }
        printf("\n");
    }
    system("pause");
    return 0;
}
