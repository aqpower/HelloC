#include <bits/stdc++.h>
using namespace std;
string change(string s){
    while(s[0] == '0'){
        s.erase(0, 1);
    }
    if(s.empty()){
        s = "0";
    }
    return s;
}
int main(){
    int n, k;
    cin >> n >> k;
    string s = to_string(n);
    if(k == 0){
        cout << s << '\n';
    } else if(abs(k) > s.size()){
        cout << "Error" << '\n';
    } else if(k > 0){
        s = s.substr(0, k);
        cout << change(s) << '\n';
    } else {
        reverse(s.begin(), s.end());
        s = s.substr(0, abs(k));
        reverse(s.begin(), s.end());
        cout << change(s) << '\n';
    }
    return 0;
}