#include "stdio.h"
#include "math.h"

int main()
{
    int i, n, date[10005], sum = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &date[i]);
        sum += date[i];
    }
    double avg = 1.0 * sum / n;
    double var = 0;
    for (i = 0; i < n; i++)
    {
        var += pow(date[i] - avg, 2);
    }
    printf("%.5f", sqrt(var / n));

    return 0;
}