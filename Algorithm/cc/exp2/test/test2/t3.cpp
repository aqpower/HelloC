#include "stdio.h"
#include "stdlib.h"

int main()
{
    int i, sum=0;
    for (i = 2; i <= 100; i++)
    {
        for (int j = 1; j < i; j++)
        {

            if (i % j == 0)
                sum += j;
        }
        if (sum == i)
            printf("%d ", i);
        sum = 0;
    }
    printf("\n");
    system("pause");
    return 0;
}
