#include <iostream>
#include <map>
using namespace std;

int main()
{
    int n, x;
    map<int, int> mp;
    char c;
    cin >> n;
    getchar();
    while (n--)
    {
        cin >> c >> x;
        getchar();
        if (c == 'I')
        {
            mp[x] = 1;
        }
        else
        {
            if (mp.find(x) != mp.end())
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