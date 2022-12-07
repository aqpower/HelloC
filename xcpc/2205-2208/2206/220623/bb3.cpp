#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int mi = 1e9, si = s.size() - 1;
        for (int i = 1; i < s.size();i++){
            if(s[i] == '5'){
                for (int j = i - 1; j >= 0;j--){
                    if(s[j] == '2' || s[j] == '7'){
                        int now = i - j - 1 + si - i;
                        mi = min(mi, now);
                        break;
                    }    
                }
            } else if(s[i] == '0'){
                for (int j = i - 1; j >= 0;j--){
                    if(s[j] == '5' || s[j] == '0'){
                        int now = i - j - 1 + si - i;
                        mi = min(mi, now);
                        break;
                    }    
                }
            }
        }
        cout << mi << '\n';
    }
    return 0;
}