#include "stdio.h"
#include "string.h"

int main()
{
    char world[99];
    gets(world);
    for (int i = 0, j = strlen(world) - 1; i <= j; i++, j--)
    {
        char t = world[i];
        world[i] = world[j];
        world[j] = t;
    }
    int rev;
    sscanf(world, "%d", &rev);
    printf("%d\n", rev);
    return 0;
}