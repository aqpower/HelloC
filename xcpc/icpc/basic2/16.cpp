#include "stdio.h"
#include "stdlib.h"
int Yuan(char c);

int main()
{
    char str[99], cnt = 0;
    gets(str);
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (Yuan(str[i]))
            cnt++;
    }
    printf("%d", cnt);
    system("pause");
    return 0;
}

int Yuan(char c)
{
    if (c >= 'a')
        return 0;
    if (c == 'A' || c == 'E' || c == 'I' || c == 'U' || c == 'O')
        return 0;
    if (c > 'A')
        return 1;
    return 0;
}
