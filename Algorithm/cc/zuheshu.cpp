#include <iostream>
using namespace std;
int res[67][67] = {0};
long long C(int n, int m)
{
    if (m == 0 || m == n)
        return 1;
    if (res[n][m])
        return res[n][m];
    return res[n][m] = C(n - 1, m) + C(n - 1, m - 1);
}
long long C_1(int n, int m)
{
    long long ans = 1;
    for (int i = 0; i <= m; i++)
    {
        ans = ans * (n - m + 1) / i;
    }
    return ans;
}
int main()
{
    int n, m;
    long long ans;
    cin >> n >> m;
    ans = C(n, m);
    cout << ans << endl;
    return 0;
}