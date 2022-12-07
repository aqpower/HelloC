#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    int ans = 0;
    while(n != k){
        ans++;
        int da = abs(n - k) - 1;
        int db = abs(2 * n - k);
        if(da < db){
            if(k > n){
                n++;
            } else {
                n--;
            }
        } else {
            n = 2 * n;
        }
        cout << n << '\n';
    }
    cout << ans << '\n';
    return 0;
}