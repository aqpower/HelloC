#include "stdio.h"

int main()
{
    char day;
    int i = 0, time[999], j = 0, flag = 0, len = 0;
    while (scanf("%c", &day))
    {

        if (day == '.')
        {
            time[j] = len;
            break;
        }
        if (day != ' ')
        {
            len++;
            flag = 1;
        }
        if (flag)
        {
            if (day == ' ')
            {
                flag = 0;
                time[j++] = len;
                len = 0;
            }
        }
    }
    for (i = 0; i <= j; i++)
    {
        if (i == j)
            printf("%d", time[i]);
        else
            printf("%d ", time[i]);
    }

    return 0;
}


