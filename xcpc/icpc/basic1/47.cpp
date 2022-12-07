#include "stdio.h"
#include "stdlib.h"
#include "math.h"

int main()
{
    double money, year, rate;
    scanf("%lf%lf%lf", &money, &year, &rate);
    printf("interest = %.2f\n", money * pow(1 + rate, year) - money);

    system("pause");
    return 0;
}