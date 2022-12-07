#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, a[12][12], flag = 1;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> a[i][j];
                if (i > j)
                {
                    if (a[i][j])
                        flag = 0;
                }
            }
        }
        cout << (flag ? "YES" : "NO") << endl;
    }

    return 0;
}