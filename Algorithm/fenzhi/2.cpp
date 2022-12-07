#include "stdio.h"
#include "math.h"

void myGen(double a, double b);
int myLenth(double a, double b);
void myPut(double gen);

double m, n, c, d, a, b;

int main()
{

    scanf("%lf%lf%lf%lf", &m, &n, &c, &d);
    scanf("%lf%lf", &a, &b);

    myGen(a, b);

    return 0;
}

int myLenth(double a, double b)
{
    if (b - a < 0.001)
        return 0;
    return 1;
}

void myGen(double a, double b)
{
    double x = (a + b) / 2;
    if (myLenth(a, b))
    {

        double fx = m * pow(x, 3) + n * pow(x, 2) + c * x + d;
        if (fx == 0)
        {
            myPut(x);
        }
        double fa = m * pow(a, 3) + n * pow(a, 2) + c * a + d;
        double fb = m * pow(b, 3) + n * pow(b, 2) + c * b + d;
        if (fa * fx > 0)
            myGen(x, b);
        else
            myGen(a, x);
    }
    else
    {
        myPut(x);
    }
}

void myPut(double gen)
{
    printf("%.2f\n", gen);
}