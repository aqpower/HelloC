#include <bits/stdc++.h>
using namespace std;
const int maxn = 10005, inf = 1e9;
vector<int> adj[maxn];
int ru[maxn];
int maxl = -1, ind = -1;
void dfs(int s, int l){
    if(adj[s].size() == 0){
        if(l > maxl){
            maxl = l;
            ind = s;
        }
        return;
    }
    for (int i = 0; i < adj[s].size();i++){
        dfs(adj[s][i], l + 1);
    }
}
int main(){
    int n;
    cin >> n;
    fill(ru, ru + maxn, 0);
    for (int i = 1; i <= n;i++){
        int k, t;
        cin >> k;
        for(int j = 0; j < k;j++){
            cin >> t;
            ru[t]++;
            adj[i].push_back(t);
        }
    }
    for (int i = 1; i <= n;i++){
        if(!ru[i]){
            dfs(i, 0);
            break;
        }
    }
    cout << ind;

    return 0;
}