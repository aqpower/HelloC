#include "stdio.h"

int main()
{
    int k, i = 0;
    char attack[20];
    scanf("%d", &k);
    k++;
    while (scanf("%s", attack), attack[0] != 'E')
    {
        i++;
        if (!(i % k))
        {
            printf("%s\n", attack);
        }
        else
        {
            if (attack[0] == 'C')
                printf("Bu\n");
            else if (attack[0] == 'J')
                printf("ChuiZi\n");
            else
                printf("JianDao\n");
        }
    }

    return 0;
}