#include "stdio.h"

int main()
{
    int t;
    scanf("%d", &t);
    getchar();
    int cnt = t;
    while (cnt--)
    {
        char a[6];
        gets(a);
        int b = 0, c = 0;
        for (int i = 0; i < 6; i++)
        {
            if (i < 3)
                b += a[i] - '0';
            else
                c += a[i] - '0';
        }
        if (b == c)
            printf("You are lucky!\n");
        else
            printf("Wish you good luck.\n");
    }

    return 0;
}