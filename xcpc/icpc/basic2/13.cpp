#include "stdio.h"

int main()
{
    int flag = 1, cnt = 0;
    char str[999];
    gets(str);
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != ' ')
        {
            if (flag)
                cnt++;
            flag = 0;
        }
        else
        {
            flag = 1;
        }
    }
    printf("%d\n", cnt);
    return 0;
}
