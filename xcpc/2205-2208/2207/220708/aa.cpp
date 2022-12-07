#include <bits/stdc++.h>
using namespace std;
struct P{
    int x, y, step;
    P(int xx,int yy,int ss):x(xx),y(yy),step(ss){};
};
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int main(){
    int t;
    cin >> t;
    while(t--){
        int x, y, m, n, fa, fb;
        int ans = 0;
        cin >> x >> y >> m >> n >> fa >> fb;
        if(x == m && x == fa && (n - fb) * (fb - y) > 0){
            ans = abs(y - n) + 2;
        } else if(y == n && y == fb && (m - fa) * (fa - x) > 0){
            ans = abs(x - m) + 2;
        } else {
            ans = abs(x - m) + abs(y - n);
        }
        cout << ans << '\n';
    }
    return 0;
}