#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n, ans = 0;
        string s;
        cin >> n >> s;
        string sn = to_string(n);
        int nsum = 0;
        for (int i = 0; i < sn.size(); i++) {
            nsum += sn[i] - '0';
        }
        cout << nsum << endl;
        if(nsum <= n){
            
        }
        cout << ans << '\n';
    }
    return 0;
}