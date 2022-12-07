#include "stdio.h"

int main()
{
    int jia, yi, n, a1, a2, b1, b2;
    int ta = 0, tb = 0;
    scanf("%d%d", &jia, &yi);
    scanf("%d", &n);
    while (n--)
    {
        int fa = 0, fb = 0;
        scanf("%d%d%d%d", &a1, &a2, &b1, &b2);
        if (a2 == a1 + b1)
        {
            fa = 1;
        }
        if (b2 == a1 + b1)
        {
            fb = 1;
        }
        if (fa == fb)
        {
            continue;
        }
        if (fa)
        {
            ta++;
            jia--;
        }
        else
        {
            tb++;
            yi--;
        }

        if (jia < 0 || yi < 0)
        {
            break;
        }
        fa = 0, fb = 0;
    }
    if (jia < 0)
        printf("A\n%d", tb);
    else
        printf("B\n%d", ta);

    return 0;
}