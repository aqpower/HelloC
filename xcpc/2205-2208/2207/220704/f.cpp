#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s = to_string(n);
        if(s.size() == 1){
            cout << n << '\n';
        } else {
            int ans = 9 * (s.size() - 1) + (s[0] - '0');
            bool fg = false;
            for (int i = 1; i < s.size();i++){
                if(s[i] < s[0]){
                    fg = true;
                    break;
                } else if(s[i] > s[0]){
                    break;
                }
            }
            if(fg){
                ans--;
            }
            cout << ans << '\n';
        }
    }
    return 0;
}