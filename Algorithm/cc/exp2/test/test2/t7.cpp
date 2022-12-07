#include "stdio.h"
#include "stdlib.h"

int main()
{
    int i, n, j, k, flag = 0;
    scanf("%d", &n);
    int t;
    t = 3 * n;
    for (i = 0; i <= n / 5; i++)
    {
        for (j = 0; j <= n / 3; j++)
        {
            for (k = 0; k <= n * 3; k++)
            {
                if (t == i * 15 + j * 9 + k && i + j + k == n)
                {
                    flag = 1;
                    printf("%d %d %d\n", i, j, k);
                    break;
                }
            }
        }
    }
    if (flag = 0)
        printf("No answer\n");
    system("pause");
    return 0;
}
