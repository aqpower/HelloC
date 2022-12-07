#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll cal(ll a, ll b){ 
    return a - a / b; }

int main()
{
    ll n1, n2, x, y;
    cin >> n1 >> n2 >> x >> y;
    ll l = 1, r = 1e9;
    while (l < r){
        ll mid = l + (r - l) / 2;
        if (n1 <= cal(mid, x) && n2 <= cal(mid, y) && n1 + n2 <= cal(mid, x * y)){
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }
    cout << r << '\n';
    return 0;
}