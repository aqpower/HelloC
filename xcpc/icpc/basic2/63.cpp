#include "stdio.h"
#include "math.h"

int main()
{
    int n, k = 1;
    scanf("%d", &n);

    int rec = n;

    while (n / 10)
    {
        k++;
        n /= 10;
    }
    if (k != 3)
        printf("Invalid Value.\n");
    else
    {
        int a = rec / 100, b = rec / 10 % 10, c = rec % 10;

        printf("%s\n", pow(a, 3) + pow(b, 3) + pow(c, 3) == rec ? "Yes" : "No");
    }

    return 0;
}