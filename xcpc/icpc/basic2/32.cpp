#include "stdio.h"
#include "string.h"

int main()
{
    char world[999][99];
    int i, n;
    scanf("%d", &n);
    getchar();
    for (i = 0; i < n; i++)
    {
        gets(world[i]);
    }
    char min[99];
    strcpy(min, world[0]);
    for (i = 0; i < n; i++)
    {
        if (strcmp(world[i], min) < 0)
            strcpy(min, world[i]);
    }
    printf("Min is: ");
    for (i = 0; min[i] != '\0'; i++)
        printf("%c", min[i]);
    return 0;
}