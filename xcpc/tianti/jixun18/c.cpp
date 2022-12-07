#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 5;
int main(){
    int n, a[maxn], dp[maxn];
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    dp[0] = a[0];
    if(n == 1){
        cout << a[0];
    } else if(n == 2){
        cout << max(a[0], a[1]);
    } else {
        dp[1] = max(a[0],a[1]);
        dp[2] = max(a[0] + a[2], dp[1]);
        for (int i = 2; i < n;i++){
            dp[i] = max((max(dp[i - 2], dp[i - 3]) + a[i]),dp[i-1]);
        }
        cout << dp[n - 1];
    }
    return 0;
}