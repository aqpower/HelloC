#include <iostream>
using namespace std;

typedef struct P {
    int x, y, z;
} P;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        P p[10];
        for (int i = 0; i < 8; i++) {
            cin >> p[i].x >> p[i].y >> p[i].z;
        }
    }
    return 0;
}