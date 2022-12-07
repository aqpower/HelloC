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
        queue<P> a;
        a.push(P(x, y, 0));
        while(1){
            P now = a.front();
            a.pop();
            for (int i = 0; i < 4;i++){
                int tox = now.x + dx[i];
                int toy = now.y + dy[i];
                if(tox == fa && toy == fb){
                    continue;
                } else if(tox == m && toy == n){
                    ans = now.step + 1;
                    break;
                } else {
                    a.push(P(tox, toy, now.step + 1));
                }
            }
            if(ans){
                break;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}