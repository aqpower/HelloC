#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, t;
    cin >> n;
    getchar();
    string s, car[5005];
    map<string, int> zan;
    for (int k = 0; k < n;k++){
        cin >> car[k];
    }
    int m,ave = 0;
    cin >> m;
    for (int i = 0; i < m;i++){
        cin >> s >> t;
        ave += t;
        zan[s] = t;
    }
    ave /= m;
    set<string> ans;
    for (auto i = zan.begin(); i != zan.end();i++){
        bool flag = false;
        s = (*i).first;
        for (int k = 0; k < n;k++){
            if(car[k] == s){
                flag = true;
                break;
            }
        }
        if(flag){
            continue;
        } else {
            if((*i).second > ave){
                ans.insert(s);
            }
        }
    }
    if(ans.empty()){
        cout << "Bing Mei You";
    } else {
        for (auto i = ans.begin(); i != ans.end();i++){
            cout << *i << '\n';
        }
    }
    return 0;
}