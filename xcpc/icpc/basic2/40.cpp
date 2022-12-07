#include "stdio.h"

int myMax(int a, int b)
{
    if (a % b == 0)
        return b;
    return myMax(b, a % b);
}

int main()
{
    int a, b;
    scanf("%d/%d", &a, &b);
    int t = myMax(a, b);
    printf("%d/%d\n", a / t, b / t);

    return 0;
}
