#include <iostream>
#include <stack>
using namespace std;
int main()
{
    int n, m, k;
    //? judge the size of stack seems much more clear...
    cin >> n >> m >> k;
    while (k--)
    {
        stack<int> s;
        int flag = 0, pos = 1, t, dn = n;
        while (dn--)
        {
            cin >> t;
            if (t == pos)
            {
                pos++;
                while (s.size())
                {
                    if (s.top() == pos)
                    {
                        pos++;
                        s.pop();
                    }
                    else
                    {
                        break;
                    }
                }
                /*if (!s.empty())
                {
                    int dt = s.top();
                    while (dt == pos)
                    {
                        s.pop();
                        if (!s.empty())
                        {
                            dt = s.top();
                        }
                        if (pos + 1 > n)
                        {
                            break;
                        }
                        else
                        {
                            pos++;
                        }
                    }
                }*/
            }
            else
            {
                s.push(t);
                if (s.size() > m) //! judge only after action
                {
                    flag = 1;
                }
            }
        }
        if (s.size() || flag)
        {
            puts("NO");
        }
        else
        {
            puts("YES");
        }
    }
    return 0;
}