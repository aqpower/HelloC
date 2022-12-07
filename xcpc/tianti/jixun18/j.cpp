#include <bits/stdc++.h>
using namespace std;
const int maxn = 205, inf = 1e9;
int a[maxn][maxn], dp[maxn];
int main(){
    int n;
    cin >> n;
    fill(dp, dp + maxn, inf);
    for (int i = 1; i < n;i++){
        for (int j = i + 1; j <= n;j++){
            cin >> a[i][j];
        }
    }
    dp[1] = 0;
    for (int i = 2; i <= n;i++){
        for (int j = i - 1; j >= 1;j--){
            dp[i] = min(dp[j] + a[j][i], dp[i]);
        }
    }
    cout << dp[n] << '\n';
    return 0;
}