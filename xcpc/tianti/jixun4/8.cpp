#include <iostream>
#include <string>
using namespace std;
int main()
{
    int t, x, y, n, pos = 0;
    cin >> x >> y >> n;
    string s;
    char op[100];
    sprintf(op, "%d", x);
    s += op;
    sprintf(op, "%d", y);
    s += op;
    while (s.length() < n)
    {
        t = (s[pos] - '0') * (s[pos + 1] - '0');
        sprintf(op, "%d", t);
        s += op;
        pos++;
    }
    for (int i = 0; i < n; i++)
    {
        if (i + 1 == n)
        {
            cout << s[i] << '\n';
        }
        else
        {
            cout << s[i] << ' ';
        }
    }
    return 0;
}