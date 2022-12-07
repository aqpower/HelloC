#include "stdio.h"
#include "stdlib.h"

void move(char a, char b)
{
    printf("%c>--%c\n", a, b);
    return;
}

void monitor(int n, char a, char b, char c)
{
    if (n == 1)
    {
        move(a, c);
        return;
    }
    move(a, b);
    return monitor(n - 1, a, b, c);
}

int main()
{
    int n;
    char a, b, c;
    scanf("%d%c%c%c", &n, &a, &b, &c);
    monitor(n, a, b, c);
    printf("\n");
    system("pause");
    return 0;
}
