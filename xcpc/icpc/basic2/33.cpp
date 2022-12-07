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
    char max[99];
    strcpy(max, world[0]);
    for (i = 0; i < n; i++)
    {
        if (strlen(world[i]) > strlen(max))
            strcpy(max, world[i]);
    }
    printf("The longest is: ");
    for (i = 0; max[i] != '\0'; i++)
        printf("%c", max[i]);
    return 0;
}