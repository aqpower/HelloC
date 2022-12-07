#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> P;
const int maxn = 2e5 + 5;
P a[maxn];

bool cmp(P a, P b){
    if(a.first != b.first){
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int tx, tr;
    for (int i = 0; i < n;i++){
        cin >> tx >> tr;
        a[i].first = tx - tr;
        a[i].second = tx + tr;
    }
    sort(a, a + n, cmp);
    int ans = 0, nr;
    for (int i = 0; i < n;i++){
        if(i){
            if(a[i].first > nr){
                ans += a[i].first - nr;
            }
            nr = max(a[i].second, nr);
        } else {
            nr = a[i].second;
        }
    }
    cout << ans << '\n';
    return 0;
}

