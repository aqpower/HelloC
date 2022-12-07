#include "stdio.h"

void selectSort(int world[], int len)
{
    int i;
    int j;
    for (i = 0; i < len - 1; i++)
    {
        int min = i;
        for (j = i + 1; j < len; j++)
        {
            if (world[j] < world[min])
            {
                min = j;
            }
        }
        int temp = world[min];
        world[min] = world[i];
        world[i] = temp;
    }
}
int main()
{
    int n, world[99];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", world + i);
    selectSort(world, n);
    for (int i = 0; i < n; i++)
        printf("%d ", world[i]);

    return 0;
}