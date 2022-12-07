#include "stdio.h"

int main()
{
    int i, k = 0, year, mon, day, sum;
    scanf("%d/%d/%d", &year, &mon, &day);
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
        k = 1;
    int years[20] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (i = 1; i < mon; i++)
        sum += *(years + i);
    if (mon > 2)
        sum += k;
    sum += day;
    printf("%d", sum);

    return 0;
}
