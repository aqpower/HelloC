#include "stdio.h"
#include "stdlib.h"

int main()
{
    int n, i, j, k, count = 0;
    scanf("%d", &n);
    for (i = 1; i < 30; i++)
    {
        for (j = 1; j < 75; j++)
        {
            for (k = 1; k < 150; k++)
            {
                if (i * 5 + j * 2 + k == 150 && i + k + j == 100)
                {
                    printf("%d %d %d\n", i, j, k);
                    count++;
                    if (count == n)
                    {
                        system("pause");
                        return 0;
                    }
                }
            }
        }
    }
    system("pause");
    return 0;
}