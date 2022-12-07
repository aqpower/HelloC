#include "stdio.h"

int main()
{
    int a, b, time = 0, sum = 0;
    scanf("%d%d", &a, &b);
    for (int i = a; i <= b; i++)
    {
        printf("%5d", i);
        time++;
        sum += i;
        if (!(time % 5))
            printf("\n");
    }
    if (time % 5)
        printf("\n");
    printf("Sum = %d", sum);

    return 0;
}