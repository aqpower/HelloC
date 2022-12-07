#include "stdio.h"

int main()
{
    int withup = 0, withlow = 0;
    double open, high, low, close;

    scanf("%lf%lf%lf%lf", &open, &high, &low, &close);

    if (low < open && low < close)
        withlow = 1;
    if (high > open && high > close)
        withup = 1;
    if (close < open)
        printf("BW-Solid");
    else if (close > open)
        printf("R-Hollow");
    else
        printf("R-Cross");

    if (withup && withlow)
        printf(" with Lower Shadow and Upper Shadow");
    else if (withup)
        printf(" with Upper Shadow");
    else if (withlow)
        printf(" with Lower Shadow");

    return 0;
}