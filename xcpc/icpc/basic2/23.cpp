#include "stdio.h"

int main()
{
    int n, i, bre, index = -1;
    int world[99];
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &world[i]);
    scanf("%d", &bre);
    if (n == 0)
    {
        printf("%d ", bre);
    }
    else
    {
        for (i = 0; i < n; i++)
        {
            if (bre <= world[i])
            {
                index = i;
                break;
            }
        }
        if (index >= 0)
        {
            for (i = 0; i < index; i++)
                printf("%d ", world[i]);
            printf("%d ", bre);
            for (i = index; i < n; i++)
                printf("%d ", world[i]);
        }
        else
        {
            for (i = 0; i < n; i++)
                printf("%d ", world[i]);
            printf("%d ", bre);
        }
        return 0;
    }
}
