#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

typedef long long LL;
typedef pair<int, int> P;
const int maxn = 2e5 + 5;
int n;
int a[maxn];
int g;
void solve() {
    cin >> n;
    int np = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (i - 1 > 0 && a[i] < a[i - 1]) {
            g = i;
            np++;
        }
    }
    if (np > 1) {
        cout << -1 << '\n';
        return;
    }
    if (np == 0) {
        for (int i = 1; i <= n; i++) {
            cout << a[i] << ' ';
        }
        cout << '\n';
        return;
    }
    if (a[n] <= a[1]) {
        for (int i = g; i <= n; i++) {
            cout << a[i] << ' ';
        }
        for (int i = 1; i < g; i++) {
            cout << a[i] << ' ';
        }
        cout << '\n';
    } else {
        cout << -1 << '\n';
    }
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
