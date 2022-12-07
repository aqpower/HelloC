#include <cmath>
#include <iostream>
using namespace std;
const double eps = 1e-5;
double f(double a)
{
    return a * a;
}
int main()
{
    double left = 1, right = 2, mid;
    while (right - left > eps)
    {
        mid = (right + left) / 2;
        if (f(mid) > 2)
            right = mid;
        else
            left = mid;
    }

    cout << mid;

    return 0;
}