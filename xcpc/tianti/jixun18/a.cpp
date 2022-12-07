#include <bits/stdc++.h>
using namespace std;
bool a[15];
int main(){
    string st, s;
    cin >> st;
    for (int i = 0; i < st.size();i++){
        if(st[i] != '*'){
            a[i] = true;
        }
    }
    int n;
    cin >> n;
    vector<string> ans;
    while(n--){
        cin >> s;
        bool flag = true;
        for (int i = 0; i < 9;i++){
            if(a[i]){
                if(s[i] != st[i]){
                    flag = false;
                    break;
                }
            }
        }
        if(flag){
            ans.push_back(s);
        }
    }
    cout << ans.size() << '\n';
    for(auto i:ans){
        cout << i << '\n';
    }
    return 0;
}