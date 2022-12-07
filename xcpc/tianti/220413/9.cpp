#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9, maxn = 505;
int v, e, k;
vector<int> adj[maxn];
int con[maxn];
int main(){
    cin >> v >> e >> k;
    int c1, c2;
    while(e--){
        cin >> c1 >> c2;
        adj[c1].push_back(c2);
        adj[c2].push_back(c1);
    }
    int n;
    cin >> n;
    while(n--){
        int t;
        set<int> ncol;
        memset(con, -1, sizeof(con));
        for(int i = 1; i <= v;i++){
            cin >> t;
            ncol.insert(t);
            con[i] = t;
        }
        bool flag = true;
        if(ncol.size() != k){
            flag = false;
        } else {
            for (int i = 1; i <= v;i++){
                for (int j = 1; j < adj[i].size();j++){
                    if(con[i] == con[adj[i][j]]){
                        flag = false;
                        break;
                    }
                }
            }
        }
        if(flag){
            cout << "Yes";
        } else {
            cout << "No";
        }
        cout << '\n';
    }
    return 0;
}