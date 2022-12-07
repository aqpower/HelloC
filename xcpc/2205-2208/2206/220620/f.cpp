#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int nn = 0;
        for (int i = 0; i < s.size();i++){
            if(s[i] == 'N'){
                nn++;
            }
        }
        if(nn == 1){
            cout << "NO" << '\n';
        } else {
            cout << "YES" << '\n';
        }
    }
    return 0;
}

