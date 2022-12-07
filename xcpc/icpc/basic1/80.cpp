#include "stdio.h"
#include "stdlib.h"

int main()
{
    int i, j, m, n;
    scanf("%d%d", &m, &n);
    char world[25][25] = {0};
    int blood[25][25] = {0};
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf(" %c", &world[i][j]);
        }
    }
    /*for (int flag = 0, i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%c", world[i][j]);

        }
    }*/
    for (i = 0; i < 20; i++)
    {
        for (j = 0; j < 20; j++)
        {
            if (world[i][j] != '#')
                blood[i][j] = 100;
        }
    }
    /*for (int flag = 0, i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", blood[i][j]);
            flag++;
            if (flag == 6)
            {
                flag = 0;
                printf("\n");
            }
        }
    }*/
    int time, k, count = 0, x, y;
    scanf("%d", &k);
    while (k--)
    {

        scanf("%d%d", &x, &y);
        getchar();
        blood[x][y] += 2;
        blood[x][y + 1] += 1;
        blood[x + 1][y] += 1;
        if (y - 1 >= 0)
            blood[x][y - 1] += 1;
        if (x - 1 >= 0)
            blood[x - 1][y] += 1;
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (blood[i][j] == 2)
                {
                    // printf("%d %d\n", i, j);
                    blood[i][j] = 100;
                    count++;
                }
            }
        }
        printf("%d\n", count);
        count = 0;
    }

    system("pause");
    return 0;
}
