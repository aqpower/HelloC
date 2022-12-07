#include "stdio.h"
#include "stdlib.h"

int main()
{
    char str[20];
    int nletter = 0, nblack = 0, ndight = 0, nother = 0;
    for (int i = 0; i < 10; i++)
        scanf("%c", &str[i]);
    for (int i = 0; i < 10; i++)
    {
        if (str[i] == 10 || str[i] == 32)
            nblack++;
        else if ('A' <= str[i] && str[i] <= 'Z' || 'a' <= str[i] && str[i] <= 'z')
            nletter++;
        else if (str[i] >= 48 && str[i] <= 57)
            ndight++;
        else
            nother++;
    }
    printf("letter = %d, blank = %d, digit = %d, other = %d\n", nletter, nblack, ndight, nother);
    system("pause");
    return 0;
}
