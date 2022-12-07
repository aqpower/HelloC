#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isprim(ll a){
    if(a == 1){
        return false;
    }
    for (ll i = 2; i <= sqrt(a);i++){
        if(a % i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    int n;
    cin >> n;
    if(isprim(n)){
        cout << 1 << '\n'
             << n << '\n';
    } else {
        n -= 3;
        for (ll i = 2;;i++){
            if(isprim(i) && isprim(n-i)){
                cout << 3 << '\n'
                     << 3 << ' ' << i << ' ' << n - i << '\n';
                break;
            }
        }
    }
    return 0;
}