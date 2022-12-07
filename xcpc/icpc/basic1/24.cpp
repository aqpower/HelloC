#include "stdio.h"
#include "stdlib.h"

int main()
{
    int i, n, score[1000];
    int nA = 0, nB = 0, nC = 0, nD = 0, nE = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &score[i]);
    for (i = 0; i < n; i++)
    {
        if (score[i] >= 90)
            nA++;
        else if (score[i] >= 80)
            nB++;
        else if (score[i] >= 70)
            nC++;
        else if (score[i] >= 60)
            nD++;
        else
            nE++;
    }
    printf("%d %d %d %d %d\n", nA, nB, nC, nD, nE);

    system("pause");
    return 0;
}
