#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000;
struct node{
    int x, y, step;
} Node, S, T;
int X[4] = {0, 0, 1, -1};
int Y[4] = {1, -1, 0, 0};
int n, m, maze[maxn][maxn];
bool inq[maxn][maxn] = {false};
bool judge(int x,int y){
    if(x >= n || x < 0 || y < 0 || y >= m){
        return false;
    }
    if(inq[x][y] || maze[x][y]){
        return false;
    }
    return true;
}
int BFS(int x,int y){
    queue<node> q;
    Node.x = x, Node.y = y, Node.step = 0;
    q.push(Node);
    inq[x][y] = true;
    while(!q.empty()){
        node top = q.front();
        if(top.x == T.x && top.y == T.y){
            return top.step;
        }
        q.pop();
        for (int i = 0; i < 4;i++){
            int newX = top.x + X[i];
            int newY = top.y + Y[i];
            if(judge(newX, newY)){
                Node.x = newX, Node.y = newY;
                Node.step = top.step + 1; //!!!
                inq[newX][newY] = true;
                q.push(Node);
            }
        }
    }
    return -1;
}
int main(){
    char t;
    cin >> n >> m;
    for (int i = 0; i < n;i++){
        getchar();
        for (int j = 0; j < m;j++){
            maze[i][j] = getchar() == '*' ? 1 : 0;
        }
    }
    cin >> S.x >> S.y >> T.x >> T.y;
    int ans = BFS(S.x, S.y);
    cout << ans << '\n';
    return 0;
}