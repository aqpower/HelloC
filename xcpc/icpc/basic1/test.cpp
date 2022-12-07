#include "stdio.h"
#include "stdlib.h"

int main()
{
    char str;
    while (scanf("%c", &str) != EOF)
        printf("%d\n", str);
    system("pause");
    return 0;
}
