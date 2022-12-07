#include <iostream>
#include <cstring>
using namespace std;
int n, m, mymin = 2 << 20;
const int N = 105;
int world[N][N];
bool pos[N][N];
void deal(int x, int y, int cnt)
{

    if (x == n && y == n)
    {
        if (cnt < mymin)
            mymin = cnt;
    }
    if (x + 1 <= n && !world[x + 1][y] && !pos[x + 1][y])
    {
        pos[x + 1][y] = true;
        deal(x + 1, y, cnt + 1);
        pos[x + 1][y] = false;
    }
    if (y + 1 <= m && !world[x][y + 1] && !pos[x][y + 1])
    {
        pos[x][y + 1] = true;
        deal(x, y + 1, cnt + 1);
        pos[x][y + 1] = false;
    }
    if (x - 1 > 0 && !world[x - 1][y] && !pos[x - 1][y])
    {
        pos[x - 1][y] = true;
        deal(x - 1, y, cnt + 1);
        pos[x - 1][y] = false;
    }
    if (y - 1 <= m && !world[x][y - 1] && !pos[x][y - 1])
    {
        pos[x][y - 1] = true;
        deal(x, y - 1, cnt + 1);
        pos[x][y - 1] = false;
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> world[i][j];
        }
    }
    memset(pos, 0, sizeof(pos));
    pos[1][1] = true;
    deal(1, 1, 0);

    cout << mymin << endl;

    return 0;
}