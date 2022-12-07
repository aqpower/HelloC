#include "stdio.h"
#include "stdlib.h"

int main()
{
    int flag = 1, i, n, x, a[25];
    scanf("%d%d", &n, &x);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (i = 0; i < n; i++)
    {
        if (a[i] == x)
        {
            printf("%d\n", i);
            flag = 0;
            break;
        }
    }
    if (flag)
        printf("Not Found\n");
    
    system("pause");
    return 0;
}
