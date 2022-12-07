#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long LL;
typedef pair<int, int> P;
const int maxn = 1e5 + 5;
string s;
string tar = "kfccrazythursdayvme50";
bool fg;
void judge(int ind, int pos) {
    if (pos >= tar.size()) {
        fg = true;
    } else {
        if (ind >= s.size()) {
            return;
        }
        if (s[ind] == tar[pos]) {
            pos++;
        }
        judge(ind+1,pos);
    }
}
void solve() {
    fg = false;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] += 32;
        }
    }
    for (int i = 0; i < s.size(); i++) {
        judge(i,0);
    }
    if (fg) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
