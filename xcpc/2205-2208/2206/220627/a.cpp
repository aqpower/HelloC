#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int ans = 0;
        if(n % 2 != 0){
            string s = to_string(n);
            bool fg = false;
            for (int i = 0; i < s.size();i++){
                if((s[i] - '0') % 2 == 0){
                    fg = true;
                    if(i){
                        ans = 2;
                    } else {
                        ans = 1;
                    }
                    break;
                }
            }
            if(!fg){
                ans = -1;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}