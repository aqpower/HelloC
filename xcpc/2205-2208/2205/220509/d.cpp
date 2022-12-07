#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        while(s.find(s[0],1) != -1){
            s.erase(0, 1);
        }
        cout << s << '\n';
    }
    return 0;
}