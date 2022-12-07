#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        int ans = 0;
        for (int i = a; i <= b;i++){
            bool fg = true;
            int t = i;
            while(t / 16){
                int b = t % 16;
                if(b > 9){
                    fg = false;
                    break;
                }
                t /= 16;
            }
            if(t > 0 && t % 16 > 9){
                fg = false;
            }
            if(fg){
                ans++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}