#include <iostream>
using namespace std;

int main()
{
    long long b[10], r[10];
    long long sb = 0, sr = 0;
    for (int i = 0; i < 5; i++) {
        cin >> b[i];
        sb += b[i];
    }
    for (int i = 0; i < 5; i++) {
        cin >> r[i];
        sr += r[i];
    }
    if (sb >= sr) {
        cout << "Blue" << '\n';
    } else {
        cout << "Red" << '\n';
    }
    return 0;
}
