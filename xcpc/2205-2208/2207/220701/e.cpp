#include <bits/stdc++.h>
using namespace std;
int mp[30];
int main(){
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        memset(mp, 0, sizeof(mp));
        string s;
        cin >> s;
        for (int i = 0; i < s.size();i++){
            mp[s[i] - 'a']++;
        }
        int n2 = 0, n1 = 0;
        for (int i = 0; i < 26;i++){
            if(mp[i] >= 2){
                n2++;
            } else if(mp[i] == 1){
                n1++;
            }
        }
        cout << n2 + n1 / 2 << '\n';
    }
    return 0;
}