#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int main()
{
    char str[10][10] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    int repeat, i, flag = 1;
    char strgo[15];
    scanf("%d", &repeat);
    getchar();
    while (repeat--)
    {
        gets(strgo);
        for (i = 0; i < 7; i++)
        {

            if (!strcmp(strgo, str[i]))
            {
                flag = 0;
                printf("%d\n", i + 1);
                break;
            }
        }
        if (flag)
            printf("-1\n");
        flag = 1;
    }
    system("pause");
    return 0;
}