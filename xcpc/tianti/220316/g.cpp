#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    while(t--){
        int l, r, m;
        cin >> l >> r >> m;
        for (int i = l; i <= r;i++){
            for (int j = l; j <= r;j++){
                for (int k = l; k <= r;k++){
                    int n = (m + k - j) / i;
                    if (n > 0 && (m+k-j)%i == 0 ){
                        cout << i << ' ' << j << ' ' << k << '\n';
                        goto l1;
                    }
                }
            }
        }
        l1:;
    }

    return 0;
}