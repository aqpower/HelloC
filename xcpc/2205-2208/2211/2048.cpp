#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

typedef long long LL;
typedef pair<int, int> P;
const int maxn = 1e3 + 5;
int n;
LL wor[maxn][maxn];

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf_s("%lld", &wor[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i - 1 >= 1 && wor[i - 1][j] == wor[i][j]) {
                printf("YES\n");
                return;
            }
            if (j - 1 >= 1 && wor[i][j - 1] == wor[i][j]) {
                printf("YES\n");
                return;
            }
        }
    }
    printf("NO\n");
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
