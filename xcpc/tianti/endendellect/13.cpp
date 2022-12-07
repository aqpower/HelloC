#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005, inf = 1e9;
vector<int> adj[maxn];
int n, m;
int d[maxn][maxn];
bool vis[maxn][maxn] = {false};
void dij(int s){
    d[s][s] = 0;
    for (int k = 1; k <= n;k++) {
        int j = -1, min = inf;
        for (int i = 1; i <= n;i++){
            if(!vis[s][i] && d[s][i] < min){
                min = d[s][i];
                j = i;
            }
        }
        if(j == -1){
            break;
        }
        vis[s][j] = true;
        for (int i = 0; i < adj[j].size();i++){
            int to = adj[j][i];
            if(!vis[s][to] && d[s][j] + 1 < d[s][to]){
                d[s][to] = d[s][j] + 1;
            }
        }
    }
}
int main(){
    fill(d[0], d[0] + maxn * maxn, inf);
    cin >> n >> m;
    int c1, c2;
    for (int i = 0; i < m;i++){
        cin >> c1 >> c2;
        adj[c1].push_back(c2);
        adj[c2].push_back(c1);
    }
    for (int i = 1; i <= n;i++){
        dij(i);
        double sum = 0;
        for (int j = 1; j <= n;j++){
            if(d[i][j] <= 6){
                sum++;
            }
        }
        cout << i << ": ";
        printf("%.2lf%%\n", sum / n * 100);
    }
    

    return 0;
}