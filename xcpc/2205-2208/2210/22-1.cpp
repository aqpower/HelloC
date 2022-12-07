#include <iostream>
using namespace std;

int main() {
    int x, y, z, a, b, c;
    cin >> x >> y >> z >> a >> b >> c;
    int i, j, k;
    i = b * z - c * y;
    j = -(a * z - c * x);
    k = a * y - b * x;
    cout << i << " " << j << " " << k << endl;
    return 0;
}


// a b c
// x y z