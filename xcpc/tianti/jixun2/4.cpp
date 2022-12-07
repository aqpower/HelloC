#include "stdio.h"

int main()
{
    int flag = 0, year, month, day, sum = 0;
    int dic[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    scanf("%d/%d/%d", &year, &month, &day);
    for (int i = 0; i < month - 1; i++)
        sum += dic[i];
    if (month > 2)
    {
        if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0)
        {
            flag = 1;
        }
    }
    sum += day + flag;
    printf("%d\n", sum);

    return 0;
}