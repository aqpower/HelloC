#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 5;
vector<int> adj[maxn];
int nump[maxn];
int maxl = -1;
vector<int> ans;
set<vector<int>> aa;
void dfs(int s, int law){
    if(adj[s].empty()){
        if(law > maxl){
            maxl = law;
            aa.clear();
            aa.insert(ans);
        } else if(law == maxl) {
            aa.insert(ans);
        } 
        return;
    }
    for (int i = 0; i < adj[s].size();i++){
        int to = adj[s][i];
        ans.push_back(to);
        dfs(to, law + 1);
        ans.pop_back();
    }
}
int main(){
    fill(nump, nump + maxn, 0);
    int n;
    cin >> n;
    int dn, t;
    for (int i = 0; i < n;i++){
        cin >> dn;
        while(dn--){
            cin >> t;
            nump[t]++;
            adj[i].push_back(t);
        }
    }
    for (int i = 0; i < n;i++){
        if(!nump[i]){
            ans.push_back(i);
            dfs(i, 1);
        }
    }
    ans = *aa.begin();
    cout << maxl << '\n';
    for (int i = 0; i < ans.size();i++){
        cout << ans[i];
        if(i != ans.size() - 1){
            cout << ' ';
        }
    }

    return 0;
}