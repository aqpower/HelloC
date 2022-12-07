#include "stdio.h"
#include "math.h"

int main()
{
    double h, w;
    scanf("%lf%lf", &w, &h);
    double a = w / pow(h, 2);
    printf("%.1f\n", a);
    printf("%s\n", a > 25 ? "PANG" : "Hai Xing");

    return 0;
}