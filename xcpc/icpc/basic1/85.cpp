#include "stdio.h"
#include "stdlib.h"

int main()
{
    int t, bla, blb, na = 0, nb = 0, n, i, asay, a, bsay, b;
    scanf("%d%d", &bla, &blb);
    scanf("%d", &n);
    for (i = 0; i <= n; i++)
    {
        scanf("%d%d%d%d", &asay, &a, &bsay, &b);
        t = asay + bsay;
        if (a == t && b == t)
            continue;
        if (a == t)
        {
            bla--;
            na++;
        }
        if (b == t)
        {
            blb--;
            nb++;
        }
        if (bla == -1)
        {
            printf("A\n");
            printf("%d\n", nb);
            break;
        }
        if (blb == -1)
        {
            printf("B\n");
            printf("%d\n", na);
            break;
        }
    }

    system("pause");
    return 0;
}
