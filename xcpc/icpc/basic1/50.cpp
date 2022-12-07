#include "stdio.h"
#include "stdlib.h"
#include "math.h"

int main()
{
    double perm, squ;
    int l1, l2, l3;
    scanf("%d%d%d", &l1, &l2, &l3);

    if (l1 + l2 > l3 && l1 + l3 > l2 && l2 + l3 > l1)
    {
        double p = 1.0 * (l1 + l2 + l3) / 2;
        printf("area = %.2f; perimeter = %.2f\n", sqrt(p * (p - l1) * (p - l2) * (p - l3)), 2 * p);
    }
    else
    {

        printf("These sides do not correspond to a valid triangle\n");
    }

    system("pause");
    return 0;
}
