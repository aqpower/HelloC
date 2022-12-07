#include "stdio.h"
#include "stdlib.h"

int myMaxyue(int a, int b);

int main()
{
    int m, n, a1, b1, a2, b2;

    scanf("%d/%d %d/%d", &a1, &b1, &a2, &b2);
    m = a1 * b2 + a2 * b1;
    n = b1 * b2;
    int t = myMaxyue(m, n);
    m /= t;
    n /= t;
    if (n == 1)
        printf("%d\n", m);
    else
        printf("%d/%d\n", m, n);

    system("pause");
    return 0;
}

int myMaxyue(int a, int b)
{
    if (a % b == 0)
        return b;
    return myMaxyue(b, a % b);
}