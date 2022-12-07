#include "stdio.h"
#include "stdlib.h"

int myFff(int n);

int fibo[99];

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", myFff(n));

    system("pause");
    return 0;
}

int myFff(int a)
{
    if (a == 1)
        return 1;
    if (a == 2)
        return 1;
    return myFff(a - 2) + myFff(a - 1);
}
