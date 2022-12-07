#include <iostream>
using namespace std;
const int P = 131;
const int N = 1e5 + 5;
typedef unsigned long long ULL;
ULL h[N], p[N];
ULL zihash(int l, int r)
{
    return h[r] - h[l - 1] * p[r - l + 1];
}
int main()
{
    int n, m, l1, r1, l2, r2;
    char s[N];
    cin >> n >> m >> s + 1;
    p[0] = 1, h[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        h[i] = h[i - 1] * P + s[i];
        p[i] = p[i - 1] * P;
    }
    while (m--)
    {
        cin >> l1 >> r1 >> l2 >> r2;
        if (zihash(l1, r1) == zihash(l2, r2))
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }

    return 0;
}