#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int ans = 0;
        for (int i = 1; i < s.size();){
            if(i == s.size() - 1){
                if(s[i]!= '5' && s[i]!='0'){
                    s.erase(i, 1);
                    i--;
                    ans++;
                } else {
                    i++;
                }
            } else {
                if(s[i]!='2' && s[i]!= '5' && s[i]!= '7' && s[i]!='0'){
                    s.erase(i, 1);
                    ans++;
                } else {
                    i++;
                }
            }
            cout << s << '\n';
        }
        cout << s << ' '<< ans << '\n';
        while(s[s.size() - 1] == '5' && (s[s.size() - 2] =='5' || s[s.size()-2] == '0')){
            s.erase(s.end() - 1);
            ans++;
        }
        cout << s << ' '<< ans << '\n';
    }
    return 0;
}