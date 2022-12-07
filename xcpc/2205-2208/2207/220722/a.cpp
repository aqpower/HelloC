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
    int n;
    cin >> n;
    ll ans = 0, now = 0;
    cin >> now;
    for (int i = 0; i < n;i++){
        cin >> now;
        ll pl = ans + now;
        ll ji = ans - now;
        ll chu;
        if(now){
            chu = ans / now;
        } else {
            chu = -1e9;
        }
        ll yu = ans & abs(now);
        ll huo = ans | abs(now);
        ll yihuo = ans ^ abs(now);
        ans = max(pl, max(ji, max(chu, max(yu, max(huo, yihuo)))));
    }
    cout << ans << '\n';
    return 0;
}
