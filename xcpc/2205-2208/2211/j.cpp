#include <iostream>
using namespace std;

string s;
void solve() {
    cin >> s;
    long long sum = 0;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[i - 1]) {
            sum++;
        }
    }
    cout << sum << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}