#include <map>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
typedef pair<int, int> P;
int dat[8][8];
bool vis[8][8];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
vector<P> pre[8][8];
bool judge(int a, int b){
    if(a >= 0 && a < 5 && b >= 0 && b < 5){
        return true;
    }
    return false;
}
int main(){
    for (int i = 0; i < 5;i++){
        for (int j = 0; j < 5;j++){
            cin >> dat[i][j];
        }
    }
    queue<P> qu;
    qu.push(P(0, 0));
    while(!qu.empty()){
        P now = qu.front();
        qu.pop();
        vis[now.first][now.second] = true;
        for (int i = 0; i < 4;i++){
            int tox = now.first + dx[i];
            int toy = now.second + dy[i];
            if(!vis[tox][toy] && judge(tox, toy) && (!dat[tox][toy])){
                pre[tox][toy].push_back(now);
                qu.push(P(tox, toy));
            }
        }
    }
    int i = 4, j = 4;
    vector<P> ans;
    while(!pre[i][j].empty()){
        int di = pre[i][j][0].first;
        int dj = pre[i][j][0].second;
        ans.push_back(pre[i][j][0]);
        i = di, j = dj;
    }
    for (int i = ans.size() - 1; i >= 0;i--){
        printf("(%d, %d)\n", ans[i].first, ans[i].second);
    }
    printf("(4, 4)");
    return 0;
}