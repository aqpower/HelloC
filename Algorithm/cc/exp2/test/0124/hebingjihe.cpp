#include <iostream>
using namespace std;
int father[100005];
int findfather(int x)
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
void Union(int a, int b)
{
    int fa = findfather(a),
        fb = findfather(b);
    if (fa != fb)
    {
        father[fa] = fb;
    }
}
int main()
{
    int n, m, a, b;
    cin >> n >> m;
    getchar();
    for (int i = 1; i <= n; i++)
        father[i] = i;
    char c;
    while (m--)
    {
        cin >> c >> a >> b;
        getchar();
        if (c == 'M')
        {
            Union(a, b);
        }
        else
        {
            if (findfather(a) == findfather(b))
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