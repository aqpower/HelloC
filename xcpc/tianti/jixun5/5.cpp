#include <bits/stdc++.h>
using namespace std;
map<int, int> ans;
int main()
{
    string str;
    cin >> str;
    int n[2000];
    int i ,t;
    for ( i = 0; i < str.size(); i++)
    {
        n[i] = str[i] - '0';
    }
    for (int j = 0; j < i;j++)
    {
        t = n[j];
        if (ans[t])
        {
            ans[t]++;
        }
        else
        {
            ans[t] = 1;
        }
    } 
    while (!ans.empty())
    {
        cout << ans.begin()->first << ":" << ans.begin()->second << '\n';
        ans.erase(ans.begin());
    }

    return 0;
}