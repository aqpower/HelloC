#include <iostream>
using namespace std;
int a[5005];
int main() {
    int n;
    cin >> n;
    int ma = -1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ma = max(ma, a[i]);
    }
    
    return 0;
}