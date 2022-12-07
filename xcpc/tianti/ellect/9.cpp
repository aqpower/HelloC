#include "stdio.h"

int main()
{
    int a[1000], b[1000];
    int n, t;
    int ta = 0, tb = 0, da = 0, db = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &t);
        if (t % 2)
            a[ta++] = t;
        else
            b[tb++] = t;
    }
    //ta--, tb--;
    int fa = 0, fb = 0;
    if (ta > tb * 2)
    {
        fa = 1;
    }
    else
    {
        fb = 1;
    }
    for (int i = 1; da + db != ta + tb; i++)
    {
        if (i % 2)
        {
            if (da < ta)
                printf("%d ", a[da++]);
        }
        else
        {
            if (da == ta - 1 && fa)
            {
                printf("%d", a[da++]);
                break;
            }
            if (db == tb - 1 && fb)
            {
                printf("%d", b[db++]);
                break;
            }
            if (da < ta)
                printf("%d ", a[da++]);
            if (db < tb)
                printf("%d ", b[db++]);
        }
    }
    return 0;
}