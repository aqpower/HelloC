#include "stdio.h"
#include "stdlib.h"

int main()
{
    int n;
    scanf("%d", &n);
    if (n > 2100 || n <= 2000)
    {
        printf("Invalid year!\n");
        return 0;
    }
    for (int i = 2001; i <= n; i++)
    {
        if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0)
            printf("%d\n", i);
    }
    if (n < 2004)
        printf("None\n");

    system("pause");
    return 0;
}
