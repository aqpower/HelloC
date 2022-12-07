#include "stdio.h"

int main()
{
    int n;
    double m, p;
    scanf("%d%lf", &n, &m);
    while (n--)
    {
        scanf("%lf", &p);
        if (p < m)
        {
            printf("On Sale! %.1f\n", p);
        }
    }

    return 0;
}