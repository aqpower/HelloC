#include "stdio.h"
#include "stdlib.h"

int main()
{
    int i, a[999], sum = 0;
    for (i = 0;; i++)
    {
        scanf("%d", &a[i]);
        if (a[i] <= 0)
            break;
    }
    for (int j = 0; j < i; j++)
    {
        if (a[j] & 1)
            sum += a[j];
    }
    printf("%d\n", sum);
    system("pause");
    return 0;
}
