#include "stdio.h"

int main()
{
    int flag = 1, i, j, world[99][99], m, n;
    scanf("%d%d", &m, &n);
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &world[i][j]);
        }
    }
    for (i = 1; i < m - 1; i++)
    {
        for (j = 1; j < n - 1; j++)
        {
            int t = world[i][j];
            if (t > world[i - 1][j] && t > world[i + 1][j] && t > world[i][j - 1] && t > world[i][j + 1])
            {
                flag = 0;
                printf("%d %d %d", t, i + 1, j + 1);
                printf("\n");
            }
        }
        if (flag)
            printf("None %d %d\n", m, n);
        flag = 1;
    }
    return 0;
}