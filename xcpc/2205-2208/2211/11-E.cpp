#include <cmath>
#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        long long x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 == x2) {
            x3 = x1 + 1, y3 = 0;
        } else if (y1 == y2) {
            x3 = 0, y3 = y1 + 1;
        } else {
            long long dx = x1 - x2, dy = y1 - y2;
            if (dx > 0) {
                if (dy > 0) {
                    if (fabs(dx) > fabs(dy)) {
                        x3 = x2 + 1, y3 = y2;
                    } else {
                        x3 = x2, y3 = y2 + 1;
                    }
                } else {
                    if (fabs(dx) > fabs(dy)) {
                        x3 = x2 + 1, y3 = y2;
                    } else {
                        x3 = x2, y3 = y2 - 1;
                    }
                }
            } else {
                if (dy > 0) {
                    if (fabs(dx) > fabs(dy)) {
                        x3 = x2 - 1, y3 = y2;
                    } else {
                        x3 = x2, y3 = y2 + 1;
                    }
                } else {
                    if (fabs(dx) > fabs(dy)) {
                        x3 = x2 - 1, y3 = y2;
                    } else {
                        x3 = x2, y3 = y2 - 1;
                    }
                }
            }
        }
        cout << x3 << ' ' << y3 << endl;
    }
    return 0;
}