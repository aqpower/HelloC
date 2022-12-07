// 找一个含n个数的数组中未出现过的最小正整数
#include <cstring>
#include <iostream>
using namespace std;

int findMin(int *a, int length) {
    bool *fg = (bool *)malloc((length + 5) * sizeof(bool));
    memset(fg, 0, sizeof(fg));
    for (int i = 0; i < length; i++) {
        if (a[i] <= length && a[i] > 0) {
            fg[a[i]] = true;
        }
    }
    for (int i = 1; i <= length; i++) {
        if (!fg[i]) {
            return i;
        }
    }
    return length + 1;
}

int main() {
    int n;
    cin >> n;
    int *a = (int *)malloc((n + 5) * sizeof(int));
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << findMin(a, n) << endl;
    return 0;
}

/*
5
1 -8 2 9 7
*/