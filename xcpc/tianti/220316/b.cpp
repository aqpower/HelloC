#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        getchar();
        string s;
        getline(cin, s);
        int i = 0, j = s.size() - 1, num = 0;
        while (i < j)
        {
            if (s[i] == s[j])
            {
                i++, j--;
                num++;
            }
            else
            {
                break;
            }
        }
        if(num == k){
            if(s.size() == 2*k){
                cout << "NO";
            } else {
                cout << "YES";
            }
        }
        else if (num > k)
        {
            cout << "YES";
        }
        else
        {
            cout << "NO";
        }
        cout << '\n';
    }

    return 0;
}