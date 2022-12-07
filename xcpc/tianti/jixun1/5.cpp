#include "stdio.h"

int myMax(int a, int b);

int main()
{
    int branch, molecular;
    int a, b, m, n;
    scanf("%d/%d %d/%d", &a, &b, &m, &n);
    branch = b * n;
    molecular = a * n + b * m;
    int max = myMax(branch, molecular);
    branch /= max;
    molecular /= max;
    if (branch == 1)
        printf("%d\n", molecular);
    else
        printf("%d/%d\n", molecular, branch);

    return 0;
}

int myMax(int a, int b)
{
    if (a % b == 0)
        return b;
    return myMax(b, a % b);
}
