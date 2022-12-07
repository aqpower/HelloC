#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    getline(cin, s);
    bool big = false, sma = false;
    set<char> se;
    bool smi = false;
    for (int i = 0; i < s.size();i++){
        if(se.count(s[i])){
            smi = false;
            cout << "No" << '\n';
            return 0;
        }
        if(s[i] >= 'A' && s[i] <= 'Z'){
            big = true;
        }
        if(s[i] >='a' && s[i] <='z'){
            sma = true;
        }
        se.insert(s[i]);
    }
    if(sma&&big){
        cout << "Yes" << '\n';
    } else {
        cout << "No" << '\n';
    }
    return 0;
}