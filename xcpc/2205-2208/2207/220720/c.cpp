#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int,int> P;
const int maxn = 1e5 + 5;

int main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        ll x;
        cin >> x;
        int ti = pow(x, 1.0 / 3);
        bool fg = false;
        for (ll i = 1; i <= ti;i++){
            ll ne = x - i * i * i;
            ll c = cbrt(ne);
            if(c * c * c == ne && c > 0){
                fg = true;
                break;
            }
        }
        if (fg){
            cout << "YES" << '\n';
        }else{
            cout << "NO" << '\n';
        }
    }
    return 0;
}
