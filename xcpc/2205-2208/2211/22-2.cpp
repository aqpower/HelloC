#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        long long x, y, z, a, b, c;
        cin >> x >> y >> z;
        if (x == y && y == z) {
            cout << "YES" << endl;
            cout << x << ' ' << x << ' ' << x << endl;
            continue;
        }
        a = min(x, y);
        b = min(x, z);
        c = min(y, z);
        if (x == max(a, b) && y == max(a, c) && z == max(b, c)) {
            cout << "YES" << endl;
            cout << a << ' ' << b << ' ' << c << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}