#include <stdio.h>
#include <math.h>
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        long long int n, i, flag = 0, f, l, mid, j, c, r;
        scanf("%lld", &n);
        for (i = 1; i <= cbrt(n); i++)
        {
            r = n - (i * i * i);
            c = cbrt(r);
            if ((c * c * c) == r && c > 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}