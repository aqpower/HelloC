#include <iostream>
using namespace std;
int addi(int n)
{
    int ans = 0;
    while (n)
    {
        ans += n % 10;
        n /= 10;
    }
    return ans;
}

int main()
{
    int t, add;
    cin >> t;
    while (t--)
    {
        int n, re, flag = 0;
        cin >> n;
        for (int i = 2; i <= 9; i++)
        {
            add = addi(n * i);
            if (i == 2)
            {
                re = add;
            }
            if (i > 2)
            {
                if (add == re)
                    continue;
                else
                {
                    flag = 1;
                    break;
                }
            }
        }
        if (flag)
            cout << "NO" << endl;
        else
            cout << re << endl;
    }

    return 0;
}
