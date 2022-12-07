#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int main()
{
    int i, count = 0;
    char str[999];
    gets(str);
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ')
            count++;
    }
    printf("%d\n", count);
    system("pause");
    return 0;
}