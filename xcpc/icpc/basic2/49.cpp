#include "stdio.h"

int main()
{
    int year, mon, day;
    scanf("%d-%d-%d", &mon, &day, &year);
    
    printf("%d-%02d-%02d", year, mon, day);

    return 0;
}