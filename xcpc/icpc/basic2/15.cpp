#include "stdlib.h"
#include "stdio.h"

int main()
{
    int m, n;
    scanf("%d%d", &m, &n);
    while (m--)
    {
        int t, i, sum = 0;
        for (i = 0; i < n; i++)
        {
            scanf("%d", &t);
            sum += t;
        }
        printf("%d\n", sum);
    }
    system("pause");
    return 0;
}