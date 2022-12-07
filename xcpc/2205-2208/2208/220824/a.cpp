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
const int maxn = 1e5 + 5;
int a[100];
int main()
{
    cin.tie(0)->ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int ma = -1;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            ma = max(ma, a[i]);
        }
        int ans = -1;
        for (int i = 0; i < n;i++)
        {
            ans = max(ma - a[i], ans);
        }
        cout << ans << '\n';
    }
    return 0;
}
