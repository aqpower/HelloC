#include "stdio.h"

int main()
{
    int i, n, nlet = 0, nblank = 0, ndigit = 0, nother = 0;
    char date;
    scanf("%d", &n);
    getchar();
    for (i = 0; i < n; i++)
    {

        scanf("%c", &date);

        if (date >= 'a' && date <= 'z' || date >= 'A' && date <= 'Z')
            nlet++;
        else if (date == ' ' || date == '\n')
            nblank++;
        else if (date >= '0' && date <= '9')
            ndigit++;
        else
            nother++;
    }
    printf("letter = %d, blank = %d, digit = %d, other = %d\n", nlet, nblank, ndigit, nother);

    return 0;
}