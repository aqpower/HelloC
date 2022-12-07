#include "stdio.h"

int main()
{
    char num[1005];
    int t, sum[10] = {0};
    scanf("%s", num);
    for (int i = 0; num[i] != '\0'; i++)
    {
        t = num[i] - '0';
        sum[t]++;
    }
    for (int i = 0; i <= 9; i++)
    {
        if (sum[i])
            printf("%d:%d\n", i, sum[i]);
    }

    return 0;
}