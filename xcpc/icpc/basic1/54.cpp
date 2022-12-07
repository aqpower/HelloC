#include "stdio.h"
#include "stdlib.h"
#include "string.h"
int main()
{
    char str[20];
    gets(str);
    for (int i = 0; i < strlen(str); i++)
        printf("%c ", str[i]);

    system("pause");
    return 0;
}
