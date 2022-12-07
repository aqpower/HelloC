#include <bits/stdc++.h>
using namespace std;
int main(){
    string str;
    cin >> str;
    int n;
    cin >> n;
    while(n--){
        string t;
        cin >> t;
        if(str.find(t)!=string::npos){
            cout << str.substr(str.find(t));
        } else {
            cout << "Not Found";
        }
        cout << '\n';
    }

    return 0;
}