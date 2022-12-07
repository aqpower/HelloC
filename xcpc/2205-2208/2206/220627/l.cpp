#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;
    cin >> t;
    while(t--){
        ll x, n;
        cin >> x >> n;
        for (ll i = 1; i <= n;i++){
            if(x % 2 == 0){
                x -= i;
            } else {
                x += i;
            }
        }
        cout << x << '\n';
    }
    return 0;
}