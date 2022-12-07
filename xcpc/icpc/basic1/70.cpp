#include "stdio.h"
#include "stdlib.h"

void myPrint(int n);

int main()
{
    int line, n;
    scanf("%d", &n);
    for (line = 1; line <= n; line++)
    {
        myPrint(line);
    }

    system("pause");
    return 0;
}

void myPrint(int n)
{
    int i;
    for (i = 1; i <= n; i++)
        printf("%d*%d=%-4d", i, n, i * n);
    printf("\n");
}