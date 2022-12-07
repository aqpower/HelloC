#include "stdio.h"
#include "stdlib.h"

int main()
{
    double cost, price;
    scanf("%lf", &cost);
    if (cost >= 0)
    {
        if (cost > 50)
            printf("cost = %.2f", 50 * 0.53 + (cost - 50) * 0.58);
        else
            printf("cost = %.2f", cost * 0.53);
    }
    else
    {
        printf("Invalid Value!");
    }
    system("pause");
    return 0;
}