#include "stdio.h"

int main()
{
    char world[1005];
    gets(world);
    int flag = 0, sum = 0;
    for (int i = 0; world[i] != '\0'; i++)
    {
        if (world[i] == ' ' || world[i] == '.')
        {
            if (flag)
            {
                sum++;
                flag = 0;
            }
        }
        else
        {
            flag = 1;
        }
    }
    printf("%d", sum);

    return 0;
}