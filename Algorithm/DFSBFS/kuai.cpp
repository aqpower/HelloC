#include <bits/stdc++.h>
using namespace std;
const int maxn = 100;
struct node
{
    int x, y;
} Node;
int n, m;
int matrix[maxn][maxn];
bool inq[maxn][maxn] = {false};
int X[4] = {0, 0, 1, -1};
int Y[4] = {1, -1, 0, 0};
bool judge(int x,int y){
    if(x >= n || x < 0 || y >= m||y < 0){
        return false;
    }
    if(matrix[x][y] == 0 || inq [x][y]){
        return false;
    }
    return true;
}
void BFS(int x,int y){
    queue<node> q;
    Node.x = x,Node.y = y;
    inq[x][y] = true;
    q.push(Node);
    while(!q.empty()){
        node top = q.front();
        q.pop();
        for (int i = 0; i < 4;i++){
            int newX = top.x + X[i];
            int newY = top.y + Y[i];
            if(judge(newX,newY)){
                inq[newX][newY] = true;
                Node.x = newX, Node.y = newY;
                q.push(Node);
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n;i++){
        for (int j = 0; j < m;j++){
            cin >> matrix[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < n;i++){
        for (int j = 0; j < m;j++){
            if(matrix[i][j] == 1 && !inq[i][j]){
                ans++;
                BFS(i, j);
            }
        }
    }
    cout << ans << '\n';
    return 0;
}