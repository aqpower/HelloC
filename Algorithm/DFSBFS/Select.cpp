#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int a[N], n, k, target, maxvalue = 0;

vector<int> v, ans;
void dfs(int index, int sumk, int sum, int sumSqu)
{
    if (sumk == k && sum == target)
    {
        if (sumSqu > maxvalue)
        {
            ans = v;
            maxvalue = sumSqu;
            return;
        }
    }
    if (index >= n || sum > target || sumk > k)
    {
        return;
    }

    v.push_back(a[index]);
    dfs(index, sumk + 1, sum + a[index], sumSqu + a[index] * a[index]);
    v.pop_back();
    dfs(index + 1, sumk, sum, sumSqu);
}
int main()
{
    cin >> n >> k >> target;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    dfs(0, 0, 0, 0);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << ' ';
    }

    return 0;
}