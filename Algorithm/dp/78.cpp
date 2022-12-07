#include <bits/stdc++.h>
using namespace std;

int main(){
    // int dp[105][105] = {0};
    vector<char> dp[105][105];
    string a, b;
    getline(cin, a);
    getline(cin, b);
    int la = a.size(), lb = b.size();
    for (int i = 1; i <= la; i++){
        for (int j = 1; j <= lb;j++){
            if(a[i-1] == b[j-1]){
                // dp[i][j] = dp[i - 1][j - 1] + 1;
                dp[i][j] = dp[i-1][j-1];
                dp[i][j].push_back(a[i - 1]);
            } else {
                if(dp[i-1][j].size() > dp[i][j-1].size()){
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }
    }
    set<vector<char>> ans;
    int max = dp[la][lb].size();
    if(!max){
        cout << "NO" << '\n';
    } else {
        for (int i = 1; i <= la;i++){
            for (int j = 1; j <= lb; j++)
            {
                if(dp[i][j].size() == max){
                    ans.insert(dp[i][j]);
                }
            }
        }
        for (auto i = ans.begin(); i != ans.end();i++){
            vector<char> t = *i;
            for (int j = 0; j < t.size();j++){
                cout << t[j];
            }
            cout << '\n';
        }
    }

    return 0;
}