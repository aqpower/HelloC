#include "stdio.h"

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        long long min, temp, n, a, b, i = 0, j = 0;
        scanf("%d%d%d", &n, &a, &b);
        double da = 1.0 * a / 2, db = 1.0 * b / 3;
        if (da > db)
        {
            j = n / 3;
            if (n % 3)
            {
                if (a > b)
                {
                    j++;
                }
                else
                {
                    i = 1;
                }
            }
        }
        else if (da == db)
        {
            j = n / 3;
            if (n % 3)
            {
                if (a > b)
                    j++;
                else
                    i++;
            }
        }
        else
        {
            i = n / 2;
            if (n % 2)
            {
                if (b > a)
                {
                    i++;
                }
                else
                {
                    j = 1;
                }
            }
        }
        min = i * a + j * b;
        if (t == 0)
            printf("%d", min);
        else
            printf("%d\n", min);
    }

    return 0;
}