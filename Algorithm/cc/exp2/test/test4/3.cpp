#include "stdlib.h"
#include "stdio.h"

int main()
{
    int a[9][9], i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    int t, max = a[0][0];

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (max < a[i][j])
            {
                max = a[i][j];
            }
        }
    }
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (a[i][j] == max)
            {
                printf("%d %d\n", i, j);
                break;
            }
        }
    }

    system("pause");
    return 0;
}
