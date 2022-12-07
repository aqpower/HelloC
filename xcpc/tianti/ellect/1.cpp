#include "stdio.h"

int main()
{
    double a, b;
    int in;
    char c;
    scanf("%lf %d %c %lf",&a,&in,&c,&b);
    printf("%c %d %f %f\n", c, in, a, b);

    return 0;
}