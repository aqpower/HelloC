#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int a[maxn];
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        bool fg = false;
        for (int i = 0; i < n;i++){
            scanf("%d", &a[i]);
            if(i){
                if(a[i] <= a[i-1]){
                    fg = true;
                }
            }
        }
        if(n & 1){
            if(fg){
                cout << "YES" << '\n';
            } else {
                cout << "NO" << '\n';
            }
        } else {
            cout << "YES" << '\n';
        }
    }
    return 0;
}