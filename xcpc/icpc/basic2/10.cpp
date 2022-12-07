#include "stdio.h"
#include "string.h"

int main()
{
    char flag = 1, tar, str[99], index;
    scanf("%c\n", &tar);
    gets(str);
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == tar)
        {
            index = i;
            flag = 0;
        }
    }
    if (flag)
        printf("Not Found\n");
    else
    {
        printf("index = %d", index);
    }
    return 0;
}