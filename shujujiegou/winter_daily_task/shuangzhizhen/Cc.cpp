#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, m, x, y, sum = 0;
        scanf("%d%d%d%d", &n, &m, &x, &y);
        getchar();
        char t;
        for (int i = 0; i < n; i++)
        {
            int date[1005];
            for (int j = 0; j < m; j++)
            {
                scanf("%c", &t);
                date[j] = t == '.' ? 0 : 1;
                if (j > 0)
                {
                    if (date[j] + date[j - 1] < 1)
                    {
                        date[j] = 1;
                        date[j - 1] = 1;
                        if (x * 2 > y)
                        {
                            sum += y;
                        }
                        else
                        {
                            sum += 2 * x;
                        }
                    }
                }
            }
            for (int k = 0; k < m; k++)
            {
                if (date[k] == 0)
                    sum += x;
            }
            getchar();
        }
        printf("%d\n", sum);
    }

    return 0;
}