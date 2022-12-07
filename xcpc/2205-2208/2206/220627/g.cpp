#include <bits/stdc++.h>
using namespace std;
int w[105];
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, l, r, k;
        scanf("%d%d%d%d", &n, &l, &r, &k);
        for (int i = 0; i < n;i++){
            cin >> w[i];
        }
        sort(w, w + n);
        int ans = 0;
        for (int i = 0; i < n;i++){
            if(w[i] < l || w[i] > r){
                continue;
            }
            if(k - w[i] >= 0){
                k -= w[i];
                ans++;
            } else {
                break;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}