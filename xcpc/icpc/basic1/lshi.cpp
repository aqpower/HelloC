#include "stdio.h"

int main()
{
    int a, b, c, n;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d%d%d", &a, &b, &c);
        if (a == 1)
        {
            if (b == 130 && c == 27)
            {
                printf("wan mei!\n");
            }
            else
            {
                printf("%s %s", b > 130 ? "ni li hai!" : "duo chi yu!", c > 27 ? "shao chi rou!" : "duo chi rou!");
            }
        }
        else
        {
            if (b == 129 && c == 25)
            {
                printf("wan mei!\n");
            }
            else
            {
                printf("%s %s", b > 129 ? "ni li hai!" : "duo chi yu!", c > 25 ? "shao chi rou!" : "duo chi rou!");
            }
        }
    }

    return 0;
}