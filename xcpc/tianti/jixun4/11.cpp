#include <iostream>
using namespace std;
const int N = 1e5 + 5;
int main()
{
    int n, d, a[N];
    cin >> n >> d;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int ans = 0, i = 0, j = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            if (a[i] + a[j] > d && a[j] + d > a[i] && a[i] + d > a[j])
            {
                ans++;
            }
        }
    }
    cout << ans / 2 << endl;
    return 0;
}