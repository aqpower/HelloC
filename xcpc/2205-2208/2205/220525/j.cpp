#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        char tar;
        int now, ans = 1e9;
        for (int i = 0; i < s.size();i++){
            tar = s[i];
            now = 0;
            for (int j = 0; j < s.size();j++){
                if(i == j){
                    continue;
                }
                if(s[j] <= tar){
                    now += tar - s[j];
                } else {
                    now += tar - s[j] + 26;
                }
            }
            ans = min(ans, now);
        }
        cout << ans << '\n';
    }
    return 0;
}