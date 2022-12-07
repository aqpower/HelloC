#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a[100];
        int ind = 0;
        string s;
        cin >> s;
        int k = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                k++;
            } else {
                if (k) {
                    a[ind++] = k;
                    k = 0;
                }
            }
        }
        if (k) {
            a[ind++] = k;
            k = 0;
        }
        sort(a, a + ind, greater());
        int ans = 0;
        for (int i = 0; i < ind; i += 2) {
            ans += a[i];
            // cout << a[i] << ' ';
        }
        cout << ans << '\n';
    }
    return 0;
}