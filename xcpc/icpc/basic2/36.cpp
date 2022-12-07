#include "stdio.h"

int main()
{
    char world[99][99];
    int i, j;
    for (i = 0; i < 4; i++)
    {
        gets(world[i]);
    }
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j <= 1; j++)
        {
            printf("%c", world[i][j]);
        }
    }
    printf("\n");
    return 0;
}