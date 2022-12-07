#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        ll n, m, x;
        cin >> n >> m >> x;
        ll c = x / n;
        if(x % n){
            c++;
        }
        ll r = x % n;
        if(r == 0){
            r = n;
        }
        ll ans = (r - 1) * m + c;
        cout << ans << '\n';
    }
    return 0;
}