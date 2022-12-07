#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
typedef long long ll;
int a[maxn];
int main(){
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ll sum = 0;
        for (int i = 0; i < n;i++){
            cin >> a[i];
            sum += a[i];
        }
        if(sum % n){
            cout << -1 << '\n';
            continue;
        } 
        int tar = sum / n;
        int ans = 0;
        for (int i = 0; i < n;i++){
            if(a[i] - tar > 0){
                ans++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}