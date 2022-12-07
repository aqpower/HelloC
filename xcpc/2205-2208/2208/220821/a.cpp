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
int a[1005][1005];
bool b[1005][1005];
int main()
{
    cin.tie(0)->ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    int ans = -1;
    for (int i = 0; i < n;i++){
        int mi = 1e9;
        for (int j = 0; j < m;j++){
            cin >> a[i][j];
            mi = min(a[i][j], mi);
        }
        ans = max(ans, mi);
    }
    for (int j = 0; j < m;j++){
        int mi = 1e9;
        for (int i = 0; i < n;i++){
            mi = min(a[i][j], mi);
        }
        ans = max(mi, ans);
    }
    cout << ans << '\n';
    return 0;
}
