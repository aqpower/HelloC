#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 4;
int n, maxs = -1;
vector<int> father[maxn], son[maxn];
set<int> ans;
void dfs(int n, int step){
    if(son[n].empty()){
        if(step > maxs){
            maxs = step;
            ans.clear();
            ans.insert(n);
        } else if(step == maxs){
            ans.insert(n);
        }
        return;
    }
    for (int i = 0; i < son[n].size();i++){
        dfs(son[n][i], step + 1);
    }
}
int main(){
    cin >> n;
    int s, t;
    for (int i = 1; i <= n;i++){
        cin >> t;
        father[i].push_back(t);
        son[t].push_back(i);
        if(t == -1){
            s = i;
        }
    }
    dfs(s,1);
    cout << maxs << '\n';
    for (auto i = ans.begin(); i != ans.end();i++){
        cout << (*i);
        if(i!= --ans.end()){
            cout << ' ';
        }
    }
    return 0;
}