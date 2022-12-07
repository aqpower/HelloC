#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        int n, ans = 1;
        int dat[105];
        cin >> n;
        int lim = 0;
        bool flag = false;
        for (int i = 0; i < n;i++){
            cin >> dat[i];
            if(dat[i]){
                ans++;
                lim = 0;
                if(i && dat[i-1]){
                    ans += 4;
                }
            } else {
                lim++;
                if(lim == 2){
                    ans = -1;
                    flag = true;
                }
            }
        }
        if(flag){
            cout << -1 << '\n';
        } else {
            cout << ans << '\n';
        }

    }
    return 0;
}