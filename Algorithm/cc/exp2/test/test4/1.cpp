#include "stdio.h"
#include "stdlib.h"

int main()
{
    int i, j, t, n, a[99];
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (i = 0; i < n - 1; i++)
    {
        for (j = i; j < n; j++)
        {
            if (a[i] < a[j])
            {
                t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
    for (i = 0; i < n; i++)
        printf("%d\t", a[i]);
    system("pause");
    return 0;
}