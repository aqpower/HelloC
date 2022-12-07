#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <list>
#include <set>
#include <string>
#include <vector>



using namespace std;

vector<int> ve;

typedef long long ll;
typedef pair<int, int> P;
const int maxn = 1e5 + 5;

int main() {

    cin.tie(0)->ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        int num = x % 10 - 1;
        int nd = 0;
        while (x) {
            nd++;
            x /= 10;
        }
        int ans = num * 10 + (1 + nd) * nd / 2;
        cout << ans << endl;
    }
    return 0;
}
