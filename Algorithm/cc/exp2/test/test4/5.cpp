#include "stdio.h"
#include "stdlib.h"

int main()
{
    int t, a[99] = {3, 4, 2, 5, 6, 23, 45, 67, 67, 45};
    for (int i = 0; i < 9; i++)
    {
        for (int j = i; j < 10; j++)
        {
            if (a[i] > a[j])
            {
                t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
    for (int i = 0; i < 10; i++)
        printf("%d\t", a[i]);
    system("pause");
    return 0;
}
