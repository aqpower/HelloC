#include "stdio.h"
#include "stdlib.h"

int main()
{
    int a, b, c, max, mid, min;
    scanf("%d%d%d", &a, &b, &c);
    max = a > b && a > c ? a : b > c ? b
                                     : c;

    min = a < b && a < c ? a : b < c ? b
                                     : c;
    mid = a < max && a > min ? a : b < max && b > min ? b
                                                      : c;
    printf("%d->%d->%d\n", min, mid, max);

    system("pause");
    return 0;
}
