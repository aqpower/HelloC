#include "stdio.h"
#include "algorithm"
#include "math.h"

using namespace std;

int Prime(int n);

int main()
{
    char world[1005];
    int a[13];
    int l, k, flag = 1;
    scanf("%d%d", &l, &k);
    getchar();
    scanf("%s", world);
    for (int i = 0; i < l - k; i++)
    {
        int j = i + k, da = 0;
        for (int di = i; di < j; di++)
        {
            a[da++] = world[di] - '0';
        }
        for (int ii = 0, jj = da - 1; ii < jj; ii++, jj--)
        {
            int t = a[ii];
            a[ii] = a[jj];
            a[jj] = t;
        }
        int re = 0, t, x = 1;
        for (int di = 0; di < da; di++)
        {
            t = a[di] * x;
            x *= 10;
            re += t;
        }
        if (Prime(re))
        {
            flag = 0;
            printf("%d\n", re);
            break;
        }
    }
    if (flag)
        printf("404\n");

    return 0;
}

int Prime(int n)
{
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}