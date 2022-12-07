#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        if(s.size() % 2){
            cout << "NO";
        } else {
            string a = s.substr(0,s.size() / 2);
            string b = s.substr(s.size() / 2, s.size());
            if(a == b){
                cout << "YES";
            } else {
                cout << "NO";
            }
        }
        cout << '\n';
    }
    return 0;
}