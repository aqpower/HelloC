#include "stdio.h"
#include "stdlib.h"

int main()
{
    int a[5];
    for (int i = 0; i < 3; i++)
        scanf("%d", &a[i]);
    printf("%c\n", a[2] == a[1] ? 'A' : a[0] == a[1] ? 'C'
                                                   : 'B');
    system("pause");
    return 0;
}
