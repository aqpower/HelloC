#include <iostream>
using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll a, b, ans = 0;
        cin >> a >> b;
        ll c = abs(a - b);
        ans += c / 10;
        if(c % 10){
            ans++;
        }
        cout << ans << endl;
    }
    return 0;
}