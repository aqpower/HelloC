#include "stdio.h"

int date[100005];
int max;

void search(int l, int r);

int main()
{
    int k, flag_fu = 1;
    scanf("%d", &k);
    for (int i = 0; i < k; i++)
    {
        scanf("%d", &date[i]);
        if (date[i] >= 0)
            flag_fu = 0;
        max += date[i];
    }
    if (flag_fu)
    {
        printf("0\n");
    }
    else
    {
        search(0, k - 1);
        printf("%d\n", max);
    }

    return 0;
}

void search(int l, int r)
{
    int t, maxl = 0, maxr = 0;
    if (l == r)
        return;
    int mid = (l + r) / 2;
    for (int i = mid; i >= l; i--)
    {
        for (int j = mid; j >= i; j--)
        {
            t += date[j];
        }
        if (t > maxl)
            maxl = t;
        t = 0;
    }
    for (int i = mid + 1; i <= r; i++)
    {
        for (int j = mid + 1; j <= i; j++)
        {
            t += date[j];
        }
        if (t > maxr)
            maxr = t;
        t = 0;
    }
    t = maxl + maxr;
    if (t > max)
        max = t;
    search(l, mid);
    search(mid + 1, r);
}