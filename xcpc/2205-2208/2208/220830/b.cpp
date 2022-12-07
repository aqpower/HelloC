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
        ll n;
        cin >> n;
        int ans = 0;
        unordered_map<int, int> mp;
        for (ll i = 1; i * i <= n;i++){
            if(i * i * i <= n){
                mp[i * i * i] = 1;
            }
            mp[i * i] = 1;
        }
        cout << mp.size() << '\n';
    }
    return 0;
}
