#include <bits/stdc++.h>
using namespace std;
int a[200];
int main(){
    int n, m;
    cin >> n >> m;
    while(n--){
        int l, r;
        cin >> l >> r;
        for (int i = l; i <= r;i++){
            a[i] = 1;
        }
    }
    int ans = 0;
    int re[200];
    for (int i = 1; i <= m;i++){
        if(!a[i]){
            re[ans++] = i;
        }
    }
    cout << ans << '\n';
    if(ans){
        for (int i = 0; i < ans;i++){
            cout << re[i] << ' ';
        }
    }
    return 0;
}