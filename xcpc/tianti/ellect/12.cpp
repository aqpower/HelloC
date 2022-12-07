#include "stdio.h"

int main()
{

    int dn = 0, n, a[5];
    scanf("%d", &n);
    while (n % 16)
    {
        int t = n % 16;
        a[dn++] = t;
        n /= 16;
    }

    for (int i = dn - 1; i >= 0; i--)
        printf("%d", a[i]);

    return 0;
}