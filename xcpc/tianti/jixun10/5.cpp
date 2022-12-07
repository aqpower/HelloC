#include <bits/stdc++.h>
using namespace std;


int main(){
    string s;
    int sum = 0, feat = -1,sume = 0;
    while(getline(cin, s), s!="."){
        sum++;
        if(s.find("chi1 huo3 guo1")!=string::npos){
            if(!sume){
                feat = sum;
            }
            sume++;
        }
    }
    cout << sum << '\n';
    if(!sume){
        cout << "-_-#" << '\n';
    } else {
        cout << feat << ' ' << sume << '\n';
    }

    return 0;
}