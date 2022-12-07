#include "stdio.h"

int main()
{
    char world[99], letter[99] = {0};
    gets(world);
    int i, j = 0, k, flag = 0, first = 1;
    for (i = 0; world[i] != '\0'; i++)
    {
        if (world[i] >= 'A' && world[i] <= 'Z')
        {
            for (k = 0; letter[k] != '\0'; k++)
            {
                if (letter[k] == world[i])
                {
                    first = 0;
                    break;
                }
            }
            if (first)
            {
                letter[j++] = world[i];
                flag++;
            }
            first = 1;
        }
    }
    if (flag)
        puts(letter);
    else
        printf("Not Found\n");
    return 0;
}