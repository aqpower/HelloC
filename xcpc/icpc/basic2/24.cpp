#include "stdio.h"

void mySwap(int *a, int *b);

int main()
{
    int i, n, world[99], t, ind_max = 0, ind_min = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &world[i]);
    t = world[0];
    for (i = 0; i < n; i++)
    {
        if (world[i] < t)
        {
            ind_min = i;
            t = world[i];
        }
    }
    mySwap(world, world + ind_min);
    t = world[0];
    for (i = 0; i < n; i++)
    {
        if (world[i] > t)
        {
            ind_max = i;
            t = world[i];
        }
    }
    mySwap(world + n - 1, world + ind_max);
    for (i = 0; i < n; i++)
        printf("%d ", world[i]);
    return 0;
}

void mySwap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
