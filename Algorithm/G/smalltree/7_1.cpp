#include <bits/stdc++.h>
using namespace std;
const int maxv = 1005, inf = 1e9;
int n;
struct edge{
    int to, cost;
};
vector<edge> Adj[maxv];
int d[maxv];
bool vis[maxv] = {false};

int Prim(int s){
    fill(d, d + n + 1, inf);
    d[s] = 0;
    int sum = 0;
    for (int k = 0; k < n;k++){
        int j = -1, min = inf;
        for (int i = 1; i <= n; i++){
            if (!vis[i] && d[i] < min)
            {
                j = i;
                min = d[i];
            }
        }
        if(j == -1){
            return -1;
        }
        vis[j] = true;
        sum += d[j];
        for (int i = 0; i < Adj[j].size();i++){
            int u = Adj[j][i].to, cost = Adj[j][i].cost;
            if(!vis[u] && cost < d[u]){
                d[u] = cost;
            }
        }
    }
    return sum;
}


int main(){
    int m;
    cin >> n >> m;
    int c1, c2, cost;
    for (int i = 0; i < m;i++){
        cin >> c1 >> c2 >> cost;
        edge vv;
        vv.to = c2, vv.cost = cost;
        Adj[c1].push_back(vv);
        vv.to = c1, vv.cost = cost;
        Adj[c2].push_back(vv);
    }
    int ans = Prim(1);
    cout << ans << '\n';

    return 0;
}