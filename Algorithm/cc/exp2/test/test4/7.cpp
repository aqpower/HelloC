#include "stdio.h"
#include "stdlib.h"

int main()
{
    int yangh[15][15];
    yangh[0][0] = 1;
    for (int i = 1; i < 10; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0 || j == i)
            {
                yangh[i][j] = 1;
            }
            else
            {
                yangh[i][j] = yangh[i - 1][j - 1] + yangh[i - 1][j];
            }
        }
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j <= i; j++)
            printf("%d\t", yangh[i][j]);
        printf("\n");
    }
    system("pause");
    return 0;
}
