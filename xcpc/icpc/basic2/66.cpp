#include "stdio.h"
#include "math.h"

int Judge(int n);

int main()
{
    int i, a, b;
    scanf("%d%d", &a, &b);
    if (a > b || Judge(a) != 3 || Judge(b) != 3)
        printf("Invalid Value.\n");
    else
    {
        for (i = a; i <= b; i++)
        {
            if (pow(i / 100, 3) + pow(i / 10 % 10, 3) + pow(i % 10, 3) == i)
                printf("%d\n", i);
        }
    }

    return 0;
}

int Judge(int n)
{
    int k = 1;
    while (n / 10)
    {
        k++;
        n /= 10;
    }
    return k;
}