#include <iostream>
#include <algorithm>
using namespace std;
const int mod = 1e9 + 7;
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;
        long long ans = 0, s = 1;
        while (k) {
            if (k % 2) {
                ans = (ans + s) % mod;
            }
            s = s * n % mod;
            k /= 2;
        }
        cout << ans << endl;
    }
    return 0;
}
