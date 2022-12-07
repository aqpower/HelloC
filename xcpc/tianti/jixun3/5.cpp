#include <iostream>
using namespace std;

int main()
{
    long long ans = 0;
    int n, a[10];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j == i)
                continue;
            ans += a[i] * 10 + a[j];
        }
    }
    cout << ans << endl;
    return 0;
}
