#include <bits/stdc++.h>
using namespace std;
int w, h, sm, sn;
int wor[25][25];
typedef pair<int, int> P;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int bfs(int a, int b){
    int sum = 0;
    queue<P> qu;
    qu.push(P(a, b));
    while(!qu.empty()){
        P now = qu.front();
        qu.pop();
        sum++;
        for (int i = 0; i < 4;i++){
            if(wor[now.first+dx[i]][now.second+dy[i]]){
                wor[now.first+dx[i]][now.second+dy[i]] = 0;
                qu.push(P(now.first + dx[i], now.second + dy[i]));
             }
        }
    }
    return sum;
}
int main(){
    char t;
    cin >> w >> h;
    for (int i = 1; i <= h;i++){
        for (int j = 1; j <= w;j++){
            cin >> t;
            if(t == '@'){
                sm = i, sn = j;
                wor[i][j] = 1;
            } else {
                wor[i][j] = (t == '.' ? 1 : 0);
            }
        }
    }
    int ans = bfs(sm, sn);
    cout << ans - 1;
    return 0;
}