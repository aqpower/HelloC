#include <iostream>
using namespace std;
int cal_1(int n, int p) // n!有多少个质因子p
{
    if (!n)
        return 0;
    return n / p + cal_1(n / p, p);
}

int cal_2(int n, int p)
{
    int ans = 0;
    while (n)
    {
        ans += n / p;
        n /= p;
    }
    return ans;
}

int main()
{
    int n, p;
    cin >> n >> p;
    int a1 = cal_1(n, p);
    int a2 = cal_2(n, p);
    cout << a1 << endl
         << a2 << endl;

    return 0;
}