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
int a[maxn];

int main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int mi = 1e9;
        for (int i = 0; i < n;i++){
            cin >> a[i];
            mi = min(mi, a[i]);
        }
        int ans = 0;
        for (int i = 0; i < n;i++){
            if(a[i] > mi){
                ans++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
