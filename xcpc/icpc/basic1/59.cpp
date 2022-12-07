#include "stdio.h"
#include "stdlib.h"

int main()
{
    int v;
    scanf("%d", &v);
    printf("Speed: %d - %s", v, v > 60 ? "Speeding" : "OK");
    system("pause");
    return 0;
}
