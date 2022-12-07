#include "stdio.h"
#include "stdlib.h"

int main()
{
    int n, y, f, flag = 1;
    // scanf("%d", &n);
    for (n = 1; n <= 99; n++)
    {
        printf("%d\n",n);
        for (f = 1; f <= 99; f++)
        {
            for (y = 1; y <= 99; y++)
            {
                if (f * 100 + y - n == 2 * y * 100 + 2 * f)
                {
                    printf("%d.%02d\n", y, f);
                    flag = 0;
                }
            }
        }
        if (flag)
            printf("No Solution\n");
        flag = 1;
    }

    system("pause");
    return 0;
}
