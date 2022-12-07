#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int na = 0, nb = 0, nc = 0;
        for (int i = 0; i < s.size();i++){
            if(s[i] == 'A'){
                na++;
            } else if(s[i] == 'B'){
                nb++;
            } else {
                nc++;
            }
        }
        if(na + nc == nb){
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
    return 0;
}