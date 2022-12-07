#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    while (n--)
    {
        int x, y, m, n, a, b;
        cin >> x >> y >> m >> n >> a >> b;
        double da[5];
        da[0] = sqrt(pow(m - a, 2) + pow(n - b, 2));
        da[1] = sqrt(pow(m - x, 2) + pow(n - y, 2));
        da[2] = sqrt(pow(a - x, 2) + pow(b - y, 2));
        sort(da, da + 3);
        if (da[0] + da[1] <= da[2])
        {
            cout << "invalid" << '\n';
        }
        else
        {
            if (fabs(da[0] * da[0] + da[1] * da[1] - da[2] * da[2]) < 1e-6)
            {
                cout << "right" << '\n';
            }
            else 
            {
                if (da[0] * da[0] + da[1] * da[1] > da[2] * da[2])
                {
                    cout << "acute" << '\n';
                }
                else
                {
                    cout << "obtuse" << '\n';
                }
            }
        }
    }
    return 0;
}