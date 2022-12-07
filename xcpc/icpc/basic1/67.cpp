#include "stdio.h"
#include "stdlib.h"

int main()
{
    int count = 0, i, n, a, b, c, site = 0;
    scanf("%d", &n);
    for (i = n * 100 + (n + 1) * 10 + n + 2; i < 999; i++)
    {
        a = i / 100;
        b = i / 10 % 10;
        c = i % 10;
        if ((a != b) && (b != c) && (a != c))
        {

            if (a == n || a == n + 1 || a == n + 2 || a == n + 3)
                count++;
            if (b == n || b == n + 1 || b == n + 2 || b == n + 3)
                count++;
            if (c == n || c == n + 1 || c == n + 2 || c == n + 3)
                count++;
            if (count == 3)
            {
                site++;
                if (site <= 5)
                    printf("%d ", i);
                else
                {
                    site = 0;
                    printf("%d\n", i);
                }
            }
            count = 0;
        }
    }

    system("pause");
    return 0;
}