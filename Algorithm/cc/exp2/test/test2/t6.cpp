#include "stdlib.h"
#include "stdio.h"

int myMax(int a, int b);

int main()
{
    int a, b, max, min;
    scanf("%d%d", &a, &b);
    max = myMax(a, b);
    min = a * b / max;
    printf("%d %d\n", max, min);
    system("pause");
    return 0;
}

int myMax(int a, int b)
{
    if (a % b == 0)
        return b;
    return myMax(b, a % b);
}
