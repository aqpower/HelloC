#include "stdio.h"
#include "stdlib.h"

int main()
{
    int a, b;
    if (scanf("%d%d", &a, &b) == 2)
    {
        printf("%d + %d = %d", a, b, a + b);
    }
    else
    {
        printf("%d %d\n", a, b);
        if (a > 0)
            printf("%d + ? = ?\n", a);
        else if (b > 0)
            printf("? + %d = ?\n", b);
    }
    system("pause");
    return 0;
}
