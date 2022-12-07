#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
const int maxn = 1e5 + 5;

vector<int> va;
void init() {
    for (ll i = 0;; i++) {
        double a = cbrt(192 * i + 1);
        int ia = (int)a;
        if (a - ia == 0) {
            cout << ia << endl;
            va.push_back(ia);
        }
        if (a > 1e9) {
            break;
        }
    }
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(false);
    init();
    int t;
    cin >> t;
    while (t--) {
        ll l, r;
        cin >> l >> r;
        ll ans = 0;
        bool fg = false;
        for (int i = 0; i < va.size(); i++) {
            if(va[i] > r){
                break;
            }
            if(va[i] >= l){
                fg = true;
            }
            if(fg){
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
