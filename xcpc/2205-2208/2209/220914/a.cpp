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
const int maxn = 1e3 + 5;
const ll MOD = 1e9 + 7;
int a[maxn], b[maxn];
ll nn, ans;

void Solution(int ind, ll exp) {
    if (ind == nn) {
        ans += exp;
        return;
    }
    Solution(ind + 1, exp * a[ind]);
    Solution(ind + 1, exp * b[ind]);
}

int main() {
    while (cin >> nn) {
        ans = 0;

        for (int i = 0; i < nn; i++) {
            cin >> a[i] >> b[i];
        }
        
        Solution(0, 1);
        cout << ans << '\n';
    }
    return 0;
}
