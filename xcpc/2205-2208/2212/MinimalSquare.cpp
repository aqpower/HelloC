/*
Find the minimum area of a square land on which you can place two identical
rectangular a \times ba×b houses. The sides of the houses should be parallel to
the sides of the desired square land.

Formally,
You are given two identical rectangles with side lengths aa and bb (1 \le a, b
\le 1001≤a,b≤100) — positive integers (you are given just the sizes, but not
their positions). Find the square of the minimum area that contains both given
rectangles. Rectangles can be rotated (both or just one), moved, but the sides
of the rectangles should be parallel to the sides of the desired square. Two
rectangles can touch each other (side or corner), but cannot intersect.
Rectangles can also touch the sides of the square but must be completely inside
it. You can rotate the rectangles. Take a look at the examples for a better
understanding.
*/

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long LL;
typedef pair<int, int> P;
const int maxn = 1e5 + 5;

int main() {
    cin.tie(0)->ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        if (a < b) {
            swap(a, b);
        }
        if (a == b) {
            cout << pow(a + b, 2) << '\n';
        } else {
            if (b * 2 > a) {
                cout << pow(b * 2, 2) << '\n';
            } else {
                cout << a * a << '\n';
            }
        }
    }
    return 0;
}
