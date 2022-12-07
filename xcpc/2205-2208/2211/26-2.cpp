#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

typedef long long LL;
typedef pair<int, int> P;
const int maxn = 1e5 + 5;
int wor[4] = {0, 1200, 1800, 2400};

int main() {
    cin.tie(0)->ios::sync_with_stdio(false);
    int op, t;
    cin >> op >> t;
    while (t--) {
        int h;
        cin >> h;
        if (h < wor[op] * 0.1) {
            cout << "underworld" << endl;
        } else if (h < wor[op] * 0.7) {
            cout << "cavern" << '\n';
        } else if (h < wor[op] * 0.8) {
            cout << "underground" << '\n';
        } else if (h < wor[op] * 0.9) {
            cout << "surface" << '\n';
        } else {
            cout << "space" << '\n';
        }
    }
    return 0;
}
