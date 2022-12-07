#include "stdio.h"
#include "math.h"
#include "string.h"

int main()
{
    char pingyin[15][15] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    int i = 0, t, n;
    int world[12];
    scanf("%d", &n);
    if (n < 0)
        printf("fu ");
    n = fabs(n);

    do
    {
        world[i++] = n % 10;
        n /= 10;
    } while (n);
    for (int j = 0, k = i - 1; j < k; j++, k--)
    {
        t = world[j];
        world[j] = world[k];
        world[k] = t;
    }
    for (int j = 0; j < i; j++)
    {
        for (int k = 0; pingyin[world[j]][k] != '\0'; k++)
        {
            printf("%c", pingyin[world[j]][k]);
        }
        if (j != i - 1)
            printf(" ");
    }
    return 0;
}