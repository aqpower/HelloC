#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9, maxv = 1000;
struct V{
    int v, dis;
};
vector<V> Adj[maxv];
int st, ed, n, m, d[maxv];
void G(int s){
    fill(d, d + n, inf);
    d[s] = 0;
    for (int k = 0; k < n - 1;k++){
        for (int u = 0; u < n;u++){
            for (int i = 0; i < Adj[u].size();i++){
                int v = Adj[u][i].v;
                int dis = Adj[u][i].dis;
                if(d[u] + dis < d[v]){
                    d[v] = d[u] + dis;
                }
            }
        }
    }
}

int main(){
    cin >> n >> m >> st >> ed;
    int dis;
    for (int i = 0; i < m;i++){
        V cc1, cc2;
        cin >> cc1.v >> cc2.v >> dis;
        cc1.dis = dis;
        cc2.dis = dis;
        Adj[cc1.v].push_back(cc2);
        Adj[cc2.v].push_back(cc1);
    }
    G(st);
    for (int i = 0; i < n;i++){
        cout << d[i] << '\t';
    }

    return 0;
}