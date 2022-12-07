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
const int maxn = 1e5 + 5;

int a[maxn];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        sort(a, a + n);
        ll ans = 0;
        for (int i = 0; i < n - 1; i++) {
            ans += a[i];
        }
        cout << ans << '\n';
    }
    return 0;
}
