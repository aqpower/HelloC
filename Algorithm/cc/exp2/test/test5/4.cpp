#include "stdio.h"
#include "stdlib.h"
void myStrrev(int *a, int n);
int main()
{
    int world[99];
    int i, n;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", world + i);
    myStrrev(world, n);
    for (i = 0; i < n; i++)
        printf("%d ", world[i]);
    printf("\n");
    system("pause");
    return 0;
}

void myStrrev(int *a, int n)
{
    int i, j;
    int t;
    for (i = 0, j = n - 1; i <= j; i++, j--)
    {
        t = *(a + i);
        *(a + i) = *(a + j);
        *(a + j) = t;
    }
}
