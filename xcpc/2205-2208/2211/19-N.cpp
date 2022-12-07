#include <cmath>
#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        // int ans = n / 2;
        // if (n % 2) {
        //     ans += 1;
        // }
        cout << (int)ceil(n) << endl;
    }
    return 0;
}