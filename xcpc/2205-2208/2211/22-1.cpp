#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n, temp;
        cin >> n;
        int a[100], k = 0;
        bool fg[100];
        memset(fg, 0, sizeof(fg));
        for (int i = 0; i < 2 * n; i++) {
            cin >> temp;
            if (!fg[temp]) {
                fg[temp] = true;
                a[k++] = temp;
            }
        }
        for (int i = 0; i < n; i++) {
            cout << a[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}