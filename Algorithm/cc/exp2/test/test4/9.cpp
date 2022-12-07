#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int main()
{
    int i, index = 0;
    char str[200];
    gets(str);
    for (i = 0; str[i + 1] != '\0'; i++)
    {
        if (str[i] != ' ' && str[i + 1] == ' ')
        {
            if(str[i+2]!=' ')
            index++;
        }
    }

    printf("%d\n", index + 1);
    system("pause");
    return 0;
}
