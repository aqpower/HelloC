#include <iostream>
#include <cstring>
using namespace std;
const int N = 5e4 + 5;
int father[N], food[N];
bool Union(int a, int b)
{
    int fa = father[a];
    int fb = father[b];
    if (fa != fb)
        return false;
    father[fa] = fb;
    food[fa] = food[fb];
    return true;
}
bool Eat(int a, int b)
{
    int fa = father[a];
    int fb = father[b];
    if (fa == fb)
        return false;
    if (food[fa] == 0)
    {
        food[fa] = fb;
        return true;
    }
    else
    {
        if (fb == food[fa])
            return true;
        return false;
    }
}
int main()
{
    int d, x, y, ans = 0, n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        father[i] = i;
    memset(food, 0, sizeof(food));
    while (k--)
    {
        cin >> d >> x >> y;
        if (x > n || y > n)
        {
            ans++;
            continue;
        }
        if (d == 1)
        {
            if (!Union(x, y))
                ans++;
        }
        else
        {
            if (!Eat(x, y))
                ans++;
        }
    }
    cout << ans << endl;
    return 0;
}