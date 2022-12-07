#include "stdio.h"

int main()
{
    int j, i, a[9999], b[9999] = {0}, n;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (a[i] == a[j])
                b[i]++;
        }
    }
    int max = b[0], index = 0;
    for (i = 0; i < n; i++)
    {
        if (b[i] > max)
        {
            index = i;
            max = b[i];
        }
    }
    printf("%d %d", a[index], b[index]);
    return 0;
}