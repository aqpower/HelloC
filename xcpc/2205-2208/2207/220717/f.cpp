#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int ans = 0;
        for (int i = 1; i <= sqrt(n);i++){
            if(n % i == 0){
                double c = pow(i * i, 1.0 / 3);
                double d = pow((n / i) * (n / i), 1.0 / 3);
                if(fabs(c - (int)c) <= 1e-6){
                    ans++;
                }
                if(fabs(d - (int)d) <= 1e-6){
                    ans++;
                }
                cout << d << ' ' << static_cast<int>(d) << '\n';
            }
        }
        cout << ans << '\n';
    }
    return 0;
}