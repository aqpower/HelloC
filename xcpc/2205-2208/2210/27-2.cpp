#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll sol1(ll a, ll b, ll x, ll y, ll n) {
    if (n >= a - x) {
        n -= (a - x);
        a = x;
        if (n >= b - y) {
            b = y;
        } else {
            b -= n;
        }
    } else {
        a -= n;
    }
    return a * b;
}

ll sol2(ll a, ll b, ll x, ll y, ll n) {
    if (n >= b - y) {
        n -= (b - y);
        b = y;
        if (n >= a - x) {
            a = x;
        } else {
            a -= n;
        }
    } else {
        b -= n;
    }
    return a * b;
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        ll a, b, x, y, n, ans;
        cin >> a >> b >> x >> y >> n;
        cout << min(sol1(a, b, x, y, n), sol2(a, b, x, y, n)) << endl;
    }
    return 0;
}
