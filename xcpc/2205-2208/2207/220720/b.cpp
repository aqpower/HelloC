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
        int c0 = 0, c1 = 0, c2 = 0;
        for (int i = 0; i < n;i++){
            cin >> a[i];
            if(a[i] % 3 == 0){
                c0++;
            } else if(a[i] % 3 == 1){
                c1++;
            } else {
                c2++;
            }
        }
        int ans = 0;
        int ta = n / 3;
        while(c0 != ta || c1 != ta || c2 != ta){
            if(c0 > ta){
                c1 += c0 - ta;
                ans += c0 - ta;
                c0 = ta;
            }
            if(c1 > ta){
                c2 += c1 - ta;
                ans+= c1 - ta;
                c1 = ta;
            }
            if(c2 > ta){
                c0 += c2 - ta;
                ans += c2 - ta;
                c2 = ta;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
