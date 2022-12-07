#include "stdio.h"
#include "stdlib.h"

int main()
{
    int sum = 0, i, k = 1, n, u, d;
    scanf("%d%d%d", &n, &u, &d);
    for (i = 1;; i++)
    {
        if (k)
        {
            sum += u;
            k = 0;
        }
        else
        {
            sum -= d;
            k = 1;
        }
        if (sum >= n)
        {
            printf("%d\n", i);
            break;
        }
    }

    system("pause");
    return 0;
}