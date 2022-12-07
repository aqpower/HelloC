#include <iostream>
using namespace std;
int main()
{
    int t, n, a = 0, b = 0, c = 0;
    cin >> n;
    while (n--)
    {
        cin >> t;
        if (t >= 85)
        {
            a++;
        }
        else if (t >= 60)
        {
            b++;
        }
        else
        {
            c++;
        }
    }
    cout << a << ' ' << b << ' ' << c << '\n';
   
    return 0;
}