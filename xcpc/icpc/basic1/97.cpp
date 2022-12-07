#include "stdio.h"
#include "stdlib.h"

int dn;

int myYear(int n);

int main()
{
    int count = 0, year, i;
    scanf("%d%d", &year, &dn);
    for (i = year;; i++)
    {
        if (myYear(i))
            break;
    }
    printf("%d %04d\n", i - year, i);

    system("pause");
    return 0;
}

int myYear(int n)
{
    int i, j, ndiffer, nsame = 0;
    int a[5];
    a[0] = n / 1000;
    a[1] = n / 100 % 10;
    a[2] = n / 10 % 10;
    a[3] = n % 10;
    for (i = 0; i <= 2; i++)
    {
        for (j = i + 1; j <= 3; j++)
            if (a[i] == a[j])
                nsame++;
    }
    ndiffer = nsame == 2 || nsame == 3 ? 2 : nsame == 0 ? 4
                                                        : 3;
    if (ndiffer == dn)
        return 1;
    return 0;
}
