#include "stdio.h"
#include "stdlib.h"

int main()
{
    int low, up;
    scanf("%d%d", &low, &up);
    if (up >= low && up <= 100)
    {
        printf("fahr celsius\n");
        while (low <= up)
        {
            printf("%d%6.1f\n", low, 5.0 * (low - 32) / 9);
            low += 2;
        }
    }
    else
    {
        printf("Invalid.");
    }

    system("pause");
    return 0;
}
