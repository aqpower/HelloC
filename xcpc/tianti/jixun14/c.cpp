#include <bits/stdc++.h>
using namespace std;
typedef pair<long long, long long> P;
const long long maxn = 1e5+5, inf = 1e9 + 7;
P a[maxn];
long long ans;

int main(){
    long long n;
    cin >> n;
    for (long long k = 0; k < n;k++){
        cin >> a[k].first >> a[k].second;
    }
    sort(a, a + n);
    long long x = 0, y = 0;
    for (long long i = 0; i < n;i++){
        ans += ((((x - a[i].first)%inf) * ((x - a[i].first)%inf))%inf + (((y - a[i].second)%inf) * ((y - a[i].second)%inf))%inf)%inf;
        ans %= inf;
        x = a[i].first, y = a[i].second;
    }
    cout << ans;
    return 0;
}