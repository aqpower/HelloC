#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
string str;
int ans = 1;
int dp[maxn][maxn];
int main(){
    fill(dp[0], dp[0] + maxn * maxn, 0);
    getline(cin, str);
    for (int i = 0; i < str.size();i++){
        dp[i][i] = 1;
        if(i > 0){
            if(str[i] == str[i - 1]){
                dp[i - 1][i] = 1;
                ans = 2;
            }
        }
    }
    for(int l = 3;l < str.size();l++){
        for(int i = 0;i + l - 1 < str.size();i++){
            if(str[i] == str[i + l - 1]){
                dp[i][i + l - 1] = dp[i + 1][i + l - 2];
                if(dp[i][i + l - 1]){
                    ans = l;
                }
            } else {
                dp[i][i + l - 1] = 0;
            }
        }
    }
    cout << ans;

    return 0;
}