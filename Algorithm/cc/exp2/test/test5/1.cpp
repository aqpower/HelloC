#include "stdio.h"

void my_power(double x, int y, double *mypow)
{
    while (y--)
        (*mypow) *= x;
}

int main()
{
    double x;
    int y;
    
    double pow = 1;
    double *ppow = &pow;
    
    scanf("%lf%d", &x, &y);
    
    my_power(x, y, ppow);
    
    printf("%lf\n", pow);

    return 0;
}
