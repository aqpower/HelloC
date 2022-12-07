#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
const int maxn = 1e5 + 5;

int main()
{
    cin.tie(0)->ios::sync_with_stdio(false);
    int t;
    cin >> t;
    int a[11];
    for (int i = 0; i < 11; i++)
    {
        a[i] = 9 - i;
    }
    while (t--)
    {
        int n;
        cin >> n;
        if (n <= 10)
        {
            for (int i = 9; n > 0; i--)
            {
                cout << i;
                n--;
            }
            cout << '\n';
        }
        else
        {
            int ind = 0;
            while(n){
                cout << a[ind];
                ind++;
                if(ind > 9){
                    ind = 0;
                }
                n--;
            }
            cout << '\n';
        }
    }
    return 0;
}
