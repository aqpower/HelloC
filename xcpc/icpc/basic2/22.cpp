#include "stdio.h"

double myNnn(int n);
double myM(int n);

int main()
{
    double pi = 1, eps, t;
    scanf("%le", &eps);
    for (int i = 1;; i++)
    {
        t = myNnn(i) / myM(i);
        pi += t;
        if (t < eps)
            break;
    }
    printf("PI = %.5f", pi * 2);

    return 0;
}

double myNnn(int n)
{
    double sum = 1;
    for (int i = 1; i <= n; i++)
        sum *= i;

    return sum;
}

double myM(int n)
{
    double sum = 1;
    for (int i = 1; i <= 2 * n + 1; i += 2)
    {
        sum *= i;
    }

    return sum;
}
