#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string a, b;
        cin >> a >> b;
        if(a == b){
            cout << 0 << '\n';
        } else {
            int maxl = -1;
            int ans = 1e9;
            for (int i = 0; i < a.size();i++){
                for (int j = 0; j < b.size();j++){
                    if(b[j] == a[i]){
                        int nl = 0;
                        int na = i, nb = j;
                        while(na < a.size() && nb < b.size() && a[na] == b[nb]){
                            nl++;
                            na++;
                            nb++;
                        }
                        if(nl >= maxl){
                            int nn = a.size() + b.size() - 2 * nl;
                            maxl = nl;
                            ans = min(nn, ans);
                        } 
                    }
                }
            }
            if(maxl != -1){
                cout << ans << '\n';
            } else {
                cout << a.size() + b.size() << '\n';
            }
        }
    }
    return 0;
}