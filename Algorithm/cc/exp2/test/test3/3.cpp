#include "stdio.h"
#include "stdlib.h"

int myNnn(int a);

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", myNnn(n));

    system("pause");
    return 0;
}

int myNnn(int a)
{
    if (a == 1)
        return 1;
    return a * myNnn(a - 1);
}
