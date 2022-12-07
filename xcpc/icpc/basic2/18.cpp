#include "stdio.h"
#include "stdlib.h"

int main()
{

    int n, hour, min, sec;
    scanf("%d:%d:%d", &hour, &min, &sec);
    scanf("%d", &n);
    sec += n;
    if (sec >= 60)
    {
        sec = sec - 60;
        min++;
        if (min == 60)
        {
            min = min - 60;
            hour++;
            if (hour == 24)
                hour = 0;
        }
    }
    printf("%02d:%02d:%02d", hour, min, sec);
 system("pause");
    return 0;
}