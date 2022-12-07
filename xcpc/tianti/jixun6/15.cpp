#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9, maxn = 1005;
int n, m;
typedef pair<int, int> P;
int d[maxn];
bool vis[maxn] = {false};
vector<P> Adj[maxn];
int ans = 0;
int prim(int s){
    d[s] = 0;
    for (int k = 1; k <= n;k++){
        int j = -1, min = inf;
        for (int i = 1; i <= n;i++){
            if(!vis[i] && d[i] < min){
                min = d[i];
                j = i;
            }
        }
        if(j == -1){
            return -1;
        }
        vis[j] = true;
        for (int i = 0; i < Adj[j].size();i++){
            int u = Adj[u][i].first, dd = Adj[u][i].second;
            if(!vis[u] && d[j] + dd < d[u]){
                d[u] = 0;
                ans += dd;
            }
        }
    }
    return 0;
}
int main(){
    fill(d, d + maxn, inf);
    cin >> n >> m;
    int c1, c2, cost;
    for (int i = 0; i < m;i++){
        cin >> c1 >> c2 >> cost;
        Adj[c1].push_back(P(c2, cost));
        Adj[c2].push_back(P(c1, cost));
    }
    if(!prim(1)){
        cout << ans;
    } else {
        cout << "Impossible";
    }


        return 0;
}