#include "stdio.h"
#include "stdlib.h"

int myMin(int a, int b);
int myMax(int a, int b);

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d %d\n", myMax(a, b), myMin(a, b));

    system("pause");
    return 0;
}

int myMin(int a, int b)
{
    return a * b / myMax(a, b);
}

int myMax(int a, int b)
{
    if (a % b == 0)
        return b;
    else
        return myMax(b, a % b);
}
