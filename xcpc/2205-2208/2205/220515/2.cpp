#include <bits/stdc++.h>
using namespace std;
char wor[1000][1000];
map<char, char> mp;
int main(){
    int n, a, b;
    cin >> n >> a >> b;
    bool dm = true, dn = true;
    string a1, a2;
    for (int i = 1; i <= n*b;i++){
        if(dn){
            a1 += '.';
            a2 += '#';
        } else {
            a1 += '#';
            a2 += '.';
        }
        if(i % b == 0){
            dn = !dn;
        }
    }
    for (int i = 1; i <= n * a;i++){
        if(dm){
            cout << a1 << '\n';
        } else {
            cout << a2 << '\n';
        }
        if(i % a == 0){
            dm = !dm;
        }
    }
        return 0;
}