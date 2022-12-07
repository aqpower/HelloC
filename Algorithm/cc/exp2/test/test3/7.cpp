#include "stdio.h"
#include "stdlib.h"

int mySusu(int n);

int main()
{
    int i, count = 0;
    for (i = 2; i <= 998; i++)
    {
        if (mySusu(i) && mySusu(i + 2))
            
            count++;
    }
    printf("%d\n", count);

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
