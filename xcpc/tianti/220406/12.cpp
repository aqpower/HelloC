#include <bits/stdc++.h>
using namespace std;
const int maxn = 504, inf = 1e9;
typedef pair<int, int> P;
int n, m, s, d, w[maxn],c[maxn];
bool vis[maxn];
vector<P> adj[maxn];
int ans = 0, smax = -1, mpa = inf;
vector<int> anspath;
void dfs(int s,vector<int> path, int len,int sum){
    if(s == d){
        if(len < mpa){
            ans = 1;
            mpa = len;
            anspath = path;
            smax = sum;
        } else if(len == mpa){
            ans++;
            if(sum > smax){
                smax = sum;
                anspath = path;
            }
        }
        return;
    }
    for (int i = 0; i != adj[s].size();i++){
        int to = adj[s][i].first, cost = adj[s][i].second;
        if(!vis[to]){
            path.push_back(to);
            vis[to] = true;
            dfs(to, path, len + cost, sum + w[to]);
            vis[to] = false;
            path.pop_back();
        }
    }
}
int main(){
    cin >> n >> m >> s >> d;
    for (int i = 0; i < n;i++){
        cin >> w[i];
    }
    int c1, c2, len;
    while(m--){
        cin >> c1 >> c2 >> len;
        adj[c1].push_back(P(c2, len));
        adj[c2].push_back(P(c1, len));
    }
    vector<int> pa;
    pa.push_back(s);
    dfs(s,pa,0,w[s]);
    cout << ans << ' ' << smax << '\n';
    for (int i = 0; i < anspath.size();i++){
        cout << anspath[i];
        if(i != anspath.size() - 1){
            cout << ' ';
        }
    }
    return 0;
}