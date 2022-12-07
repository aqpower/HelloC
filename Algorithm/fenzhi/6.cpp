#include "stdio.h"
#include "math.h"

struct PLATER
{
    int num;
    int live[128] = {0};
} player[129];

int myfind(int *a, int x, int num);

int main()
{
    int m, n, dk = 0;
    scanf("%d", &m);
    n = pow(2, m);
    for (int i = 1; i <= n; i++)
        player[i].num = i;
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", i);
        int condition[128] = {0};
        for (int j = 0; j < n - 1; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                if (i == k)
                {
                    continue;
                }
                if (player[k].live[j] == i)
                {
                    printf("%d ", player[k].num);
                    condition[dk++] = k;
                    break;
                }
                if (myfind(condition, k, n))
                    continue;

                if (!player[k].live[j])
                {
                    printf("%d ", player[k].num);
                    condition[dk++] = k;
                    player[k].live[j] = i;
                    player[i].live[j] = k;
                    break;
                }
            }
        }
        dk = 0;
        printf("\n");
    }

    return 0;
}

int myfind(int *a, int x, int num)
{
    for (int i = 0; i < num; i++)
    {
        if (a[i] == x)
            return 1;
    }
    return 0;
}
