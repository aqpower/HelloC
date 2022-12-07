#include "stdio.h"

int main()
{
    double met, sum = 10;
    int mins;
    scanf("%lf%d", &met, &mins);
    if (met > 3 && met <= 10)
        sum += (met - 3) * 2;
    else if (met > 10)
        sum += 14 + (met - 10) * 3;
    sum += (mins / 5) * 2;
    printf("%.0f", sum);
    return 0;
}