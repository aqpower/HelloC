#include "stdio.h"
#include "stdlib.h"

int main()
{
    double rate, earn;
    scanf("%lf", &earn);
    rate = earn > 4500 ? 0.2 : earn > 3500 ? 0.15
                           : earn > 2500   ? 0.1
                           : earn > 1600   ? 0.05
                                           : 0;
    printf("%.2f\n", earn > 1600 ? rate * (earn - 1600) : 0);
    system("pause");
    return 0;
}