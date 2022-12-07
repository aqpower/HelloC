#include "stdio.h"
#include "stdlib.h"
#include "math.h"

int main()
{
    int n, mon = 0, time[999] = {1, 1};
    scanf("%d", &n);
    for (int i = 2; i < 40; i++)
    {
        time[i] = time[i - 1] + time[i - 2];
    }
    while (time[mon] < n)
        mon++;
    printf("%d\n", mon + 1);
    system("pause");
    return 0;
}
