#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 20;
struct qujian
{
    int x, y;
    bool cod = false;
} a[MAXN];
bool cmp(qujian a, qujian b)
{
    if (a.x != b.x)
        return a.x > b.x;
    return a.y < b.y;
}
int main()
{
    int ans = 1, n, i;
    cin >> n;
    for (i = 0; i < n; i++)
        cin >> a[i].x >> a[i].y;
    sort(a, a + n, cmp);
    int lastx = a[0].x;
    a[0].cod = true;
    for (i = 1; i < n; i++)
    {
        if (a[i].y <= lastx)
        {
            a[i].cod = true;
            lastx = a[i].x;
            ans++;
        }
    }
    cout << ans << endl;
    for (i = 0; i < n; i++)
    {
        if (a[i].cod)
            cout << a[i].x << ' ' << a[i].y << endl;
    }

    return 0;
}