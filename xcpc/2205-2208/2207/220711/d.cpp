#include <bits/stdc++.h>
using namespace std;
int a[300];
int main(){
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        bool fu = false;
        for (int i = 0; i < n;i++){
            cin >> a[i];
            if(a[i] < 0){
                fu = true;
            }
        }
        if(fu){
            cout << "NO" << '\n';
        } else {
            sort(a, a + n);
            int de = 1e9;
            for (int i = 1; i < n;i++){
                de = min(de, a[i] - a[i - 1]);
            }
            for (int i = 1; i < n;i++){
                if((a[i] - a[i-1]) % de){
                    de = 1;
                    break;
                }
            }
            if(a[0] % de){
                de = 1;
            }
            int k = a[n - 1] / de;
            if(a[n-1] % de){
                cout << "NO" << '\n';
                continue;
            }
                if(a[0]){
                    a[0] = de;
                } else {
                    k++;
                }
            if(k > 300){
                cout << "NO" << '\n';
            } else {
                cout << "YES" << '\n';
                cout << k << '\n';
                for (int i = 0; i < k;i++){
                    cout << a[0] + de * i << ' ';
                }
                cout << '\n';
            }
        }
    }
    return 0;
}