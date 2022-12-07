#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> P;
const int maxn = 55;

int a[maxn];

int main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int ans = 0;
        for (int i = 0; i < n;i++){
            cin >> a[i];
            if(i){
                int ma = max(a[i], a[i - 1]);
                int mi = min(a[i], a[i - 1]);
                if(1.0 * ma / mi > 2){
                    int ti = 0;
                    while(1.0 * ma / mi > 2){
                        mi *= 2;
                        ti++;
                    }
                    ans += ti;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
