#include <bits/stdc++.h>
using namespace std;
bool used[10];
bool ping(int n) {
    string s1, s2;
    int t;
    s1 = to_string(n * n);
    s2 = to_string(n * n * n);
    if (s1.size() + s2.size() != 10) {
        return false;
    }
    for (int i = 0; i < s1.size(); i++) {
        t = s1[i] - '0';
        if (used[t]) {
            return false;
        } else {
            used[t] = true;
        }
    }
    for (int i = 0; i < s2.size(); i++) {
        t = s2[i] - '0';
        if (used[t]) {
            return false;
        } else {
            used[t] = true;
        }
    }

    return true;
}
int main() {
    for (int i = 1;; i++) {
        memset(used, 0, sizeof(used));
        if (ping(i)) {
            cout << i;
            break;
        }
    }

    return 0;
}