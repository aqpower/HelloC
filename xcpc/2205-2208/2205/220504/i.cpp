#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int dp[maxn];
int main(){
    int n, ans = -1;
    cin >> n;
    for (int i = 0; i < n;i++){
        cin >> dp[i];
        if(i){
            dp[i] = max(dp[i-1] + dp[i], dp[i]);
        }
        if(dp[i] > ans){
            ans = dp[i];
        }
    }
    cout << ans;
    return 0;
}