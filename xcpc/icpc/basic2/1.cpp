#include "stdio.h"
#include "stdlib.h"

int main()
{
    int n;
    scanf("%d", &n);
    printf("Celsius = %.d\n", 5 * (n - 32) / 9);
    system("pause");
    return 0;
}
