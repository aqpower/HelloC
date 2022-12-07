#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 35;
int a[maxn], dp[maxn], mymax = 1;
int main(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n;i++){
        scanf("%d", &a[i]);
    }
    for (int i = n; i > 0;i--){
        dp[i] = dp[i + a[i]] + 1;
        if(dp[i] > mymax){
            mymax = dp[i];
        }
    }
    cout << mymax;
    return 0;
}