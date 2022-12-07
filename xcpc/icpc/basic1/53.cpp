#include "stdio.h"
#include "stdlib.h"

int main()
{
    int i;
    for (i = 1;; i++)
    {
        if (i % 5 == 1 && i % 6 == 5 && i % 7 == 4 && i % 11 == 10)
            break;
    }
    printf("%d\n", i);
    system("pause");
    return 0;
}
