#include <iostream>
#include <vector>
#include <map>
using namespace std;
const int maxn = 205, inf = 1e9;
typedef pair<int, int> P;
int n, k, d[maxn], w[maxn], numpath, maxatt = -1, maxnum = -1;
bool vis[maxn];
string op, ed;
map<string, int> si;
map<int, string> is;
vector<P> adj[maxn];
vector<int> pre[maxn], anspath, now;
void dijkstra(){
    fill(d, d + maxn, inf);
    d[si[op]] = 0;
    for (int k = 0; k < n;k++){
        int j = -1, minv = inf;
        for (int i = 0; i < n;i++){
            if(!vis[i] && d[i] < minv){
                minv = d[i];
                j = i;
            }
        }
        if(j == -1){
            return;
        }
        vis[j] = true;
        for (int i = 0; i < adj[j].size();i++){
            int to = adj[j][i].first, cost = adj[j][i].second;
            if(!vis[to] && d[j] + cost < d[to]){
                d[to] = d[j] + cost;
                pre[to].clear();
                pre[to].push_back(j);
            } else if(!vis[to] && d[j] + cost == d[to]){
                pre[to].push_back(j);
            }
        }
    }
}
void dfs(int c){
    if(c == si[op]){
        numpath++;
        int nowarr = 0, numcity = 0;
        for (int i = 0; i < now.size();i++){
            nowarr += w[now[i]];
            numcity++;
        }
        if(numcity > maxnum){
            maxatt = nowarr;
            maxnum = numcity;
            anspath = now;
        } else if(numcity == maxnum){
            if(nowarr > maxatt){
                maxatt = nowarr;
                anspath = now;
            }
        }
        return;
    }
    for (int i = 0; i < pre[c].size();i++){
        now.push_back(pre[c][i]);
        dfs(pre[c][i]);
        now.pop_back();
    }
}
int main(){
    cin >> n >> k >> op >> ed;
    si[op] = 0;
    is[0] = op;
    string ts;
    for (int i = 1; i < n;i++){
        cin >> ts >> w[i];
        si[ts] = i;
        is[i] = ts;
    }
    string s1, s2;
    int td;
    while(k--){
        cin >> s1 >> s2 >> td;
        adj[si[s1]].push_back(P(si[s2],td));
        adj[si[s2]].push_back(P(si[s1],td));
    }
    dijkstra();
    now.push_back(si[ed]);
    dfs(si[ed]);
    reverse(anspath.begin(), anspath.end());
    for (int i = 0; i < anspath.size();i++){
        cout << is[anspath[i]];
        if(i != anspath.size() - 1){
            cout << "->";
        }
    }
    cout << '\n'
         << numpath << ' ' << d[si[ed]] << ' ' << maxatt << '\n';
    return 0;
}