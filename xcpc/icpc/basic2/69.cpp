#include "stdio.h"

int main()
{
    int i, n, nblank = 0, ndigit = 0, nother = 0;
    char date[999];
    gets(date);
    for (i = 0; date[i] != '\0'; i++)
    {

        if (date[i] == ' ' || date[i] == '\n')
            nblank++;
        else if (date[i] >= '0' && date[i] <= '9')
            ndigit++;
        else
            nother++;
    }
    printf("blank = %d, digit = %d, other = %d\n", nblank, ndigit, nother);

    return 0;
}