#include "stdio.h"
#include "stdlib.h"

int main()
{
    int n;
    scanf("%d", &n);
    printf("%s in day %d\n", n % 5 == 0 || n % 5 == 4 ? "Drying" : "Fishing", n);
    system("pause");
    return 0;
}
