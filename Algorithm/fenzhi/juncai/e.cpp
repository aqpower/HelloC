#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int dat[maxn];
int main(){
    int n, x, ans;
    cin >> n >> x;
    for (int i = 0; i < n;i++){
        scanf("%d", &dat[i]);
    }
    int l = 0, r = n - 1;
    bool flag = false;
    while(l <= r){
        int mid = (l + r) / 2;
        if(dat[mid] == x){
            flag = true;
            ans = dat[mid];
            break;
        } else if(dat[mid] < x){
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    if (!flag){
        if(l == n){
            ans = dat[n - 1];
        } else if(r == -1){
            ans == dat[0];
        } else {
            ans = min(dat[l], dat[r]);
        }
    }
    // ans = lower_bound(dat, dat + n, x) - dat;
    // if(!ans){
    //     ans = dat[0];
    // } else if(ans == n){
    //     ans = dat[n - 1];
    // } else {
    //     ans = min(dat[ans], dat[ans - 1]);
    // }
    cout << ans << '\n';
    return 0;
}