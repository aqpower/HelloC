#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 5;
bool vis[maxn] = {false};
int maxl = -1;
vector<vector<int>> ans;
vector<int> a[maxn];
void dfs(vector<int> v,int now,int l){
    if(a[now].size() == 0){
        if(l > maxl){
            ans.clear();
            maxl = l;
            ans.push_back(v);
        } else if(l == maxl){
            ans.push_back(v);
        }
        return;
    }
    for (int i = 0; i < a[now].size();i++){
        v.push_back(a[now][i]);
        dfs(v, a[now][i], l + 1);
        v.pop_back();
    }
}
int main(){
    int n, k, t;
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> k;
        while(k--){
            cin >> t;
            a[i].push_back(t);
            vis[t] = true;
        }
    }
    for (int i = 0; i < n;i++){
        if(!vis[i]){
            vector<int> an;
            an.push_back(i);
            dfs(an, i, 1);
            break;
        }
    }
    cout << maxl << '\n';
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans[0].size();i++){
        cout << ans[0][i];
        if(i != ans[0].size() - 1){
            cout << ' ';
        }
    }
        return 0;
}