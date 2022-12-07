#include "stdio.h"

int main()
{
    int hour, min, exp, t;
    scanf("%d%d", &t, &exp);
    hour = t / 100;
    min = t % 100;
    min += exp;
    while (min >= 60)
    {
        min -= 60;
        hour++;
    }
    while (min < 0)
    {
        min += 60;
        hour--;
    }
    printf("%d%02d", hour, min);
    return 0;
}
