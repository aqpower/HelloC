#include "stdio.h"
#include "stdlib.h"

int main()
{
    char tar, world[105][105], mynew[105][105];
    int size;
    scanf("%c%d", &tar, &size);
    getchar();
    for (int i = 0; i < size; i++)
    {
        gets(world[i]);
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (world[i][j] != ' ')
            {
                mynew[size - 1 - i][size - 1 - j] = tar;
            }
            else
            {
                mynew[size - 1 - i][size - 1 - j] = ' ';
            }
        }
    }
    for (int i = 0; i < size; i++)
    {
        puts(mynew[i]);
    }

    system("pause");
    return 0;
}