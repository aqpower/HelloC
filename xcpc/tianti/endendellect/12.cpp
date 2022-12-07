#include <bits/stdc++.h>
using namespace std;
const int maxn = 105, inf = 1e9;
typedef pair<int, int> P;
vector<P> adj[maxn];
bool vis[maxn] = {false};
int n, m;
int d[maxn];

int ru[maxn] = {0};
bool prim(int s, int& sum){
    d[s] = 0;
    for (int k = 0; k < n;k++){
        int j = -1, min = inf;
        for (int i = 0; i < n;i++){
            if(!vis[i] && d[i] < min){
                j = i;
                min = d[i];
            }
        }
        if(j == -1){
            return false;
        }
        vis[j] = true;
        sum += d[j];
        for (int i = 0; i < adj[j].size();i++){
            int to = adj[j][i].first, co = adj[j][i].second;
            if(!vis[to] && co < d[to]){
                d[to] = co;
            }
        }
    }
    return true;
}
int main(){
    fill(d, d + maxn, inf);
    cin >> n >> m;
    int c1, c2, c;
    for (int i = 0; i < m;i++){
        cin >> c1 >> c2 >> c;
        ru[c2]++;
        adj[c1].push_back(P(c2,c));
    }
    for (int i = 0; i < n;i++){
        if(!ru[i]){
            int sum = 0;
            if(prim(i, sum)){
                cout << sum;
                return 0;
            } 
        }
    }
    cout << "Impossible";
    return 0;
}