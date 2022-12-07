#include "stdio.h"
#include "stdlib.h"
int main()
{
    int i, counter = 0;
    for (i = 101; i <= 991; i = i + 10)
    {
        if (i % 7 != 0)
        {
            continue;
        }
        else
        {
            printf("%d\n", i);
            counter++;
        }
    }
    printf("%d\n", counter);
    system("pause");
    return 0;
}