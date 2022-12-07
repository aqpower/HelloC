#include "stdio.h"

int main()
{
    int line, i, j;
    char str = 'A';
    scanf("%d", &line);
    for (i = 0; i < line; i++)
    {
        for (j = line - i; j > 0; j--)
        {
            printf("%c ", str++);
        }
        printf("\n");
    }
    return 0;
}