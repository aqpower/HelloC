#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005, inf = 1e9;
int d[maxn], m, n, maxt = -1;
typedef pair<int, int> P;
vector<P> adj[maxn];
bool vis[maxn] = {false};
bool prim(int s){
    d[s] = 0;
    for (int k = 0; k < n;k++){
        int j = -1, min = inf;
        for (int i = 1; i <= n;i++){
            if(!vis[i] && d[i] < min){
                min = d[i];
                j = i;
            }
        }
        if(j == -1){
            return false;
        }
        vis[j] = true;
        if(d[j] > maxt){
            maxt = d[j];
        }
        for (int i = 0; i < adj[j].size();i++){
            int to = adj[j][i].first, nt = adj[j][i].second;
            if(!vis[to] && nt < d[to]){
                d[to] = nt;
            }
        }
    }
    return true;
}
int main(){
    fill(d, d + maxn, inf);
    cin >> n >> m;
    int c1, c2, c;
    while(m--){
        cin >> c1 >> c2 >> c;
        adj[c1].push_back(P(c2, c));
        adj[c2].push_back(P(c1, c));
    }
    if(prim(1)){
        cout << maxt;
    } else {
        cout << -1;
    }
    return 0;
}