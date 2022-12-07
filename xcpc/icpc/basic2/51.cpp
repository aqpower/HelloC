#include "stdio.h"

struct List
{
    char num[20];
    int pre;
    int exam;
};

int main()
{
    int N, M, find[1005];
    struct List list[1005];

    scanf("%d", &N);
    getchar();

    for (int i = 0; i < N; i++)
    {
        scanf("%s %d%d", list[i].num, &list[i].pre, &list[i].exam);
        getchar();
    }
    scanf("%d", &M);
    for (int i = 0; i < M; i++)
    {
        scanf("%d", &find[i]);
    }
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (find[i] == list[j].pre)
            {
                printf("%s %d\n", list[j].num, list[j].exam);
                break;
            }
        }
    }

    return 0;
}