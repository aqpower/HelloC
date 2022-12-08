#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long LL;
typedef pair<int, int> P;
const int maxn = 1e2 + 5;
int main() {
    cin.tie(0)->ios::sync_with_stdio(false);
    int n;
    cin >> n;
    cout << (LL)pow(2, n + 1) - 2;
    return 0;
}
