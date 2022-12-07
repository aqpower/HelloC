#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        long long ans = 1;
        for (int i = 0; i < s.size();i++){
            ans *= (s[i] - '0');
        }
        cout << ans << '\n';
    }
    return 0;
}