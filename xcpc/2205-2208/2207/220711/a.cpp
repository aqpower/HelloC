#include <bits/stdc++.h>
using namespace std;
int a[105];
int main(){
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int sma, bi;
        for (int i = 0; i < n;i++){
            cin >> a[i];
            if(a[i] == 1){
                sma = i;
            }
            if(a[i] == n){
                bi = i;
            }
        }
        int ans = n - 1 - max(sma, bi)  + 1 + min(sma, bi) + 1;
        int a2 = max(sma, bi) + 1;
        int a3 = n - 1 - min(bi, sma) + 1;
        cout << min(ans,min(a2,a3)) << '\n';
    }

    return 0;
}