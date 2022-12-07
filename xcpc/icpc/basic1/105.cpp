#include "stdio.h"

struct SLEEPER
{
    char name[5];
    int frequency;
    int breth;
} sleeper[15];

int main()
{
    int n, flag = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s%d%d", sleeper[i].name, &sleeper[i].frequency, &sleeper[i].breth);
        if (sleeper[i].frequency > 20 || sleeper[i].frequency < 15)
            flag = 1;
        if (sleeper[i].breth > 70 || sleeper[i].breth < 50)
            flag = 1;
        if (flag)
            printf("%s\n", sleeper[i].name);
        flag = 0;
    }

    return 0;
}