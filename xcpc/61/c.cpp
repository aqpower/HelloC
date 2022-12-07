#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long LL;
typedef pair<int, int> P;
const int maxn = 1e5 + 5;
int a[maxn];
int pre[25];
void print(int n) {
    for (int i = 1; i <= n; i++) {
        cout << a[i] << ' ';
    }
    cout << endl;
}
void solve(int n) {
    pre[1] = 1;
    for (int i = 2; i <= 20; i++) {
        pre[i] = pre[i - 1] * 2 + 1;
    }
    int k = 1;
    while (pre[k] < n) {
        k++;
    }
    int d = k;
    while (k) {
        for (int i = pow(2, d - k); i <= n; i += pow(2, d - k + 1)) {
            a[i] = k;
        }
        k--;
    }
    print(n);
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(false);
    int n;
    cin >> n;
    solve(n);
    return 0;
}
