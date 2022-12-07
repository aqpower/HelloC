#include <cstring>
#include <iostream>

using namespace std;
const int maxn = 3e5;
int a[maxn];
int main()
{
    int t;
    scanf_s("%d",&t);
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            scanf_s("%d", &a[i]);
        }
        int pos = n - 1;
        while (pos > 0 && a[pos] >= a[pos + 1]) {
            pos--;
        }
        while (pos > 0 && a[pos] <= a[pos + 1]) {
            pos--;
        }
        printf("%d\n", pos);
    }
    return 0;
}