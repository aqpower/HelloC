#include "stdio.h"
#include "stdlib.h"

int main()
{
    int n, x, y, flag = 0;
    scanf("%d", &n);
    for (x = 1; x < n; x++)
    {
        for (y = x; y < n; y++)
        {
            if (x * x + y * y == n)
            {
                printf("%d %d\n", x, y);
                flag++;
            }
        }
    }
    if(!flag)
    printf("No Solution");

    system("pause");
    return 0;
}