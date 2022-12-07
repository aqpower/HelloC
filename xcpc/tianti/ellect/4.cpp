#include "stdio.h"
#include "math.h"

double zi(int n);
double mu(int n);

int main()
{
    double t, n;
    scanf("%lf", &n);
    int i;
    double sum = 1;
    for (i = 1;; i++)
    {
        printf("%f %f\n", zi(i), mu(i));
        t = zi(i) / mu(i);
        sum += t;
        if (t < n)
            break;
    }

    printf("%f\n", sum * 2);
    return 0;
}

double zi(int n)
{
    double re = 1;
    for (int i = 1; i <= n; i++)
    {
        re *= i;
    }
    return re;
}

double mu(int n)
{
    double re = 1;
    for (int i = 1; i <= (2 * n + 1); i += 2)
    {
        re *= i;
    }
    return re;
}