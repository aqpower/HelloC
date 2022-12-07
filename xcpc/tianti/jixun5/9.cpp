#include <bits/stdc++.h>
using namespace std;
const int maxn = 505, inf = 1e9;
int n, m, s, tar;
typedef pair<int, int> P;
vector<P> Adj[maxn];
int w[maxn], d[maxn],num[maxn],maxw[maxn],pre[maxn];
bool vis[maxn] = {false};
void ans()
{
    d[s] = 0;
    num[s] = 1;
    maxw[s] = w[s];
    for (int k = 0; k < n; k++)
    {
        int j = -1, min = inf;
        for (int i = 0; i < n; i++)
        {
            if (d[i] < min && !vis[i])
            {
                j = i;
                min = d[i];
            }
        }
        if (j == -1)
        {
            return;
        }
        vis[j] = true;
        for (int i = 0; i < Adj[j].size();i++){
            int u = Adj[j][i].first, cost = Adj[j][i].second;
            if(d[j] + cost < d[u] && !vis[u]){
                pre[u] = j;
                maxw[u] = maxw[j] + w[u];
                d[u] = d[j] + cost;
                num[u] = num[j];
            } else if(d[j] + cost == d[u]){
                num[u] += num[j];
                if(maxw[j] + w[u] > maxw[u] ){
                    pre[u] = j;
                    maxw[u] = maxw[j] + w[u];
                }
            }
        }
    }
}

void Print(int s){
    if(pre[s] == s){
        cout << s << ' ';
        return;
    }
    Print(pre[s]);
    cout << s ;
    if(s!=tar){
        cout << ' ';
    }
}

int main()
{
    cin >> n >> m >> s >> tar;
    for (int i = 0; i < n; i++)
    {
        d[i] = inf;
        num[i] = 0;
        maxw[i] = 0;
        pre[i] = i;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }
    int c1, c2, w;
    for (int k = 0; k < m; k++)
    {
        cin >> c1 >> c2 >> w;
        Adj[c1].push_back(P(c2, w));
        Adj[c2].push_back(P(c1, w));
    }

    ans();

    cout << num[tar] << ' ' << maxw[tar] << '\n';
    Print(tar);

    return 0;
}