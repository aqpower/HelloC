#include <iostream>
using namespace std;
int a[105];
int main() {
    int n, m;
    double sum = 0;
    cin >> n >> m;
    int temp;
    for (int i = 1; i <= n; i++) {
        cin >> temp;
        cin >> a[temp];
        sum += a[temp];
    }
    if (a[m] < 60) {
        a[m] = 60;
    }
    sum /= n;
    for (int i = 1; i <= n; i++) {
        if (a[i] > sum && i != m) {
            a[i] -= 2;
            if (a[i] < 0) {
                a[i] = 0;
            }
        }
        cout << a[i] << " ";
    }
    return 0;
}