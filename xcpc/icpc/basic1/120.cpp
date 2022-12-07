#include "stdio.h"

int main()
{
    int n, sex, h, w;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d%d%d", &sex, &h, &w);
        if (sex)
        {
            if (h > 130)
                printf("ni li hai! ");
            else if (h == 130)
                printf("wan mei! ");
            else
                printf("duo chi yu! ");
            if (w > 27)
                printf("shao chi rou!\n");
            else if (w == 27)
                printf("wan mei!\n");
            else
                printf("duo chi rou!\n");
        }
        else
        {
            if (h > 129)
                printf("ni li hai! ");
            else if (h == 129)
                printf("wan mei! ");
            else
                printf("duo chi yu! ");
            if (w > 25)
                printf("shao chi rou!\n");
            else if (w == 25)
                printf("wan mei!\n");
            else
                printf("duo chi rou!\n");
        }
    }

    return 0;
}