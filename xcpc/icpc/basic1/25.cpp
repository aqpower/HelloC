#include "stdio.h"
#include "stdlib.h"
#include "math.h"

int main()
{
    double x1, y1, x2, y2, x3, y3, perm, squ;
    double l1, l2, l3;
    scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3);
    
    l1 = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    l2 = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));
    l3 = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
    
    if (l1 + l2 > l3 && l1 + l3 > l2 && l2 + l3 > l1)
    {
        double p = 1.0 * (l1 + l2 + l3) / 2;
        printf("L = %.2f, A = %.2f\n", 2 * p, sqrt(p * (p - l1) * (p - l2) * (p - l3)));
    }
    else
    {

        printf("Impossible\n");
    }

    system("pause");
    return 0;
}
