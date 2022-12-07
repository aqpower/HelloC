#include <iostream>
using namespace std;

typedef long long ll;

const int maxn = 1e5;
int n;
ll a[maxn];

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        if (n < 3) {
            cout << -1 << '\n';
            continue;
        }
        int ta = a[1], b = a[2], c = a[n];
        if (ta + b <= c) {
            cout << "1 2 " << n << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
    return 0;
}