#include "stdio.h"
#include "stdlib.h"
#include "math.h"

int main()
{
    double x;
    scanf("%lf", &x);
    printf("f(%.2f) = %.2f", x, x >= 0 ? sqrt(x) : pow(x + 1, 2) + 2 * x + 1 / x);

    system("pause");
    return 0;
}
