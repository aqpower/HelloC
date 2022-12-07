#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
const int maxn = 2e5 + 5;
int a[maxn];
int cnt[maxn];

int main() {
    cin.tie(0)->ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            cnt[a[i]]++;
        }
        bool flag = false;
        for (int i = 1; i <= n; i++) {
            if (cnt[i] == 1) {
                flag = true;
                for (int j = 1; j <= n; j++) {
                    if (a[j] == i) {
                        cout << j << '\n';
                        break;
                    }
                }
                break;
            }
        }
        if (!flag) {
            cout << -1 << '\n';
        }
    }
    return 0;
}
