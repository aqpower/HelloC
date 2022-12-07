#include "stdio.h"
#include "stdlib.h"

int main()
{
    int hour, min;
    scanf("%d:%d", &hour, &min);

    printf("%d:%d %s\n", hour > 12 ? hour - 12 : hour, min, hour >= 12 ? "PM" : "AM");
    system("pause");
    return 0;
}
