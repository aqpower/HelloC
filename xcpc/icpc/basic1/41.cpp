#include "stdio.h"
#include "stdlib.h"

int main()
{
    int x = 3, y;
    y = x * x;

    printf("%d = %d * %d\n\
%d * %d = %d\n",
           y, x, x, x, x, y);
    system("pause");
    return 0;
}