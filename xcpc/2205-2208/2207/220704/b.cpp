#include <bits/stdc++.h>
using namespace std;
int a[55];
bool wor[10005];
int main(){
    int t;
    cin >> t;
    while(t--){
        memset(wor, 0, sizeof(wor));
        int n;
        cin >> n;
        int nu = 0,qu = 0;
        for (int i = 0; i < n;i++){
            cin >> a[i];
            if(!wor[a[i]]){
                wor[a[i]] = true;
                nu++;
            } else {
                qu++;
            }
        }
        if(qu & 1){
            nu--;
        }
        cout << nu << '\n';
    }
    return 0;
}