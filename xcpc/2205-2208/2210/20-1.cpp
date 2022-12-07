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
    cout << t << endl;
    for (int i = 0; i < t; i++) {
        cout << i << endl;
        continue;
        break;
    }
    std::cout << "Ok" << std::endl;
    
    while (t--) {
        int n, x;
        cin >> n >> x;
        int ans = 1;
        if (n > 2) {
            ans += (n - 2) / x;
        }
        if (n > 2 && (n - 2) % x) {
            ans++;
        }
        cout << ans << '\n';
    }
    return 0;
}
