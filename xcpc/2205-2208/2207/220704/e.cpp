#include <bits/stdc++.h>
using namespace std;
bool a[50];
int main(){
    int t;
    cin >> t;
    while(t--){
        memset(a, 0, sizeof(a));
        int n;
        cin >> n;
        char pr;
        char now;
        bool fg = true;
        for (int i = 0; i < n;i++){
            cin >> now;
            if(i && now != pr){
                    if (a[now - 'A']){
                        fg = false;
                    }
            } 
            a[now - 'A'] = true;
            pr = now;
        }
        if(fg){
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
    return 0;
}