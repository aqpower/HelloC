#include "stdio.h"

int main()
{
    int a[9] = {9, 3, 2, 5, 6, 1, 6, 7}, sum = 0;
    int *pa = a;
    for (int i = 0; i < 8; i++)
    {
        sum += *(pa + i);
    }
    printf("%d\n", sum / 8);

    return 0;
}