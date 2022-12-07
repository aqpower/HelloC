#include <bits/stdc++.h>
using namespace std;
vector<int> ans;
vector<int> myfind(int fir, int dn){
    vector<int> a;
    for (int i = fir; i <= dn;i++){
        if(dn % i == 0){
            a.push_back(i);
            dn /= i;
            if(dn == 1){
                break;
            }
        }
    }
    if(dn == 1){
        return a;
    } else {
        a.clear();
        return a;
    }
}
int num[10000];
int cal(vector<int> a){
    int l = 0, ml = 0;
    for (int i = 1; i < a.size();i++){
        if(a[i]-a[i-1] == 1){
            l++;
        } else {
            if(ml < l){
                ml = l;
            }
            l = 0;
        }
    }
    if(ml < l){
        ml = l;
    }
    return l;
}

int main(){
    int n;
    memset(num, 0, sizeof(num));
    cin >> n;
    vector<vector<int>> ans;
    for (int i = 1; i < sqrt(n);i++){
        vector<int> t = myfind(i, n);
        if(!t.empty()){
            ans.push_back(t);
        }
    }
    for (int i = 0; i < ans.size();i++){
        num[i] = cal(ans[i]);
    }
    int cp = -1, j = -1;
    for (int i = 0; i < ans.size();i++){
        if(num[i] > cp){
            cp = num[i];
            j = i;
        }
    }
    set<int> ffans;
    set<int> fans;
    for (int i = 1; i < ans[j].size();i++){
        if(ans[j][i] - ans[j][i-1] == 1){
            ffans.insert(ans[j][i]);
            ffans.insert(ans[j][i-1]);
        } else {
            if(fans.size() < ffans.size()){
                fans = ffans;
            }
            ffans.clear();
        }
    }
            if(fans.size() < ffans.size()){
                fans = ffans;
            }
    if(*fans.begin() == 1){
        fans.erase(fans.begin());
    }
    cout << fans.size() << '\n';
    for (auto i = fans.begin(); i != fans.end();i++){
        cout << *i;
        if(cp>0){
            cout << '*';
            cp--;
        }
    }

        return 0;
}

