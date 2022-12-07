#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, c0, c1, h;
        cin >> n >> c0 >> c1 >> h;
        string s;
        cin >> s;
        int n0 = 0, n1 = 0;
        for (int i = 0; i < s.size();i++){
            if(s[i] == '0'){
                n0++;
            } else {
                n1++;
            }
        }
        int ans;
        int g0 = c0 - c1 - h;
        int g1 = c1 - c0 - h;
        if(g1 <= 0 || g0 <= 0){
            if(g0 > 0){
                ans = c1 * n + h * n0;
            } else if(g1 > 0){
                ans = c0 * n + h * n1;
            } else {
                ans = n0 * c0 + n1 * c1;
            }
        } else {
            if(g0 >= g1){
                ans = c1 * n + h * n0;
            } else if(g1 > g0){
                ans = c0 * n + h * n1;
            } 
        }
        cout << ans << '\n';
    }
    return 0;
}