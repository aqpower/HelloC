#include "stdio.h"
#include "stdlib.h"

int main()
{
    int n, t, simp = 0, coup = 0;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &t);
        if (t % 2 == 0)
            coup++;
        else
            simp++;
    }
    printf("%d %d\n", simp, coup);
    system("pause");
    return 0;
}
