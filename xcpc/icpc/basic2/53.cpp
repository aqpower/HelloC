#include "stdio.h"

struct Judge
{
    char let;
    char type;
};

int main()
{
    int N, i, mess = 0;
    int ans[105] = {0};

    struct Judge judge[7];

    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        int j = 4;
        while (j--)
        {
            getchar();
            scanf("%c-%c", &judge[j].let, &judge[j].type);
        }
        for (int k = 0; k < 4; k++)
        {
            if (judge[k].type == 'T')
            {
                ans[mess++] = judge[k].let - 'A' + 1;
            }
        }
    }
    for (i = 0; i < N; i++)
        printf("%d", ans[i]);

    return 0;
}