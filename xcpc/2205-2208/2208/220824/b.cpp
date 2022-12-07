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

bool myChange(int re,int to){
    if(re <= to && to % re == 0){
        return true;
    }
    return false;
}


int main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        ll a, b, c;
        cin >> a >> b >> c;
        bool fg = false;
        double dt1 = (a + c) / 2.0;
        int t1 = (a + c) / 2;
        if(dt1 - t1 == 0 && myChange(b, t1)){
            fg = true;
        }
        int t2 = b - (c - b);
        if(myChange(a,t2)){
            fg = true;
        }
        int t3 = b + (b - a);
        if(myChange(c,t3)){
            fg = true;
        }
        if(fg){
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
    return 0;
}
