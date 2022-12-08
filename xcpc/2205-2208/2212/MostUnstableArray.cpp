#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long LL;
typedef pair<int, int> P;
const int maxn = 1e5 + 5;

int main() {
    cin.tie(0)->ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        if (n == 1) {
            cout << 0 << '\n';
        } else if (n == 2) {
            cout << m << '\n';
        } else {
            cout << m * 2 << '\n';
        }
    }
    return 0;
}
