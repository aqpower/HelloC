#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int main()
{
    char str[20][20];
    int i = 1;
    while (gets(str[i]))
    {
        if (!strcmp(str[i], "."))
            break;
        i++;
    }
    if (i <= 2)
        printf("Momo... No one is for you ...\n");
    else if (i - 1 <= 13)
        printf("%s is the only one for you...\n", str[2]);
    else
        printf("%s and %s are inviting you to dinner...\n", str[2], str[14]);
    system("pause");
    return 0;
}
