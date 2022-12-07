#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int,int> P;
const int maxn = 1e5 + 5;
vector<P> adj[maxn];
int d[maxn][maxn];

int dij(int s){
    
}




int main(){
    cin.tie(0)->ios::sync_with_stdio(false);
    int n, m, k, u, v, l;
    cin >> n >> m >> k;
    for (int i = 0; i < m;i++){
        cin >> u >> v >> l;
        adj[u].push_back(P(v, l));
        adj[v].push_back(P(u, l));
    }
    int w, ans = 1e9;
    for (int i = 0; i < k;i++){
        cin >> w;
        for (int j = 0; j < adj[w].size();j++){
            int cost = adj[w][j].second;
            ans = min(cost, ans);
        }
    }


    if(ans == 1e9){
        cout << -1 << '\n';
    } else {
        cout << ans << '\n';
    }
    return 0;
}
