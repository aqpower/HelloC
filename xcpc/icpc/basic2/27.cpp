#include "stdio.h"
#include "string.h"

int main()
{
    char world[99], num[99];
    int i, j = 0, tar;
    gets(world);
    for (i = 0; world[i] != '\0'; i++)
    {
        if (world[i] >= '0' && world[i] <= '9')
        {
            num[j++] = world[i];
        }
    }
    sscanf(num, "%d", &tar);
    printf("%d\n", tar);

    return 0;
}