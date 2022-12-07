#include <bits/stdc++.h>
using namespace std;
int a[55];
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int min = 1e9;
        for (int i = 0; i < n;i++){
            cin >> a[i];
            if(a[i] < min){
                min = a[i];
            }
        }
        int ans = 0;
        for (int i = 0; i < n;i++){
            ans += a[i] - min;
        }
        cout << ans << '\n';
    }
    return 0;
}