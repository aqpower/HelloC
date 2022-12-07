#include "stdio.h"
#include "string.h"

int main()
{
    char str[99];
    gets(str);
    int i, j;
    for (i = 0, j = strlen(str) - 1; i <= j; i++, j--)
    {
        char t = str[i];
        str[i] = str[j];
        str[j] = t;
    }
    puts(str);

    return 0;
}