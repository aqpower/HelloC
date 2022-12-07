#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
const int maxn = 1e5 + 5;

int main()
{
    cin.tie(0)->ios::sync_with_stdio(false);
    string s, sa, sb;
    cin >> s;
    ll a, b;
    bool fg = true, fa = true, fpl = true;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] > '9' || s[i] < '0')
        {
            if (s[i] == '-')
            {
                fpl = false;
            }
            else if (s[i] == '+')
            {
                
            }
            else
            {
                fg = false;
                break;
            }
            if (sa.size() == 0)
            {
                fg = false;
                break;
            }
            fa = false;
        }
        else
        {
            if (fa)
            {
                sa += s[i];
            }
            else
            {
                sb += s[i];
            }
        }
    }
    if(sa.size() == 0 || sb.size() == 0){
        fg = false;
    }
    if (!fg)
    {
        cout << "skipped" << endl;
        return 0;
    }
    a = stoll(sa);
    b = stoll(sb);
    if (fpl)
    {
        cout << a + b << '\n';
    }
    else
    {
        cout << a - b << '\n';
    }
    return 0;
}
