#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        string b = s;
        int len = s.size();
        sort(s.begin(), s.end());
        bool fg = true;
        for (int i = 0; i < len;i++){
            if(s[i] != 'a' + i){
                fg = false;
                break;
            }
        }
        if(fg){
            bool pre = true;
            for (int i = 0; i < len;i++){
                if(b[i] == 'a'){
                    pre = false;
                } else if(pre && i){
                    if(b[i] > b[i-1]){
                        fg = false;
                        break;
                    }
                } else {
                    if(b[i] < b[i-1]){
                        fg = false;
                        break;
                    }
                }
            }
            if(fg){
                cout << "YES" << '\n';
            } else {
                cout << "NO" << '\n';
            }
        } else {
            cout << "NO" << '\n';
        }
    }
    return 0;
}