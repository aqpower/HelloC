#include <iostream>
using namespace std;

typedef long long ll;
ll a[100];
ll b[100];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        ll mia = 1e9, mib = 1e9;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            mia = min(mia, a[i]);
        }
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
            mib = min(mib, b[i]);
        }
        ll ans = 0;
        
        for (int i = 1; i <= n; i++) {
            if(a[i] > mia && b[i] > mib){
                ll da = a[i] - mia;
                ll db = b[i] - mib;
                ans += max(da, db);
            } else if(a[i] > mia){
                ans += a[i] - mia;
            } else if(b[i] > mib){
                ans += b[i] - mib;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}