#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
typedef long long ll;
ll a[maxn];
int main(){
    ios::sync_with_stdio(false);
    ll t;
    cin >> t;
    while(t--){
        ll n, l, r;
        cin >> n >> l >> r;
        for (ll i = 0; i < n;i++){
            cin >> a[i];
        }
        sort(a, a + n);
        ll ans = 0;
        for (ll i = 0; i < n;i++){
            if(a[i] < r){
                ll x = lower_bound(a + i + 1, a + n, l - a[i]) - a;
                ll y = upper_bound(a + i + 1, a + n, r - a[i]) - a;
                ans += y - x;
            } else {
                break;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}