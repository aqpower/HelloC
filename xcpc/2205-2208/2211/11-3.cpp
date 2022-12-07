#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;

int n;
int a[100];

int main() {
    int t;
    cin >> t;
    while (t--) {
        unordered_map<int, int> mp;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        if (n == 1) {
            cout << 0 << '\n';
            continue;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (mp[a[i] + a[j]]) {
                    mp[a[i] + a[j]] += 1;
                } else {
                    mp[a[i] + a[j]] = 1;
                }
            }
        }
        int ma = -1;
        int sum = 0;
        int ans = 0;
        for (auto m = mp.begin(); m != mp.end(); m++) {
            bool fg[100];
            for (int i = 0; i < 100; i++) {
                fg[i] = false;
            }
            int dans = 0;
            for (int i = 1; i <= n; i++) {
                if (fg[i] == false) {
                    for (int j = i + 1; j <= n; j++) {
                        if (a[j] + a[i] == (*m).first && (!fg[j])) {
                            dans++;
                            fg[j] = true;
                            break;
                        }
                    }
                }
                fg[i] = true;
            }
            ans = max(ans, dans);
        }
        cout << ans << '\n';
    }
    return 0;
}