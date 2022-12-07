#include <iostream>
#include <algorithm>
using namespace std;

int a[100];

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        if(n == 1){
            cout << "YES" << '\n';
            continue;
        }
        sort(a + 1, a + 1 + n);
        bool fg = true;
        for (int i = 2; i <= n; i++) {
            if(a[i] - a[i-1] > 1){
                fg = false;
                break;
            }
        }
        if(fg){
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
    return 0;
}