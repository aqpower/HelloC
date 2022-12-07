#include <bits/stdc++.h>
using namespace std;
struct act{
    int s, f;
} a[1005];
bool cmp(act a, act b){
    if(a.f != b.f){
        return a.f < b.f;
    }
    return a.s < b.s;
}
int main(){
    int n;
    cin >> n;
    for (int k = 0; k < n;k++){
        cin >> a[k].s >> a[k].f;
    }
    sort(a, a + n, cmp);
    int ans = 0, pre = -1;
    for (int i = 0; i < n;i++){
        if(a[i].s >= pre){
            ans++;
            pre = a[i].f;
        }
    }
    cout << ans;
    return 0;
}