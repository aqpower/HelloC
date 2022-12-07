#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
const int N = 1e5 + 5;
int n = 0, m = 0, h[N], hp[N], ph[N];
void heap_swap(int a, int b)
{
    swap(ph[hp[a]], ph[hp[b]]);
    swap(hp[a], hp[b]);
    swap(h[a], h[b]);
}
void down(int u)
{
    int t = u;
    if (u * 2 <= n && h[t] > h[u * 2])
        t = u * 2;
    if (u * 2 + 1 <= n && h[t] > h[u * 2] + 1)
        t = u * 2 + 1;
    if (t != u)
    {
        heap_swap(t, u);
        down(t);
    }
}
void up(int u)
{
    while (u / 2 && h[u] < h[u / 2])
    {
        heap_swap(u, u / 2);
        up(u / 2);
    }
}
int main()
{
    int t, x;
    string c;
    cin >> t;
    while (t--)
    {
        cin >> c;
        if (c == "I")
        {
            cin >> x;
            n++, m++;
            hp[n] = m, ph[m] = n;
            h[n] = x;
            up(n);
        }
        else if (c == "PM")
            cout << h[1] << endl;
        else if (c == "DM")
        {
            heap_swap(1, n);
            n--;
            down(1);
        }
        else if (c == "D")
        {
            int k;
            cin >> k;
            k = ph[k];
            heap_swap(k, n);
            n--;
            down(k), up(k);
        }
        else
        {
            int k, x;
            cin >> k >> x;
            k = ph[k];
            h[k] = x;
            down(k), up(k);
        }
    }
    return 0;
}