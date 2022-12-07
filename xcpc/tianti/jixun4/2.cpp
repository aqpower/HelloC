#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n, x, y, z;
    cin >> n;
    while (n--)
    {
        cin >> x >> y >> z;
        if (pow(x, 2) + pow(y, 2) + pow(z, 2) == 3 * x * y * z)
        {
            puts("Yes");
        }
        else
        {
            puts("No");
        }
    }
    return 0;
}