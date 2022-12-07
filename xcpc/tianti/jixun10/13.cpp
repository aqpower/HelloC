#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 5;
int n, m;
int dic[maxn];
vector<int> now;
vector<vector<int>> ans;
void dfs(int sum, int e){
    if(e > n){
        return;
    }
    if(sum > m){
        return;
    }
    if (sum == m){
        ans.push_back(now);
        return;
    }
    now.push_back(dic[e]);
    dfs(sum + dic[e], e + 1);
    now.pop_back();
    dfs(sum, e + 1);
}
bool cmp(vector<int> a,vector<int> b){
    int m = min(a.size(), b.size());
    int da = 0, db = 0;
    while(a[da]==b[db]){
        da++;
        db++;
        if(da>m||db>m){
            a.size() < b.size();
        }
    }
    return a[da] < b[db];
}
int main(){
    int t;
    cin >> n >> m;
    for (int i = 1; i <= n;i++){
        cin >> t;
        dic[i] = t;
    }
    sort(dic + 1, dic + n + 1);
    dfs(0, 1);
    if(ans.empty()){
        cout << "No Solution";
    } else {
        for (int i = 0; i < ans.size();i++){
            sort(ans[i].begin(), ans[i].end());
        }
        sort(ans.begin(), ans.end(), cmp);
        for (int i = 0; i < ans[0].size();i++){
            cout << ans[0][i];
            if(i!=ans[0].size()-1){
                cout << ' ';
            }
        }
    }

    return 0;
}