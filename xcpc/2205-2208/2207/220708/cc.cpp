#include <bits/stdc++.h>
using namespace std;
int a[105], b[105], ans[300];
int main(){
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int k, n, m;
        cin >> k >> n >> m;
        for (int i = 0; i < n;i++){
            cin >> a[i];
        }
        for (int i = 0; i < m;i++){
            cin >> b[i];
        }
        int na = 0, nb = 0, ind = 0;
        while(1){
            if(na < n && a[na] == 0){
                ans[ind++] = a[na++];
                k++;
            } else if(nb < m && b[nb] == 0){
                ans[ind++] = b[nb++];
                k++;
            } else if(na < n && a[na] <= k){
                ans[ind++] = a[na++];
            } else if(nb < m && b[nb] <= k){
                ans[ind++] = b[nb++];
            } else {
                if(ind == m + n){
                    for (int i = 0; i < ind;i++){
                        cout << ans[i] << ' ';
                    }
                    cout << '\n';
                } else {
                    cout << -1 << '\n';
                }
                break;
            }
        }
    }
    return 0;
}