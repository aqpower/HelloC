#include "stdio.h"

int main()
{
    char world[99];
    gets(world);
    for (int i = 0; world[i] != '\0'; i++)
    {
        if (world[i] >= 'A' && world[i] <= 'Z')
            world[i] += 32;
        else if (world[i] >= 'a' && world[i] <= 'z')
            world[i] -= 32;
        else if (world[i] == '#')
            world[i] = '\0';
    }
    puts(world);
    return 0;
}
