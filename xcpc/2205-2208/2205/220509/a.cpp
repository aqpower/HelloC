#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    int a, b, c, x, y;
    cin >> t;
    while(t--){
        cin >> a >> b >> c >> x >> y;
        a -= x;
        b -= y;
        if(a < 0){
            c += a;
        }
        if(b < 0){
            c += b;
        }
        if(c < 0){
            cout << "NO";
        } else {
            cout << "YES";
        }
        cout << '\n';
    }
    return 0;
}