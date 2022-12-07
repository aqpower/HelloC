#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int len;
        cin >> len;
        int dt = len - 2;
        string st, ans;
        for (int i = 0; i < dt;i++){
            cin >> st;
            ans += st;
        }
        if(ans.size() < 3){
            ans += 'b';
        } else {
            bool flag = true;
            for (int i = 2; i < ans.size();){
                if(ans[i] == ans[i-1]){
                    ans.erase(i, 1);
                    i++;
                } else {
                    flag = false;
                    i += 2;
                }
            }
            if(flag){
                ans += 'b';
            }
        }
        cout << ans << '\n';
    }
    return 0;
}