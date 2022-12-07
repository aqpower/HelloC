#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int> adj[205];

int main(){
    cin >> n >> m;
    int c1, c2;
    for (int i = 0; i < m;i++){
        cin >> c1 >> c2;
        adj[c1].push_back(c2);
        adj[c2].push_back(c1);
    }
    int k;
    cin >> k;
    while(k--){
        bool vis[n + 5] = {false};
        int num, t;
        cin >> num;
        vector<int> road;
        for (int i = 0; i < num;i++){
            cin >> t;
            road.push_back(t);
        }
        bool f = false;
        for (int i = 0; i < road.size();i++){
            if(!i){
                continue;
            }
            int pre = road[i - 1];
            int now = road[i];
            for (int j = 0; j < adj[pre].size();j++){
                if(now == adj[pre][j]){
                    if(vis[now]){
                        f = true;
                    }
                    vis[now] = true;
                    continue;
                }
            }
        }
        for (int i = 1; i <= n;i++){
            if(vis[i] == false){
                f = true;
            }
        }
        if(f){
            cout << "NO" << '\n';
        } else {
            cout << "YES" << '\n';
        }
    }

    return 0;
}