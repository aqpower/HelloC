#include <iostream>
using namespace std;

int main() {
    auto f = [](int a, int b) { return a + b; };
    cout << f(1, 2) << endl;
    int n = 100, m = 10;
    auto g = [n, &m](int i) {
        m = 20 * i;
        return m * 10;
    };
    cout << g(10) << endl;
    cout << n << endl;
    cout << m << endl;
    return 0;
}