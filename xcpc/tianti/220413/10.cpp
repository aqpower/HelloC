#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6;
int dic[maxn];
int nex[maxn];
void print(vector<int> &a){
    for (int i = 0; i < a.size();i++){
        printf("%05d %d ", a[i], dic[a[i]]);
        if(nex[a[i]] == -1){
            cout << -1;
        } else {
            printf("%05d", nex[a[i]]);
        }
        cout << '\n';
    }
}
int main(){
    set<int> se;
    int sta, n, ind, a, tnex,p;
    cin >> sta >> n;
    while(n--){
        cin >> ind;
        cin >> dic[ind] >> nex[ind];
    }
    vector<int> ans, pass;
    while(sta != -1){
        int now = abs(dic[sta]);
        if(!se.count(now)){
            se.insert(now);
            ans.push_back(sta);
        } else {
            pass.push_back(sta);
        }
        sta = nex[sta];
    }
    for (int i = 1; i < ans.size();i++){
        nex[ans[i-1]] = ans[i];
        if(i == ans.size() - 1){
            nex[ans[i]] = -1;
        }
    }
    for (int i = 1; i < pass.size();i++){
        nex[pass[i - 1]] = pass[i];
        if(i == pass.size() - 1){
            nex[pass[i]] = -1;
        }
    }
    print(ans);
    print(pass);
    return 0;
}