#include "stdio.h"

int main()
{
    int date[105], n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &date[i]);
    }
    for (int i = n; i >= 0; i--)
    {
        for (int j = 0; j < i - 1; j++)
        {
            if (date[j] > date[j + 1])
            {
                int t = date[j];
                date[j] = date[j + 1];
                date[j + 1] = t;
            }
        }
        k--;
        if (k == 0)
            break;
    }
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
            printf("%d", date[i]);
        else
            printf("%d ", date[i]);
    }
    return 0;
}