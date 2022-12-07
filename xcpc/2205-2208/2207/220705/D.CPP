#include <bits/stdc++.h>
using namespace std;
struct P{
    int s, e;
} a[105];
bool cmp(P a, P b){
    if(a.s != b.s){
        return a.s < b.s;
    }
    return a.e < b.e;
}
int main(){
    int ans[105];
    int n, m;
    cin >> n >> m;
    int k = 0;
    for (int i = 0; i < n;i++){
        cin >> a[i].s >> a[i].e;
    }
    sort(a, a + n, cmp);
    int ind = 1;
    for (int i = 0; i < n;i++){
        if(i){
            if(a[i].s > ind){
                for (int j = ind + 1; j < a[i].s;j++){
                    ans[k++] = j;
                }
            }
            ind = a[i].e;
        } else {
            if(a[i].s != 1){
                for (int j = 1; j < a[i].s;j++){
                    ans[k++] = j;
                }
            }
            ind = a[i].e;
        }
        if(i == n - 1){
            if(a[i].e != m){
                for (int j = a[i].e + 1; j <= m;j++){
                    ans[k++] = j;
                }
            }
        }
        cout << a[i].s << ' ' << a[i].e << ind <<  '\n';
    }
    cout << k << '\n';
    for (int i = 0; i < k;i++){
        cout << ans[i] << ' ';
    }
    return 0;
}