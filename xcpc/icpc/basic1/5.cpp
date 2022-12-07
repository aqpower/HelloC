#include "stdio.h"
#include "stdlib.h"

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d + %d = %d\n", a, b, a + b);
    printf("%d - %d = %d\n", a, b, a - b);
    printf("%d * %d = %d\n", a, b, a * b);
    printf("%d / %d = %d\n", a, b, a / b);

    system("pause");
    return 0;
}
