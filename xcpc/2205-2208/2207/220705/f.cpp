#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
int d[maxn];
bool  cmp(ll a, ll b){
    return a > b;
}
int main(){
    ios::sync_with_stdio(false);
    ll n, m;
    cin >> n >> m;
    ll now = 0;
    ll pr, ne;
    for (ll i = 0;i < n;i++){
        cin >> pr >> ne;
        d[i] = pr - ne;
        now += pr;
    }
    sort(d, d + n, cmp);
    ll dd = now - m, ind = 0;
    while(dd > 0 && ind < n){
        dd -= d[ind++];
    }
    if(dd <= 0){
        cout << ind << '\n';
    } else {
        cout << -1 << '\n';
    }
    return 0;
}