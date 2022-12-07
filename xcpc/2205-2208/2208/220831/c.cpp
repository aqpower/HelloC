#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int,int> P;
const int maxn = 2e5 + 5;
ll a[maxn];
ll dp[maxn];

int main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for (int i = 1; i <= n;i++){
            cin >> a[i];
        }
        ll ans = a[n];
        dp[n] = a[n];
        for (int i = n - 1; i >= 1;i--){
            if(i + a[i] <= n){
                dp[i] = dp[i + a[i]] + a[i];
            } else {
                dp[i] = a[i];
            }
            if(dp[i] > ans){
                ans = dp[i];
            }
        }
        // for (int i = 1; i <= n;i++){
        //     cout << dp[i] << ' ';
        // }
        // cout << '\n';
        cout << ans << '\n';
    }
    return 0;
}
