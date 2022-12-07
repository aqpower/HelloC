#include <bits/stdc++.h>
using namespace std;
const int maxv = 105, inf = 1e9;
struct edge{
    int to;
    long long cost;
    edge(){};
    edge(int _to,int _cost): to(_to),cost(_cost){}
};
int n;
vector<edge> Adj[maxv];
int d[maxv];
bool vis[maxv] = {false};

long long Prim(int s ){
    long long sum = 0;
    d[s] = 0;
    for (int k = 0; k < n;k++){
        int j = -1, min = inf;
        for (int i = 1; i <= n;i++){
            if(!vis[i] && d[i] < min){
                j = i;
                min = d[i];
            }
        }
        if(j == -1){
            break;
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
    cin >> n;
    int c1, c2, con;
    long long cost;
    fill(d, d + n + 1, inf);
    for (int k = 0; k < n * (n - 1) / 2;k++){
        cin >> c1 >> c2 >> cost >> con;
        Adj[c1].push_back(edge(c2, cost));
        Adj[c2].push_back(edge(c1, cost));
        if(con){
            d[c1] = d[c2] = 0;
        }
    }
    long long ans = Prim(1);
    cout << ans << '\n';

    return 0;
}
