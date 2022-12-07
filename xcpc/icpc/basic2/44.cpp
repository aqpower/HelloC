#include "stdio.h"

int main()
{
    int h, m, time;
    scanf("%d:%d", &h, &m);
    if (h <= 12)
    {
        printf("Only %02d:%02d.  Too early to Dang.", h, m);
    }
    else
    {
        if (m > 0)
            h++;
        while (h - 12)
        {
            h--;
            printf("Dang");
        }
    }
    return 0;
}