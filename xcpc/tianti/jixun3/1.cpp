#include <iostream>
using namespace std;
int main()
{
    int num, t, flag = 0;
    cin >> num >> t;
    int te = t;
    while (t--)
    {
        if (flag)
        {
            num *= 2;
            flag = 0;
        }
        else
        {
            flag = 1;
        }
    }
    cout << (te & 1 ? 1 : 0) << ' ' << num << endl;
    return 0;
}