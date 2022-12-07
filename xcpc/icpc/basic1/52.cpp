#include "stdio.h"
#include "stdlib.h"

int main()
{
    double a;
    int b;
    char c;
    scanf("%lf%d %c", &a, &b, &c);
    printf("%.2f\n", a * (b == 90 ? 6.95 : b == 93 ? 7.44
                                                 : 7.93) 
                     * (c == 'm' ? 0.95 : 0.97));

    system("pause");
    return 0;
}
