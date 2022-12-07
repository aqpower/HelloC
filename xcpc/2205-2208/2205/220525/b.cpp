#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
int dat[maxn];
int main(){
    int n, m;
    cin >> n >> m;
    while(m--){
        int s, e;
        scanf("%d%d", &s, &e);
        for (int i = s; i <= e;i++){
            dat[i] = 1;
        }
    }
    int ans = 0;
    for (int i = 0; i <= n;i++){
        if(!dat[i]){
            ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}