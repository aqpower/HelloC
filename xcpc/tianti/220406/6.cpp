#include <bits/stdc++.h>
using namespace std;
map<string, string> win;
int main(){
    win["ChuiZi"] = "Bu";
    win["JianDao"] = "ChuiZi";
    win["Bu"] = "JianDao";
    int k, now = 0;
    cin >> k;
    getchar();
    string s;
    while (cin >> s,s!="End"){
        if(now == k){
            now = 0;
            cout << s;
        } else {
            cout << win[s];
            now++;
        }
        cout << '\n';
        
    }
    return 0;
}