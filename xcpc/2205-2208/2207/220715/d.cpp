#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int op, ed;
        for (int i = 0; i < s.size();i++){
            if(s[i] == '*'){
                op = i;
                break;
            }
        }
        for (int i = s.size() - 1; i >= 0;i--){
            if(s[i] == '*'){
                ed = i;
                break;
            }
        }
        s[op] = 'x';
        s[ed] = 'x';
        if(op != ed){
            int ans = 2;
            for (int i = op; i < ed;i++){
                if(s[i] == 'x'){
                    bool fg = false;
                    int pr = -1;
                    for (int j = i + k; j > i;j--){
                        if(s[j] == '*' && pr == -1){
                            pr = j;
                        }
                        if(s[j] == 'x'){
                            fg = true;
                            break;
                        }
                    }
                    if(!fg){
                        s[pr] = 'x';
                        ans++;
                    }
                }
            }
            cout << ans << '\n';
        } else {
            cout << 1 << '\n';
        }
    }
    return 0;
}