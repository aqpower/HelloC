#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int a, t, ans = 0;
        cin >> a;
        for (int i = 0; i < 3;i++){
            cin >> t;
            if(t > a){
                ans++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}