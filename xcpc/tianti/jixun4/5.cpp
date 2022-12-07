#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int m, n;
    cin >> m >> n;
    if (m >= 100 && n >= m && n <= 999)
    {
        for (int i = m; i <= n; i++)
        {
            int a = i / 100,
                c = i % 10,
                b = i / 10 % 10;
            if (pow(a, 3) + pow(b, 3) + pow(c, 3) == i)
            {
                cout << i << '\n';
            }
        }
    }
    else
    {
        puts("Invalid Value.");
    }
    return 0;
}