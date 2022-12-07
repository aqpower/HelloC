#include "stdio.h"
#include "stdlib.h"

int main()
{
    double x;
    scanf("%lf", &x);
    printf("%.2f\n", x <= 15 ? 4 * x / 3 : 2.5 * x - 17.5);
    system("pause");
    return 0;
}
