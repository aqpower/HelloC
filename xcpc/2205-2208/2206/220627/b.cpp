#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;
    cin >> t;
    while(t--){
        ll a, b;
        cin >> a >> b;
        ll n = min(a, b);
        ll ta = n * 4;
        if(a + b <= ta){
            n = (a + b) / 4;
        }
        cout << n << '\n';
    }
    return 0;
}