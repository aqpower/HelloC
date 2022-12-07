#include "stdio.h"
#include "string.h"

int main()
{
    char a[5][80];
    for (int i = 0; i < 5; i++)
        scanf("%s", a[i]);
    for (int i = 0; i < 4; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            if (strcmp(a[i], a[j]) > 0)
            {
                char t[80];
                strcpy(t, a[i]);
                strcpy(a[i], a[j]);
                strcpy(a[j], t);
            }
        }
    }
    printf("After sorted:\n");
    for (int i = 0; i < 5; i++)
        puts(a[i]);

    return 0;
}