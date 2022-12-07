#include "stdio.h"
#include "string.h"

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    int c = a * b;
    char world[20];
    sprintf(world, "%d", c);
    for (int i = 0, j = strlen(world) - 1; i < j; i--, j++)
    {
        char t = world[i];
        world[i] = world[j];
        world[j] = t;
    }

    puts(world);

    return 0;
}