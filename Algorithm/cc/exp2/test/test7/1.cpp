#include "stdio.h"

FILE *fp = NULL;

int main()
{
    char world[99] = {0};
    scanf("%s", world);

    fp = fopen(world, "r");

    if (fp == NULL)
    {
        fp = fopen(world, "w");
        printf("The file is not exist.The new file is created successfully.\n");
    }
    else
    {
        printf("The file exists.\n");
    }

    fclose(fp);

    return 0;
}
