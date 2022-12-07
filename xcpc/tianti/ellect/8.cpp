#include "stdio.h"
#include "algorithm"

using namespace std;

int main()
{
    int n, a[3], t, max, min;
    scanf("%d", &n);
    for (int i = 1;; i++)
    {
        a[0] = n / 100;
        a[1] = n / 10 % 10;
        a[2] = n % 10;
        sort(a, a + 3);
        min = a[0] * 100 + a[1] * 10 + a[2] * 1;
        max = a[2] * 100 + a[1] * 10 + a[0] * 1;
        t = max - min;
        printf("%d: %d - %d = %d", i,max, min, t);
        if (t == 495)
            break;
        n = t;
    }

    return 0;
}