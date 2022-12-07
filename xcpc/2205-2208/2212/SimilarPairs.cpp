#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long LL;
typedef pair<int, int> P;
const int maxn = 1e5 + 5;
int a[maxn];

int main() {
    cin.tie(0)->ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int ne = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i] & 1) {
                ne++;
            }
        }
        if (ne % 2 == 0) {
            cout << "YES" << '\n';
        } else {
            sort(a + 1, a + 1 + n);
            int cnt = 0;
            for (int i = 2; i <= n; i++) {
                if (a[i] - a[i - 1] == 1) {
                    cnt++;
                }
            }
            if (cnt) {
                cout << "YES" << '\n';
            } else {
                cout << "NO" << '\n';
            }
        }
    }
    return 0;
}
