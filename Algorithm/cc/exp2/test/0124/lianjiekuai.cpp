#include <iostream>
#include <string>
using namespace std;
int father[100005];
int num[100005];
int findFather(int x)
{
    int a = x;
    while (x != father[x])
    {
        x = father[x];
    }
    while (a != father[a])
    {
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;
}
int findnum(int a, int n)
{
    int ans = 0, t = findFather(a);
    for (int i = 1; i <= n; i++)
    {
        if (findFather(i) == t)
            ans++;
    }
    return ans;
}
void Union(int a, int b)
{
    int fa = findFather(a);
    int fb = findFather(b);
    if (fa != fb)
    {
        father[fa] = fb;
        num[fb] += num[fa];
    }
}
int main()
{
    int n, m, a, b;
    string c;
    cin >> n >> m;
    getchar();
    for (int i = 1; i <= n; ++i)
    {
        father[i] = i;
        num[i] = 1;
    }
    while (m--)
    {
        cin >> c;
        if (c == "C")
        {
            cin >> a >> b;
            Union(a, b);
        }
        else if (c == "Q1")
        {
            cin >> a >> b;
            if (findFather(a) == findFather(b))
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
        else
        {
            cin >> a;
            cout << num[findFather(a)] << endl;
        }
        getchar();
    }
    return 0;
}