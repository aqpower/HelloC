#include "stdio.h"
#include "stdlib.h"

int main()
{
    double a1, a2;
    int n;
    char str;
    scanf("%lf%d %c%lf", &a1, &n, &str, &a2);
    printf("%c %d %.2f %.2f", str, n, a1, a2);
    system("pause");
    return 0;
}
