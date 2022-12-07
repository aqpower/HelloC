#include "stdio.h"
#include "stdlib.h"

int main()
{
    int i, count = 0;
    for (i = 101; i <= 991; i += 10)
    {
        if (i % 7 == 0)
        {
            printf("%d ", i);
            count++;
        }
    }
    printf("\n");
    printf("%d\n", count);
    system("pause");
    return 0;
}
