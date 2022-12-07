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

int main() {
    cin.tie(0)->ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        // cout << n << " " << m << endl;
        bool fg = false, fgfg = false;
        for (int i = 0; i < n; i++) {
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            // cout << a << " " << b << " " << c << " " << d << '\n';
            if(b == c){
                fg = true;
            }
        }
        if(m % 2){
            fg = false;
        }
        if(fg){
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
    return 0;
}
