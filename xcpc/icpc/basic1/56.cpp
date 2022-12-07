#include "stdio.h"
#include "stdlib.h"

int main()
{
    int t, i, a[10];
    for (i = 0; i < 4; i++)
        scanf("%1d", &a[i]);
    for (i = 0; i < 4; i++)
        a[i] = (a[i] + 9) % 10;
    t = a[3];
    a[3] = a[1];
    a[1] = t;
    t = a[2];
    a[2] = a[0];
    a[0] = t;
    printf("The encrypted number is ");
    for (i = 0; i < 4; i++)
        printf("%d", a[i]);
    system("pause");
    return 0;
}
