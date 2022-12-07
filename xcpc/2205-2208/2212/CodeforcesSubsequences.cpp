#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

typedef pair<int, int> P;

string s = "codeforces";
int main() {
    cin.tie(0)->ios::sync_with_stdio(false);
    long long k;
    cin >> k;
    long long cnt[15];
    for (int i = 0; i < 10; i++) {
        cnt[i] = 1;
    }
    long long now = 1;
    int t = 0;
    while (now < k) {
        now = now / cnt[t] * (cnt[t] + 1);
        cnt[t++]++;
        if (t == 10) {
            t = 0;
        }
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < cnt[i]; j++) {
            cout << s[i];
        }
    }
    return 0;
}
