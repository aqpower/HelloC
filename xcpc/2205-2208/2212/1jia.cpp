#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long LL;
typedef pair<int, int> P;
const int maxn = 1e5 + 5;
int fib[maxn];
void init() {
    fib[0] = 0;
    fib[1] = fib[2] = 1;
    for (int i = 3; i <= 2000; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(false);
    init();
    int t;
    cin >> t;
    while (t--) {
        LL a, b, n;
        cin >> a >> b >> n;
        if (b > a) {
            swap(a, b);
        }
        int i = 1, j = 0;
        LL max = fib[i++] * a + fib[j++] * b;
        while (max <= n) {
            max = fib[i++] * a + fib[j++] * b;
        }
        cout << j - 1 << endl;
    }
    return 0;
}
