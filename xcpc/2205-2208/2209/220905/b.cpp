#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
const int maxn = 1e4 + 5;
int a[maxn];
int dppre[maxn], dpafter[maxn];
int num1pre[maxn], num1after[maxn];

int main()
{
    cin.tie(0)->ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int num1 = 0;
    string s;
    cin >> s;
    for (int i = 1; i <= n; i++)
    {
        a[i] = s[i - 1] - '0';
        num1pre[i] = num1;
        if (a[i] == 1)
        {
            num1++;
        }
    }
    int lanum1 = 0;
    for (int i = n; i >= 1; i--)
    {
        num1after[i] = lanum1;
        if (a[i] == 1)
        {
            lanum1++;
        }
    }

    for (int i = 2; i <= n; i++)
    {
        dppre[i] = dppre[i - 1] + num1pre[i];
    }
    for (int i = n - 1; i >= 1; i--)
    {
        dpafter[i] = dpafter[i + 1] + num1after[i];
    }

    int q;
    cin >> q;
    while (q--)
    {
        int id;
        cin >> id;
        cout << dpafter[id] + dppre[id] << '\n';
    }
    return 0;
}
