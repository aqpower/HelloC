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

ll ans = -1;
void solve(int w, int h, int num){
    while(w % 2 == 0){
        w /= 2;
        num *= 2;
    }
    while(h % 2 == 0){
        h /= 2;
        num *= 2;
    }
    if(num > ans){
        ans = num;
    }
}



int main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        ans = -1;
        ll w, h, n;
        cin >> w >> h >> n;
        solve(w, h, 1);
        if(ans >= n){
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
    return 0;
}
