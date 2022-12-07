#include "stdio.h"
#include "stdlib.h"

int main()
{
    int cnt = 0, t, n;
    int sum = 0;
    scanf("%d", &n);
    int all = n;
    if (n == 0)
    {
        printf("average = 0.0\n\
count = 0\n");
    }
    else
    {
        while (n--)
        {
            scanf("%d", &t);
            if (t >= 60)
                cnt++;
            sum += t;
        }
        printf("average = %.1f\n\
count = %d\n",1.0 * sum / all, cnt);
    }

    system("pause");
    return 0;
}
