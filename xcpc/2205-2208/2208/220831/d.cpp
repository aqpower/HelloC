#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
const int maxn = 1e5 + 5;

int main()
{
    cin.tie(0)->ios::sync_with_stdio(false);
    int t;
    cin >> t;
    int a[10];
    a[0] = 9;
    for (int i = 1; i < 10;i++){
        a[i] = i - 1;
    }
    while (t--)
    {
        int n;
        cin >> n;
        int ind = 0;
        bool fg = true;
        while (n)
        {
            cout << a[ind];
            if (fg)
            {
                ind++;
                if (ind == 10)
                {
                    ind = 8;
                    fg = false;
                }
            }
            else
            {
                ind--;
                if (ind == -1)
                {
                    ind = 1;
                    fg = true;
                }
            }
            n--;
        }
        cout << '\n';
        }
    return 0;
}
