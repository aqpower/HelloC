#include "stdio.h"

int main()
{
    char world[10005];
    gets(world);
    int len = 0;
    for (int i = 0; world[i] != '\0'; i++)
    {
        if (world[i] != ' ')
        {
            len++;
            if (world[i + 1] == '\0')
            {
                printf("%d ", len);
            }
        }
        else
        {
            if (len)
            {
                printf("%d ", len);
                len = 0;
            }
        }
    }
    printf("\n");

    return 0;
}
