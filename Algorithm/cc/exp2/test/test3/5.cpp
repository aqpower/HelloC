#include "stdio.h"
#include "stdlib.h"

int myNnnx(int x, int n);

int main()
{
    int x, n;
    scanf("%d %d", &x, &n);
    printf("%d\n", myNnnx(x, n));
    system("pause");
    return 0;
}

int myNnnx(int x, int n)
{
    if (n == 1)
        return x;
    return x * myNnnx(x, n - 1);
}