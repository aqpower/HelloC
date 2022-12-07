#include <bits/stdc++.h>
using namespace std;
int dp[105],a[105];
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, k;
        int ans = -1;
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n;i++){
            scanf("%d", &a[i]);
        }
        for (int i = 1; i <= n;i++){
            scanf("%d", &dp[i]);
            if(i != 1){
                int dpt = 0;
                for (int j = 1; a[i] - a[j] > k;j++){
                    dpt = max(dpt, dp[j]);
                }
                dp[i] += dpt;
            }
            ans = max(ans, dp[i]);
        }
        printf("%d\n", ans);
    }
    return 0;
}