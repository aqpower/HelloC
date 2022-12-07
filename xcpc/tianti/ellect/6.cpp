#include "stdio.h"

int main()
{
    char world[999];
    int sum = 0, flag;
    gets(world);
    for (int i = 0; world[i] != '\0'; i++)
    {
        if (world[i] == '.')
        {
            if (sum)
                printf("%d", sum);
        }
        if (world[i] == ' ')
        {
            flag = 0;
            if (sum)
                printf("%d ", sum);
            sum = 0;
        }
        else
        {
            flag = 1;
        }
        if (flag)
            sum++;
    }

    return 0;
}