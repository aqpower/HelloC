#include <bits/stdc++.h>
using namespace std;


int main(){
    int t;
    vector<int> ans;
    while(cin >> t && t != -1){
        ans.push_back(t);
    }
    while(cin >> t && t != -1){
        ans.push_back(t);
    }
    if(ans.empty()){
        cout << "NULL\n";
    } else {
        sort(ans.begin(), ans.end());
        for (int i = 0; i < ans.size();i++){
            cout << ans[i];
            if(i != ans.size() - 1){
                cout << ' ';
            }
        }
    }


    return 0;
}