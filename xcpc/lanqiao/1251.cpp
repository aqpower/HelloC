#include <bits/stdc++.h>
using namespace std;
bool isleap(int n) { return (n % 4 == 0 && n % 100 != 0) || (n % 400 == 0); }
int dic[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main() {
    int a, b, c, n;
    while (cin >> a >> b >> c >> n) {
        while (n) {
            n--;
            int lim = dic[b];
            if (isleap(a) && b == 2) {
                lim++;
            }
            if (c < lim) {
                c++;
            } else {
                c = 1;
                if (b < 12) {
                    b++;
                } else {
                    b = 1;
                    a++;
                }
            }
        }
        printf("%d-%02d-%02d\n", a, b, c);
    }

    return 0;
}