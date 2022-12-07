#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int t = n / 3;
        int b1 = t, b2 = t + 1;
        int a1 = n - 2 * b1;
        int a2 = n - 2 * b2;
        if(abs(a1 - b1) < abs (a2 - b2)){
            cout << a1 << ' ' << b1 << '\n';
        } else {
            cout << a2 << ' ' << b2 << '\n';
        }
    }
    return 0;
}