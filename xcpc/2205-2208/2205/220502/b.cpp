#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int k = 1;k <= t;k++){
        int n, ans = 0;
        cin >> n;
        getchar();
        string s;
        getline(cin, s);
        int bro = 0;
        for (int i = 0; i < s.size();i++){
            if(s[i] == '.'){
                if(bro < 0){
                    ans++;
                    bro = 3;
                } else if(bro == 0){
                    ans++;
                    bro += 3;
                }
            }
            bro--;
        }
        printf("Case %d: %d\n", k, ans);
    }
    return 0;
}