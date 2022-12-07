#include "stdio.h"

int myStrcmp(char *a, char *b);

int main()
{
    char s1[99], s2[99];
    gets(s1);
    gets(s2);
    int k = myStrcmp(s1, s2);
    printf("%d\n", k);
    return 0;
}

int myStrcmp(char *a, char *b)
{
    for (int i = 0; *(a + i) != '\0'; i++)
    {
        if (*(a + i) != *(b + i))
            return *(a + i) - *(b + i);
    }
}
