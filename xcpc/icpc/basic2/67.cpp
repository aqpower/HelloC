#include "stdio.h"

int main()
{
    int i, n, date, nA = 0, nB = 0, nC = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &date);
        if (date >= 85)
            nA++;
        else if (date >= 60)
            nB++;
        else
            nC++;
    }
    printf("%d %d %d\n", nA, nB, nC);

    return 0;
}