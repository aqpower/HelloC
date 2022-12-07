#include "stdio.h"
#include "stdlib.h"

int main()
{
    int i = 1, j, a[999];
    while (scanf("%d", &a[i]) == 1)
        i++;
    for (j = 1; j <= i; j++)
    {
        printf("%d %d\n",j,a[j]);
        if (a[j] == 250)
        {
            printf("%d\n", j);
            break;
        }
    }
    system("pause");
    return 0;
}
