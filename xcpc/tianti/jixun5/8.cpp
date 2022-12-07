#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6;
int n;
bool fri[maxn] = {false};
bool vis[maxn] = {false};

int main(){
        int k;
    cin >> n;
    for (int i = 0; i < n;i++){
        int at;
        set<int> a;
        cin >> k;
        if(k == 1){
            cin >> at;
        } else {
            for (int j = 0; j < k;j++){
                cin >> at;
                a.insert(at);
            }
            for (set<int>::iterator j = a.begin(); j != a.end();j++){
                fri[*j] = true;
            }
        }
    }
    int m,t;
    vector<int> ans;
    cin >> m;
    for (int i = 0; i < m;i++){
        cin >> t;
        if(!fri[t] && !vis[t]){
            ans.push_back(t);
            vis[t] = true;
        } 
    }
    if(ans.empty()){
        cout << "No one is handsome";
    } else {
        for (int i = 0; i < ans.size();i++){
            cout << ans[i];
            if(i!=ans.size()-1){
                cout << ' ';
            }
        }
    }
    

    return 0;
}