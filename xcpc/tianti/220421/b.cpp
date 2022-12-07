#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, al = 0;
        cin >> n;
        int p = 0, g = 0;
        while(n){
            n--;
            p++;
            g++;
            al++;
            if(p == 3){
                n++;
                p = 0;
            }
            if(g == 4){
                n++;
                g = 0;
            }
        }
        cout << al << '\n';
    }
    return 0;
}