#include "stdio.h"

int main()
{
    int i, n, flag = 0, world[99];
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &world[i]);
    for (i = 1; i < n; i++)
    {
        flag++;
        printf("%d", world[i] - world[i - 1]);
        if (flag == n - 1)
            break;
        if (flag % 3)
            printf(" ");
        else
            printf("\n");
    }
    return 0;
}