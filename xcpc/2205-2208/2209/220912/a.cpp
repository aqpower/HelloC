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
    int na, pa, sa;
    cin >> na >> pa >> sa;
    int nb, pb, sb;
    cin >> nb >> pb >> sb;
    if (na < nb) {
        cout << 2 << '\n';
        return 0;
    } else if (na > nb) {
        cout << 1 << '\n';
        return 0;
    }
    if (pa < pb) {
        cout << 1 << '\n';
        return 0;
    } else if (pa > pb) {
        cout << 2 << '\n';
        return 0;
    }
    if (sa < sb) {
        cout << 1 << '\n';
        return 0;
    } else if (sa > sb) {
        cout << 2 << '\n';
        return 0;
    }
    cout << "God" << '\n';
    return 0;
}
