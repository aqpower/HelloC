#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9, maxv = 1000;
struct V{
    int v, dis;
};
int  s,tar;
int d[maxv], w[maxv], num[maxv], n, m, helper[maxv];
vector<V> Adj[maxv];
bool vis[maxv] = {false};

void Dijkatra ( ){
    fill(d, d + n, inf);
    fill(w, w + n, 0);
    fill(num, num + n, 0);
    d[s] = 0;
    w[s] = helper[s];
    num[s] = 1;
    for (int k = 0; k < n; k++){
        int j = -1, mindis = inf;
        for (int i = 0; i < n; i++){
            if (!vis[i] && d[i] < mindis)
            {
                j = i;
                mindis = d[i];
            }
        }
        if (j == -1){
            return;
        }
        vis[j] = true;
        for (int i = 0; i < Adj[j].size(); i++){
            int u = Adj[j][i].v, ddis = Adj[j][i].dis;
            int dw = w[j] + helper[u];
            if (!vis[u] && d[j] + ddis < d[u]){
                num[u] = num[j];
                d[u] = d[j] + ddis;
                w[u] = dw;
            } 
            else if (d[j] + ddis == d[u]) {
                num[u] += num[j];
                if(dw > w[u]){
                    w[u] = dw;
                }
            }
        }
    }
}

int main(){
    cin >> n >> m >> s >> tar;
    for (int i = 0; i < n;i++){
        cin >> helper[i];
    }
    int dis;
    for (int i = 0; i < m;i++){
        V cc1, cc2;
        cin >> cc1.v >> cc2.v >> dis;
        cc1.dis = dis;
        cc2.dis = dis;
        Adj[cc1.v].push_back(cc2);
        Adj[cc2.v].push_back(cc1);
    }
    Dijkatra();
    cout << num[tar] << ' ' << w[tar];
    
    
    cout << '\n';
    for (int i = 0; i < n;i++){
        cout << d[i] << '\t';
    }

    return 0;
}
