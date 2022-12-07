#include "stdio.h"
#include "stdlib.h"

int main()
{
    int day;
    scanf("%d", &day);
    printf("%d\n", day > 5 ? day % 5 : day + 2);
    system("pause");
    return 0;
}
