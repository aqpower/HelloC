#include "stdio.h"
#include "stdlib.h"

int mySusu(int n);

int main()
{
    int n;
    scanf("%d", &n);
    if (mySusu(n))
        printf("Yes\n");
    else
        printf("No\n");

    system("pause");
    return 0;
}

int mySusu(int n)
{
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}