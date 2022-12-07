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

int cnt;
void solution(int n) {
    if (n <= 1) {
        return;
    }
    if (n % 10 == 0) {
        n /= 10;
    } else {
        n++;
    }
    cnt++;
    solution(n);
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cnt = 0;
        solution(n);
        cout << cnt << endl;
    }
    return 0;
}
