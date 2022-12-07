#include "stdio.h"

int main()
{
    char world[999];
    gets(world);

    int fword = 1, first = 1;

    for (int i = 0; world[i] != '\n'; i++)
    {
        if (world[i] != ' ')
        {
            if (fword)
            {
                if (first)
                {
                    if (world[i] >= 'a' && world[i] <= 'z')
                        world[i] -= 32;
                    first = 0;
                }
            }
        }
        else
        {
            first = 1;
            fword = 1;
        }
    }

    puts(world);

    return 0;
}