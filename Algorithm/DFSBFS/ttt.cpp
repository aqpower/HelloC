#include <iostream>
#include <algorithm>
using namespace std;
void dfs(int g[3][4], int i, int j)
{
    g[i][j] = 0;
    if (i - 1 >= 0 && g[i - 1][j] == 1)
        dfs(g, i - 1, j);
    if (i + 1 <= 2 && g[i + 1][j] == 1)
        dfs(g, i + 1, j);
    if (j - 1 >= 0 && g[i][j - 1] == 1)
        dfs(g, i, j - 1);
    if (j + 1 <= 3 && g[i][j + 1] == 1)
        dfs(g, i, j + 1);
}
int main()
{
    int a[12] = {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1};
    int ans = 0;
    do
    {
        int g[3][4];
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (a[i * 4 + j] == 1)
                {
                    g[i][j] = 1;
                }
                else
                {
                    g[i][j] = 0;
                }
            }
        } // g中有五个格子被标记为1，现在用DFS做连通性检查
        int cnt = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (g[i][j] == 1)
                {                                                                   
                    dfs(g, i, j);
                    cnt++;
                }
            }
        }
        if (cnt == 1)
        {
            ans++;
        }
    } while (next_permutation(a, a + 12));
    cout << ans << endl;
}