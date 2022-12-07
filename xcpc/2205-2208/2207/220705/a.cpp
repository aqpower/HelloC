#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    string t;
    cin >> t;
    int maxl = 0;
    for (int i = 1; i < t.size();i++){
        bool fg = true;
        for (int j = t.size() - i, k = 0; j < t.size(),k < i;j++,k++){
            if(t[j] != t[k]){
                fg = false;
                break;
            }
        }
        if(fg){
            maxl = i;
        } 
    }
    string ans;
    if(maxl){
        ans += t;
        k--;
        string sb = t.substr(maxl,t.size() - maxl);
        while(k--){
            ans += sb;
        }
    } else {
        while(k--){
            ans += t;
        }
    }
    cout << ans << '\n';
    return 0;
}