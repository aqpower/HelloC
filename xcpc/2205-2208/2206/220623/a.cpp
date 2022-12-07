#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int a[5],g[5];
        cin >> a[0] >> a[1] >> a[2];
        int m = max(a[0], max(a[1], a[2]));
        g[0] = m - a[0];
        g[1] = m - a[1];
        g[2] = m - a[2];
        int nm = 0;
        for (int i = 0; i < 3;i++){
            if(a[i] == m){
                nm++;
            }
        }
        bool fg = false;
        if(nm != 1){
            fg = true;
        }
        for (int i = 0; i < 3;i++){
            if(a[i] == m){
                if(fg){
                    g[i]++;
                }
            } else {
                g[i]++;
            }
            cout << g[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}