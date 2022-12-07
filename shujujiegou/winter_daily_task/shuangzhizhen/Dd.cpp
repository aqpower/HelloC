#include "stdio.h"

int myfind(double *a, double x, int l, int r);

int main()
{
    int n, m;
    double dor[20005], pre[20005];
    pre[0] = 0;
    scanf("%d%d", &n, &m);
    if (n < 5000)
    {
        for (int i = 1; i <= n; i++)
        {
            scanf("%lf", &dor[i]);
        }

        while (m--)
        {
            int loc = 1;
            double t;
            scanf("%lf", &t);

            while (t - dor[loc] > 0)
            {
                t -= dor[loc];
                loc++;
            }
            printf("%d %.0lf\n", loc, t);
        }
    }
    else
    {
        scanf("%lf", &dor[1]);
        pre[1] = dor[1];
        for (int i = 2; i <= n; i++)
        {
            scanf("%lf", &dor[i]);
            pre[i] = dor[i] + pre[i - 1];
        }

        while (m--)
        {
            double t, poi;
            scanf("%lf", &t);
            int loc = myfind(pre, t, 1, n);

            if (t - pre[loc] < 0)
            {
                poi = t - pre[loc - 1];
            }
            else if (t - pre[loc] == 0)
            {
                poi = dor[loc];
            }
            else
            {
                poi = t - pre[loc];
                loc++;
            }
            printf("%d %.0lf\n", loc, poi);
        }
    }

    return 0;
}

int myfind(double *a, double x, int l, int r)
{
    int loc;
    if (l == r)
    {
        return l;
    }
    int mid = (l + r) / 2;
    if (a[mid] == x)
    {
        loc = mid;
    }
    else if (a[mid] < x)
    {
        loc = myfind(a, x, mid + 1, r);
    }
    else if (a[mid] > x)
    {
        loc = myfind(a, x, l, mid - 1);
    }

    return loc;
}