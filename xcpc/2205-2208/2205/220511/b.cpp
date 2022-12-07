#include <bits/stdc++.h>
using namespace std;
int dat[200];
int main(){
    int n;
    cin >> n;
    while(n--){
        memset(dat, 0, sizeof(dat));
        string s, t;
        cin >> s >> t;
        // set<char> se;
        // for (int i = 0; i < t.size();i++){
        //     for (int j = i; j < s.size();){
        //         if(s[j] != t[i] && se.count(s[j]) == 0){
        //             s.erase(j, 1);
        //         } else {
        //             se.insert(s[j]);
        //             break;
        //         }
        //     }
        // }
        for (int i = 0; i < s.size();i++){
            if(t.find(s[i]) != -1){
                dat[s[i]] = i;
            }
        }
        for (int i = 0; i < t.size();i++){
            cout << i << ' '<< dat[t[i]] << '\n';
        }
        cout << '\n\n';
    }
    return 0;
}