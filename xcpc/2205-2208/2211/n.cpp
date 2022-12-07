#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long LL;
typedef pair<int, int> P;
const int maxn = 1e5 + 5;
LL n;
void solve() {
    cin >> n;
    LL res = n / 2 + n % 2;
    if (n == 1) {
        res = -1;
    }
    cout << res << '\n';
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
