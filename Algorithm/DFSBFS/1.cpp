#include <iostream>
#include <cstring>
using namespace std;
const int N = 1e5 + 5;
struct Man
{
    char sex;
    int fa;
    int ma;
} a[N];
int judge[N], ans;
void dfs(int x, int cnt)
{
    if (x == 0 || cnt > 4)
    {
        return;
    }
    judge[x] = 1;
    dfs(a[x].fa, ++cnt);
    dfs(a[x].ma, ++cnt);
}
void dfs_(int x, int cnt)
{
    if (x == 0 || cnt > 4)
    {
        return;
    }
    if (judge[x] == 1)
    {
        ans = 0;
        return;
    }
    dfs(a[x].fa, ++cnt);
    dfs(a[x].ma, ++cnt);
}

int main()
{
    int t, n, x, y, m, dn;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> t;
        cin >> a[t].sex >> m >> dn;
        if (m != -1)
        {
            a[t].fa = m;
        }
        if (dn != -1)
        {
            a[t].ma = dn;
        }
    }
    int k;
    cin >> k;
    while (k--)
    {
        cin >> x >> y;
        if (a[x].sex == a[y].sex)
        {
            cout << "Never Mind" << endl;
        }
        else
        {
            ans = 1;
            memset(judge, 0, sizeof(judge));
            dfs(x, y);
            dfs_(x, y);
            if (ans)
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
    }
    return 0;
}