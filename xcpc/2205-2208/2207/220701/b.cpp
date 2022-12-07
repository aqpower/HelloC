#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int a, b, c;
        cin >> a >> b >> c;
        int de = abs(a - b);
        int n = de * 2;
        if(c > n){
            cout << -1 << '\n';
            continue;
        }
        if(max(a,b) > n){
            cout << -1 << '\n';
            continue;
        }
        if(c > de){
            cout << c - de << '\n';
        } else {
            cout << c + de << '\n';
        }
    }
    return 0;
}