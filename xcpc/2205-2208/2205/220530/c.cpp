#include <bits/stdc++.h>
using namespace std;
int n, m, rs, cs, rd, cd;
int a[105][105];
int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m >> rs >> cs >> rd >> cd;
        int nr = rs, nc = cs;
        int ans = 0;
        int dx = 1, dy = 1;
        while(nr != rd && nc != cd){
            ans++;
            if(nr + dx == n + 1|| nr + dx == 0){
                dx = -dx;
            }
            if(nc + dy == 0 || nc + dy == m + 1){
                dy = -dy;
            }
            nr += dx;
            nc += dy;
        }
        cout << ans << '\n';
    }
    return 0;
}