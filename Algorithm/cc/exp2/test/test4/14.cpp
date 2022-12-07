#include "stdio.h"
#include "stdlib.h"

int main()
{
    int i, j, n, line, flag = 1;
    scanf("%d", &n);
    while (n--)
    {
        int are[99][99];
        scanf("%d", &line);
        for (i = 0; i < line; i++)
        {
            for (j = 0; j < line; j++)
            {
                scanf("%d", &are[i][j]);
            }
        }
        for (i = 0; i < line; i++)
        {
            for (j = 0; j < i; j++)
            {
                if (are[i][j] != 0)
                {
                    flag = 0;
                }
            }
        }
        printf("%s\n", flag ? "YES" : "NO");
        flag = 1;
    }
    system("pause");
    return 0;
}