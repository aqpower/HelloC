#include "stdio.h"
#include "math.h"

int absmin(int *a, int n);

int main()
{
    int i, n, want, world[99]={0}, tar;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", world + i);
    
    tar = absmin(world, n);
    
    printf("%d\n", tar);
    return 0;
}

int absmin(int *a, int n)
{
    int i, j, index = 0;
    int min = fabs(*a);
    for (i = 0; i < n; i++)
    {
        if (fabs(*(a + i)) < min)
        {
            index = i;
            min = fabs(*(a + i));
        }
    }
    return *(a + index);
}
