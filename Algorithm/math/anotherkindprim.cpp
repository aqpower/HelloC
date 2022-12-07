#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6;
bool prim[maxn] = {false};
void initprim() {
    prim[2] = true;
    for (int i = 2; i < maxn; i++) {
        if (prim[i]) {
        }
    }
}
int main() {
    initprim();
    int n, t1, t2;
    scanf("%d", &n);
    while (n--) {
        scanf("%d%d", &t1, &t2);
        for (int i = t1; i <= t2; i++) {
            vector<int> di;
            while (i) {
                di.push_back(i % 10);
                i /= 10;
            }
            int sum = 0;
            for (int j = 0; j < di.size(); j++) {
                sum += di[j];
            }
        }
    }

    return 0;
}