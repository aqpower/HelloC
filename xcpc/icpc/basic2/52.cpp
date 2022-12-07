#include "stdio.h"

int main()
{
    int j, i, n, m;
    int judge[105];
    int score[105];
    int right[105];
    int result = 0;

    scanf("%d%d", &n, &m);
    for (i = 0; i < m; i++)
    {
        scanf("%d", &score[i]);
    }
    for (i = 0; i < m; i++)
    {
        scanf("%d", &right[i]);
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &judge[j]);
            if (judge[j] == right[j])
            {
                result += score[j];
            }
        }
        printf("%d\n", result);
        result = 0;
    }

    return 0;
}