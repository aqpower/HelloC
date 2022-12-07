#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int main()
{
    char str[120][120];
    int i, j, n;
    scanf("%d", &n);
    getchar();
    for (i = 0; i < n; i++)
        gets(str[i]);
    for (i = 0; i < n - 1; i++)
    {
        for (j = i; j < n; j++)
        {
            if (strcmp(str[i], str[j]) > 0)
            {
                char temp[20];
                strcpy(temp, str[i]);
                strcpy(str[i], str[j]);
                strcpy(str[j], temp);
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        puts(str[i]);
    }
    system("pause");
    return 0;
}