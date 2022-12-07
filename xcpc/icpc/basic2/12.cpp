#include "stdio.h"
#include "stdlib.h"

int main()
{
    int i = 0, flag = 1, k = 1;
    char t, str[99];
    long int n;
    while (scanf("%c", &t) && t != '#')
    {
        if (t >= '0' && t <= '9' || t >= 'a' && t <= 'f' || t >= 'A' && t <= 'F')
        {
            str[i++] = t;
            flag = 0;
        }
        if (flag)
        {
            if (t == '-')
                k = -1;
        }
    }
    sscanf(str, "%x", &n);
    printf("%d\n", n * k);

    system("pause");
    return 0;
}