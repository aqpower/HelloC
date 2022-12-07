#include "stdio.h"

int main()
{
    int a1, b1, a2, b2;
    scanf("%d/%d %d/%d", &a1, &b1, &a2, &b2);
    
    int t1 = a1 * b2, t2 = a2 * b1;
    
    printf("%d/%d %c %d/%d\n", a1, b1, t1 == t2 ? '=' : t1 > t2 ? '>'
                                                                : '<',
           a2, b2);
    return 0;
}