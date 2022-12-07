#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int k;
    cin >> k;
    unordered_map<string, int> mp;
    for (int i = 0; i + k <= s.size();i++){
        string a = s.substr(i, k);
        if(mp[a]){
            mp[a]++;
        } else {
            mp[a] = 1;
        }
    }
    int maxn = -1;
    for (auto it = mp.begin(); it != mp.end();it++){
        if(it->second > maxn){
            maxn = it->second;
        }
    }
    cout << maxn;
    return 0;
}