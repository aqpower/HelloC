#include "stdio.h"
#include "stdlib.h"

int main()
{
    int i, j, k, m, n, flag = 1;
    char letter;
    scanf("%c%d", &letter, &n);
    for (i = 0; i < n / 2 + 1; i++)
    {
        for (j = n / 2 - i; j > 0; j--)
            printf(" ");
        if (flag)
        {
            printf("%c", letter);
            flag = 0;
        }
        else
        {
            for (k = 1; k <= 2; k++)
            {

                printf("%c", letter + i);
                for (m = 0; m < 2 * i - 1; m++)
                    printf(" ");
            }
        }
        printf("\n");
    }
    for (i = n / 2; i > 0; i--)
    {
        for (j = (n + 1) / 2 - i; j > 0; j--)
            printf(" ");
        if (!(i - 1))
        {
            printf("%c", letter);
        }
        else
        {
            for (k = 1; k <= 2; k++)
            {

                printf("%c", letter + i - 1);
                for (m = 0; m < 2 * (i - 1) - 1; m++)
                    printf(" ");
            }
        }
        printf("\n");
    }
    system("pause");
    return 0;
}
